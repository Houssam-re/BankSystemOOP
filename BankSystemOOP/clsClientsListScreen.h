#include <iostream>
#include "clsBankClients.h"
#include "clsUtil.h"
using namespace std;

class clsClientsListScreen : protected clsScreen
{

	static void _PrintClientRecordLine(clsBankClients Client)
	{

		cout << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(10) << left << Client.FirstName;
		cout << "| " << setw(10) << left << Client.LastName;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(12) << left << Client.PhoneNumber;
		cout << "| " << setw(20) << left << Client.AccountBalance;

	}


public :

	static void ShowAllClientsScreen()
	{

		if (!CheckAccessRights(clsBankUsers::enPermissions::pListClients))
		{
			return;
		}
		
		vector <clsBankClients> vClients = clsBankClients::GetClientsList();
		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(10) << "FistName";
		cout << "| " << left << setw(10) << "LastName";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(12) << "PhoneNumber";
		cout << "| " << left << setw(20) << "AccountBalance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClients Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________________________\n" << endl;

	}

};

