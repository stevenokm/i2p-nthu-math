#include <iostream>

using namespace std;

class Integer
{
private:
    int m_int_value;

public:
    Integer(int arg_int_value)
    {
        m_int_value = arg_int_value;
    }
    int get_int_value()
    {
        return m_int_value;
    }
    void set_int_value(int arg_int_value)
    {
        m_int_value = arg_int_value;
    }
};

class Real : public Integer
{
private:
    double after_decimal;

public:
    Real(double arg_value) : Integer((int)arg_value),
                             after_decimal(arg_value - (int)arg_value)
    {
    }
    double get_real_value()
    {
        return after_decimal + get_int_value();
    }
    void set_real_value(double arg_value)
    {
        set_int_value((int)arg_value);
        after_decimal = arg_value - (int)arg_value;
    }
};

int main()
{
    Real r(3.14);
    cout << r.get_int_value() << endl;
    cout << r.get_real_value() << endl;
    r.set_real_value(3.1415);
    cout << r.get_real_value() << endl;
    r.set_int_value(4);
    cout << r.get_real_value() << endl;
    return 0;
}