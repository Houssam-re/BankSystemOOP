#include <iostream>
#include "clsBankUsers.h"
#include "clsUtil.h"
#include "clsScreen.h"
using namespace std;
class clsLoginRegistreScreen : protected clsScreen
{

	string _UserName;
	string _Password;
	int _Permissions;
	string _Time;
	static void PrintUsersRegisterRecord(clsLoginRegistreScreen User)
	{
		cout << setw(20) << left << "" << "| " << setw(20) << left << User._Time;
		cout << "| " << setw(25) << left << User._UserName;
		cout << "| " << setw(12) << left << User._Password;
		cout << "| " << setw(12) << left << User._Permissions;
	}
static	clsLoginRegistreScreen ConvertLineToRecord(string Line)
	{
		vector <string> vUsersLog = clsString::SplitString(Line, "#//#");
		return clsLoginRegistreScreen(
			vUsersLog[0], vUsersLog[1], vUsersLog[2], stoi(vUsersLog[3]));
	}
	clsLoginRegistreScreen(
		string Time,
		string UserName,
		string Password,
		int Permissions
	) {
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
		_Time = Time;
	}
		static vector <clsLoginRegistreScreen> _LoadRegisterLoginFromFileToVector()
	{
			fstream File;
			vector <clsLoginRegistreScreen> vUsersL;
			File.open("LoginFile.txt", ios::in);
			if (File.is_open())
			{
				string Line;
				while (getline(File,Line))
				{
					vUsersL.push_back(ConvertLineToRecord(Line));
				}
				return vUsersL;
			}
	}

	static void PrintRegistredTable(int Num)
	{
		string Title = "\t  Login Register Screen";
		string SubTitle = "\t    (" + to_string(Num) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(20 ) << left << "" << "| " << left << setw(20) << "Date /Time";
		cout << "| " << left << setw(25) << "UserName";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;
	}
public:
	static vector <clsLoginRegistreScreen> GetUserRegisterLoginList()
	{
		return _LoadRegisterLoginFromFileToVector();
	}
	static void ShowRegisterScreen()
	{
		system("cls");
		if (!CheckAccessRights(clsBankUsers::enPermissions::pListRegisterUser))
		{
			return;
		}
		vector <clsLoginRegistreScreen> vUser;
		vUser = clsLoginRegistreScreen::GetUserRegisterLoginList();



		PrintRegistredTable(vUser.size());
		for (auto& i : vUser)
		{
			PrintUsersRegisterRecord(i);
			cout << endl;
		}

	}
};

