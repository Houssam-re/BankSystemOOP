#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsGlobale.h"
#include "clsUtil.h"
using namespace std;
class clsBankUsers : public clsPerson
{
	private:
		enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

		enMode _Mode;
		string _UserName;
		string _Password;
		int _Permissions;
		bool _MarkForDelete = false;
		string _Time = clsDate::GetSystemDateTimeString();
		string _PrepareLogInRecord()
		{
			string line = "";
			string EnCrypte = clsUtil::EncryptText(_Password, 5);
			line += _Time + "#//#";
			line += _UserName + "#//#";
			line += EnCrypte + "#//#";
			line += to_string(_Permissions);
			return line;
		}
		static clsBankUsers _ConvertLineToObject(string Line)
		{
			vector <string> vUsers = clsString::SplitString(Line, "#//#");
			return clsBankUsers(enMode::UpdateMode,
				vUsers[0],
				vUsers[1],
				vUsers[2],
				vUsers[3],
				vUsers[4],
				clsUtil::DecryptText(vUsers[5],5),
				stoi(vUsers[6]));
		}

		static string _ConvertObjectToLine(clsBankUsers Client)
		{
			string Line = "";
			string EnCrypte = clsUtil::EncryptText(Client.Password,5);
			Line += Client.FirstName + "#//#";
			Line += Client.LastName + "#//#";
			Line += Client.Email + "#//#";
			Line += Client.PhoneNumber + "#//#";		
			Line += Client.UserName + "#//#";
			Line += EnCrypte + "#//#";
			Line += to_string(Client._Permissions);
			return Line;
		}
		static clsBankUsers _GetEmptyUser()
		{
			return clsBankUsers(enMode::EmptyMode, "", "","","","","", 0);
		}
		static vector <clsBankUsers> _LoadUsersDataFromFileToVector()
		{
			fstream File;
			vector <clsBankUsers> vUsers;
			File.open("Users.txt", ios::in);
			if (File.is_open())
			{
				string Line;
				while (getline(File, Line))
				{
					vUsers.push_back(_ConvertLineToObject(Line));
				}
				return vUsers;
			}

		}		
		static void _SaveUsersDataFromVectorToFile(vector <clsBankUsers> vUsers)
		{
			fstream File;
			File.open("Users.txt", ios::out);
			if (File.is_open())
			{
				for (clsBankUsers& i : vUsers)
				{
					if (!i._MarkForDelete)
						File << _ConvertObjectToLine(i) << endl;
				}
			}

		}
		void _AddDateLineToFile(string Line)
		{
			fstream File;
			File.open("Users.txt", ios::app);
			if (File.is_open())
			{
				File << Line << endl;
				File.close();
			}
		}
		void _Update()
		{
			vector <clsBankUsers> vUserss = _LoadUsersDataFromFileToVector();

			for (clsBankUsers& i : vUserss)
			{
				if (i.UserName == UserName)
				{
					i = *this;
				}
			}
			_SaveUsersDataFromVectorToFile(vUserss);
		}

		void _AddUser()
		{
			_AddDateLineToFile(_ConvertObjectToLine(*this));
		}

	public:

		clsBankUsers(
			enMode Mode,
			string FirstName,
			string LastName,
			string Email,
			string PhoneNumber,
			string UserName,
			string Password,
			int Permission) : clsPerson(FirstName,LastName,Email,PhoneNumber)
		{
			_Mode = Mode;
			_UserName = UserName;
			_Password = Password;
			_Permissions = Permission;
		}
		static enum enPermissions {
			eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
			pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64,pListRegisterUser = 128
		};
		static enum enSave { enSaveDone = 1, enSaveFaild = 2 };

		void setMarkedForDelete(bool Mark)
		{
			_MarkForDelete = Mark;
		}
		void setPassword(string Password)
		{
			_Password = Password;
		}
		bool CheckPermission(enPermissions Permission)
		{
			if (this->Permission == enPermissions::eAll)
				return true;

			return (Permission & this->Permission);
		}
		string getPassword()
		{
			return _Password;
		}
		__declspec(property(get = getPassword, put = setPassword))string Password;

		void setUserName(string UserName)
		{
			_UserName = UserName;
		}
		string getUserName()
		{
			return _UserName;
		}
		__declspec(property(get = getUserName, put = setUserName))string UserName;

		void setPermission(int Per)
		{
			_Permissions = Per;
		}
		int getPermission()
		{
			return _Permissions;
		}
		__declspec(property(get = getPermission, put = setPermission))int Permission;
		bool  isEmptyMode()
		{
			return (_Mode == enMode::EmptyMode);
		}

		static clsBankUsers Find(string UserName)
		{
			vector <clsBankUsers> vUsers = _LoadUsersDataFromFileToVector();
			for (clsBankUsers& i : vUsers)
			{
				if (i.UserName == UserName)
				{
					return i;
				}
			}
			return _GetEmptyUser();
		}
		static clsBankUsers Find(string UserName, string Password)
		{
			clsBankUsers Client = Find(UserName);
			if (!Client.isEmptyMode() && (Password == Client.Password))
				return Client;
			return _GetEmptyUser();
		}
		void RegistreLogin()
		{
			fstream File;
			File.open("LoginFile.txt", ios::out | ios::app);
			if (File.is_open())
			{
				string Line = _PrepareLogInRecord();
				File << Line << endl;
				File.close();
			}
		}
		static bool isUserExist(string UserName)
		{
			clsBankUsers Client = Find(UserName);
			return(!Client.isEmptyMode());
		}
		static clsBankUsers GetAddNewUser(string UserName)
		{
			return clsBankUsers(clsBankUsers::AddNewMode, "", "","", "", UserName, "", 0);
		}


		enSave Save()
		{
			switch (_Mode)
			{
			case clsBankUsers::EmptyMode:
				return enSaveFaild;

			case clsBankUsers::UpdateMode:
				_Update();
				return enSaveDone;

			case clsBankUsers::AddNewMode:
				_AddUser();
				_Mode = UpdateMode;
				return enSaveDone;
			}
		}

		static vector <clsBankUsers>  GetUsersList()
		{
			return _LoadUsersDataFromFileToVector();
		}	
		static vector <clsBankUsers>  GetRegistredUsersList()
		{
			return _LoadUsersDataFromFileToVector();
		}

		bool Delete()
		{
			vector <clsBankUsers> vUsers = _LoadUsersDataFromFileToVector();
			for (auto& c : vUsers)
			{
				if (c.UserName == UserName)
				{
					c._MarkForDelete = true;
					break;
				}
			}
			_SaveUsersDataFromVectorToFile(vUsers);
			*this = _GetEmptyUser();
			return true;
		}






};

