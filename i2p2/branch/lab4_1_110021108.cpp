#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Simple scientific calculator" << '\n'
         << "1) plus (+)" << '\n'
         << "2) minus (-)" << '\n'
         << "3) multiplication (*)" << '\n'
         << "4) division (/)" << '\n'
         << "Please select the operator: ";
    cin >> a;
    switch (a)
    {
    case 1:
        cout << "You selected: +" << endl;
        break;
    case 2:
        cout << "You selected: -" << endl;
        break;
    case 3:
        cout << "You selected: *" << endl;
        break;
    case 4:
        cout << "You selected: /" << endl;
        break;
    default:
        cout << "You selected: ?" << endl;
    }
    return 0;
}