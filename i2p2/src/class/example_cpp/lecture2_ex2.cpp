#include <iostream>

using namespace std;

class Vector
{
public:
    int x, y, z;

    void init();
    void print();
    void modify(int, int, int);
    int dot(const Vector &);
    Vector cross(const Vector &);
};

void Vector::init()
{
    x = 0;
    y = 0;
    z = 0;
}

void Vector::print()
{
    cout << "Vector: "
         << "(" << x << ", " << y << ", " << z << ")";
}

void Vector::modify(int arg_x, int arg_y, int arg_z)
{
    x = arg_x;
    y = arg_y;
    z = arg_z;
}

int Vector::dot(const Vector &arg_v)
{
    return x * arg_v.x + y * arg_v.y + z * arg_v.z;
}

Vector Vector::cross(const Vector &arg_v)
{
    Vector v;
    v.x = y * arg_v.z - z * arg_v.y;
    v.y = z * arg_v.x - x * arg_v.z;
    v.z = x * arg_v.y - y * arg_v.x;
    return v;
}

int main()
{
    Vector v1, v2;
    v1.init();
    v1.print();
    cout << endl;
    v1.modify(1, 1, 1);
    v1.print();
    cout << endl;
    cout << endl;

    v2.init();
    v2.print();
    cout << endl;
    cout << endl;

    v2.modify(2, 3, 4);
    cout << "v1: ";
    v1.print();
    cout << endl;
    cout << "v2: ";
    v2.print();
    cout << endl;
    cout << "Dot: " << v1.dot(v2) << endl;
    cout << endl;

    v2.modify(5, 6, 7);
    Vector v3 = v1.cross(v2);
    cout << "v1: ";
    v1.print();
    cout << endl;
    cout << "v2: ";
    v2.print();
    cout << endl;
    cout << "Cross: ";
    v3.print();
    cout << endl;
    cout << endl;

    return 0;
}