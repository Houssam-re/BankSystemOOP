#include <iostream>
#include "clsBankClients.h"
#include "clsUtil.h"
using namespace std;



class clsUpdateClients : protected clsScreen
{
	static void ReadClientInfo(clsBankClients& Client)
	{

		Client.PinCode = clsInputValidate::ReadStrings("Enter PinCode  : ");
		Client.FirstName = clsInputValidate::ReadStrings("Enter FirstName  : ");
		Client.LastName = clsInputValidate::ReadStrings("Enter LastName  : ");
		Client.PhoneNumber = clsInputValidate::ReadStrings("Enter PhoneNumber  : ");
		Client.Email = clsInputValidate::ReadStrings("Enter Email  : ");
		Client.AccountBalance = clsInputValidate::ReadDblNumber("Enter AccountBalance  : ");

	}

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

	static void UpdateClient()
	{
		if (!CheckAccessRights(clsBankUsers::enPermissions::pUpdateClients))
		{
			return;
		}
		_DrawScreenHeader("\t Update Client Screen");

		string AccountNumber;
		AccountNumber = clsInputValidate::ReadStrings("Enter The AccountNumber  : ");
		while (!clsBankClients::isUserExist(AccountNumber))
		{
			cout << "Invalid AccountNumber,, Try Another one ,, : ";
			AccountNumber = clsInputValidate::ReadStrings("Enter The AccountNumber  : ");
		}
		clsBankClients Client = clsBankClients::Find(AccountNumber);
		_PrintClient(Client);
		cout << "\n\n\tAre You Sure You To Update This Client ?  y/n :";
		char Answer;
		cin >> Answer;
		if (towlower(Answer) == 'y')
		{
			ReadClientInfo(Client);
			clsBankClients::enSave SaveResult = Client.Save();
			switch (SaveResult)
			{
			case clsBankClients::enSaveDone:
				cout << "Updated Client Successful\n\n";

				break;
			default:
				cout << "Save is Failed is empty \n\n\n";
				break;

			}
		}
		else
			return;

	}
};

