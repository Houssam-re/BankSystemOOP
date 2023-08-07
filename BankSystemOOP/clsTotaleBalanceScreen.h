#pragma once
#include "clsTransactionMenueScreen.h"
#include "clsInputValidation.h"
#include "clsBankClients.h"
#include <iostream>

using namespace std;
class clsTotaleBalanceScreen : protected clsScreen
{

	static void PrintClientRecordBalanceLine(clsBankClients Client)
	{
		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}
	static void PrintTransactionTable(int Num)
	{
		string Title = "\t  Balances List Screen";
		string SubTitle = "\t    (" + to_string(Num) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;
	}
public:
	static void ShowBalancesScreen()
	{
		system("cls");
		vector <clsBankClients> vClient;
		vClient = clsBankClients::GetClientsList();



		PrintTransactionTable(vClient.size());
		for (auto& i : vClient)
		{
			PrintClientRecordBalanceLine(i);
			cout << endl;
		}
		double TotaleBalances = clsBankClients::GetTotaleBalances();
		cout << "\nTotal Balances = " << TotaleBalances;
		cout <<"\n"<<clsUtil::NumberToText(TotaleBalances);
	}
};

