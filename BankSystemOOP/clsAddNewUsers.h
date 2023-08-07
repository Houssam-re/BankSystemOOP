#include <iostream>
#include "clsBankUsers.h"
#include "clsUtil.h"
class clsAddNewUsers : protected clsScreen
{
     static void _ReadUserInfo(clsBankUsers& User)
    {

        User.Password = clsInputValidate::ReadStrings("Enter Password  : ");
        User.FirstName = clsInputValidate::ReadStrings("Enter FirstName  : ");
        User.LastName = clsInputValidate::ReadStrings("Enter LastName  : ");
        User.PhoneNumber = clsInputValidate::ReadStrings("Enter PhoneNumber  : ");
        User.Email = clsInputValidate::ReadStrings("Enter Email  : ");
        User.Permission = _ReadPermissionsToSet();
    }
   static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsBankUsers::pListClients;
        }
        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUsers::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUsers::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUsers::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUsers::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUsers::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUsers::pManageUsers;
        }   
        cout << "\nShow Register Login Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUsers::pListRegisterUser;
        }
       
        return Permissions;

    }
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
    static void AddNewUser()
    {

        _DrawScreenHeader("\t Add New User Screen");

        string username;
        cout << "Enter The username  : ";
        cin >> username;
        while (clsBankUsers::isUserExist(username))
        {
            cout << "Exist User   Username ,,, Try Another one ,, : ";
            username = clsInputValidate::ReadStrings("Enter The username  : ");
        }
        clsBankUsers User = clsBankUsers::GetAddNewUser(username);

        _ReadUserInfo(User);

        clsBankUsers::enSave SaveResult = User.Save();
        switch (SaveResult)
        {
        case clsBankUsers::enSaveDone:
            cout << "Account Added Successfully\n\n";
            break;
        case clsBankUsers::enSaveFaild:
            cout << "there is problem\n";
            break;
        }
    }
};

