#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
     int a, i = 0;
     string text, old, password, password0, password1, password2, name, user, age, word, word1;
     string creds[2], cp[2];

     cout << "_______________________________" << endl
          << endl;
     cout << "         Security System      " << endl
          << endl;
     cout << "_______________________________" << endl;
     cout << "|        1. Register          |" << endl;
     cout << "|        2. Login             |" << endl;
     cout << "|        3. Change Password   |" << endl;
     cout << "|________4. End Program_______|" << endl
          << endl;

     do
     {
          cout << endl
               << endl;
          cout << "Enter Your Choice----";
          cin >> a;
          switch (a)
          {
          case 1:
          {
               cout << "_________________________________" << endl
                    << endl;
               cout << "|-----------Register-------------|" << endl;
               cout << "|________________________________|" << endl
                    << endl;
               cout << "Enter Username -";
               cin >> name;
               cout << "Enter Password -";
               cin >> password0;
               cout << "Enter your Age -";
               cin >> age;

               ofstream of1;
               of1.open("file.txt");
               if (of1.is_open())
               {
                    of1 << name << "\n";
                    of1 << password0;
                    cout << "Registration Successfull" << endl;
                    of1.close();
               }
               break;
          }
          case 2:
          {
               cout << "________________________________" << endl
                    << endl;
               cout << "|-------------Login-------------|" << endl;
               cout << "|_______________________________|" << endl
                    << endl;
               //   read from file
               ifstream of2;
               of2.open("file.txt");
               cout << "Enter Your username:- ";
               cin >> user;
               cout << "Enter Password:- ";
               cin >> password;

               if (of2.is_open())
               { // when end of file is not reached
                    while (!of2.eof())
                    {
                         // read file line by line
                         while (getline(of2, text))
                         {

                              istringstream iss(text); // store extracted data
                              iss >> word;
                              creds[i] = word;
                              i++;
                         }

                         // check if the username and password matches
                         if (user == creds[0] && password == creds[1])
                         {
                              cout << "---Login Successfull---";
                              cout << endl
                                   << endl;

                              cout << "DETAILS :" << endl;
                              cout << "Username: " + user << endl;
                              cout << "Password: " + password << endl;
                              cout << "Age: " + age << endl;
                         }
                         // if username and password does not match
                         else
                         {
                              cout << endl
                                   << endl;
                              cout << "Incorrect Credentials" << endl;
                              cout << "|    1. Press 2 to login             |" << endl;
                              cout << "|    2. Press 3 to change password   |" << endl;
                              break;
                         }
                    }
               }
               break;
          }
          case 3:
          {
               i = 0;

               cout << "--------Change Password--------" << endl;
               ifstream of0;
               of0.open("file.txt");

               cout << "Enter the old Password:- ";
               cin >> old;
               if (of0.is_open())
               {
                    while (!of0.eof())
                    {
                         while (getline(of0, text))
                         {
                              istringstream iss(text);
                              iss >> word1;
                              cp[i] = word1;
                              i++;
                         }
                         if (old == cp[1])
                         {
                              of0.close();

                              ofstream of1;
                              of1.open("file.txt");
                              if (of1.is_open())
                              {
                                   cout << "Enter your new password:- ";
                                   cin >> password1;
                                   cout << "Confirm password:- ";
                                   cin >> password2;
                                   if (password1 == password2)
                                   {
                                        of1 << cp[0] << "\n";
                                        of1 << password1;
                                        cout << "Password Changed Successfully" << endl;
                                   }
                                   else
                                   {
                                        of1 << cp[0] << "\n";
                                        of1 << old;
                                        cout << "Passwor do not match" << endl;
                                   }
                              }
                              of1.close();
                         }
                         else
                         {
                              cout << "Enter a Valid Password" << endl;
                              break;
                         }
                    }
               }
               break;
          }
          case 4:
          {
               cout << "________Thank You________";
               break;
          }
          default:
               cout << "Enter a valid choice";
          }
     } while (a != 4);
     return 0;
}