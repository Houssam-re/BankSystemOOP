#include <iostream>
#include "clsBankUsers.h"
#include "clsUtil.h"
using namespace std;
class clsFindUserScreen : protected clsScreen
{


    static void _PrintUser(clsBankUsers User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.PhoneNumber;
        cout << "\nPermission  : " << User.Permission;
        cout << "\nPassword    : " << User.Password;
        cout << "\n___________________\n";
    }

public:
    static void FindUser()
    {

        _DrawScreenHeader("\t Find User Screen");

        string username;
        username = clsInputValidate::ReadStrings("Enter The username  : ");
        while (!clsBankUsers::isUserExist(username))
        {
            cout << "Exist Dont User   Username ,,, Try Another one ,, : ";
            username = clsInputValidate::ReadStrings("Enter The username  : ");
        }
        clsBankUsers User = clsBankUsers::Find(username);
        cout << "\n\nUser Found :) \n";
        _PrintUser(User);
    }
};

