#include <iostream>
#include <fstream>
#include <cmath>

#include "lecture18_ex.h"

using namespace std;


// main function

int main()
{
    Vector_3D v1(1, 2, 3);
    Vector_3D v2(4, 5, 6);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    // save the vector to the file in binary format
    ofstream ofs("vector.bin", ios::binary | ios::trunc);
    v1.write_binary(ofs);
    v2.write_binary(ofs);
    ofs.close();

    // read the vector from the file in binary format
    ifstream ifs("vector.bin", ios::binary);
    Vector_3D v3, v4;
    v3.read_binary(ifs);
    v4.read_binary(ifs);

    cout << "v3 = " << v3 << endl;
    cout << "v4 = " << v4 << endl;

    // or read/write whole object
    ofstream ofs2("vector_whole.bin", ios::binary | ios::trunc);
    ofs2.write((char *)&v1, sizeof(Vector_3D));
    ofs2.write((char *)&v2, sizeof(Vector_3D));
    ofs2.close();

    ifstream ifs2("vector_whole.bin", ios::binary);
    Vector_3D v5, v6;
    ifs2.read((char *)&v5, sizeof(Vector_3D));
    ifs2.read((char *)&v6, sizeof(Vector_3D));

    cout << "v5 = " << v5 << endl;
    cout << "v6 = " << v6 << endl;

    // NOTE: compaire "vector.bin" and "vector_whole.bin"

    return 0;
}