#include <iostream>
#include "clsBankClients.h"
#include "clsUtil.h"
#include "clsBankUsers.h"
using namespace std;

class clsDeleteClients :protected clsScreen
{
	static void _PrintClient(clsBankClients Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.PhoneNumber;
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:

	static void DeleteClient() 
	{
		if (!CheckAccessRights(clsBankUsers::enPermissions::pDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("\t Delete Client Screen");

		string AccountNumber;
		cout << "Enter The AccountNumber  : ";
		cin >> AccountNumber;
		while (!clsBankClients::isUserExist(AccountNumber))
		{
			cout << "Invalid AccountNumber,, Try Another one ,,, : ";
			cin >> AccountNumber;
		}
		clsBankClients Client = clsBankClients::Find(AccountNumber);
		_PrintClient(Client);
		cout << "Are You Sure Delete it ? ";
		char Answer;
		cin >> Answer;
		if (towlower(Answer) == 'y')
		{
			cout << "\n\nDelete Client Info :\n";
			cout << "=============================\n";
			if (Client.Delete())
			{
				cout << "Deleted Sucessed . . .\n\n";
				_PrintClient(Client);
			}
			else  cout << "Deleted Failed,,,\n\n";
		}
		else
		{
			return;
		}

	}

};

