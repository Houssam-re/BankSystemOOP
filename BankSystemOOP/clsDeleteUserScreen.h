#include <iostream>
#include "clsBankUsers.h"
#include "clsUtil.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen
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

	static void DeleteUser()
	{
		_DrawScreenHeader("\t Delete User Screen");

		string UserName;
		cout << "Enter The UserName  : ";
		cin >> UserName;
		while (!clsBankUsers::isUserExist(UserName))
		{
			cout << "Invalid UserName,, Try Another one ,,, : ";
			cin >> UserName;
		}
		clsBankUsers User = clsBankUsers::Find(UserName);
		_PrintUser(User);
		cout << "Are You Sure Delete it ? ";
		char Answer;
		cin >> Answer;
		if (towlower(Answer) == 'y')
		{
			cout << "\n\nDelete User Info :\n";
			cout << "=============================\n";
			if (User.Delete())
			{
				cout << "Deleted Sucessed . . .\n\n";
				_PrintUser(User);
			}
			else  cout << "Deleted Failed,,,\n\n";
		}
		else
		{
			return;
		}

	}
};

