#include <iostream>
#include "clsBankUsers.h"
#include "clsUtil.h"
#include "clsScreen.h"
class clsTransferListScreen : protected clsScreen
{

	struct stTransfer 
	{
		string sAccountNumber;
		string dAccountNumber;
		double Amount;
		double sBalance;
		double dBalance;
		string UserName;
		string Time;
	};
	static void PrintTransferRegisterRecord(stTransfer User)
	{
		cout << setw(15) << left << "" << "| " << setw(20) << left << User.Time;
		cout << "| " << setw(12) << left << User.sAccountNumber;
		cout << "| " << setw(12) << left << User.dAccountNumber;
		cout << "| " << setw(12) << left << User.Amount;
		cout << "| " << setw(12) << left << User.sBalance;
		cout << "| " << setw(12) << left << User.dBalance;
		cout << "| " << setw(12) << left << User.UserName;
	}
	static	stTransfer ConvertLineToRecord(string Line)
	{
		vector <string> vUsersLog = clsString::SplitString(Line, "#//#");
		stTransfer User;
		User.Time = vUsersLog[0];
		User.sAccountNumber = vUsersLog[1];
		User.dAccountNumber = vUsersLog[2];
		User.Amount = stod(vUsersLog[3]);
		User.sBalance = stod(vUsersLog[4]);
		User.dBalance = stod(vUsersLog[5]);
		User.UserName = vUsersLog[6];
		return User;
	
	}
	static vector <stTransfer> _LoadRegisterTransferFromFileToVector()
	{
		fstream File;
		vector <stTransfer> vUsersL;
		File.open("TransferFile.txt", ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				vUsersL.push_back(ConvertLineToRecord(Line));
			}
			return vUsersL;
		}
	}

	static void PrintRegistredTable(int Num)
	{
		string Title = "\t  Transfer Log List Screen";
		string SubTitle = "\t    (" + to_string(Num) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(15) << left << "" << "\n\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(15) << left << "" << "| " << left << setw(20) << "Date /Time";
		cout << "| " << left << setw(12) << "s.Acct";
		cout << "| " << left << setw(12) << "d.Acct";
		cout << "| " << left << setw(12) << "Amount";
		cout << "| " << left << setw(12) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(12) << "User";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;
	}
public:
	static vector <stTransfer> GetTransferRegisterList()
	{
		return _LoadRegisterTransferFromFileToVector();
	}
	static void ShowTransferRegisterScreen()
	{
		//system("cls");
		//if (!CheckAccessRights(clsBankUsers::enPermissions::pListRegisterUser))
		//{
		//	return;
		//}
		vector <stTransfer> vUser;
		vUser = GetTransferRegisterList();



		PrintRegistredTable(vUser.size());
		for (auto& i : vUser)
		{
			PrintTransferRegisterRecord(i);
			cout << endl;
		}

	}
};

