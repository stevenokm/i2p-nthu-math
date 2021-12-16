#include <iostream>
#include <vector>

using namespace std;

int main()
{
     char buffer[10001];
     vector<int> a, b, c;
     int n, a_sign = 1, b_sign = 1, c_sign = 1;
     bool zero_start = true;

     cout << "Big number calculator"
          << endl
          << "1) display only"
          << endl
          << "2) plus (+)"
          << endl
          << "3) minus (-)"
          << endl
          << "4) multiplication (*)"
          << endl
          << "5) division (/)"
          << endl
          << "Please select the operator: ";

     cin >> buffer;
     if (!isdigit(buffer[0]) || buffer[1] != '\0')
     {
          cout << "Invalid input: " << buffer << endl;
          return 0;
     }

     n = buffer[0]-'0' ;
     switch (n)
     {
     case 1:
          cout << "You selected: display only" << endl;
          break;
     case 2:
          cout << "You selected: +" << endl;
          break;
     case 3:
          cout << "You selected: -" << endl;
          break;
     case 4:
          cout << "You selected: *" << endl;
          break;
     case 5:
          cout << "You selected: /" << endl;
          break;
     default:
          cout << "Invalid input: " << buffer << endl;
          return 0;
     }
     
     for(int i=0; buffer[i] != '\0'; i++) buffer[i] = '\0' ;
     cout << "Input integer number (a): ";
     cin >> buffer;
     zero_start = true;

     for (int i = 0; buffer[i] != '\0'; i++)
     {
          if (!isdigit(buffer[i]))
          {
               if (i == 0 && buffer[i] == '-')
               {
                    a_sign = -1;
                    continue;
               }
               else
               {
                    cout << "Invalid input: " << buffer << endl;
                    return 0;
               }
          }

          if (buffer[i] == '0' && zero_start)
               continue;
          else
          {
               a.push_back((int)(buffer[i] - '0'));
               zero_start = false;
          }
     }
     if (a.empty())
     {
          a.push_back(0);
          a_sign = 0;
     }
     reverse(a.begin(), a.end());

     for(int i=0; buffer[i] != '\0'; i++) buffer[i] = '\0' ;
     cout << "Input integer number (b): ";
     cin >> buffer;
     zero_start = true;
     for (int i = 0; buffer[i] != '\0'; i++)
     {
          if (!isdigit(buffer[i]))
          {
               if (i == 0 && buffer[i] == '-')
               {
                    b_sign = -1;
                    continue;
               }
               else
               {
                    cout << "Invalid input: " << buffer << endl;
                    return 0;
               }
          }

          if (buffer[i] == '0' && zero_start)
               continue;
          else
          {
               b.push_back((int)(buffer[i] - '0'));
               zero_start = false;
          }
     }
     if (b.empty())
     {
          if (n == 5)
          {
               cout << "Invalid input: " << buffer << endl;
               return 0;
          }
          b.push_back(0);
          b_sign = 0;
     }
     reverse(b.begin(), b.end());

     cout << "(a) = " << (a_sign == -1 ? "-" : "");
     for (int i = a.size() - 1; i >= 0; i--)
          cout << a[i];
     cout << '\n'
          << "(b) = " << (b_sign == -1 ? "-" : "");
     for (int i = b.size() - 1; i >= 0; i--)
          cout << b[i];
     cout << endl;
     // Initialization Done

     int carry = 0;
     if (n == 1)
          return 0; // "Display only"
     // "Display only" Done

     else if (n == 2) // "+"
     {
          for (int i = 0; i < a.size() && i < b.size(); i++)
          {
               c.push_back((a[i] * a_sign + b[i] * b_sign + carry) % 10);
               carry = (a[i] * a_sign + b[i] * b_sign + carry) / 10;
          }
          if (a.size() > b.size())
          {
               for (int i = b.size(); i < a.size(); i++)
               {
                    c.push_back((a[i] * a_sign + carry) % 10);
                    carry = (a[i] * a_sign + carry) / 10;
               }
          }
          else
          {
               for (int i = a.size(); i < b.size(); i++)
               {
                    c.push_back((b[i] * b_sign + carry) % 10);
                    carry = (b[i] * b_sign + carry) / 10;
               }
          }
          c.push_back(carry);

          zero_start = true;
          for (int i = c.size() - 1; i >= 0; i--)
          {
               if (c[i] == 0 && zero_start)
                    c.pop_back();
               else
                    break;
          }
          if (c.empty())
               c.push_back(0);

          c_sign = (c[c.size() - 1] < 0 ? -1 : 1);

          for (int i = 0; i < c.size(); i++)
          {
               if (c_sign * c[i] < 0)
               {
                    c[i] += (10 * c_sign);
                    if (i + 1 < c.size())
                         c[i + 1] += (-1 * c_sign);
                    else
                         c.push_back(-1 * c_sign);
               }
               c[i] *= c_sign;
          }

          cout << "(a) + (b) = " << (c_sign < 0 ? "-" : "");
          for (int i = c.size() - 1; i >= 0; i--)
               cout << c[i];
          cout << endl;
          return 0;
     }
     // "+" Done

     else if (n == 3) // "-"
     {
          for (int i = 0; i < a.size() && i < b.size(); i++)
          {
               c.push_back((a[i] * a_sign - b[i] * b_sign + carry) % 10);
               carry = (a[i] * a_sign - b[i] * b_sign + carry) / 10;
          }
          if (a.size() > b.size())
          {
               for (int i = b.size(); i < a.size(); i++)
               {
                    c.push_back((a[i] * a_sign + carry) % 10);
                    carry = (a[i] * a_sign + carry) / 10;
               }
          }
          else
          {
               for (int i = a.size(); i < b.size(); i++)
               {
                    c.push_back((-b[i] * b_sign + carry) % 10);
                    carry = (-b[i] * b_sign + carry) / 10;
               }
          }
          c.push_back(carry);

          zero_start = true;
          for (int i = c.size() - 1; i >= 0; i--)
          {
               if (c[i] == 0 && zero_start)
                    c.pop_back();
               else
                    break;
          }
          if (c.empty())
               c.push_back(0);

          c_sign = (c[c.size() - 1] < 0 ? -1 : 1);

          for (int i = 0; i < c.size(); i++)
          {
               if (c_sign * c[i] < 0)
               {
                    c[i] += (10 * c_sign);
                    if (i + 1 < c.size())
                         c[i + 1] += (-1 * c_sign);
                    else
                         c.push_back(-1 * c_sign);
               }
               c[i] *= c_sign;
          }

          cout << "(a) - (b) = " << (c_sign < 0 ? "-" : "");
          for (int i = c.size() - 1; i >= 0; i--)
               cout << c[i];
          cout << endl;
          return 0;
     }
     // "-" Done

     else if (n == 4) // "*"
     {
          c_sign = a_sign * b_sign;
          for (int i = 0; i < b.size(); i++)
          {
               for (int j = 0; j < a.size(); j++)
               {
                    if (i + j >= c.size())
                         c.push_back(a[j] * b[i]);
                    else
                         c[i + j] += a[j] * b[i];
               }
          }
          for (int i = 0; i < c.size(); i++)
          {
               carry += c[i];
               c[i] = carry % 10;
               carry /= 10;
          }
          c.push_back(carry);

          zero_start = true;
          for (int i = c.size() - 1; i >= 0; i--)
          {
               if (c[i] == 0 && zero_start)
                    c.pop_back();
               else
                    break;
          }
          if (c.empty())
               c.push_back(0);

          cout << "(a) * (b) = " << (c_sign < 0 ? "-" : "");
          for (int i = c.size() - 1; i >= 0; i--)
               cout << c[i];
          cout << endl;
          return 0;
     }
     // "*" Done

     else if (n == 5) // "/"
     {
          c_sign = a_sign * b_sign;
          c.push_back(0) ;

          while (a.size() >= b.size())
          {
               for (int i = 0; i < b.size(); i++)
               {
                    carry += a[i] - b[i] + 10 ;
                    a[i] = carry % 10 ;
                    carry = carry / 10 - 1 ;
               }

               for (int i = b.size(); i < a.size(); i++)
               {
                    if( carry == 0 ) break ;
                    carry += a[i] + 10 ;
                    a[i] = carry % 10 ;
                    carry = carry / 10 - 1 ;
               }
               a.push_back(carry) ;

               zero_start = true;
               for (int i = a.size() - 1; i >= 0; i--)
               {
                    if (a[i] == 0 && zero_start)
                         a.pop_back();
                    else
                         break;
               }
               if (a.empty())
                    a.push_back(0);

               if ( a[a.size()-1] >= 0 ) c[0]++ ;
               else break ;
          }

          cout << "(a) / (b) = " << (c_sign < 0 ? "-" : "") << c[0] << endl ;
          return 0 ;
     }
     // "/" Done

     return 0;
}