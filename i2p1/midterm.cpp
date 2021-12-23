#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    vector<int> num_a, num_b;
    string input_buffer;
    int select_function;

    while (true)
    {
        // select function
        cout << "Big number calculator" << endl
             << "1) display only" << endl
             << "2) plus (+)" << endl
             << "3) greatest common divider (gcd)" << endl
             << "0) exit" << endl
             << "Please select the operator: ";
        cin >> input_buffer;

        // start of check selected function is valid
        if (input_buffer == "0")
        {
            select_function = 0;
        }
        else if (input_buffer == "1")
        {
            select_function = 1;
        }
        else if (input_buffer == "2")
        {
            select_function = 2;
        }
        else if (input_buffer == "3")
        {
            select_function = 3;
        }
        else
        {
            cout << "Invalid input: " << input_buffer << endl
                 << endl;
            continue;
        }
        // end of check selected function is valid
        // start of inform selected function
        if (select_function == 0)
        {
            cout << endl;
            break;
        }
        else if (select_function == 1)
        {
            cout << "You selected: display only" << endl;
        }
        else if (select_function == 2)
        {
            cout << "You selected: +" << endl;
        }
        else if (select_function == 3)
        {
            cout << "You selected: gcd" << endl;
        }
        // end of inform selected function

        // clear buffer
        input_buffer.clear();

        // input number (a)
        while (true)
        {
            cout << "Input integer number (a): ";
            cin >> input_buffer;

            bool valid = true;
            // check if input is valid
            for (int i = 0; i < input_buffer.size(); i++)
            {
                if (!isdigit(input_buffer[i]))
                {
                    valid = false;
                    break;
                }
            }

            if (!valid)
            {
                cout << "Invalid input: " << input_buffer << endl
                     << endl;
                continue;
            }

            // convert string to int
            for (int i = 0; i < input_buffer.size(); i++)
            {
                num_a.push_back(input_buffer[i] - '0');
            }

            // remove leading zeros
            while (num_a.size() > 1 && num_a[0] == 0)
            {
                num_a.erase(num_a.begin());
            }

            reverse(num_a.begin(), num_a.end());

            // check if input is valid for gcd
            if (select_function == 3 && num_a.size() == 1 && num_a[0] == 0)
            {
                cout << "Invalid input: " << input_buffer << endl
                     << endl;
                num_a.clear();
                continue;
            }

            break;
        }

        // clear buffer
        input_buffer.clear();

        // input number (b)
        while (true)
        {
            cout << "Input integer number (b): ";
            cin >> input_buffer;

            bool valid = true;
            // check if input is valid
            for (int i = 0; i < input_buffer.size(); i++)
            {
                if (!isdigit(input_buffer[i]))
                {
                    valid = false;
                    break;
                }
            }

            if (!valid)
            {
                cout << "Invalid input: " << input_buffer << endl
                     << endl;
                continue;
            }

            // convert string to int
            for (int i = 0; i < input_buffer.size(); i++)
            {
                num_b.push_back(input_buffer[i] - '0');
            }

            // remove leading zeros
            while (num_b.size() > 1 && num_b[0] == 0)
            {
                num_b.erase(num_b.begin());
            }

            reverse(num_b.begin(), num_b.end());

            // check if input is valid for gcd
            if (select_function == 3 && num_b.size() == 1 && num_b[0] == 0)
            {
                cout << "Invalid input: " << input_buffer << endl
                     << endl;
                num_b.clear();
                continue;
            }

            break;
        }

        // clear buffer
        input_buffer.clear();

        // print number (a)
        cout << "(a) = ";
        for (int i = num_a.size() - 1; i >= 0; i--)
        {
            cout << num_a[i];
        }
        cout << endl;
        // print number (b)
        cout << "(b) = ";
        for (int i = num_b.size() - 1; i >= 0; i--)
        {
            cout << num_b[i];
        }
        cout << endl;

        // calculation

        if (select_function == 2)
        {
            // plus
            vector<int> result;
            int carry = 0;

            for (int i = 0; i < max(num_a.size(), num_b.size()); i++)
            {
                int sum = carry;
                if (i < num_a.size())
                {
                    sum += num_a[i];
                }
                if (i < num_b.size())
                {
                    sum += num_b[i];
                }

                result.push_back(sum % 10);
                carry = sum / 10;
            }

            if (carry != 0)
            {
                result.push_back(carry);
            }

            cout << "(a) + (b) = ";
            for (int i = result.size() - 1; i >= 0; i--)
            {
                cout << result[i];
            }
            cout << endl;
        }
        else if (select_function == 3)
        {
            // gcd
            while (true)
            {
                // compaire a and b
                int comp = 0;
                if (num_a.size() > num_b.size())
                {
                    comp = 1;
                }
                else if (num_a.size() < num_b.size())
                {
                    comp = -1;
                }
                else
                {
                    for (int i = num_a.size() - 1; i >= 0; i--)
                    {
                        if (num_a[i] > num_b[i])
                        {
                            comp = 1;
                            break;
                        }
                        else if (num_a[i] < num_b[i])
                        {
                            comp = -1;
                            break;
                        }
                    }
                }

                // if a == b, break
                if (comp == 0)
                {
                    break;
                }
                // if a > b
                else if (comp == 1)
                {
                    // a = a - b
                    int carry = 0;
                    for (int i = 0; i < num_a.size(); i++)
                    {
                        int sub = num_a[i] - carry;
                        if (i < num_b.size())
                        {
                            sub -= num_b[i];
                        }
                        if (sub < 0)
                        {
                            sub += 10;
                            carry = 1;
                        }
                        else
                        {
                            carry = 0;
                        }
                        num_a[i] = sub;
                    }
                }
                // if a < b
                else
                {
                    // b = b - a
                    int carry = 0;
                    for (int i = 0; i < num_b.size(); i++)
                    {
                        int sub = num_b[i] - carry;
                        if (i < num_a.size())
                        {
                            sub -= num_a[i];
                        }
                        if (sub < 0)
                        {
                            sub += 10;
                            carry = 1;
                        }
                        else
                        {
                            carry = 0;
                        }
                        num_b[i] = sub;
                    }
                }

                // remove leading zeros
                for (int i = num_a.size() - 1; i >= 0; i--)
                {
                    if (num_a[i] != 0)
                    {
                        break;
                    }
                    num_a.pop_back();
                }
                for (int i = num_b.size() - 1; i >= 0; i--)
                {
                    if (num_b[i] != 0)
                    {
                        break;
                    }
                    num_b.pop_back();
                }

                // if a == 0, b is the result
                if (num_a.size() == 1 && num_a[0] == 0)
                {
                    num_a.swap(num_b);
                    break;
                }
                // else if b == 0, a is the result
                else if (num_b.size() == 1 && num_b[0] == 0)
                {
                    break;
                }
            }

            cout << "(a) gcd (b) = ";
            for (int i = num_a.size() - 1; i >= 0; i--)
            {
                cout << num_a[i];
            }
            cout << endl;
        }

        // clean up (a) and (b)
        num_a.clear();
        num_b.clear();

        cout << endl;
    }
}