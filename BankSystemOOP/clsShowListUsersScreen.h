#pragma once
#include "clsTransactionMenueScreen.h"
#include "clsInputValidation.h"
#include "clsBankUsers.h"
#include <iostream>

using namespace std;
class clsShowListUsersScreen : protected clsScreen 
{

   static void _PrintUserRecordLine(clsBankUsers User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.PhoneNumber;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.getPermission();

    }
public:
   static void ShowUsersList()
    {
       
        vector <clsBankUsers> vUsers = clsBankUsers::GetUsersList();
        string Title = "\t  User List Screen ";
        string SubTitle = "      \t(" + to_string(vUsers.size()) + ") Users(s).";
        _DrawScreenHeader(Title,SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsBankUsers User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }





};
