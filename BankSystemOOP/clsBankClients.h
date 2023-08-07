#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsInputValidation.h"
using namespace std;

class clsBankClients : public clsPerson
{

private :
	enum enMode { EmptyMode = 0, UpdateMode = 1 ,AddNewMode = 2 };
	
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool MarkForDelete = false;
	static clsBankClients _ConvertLineToObject(string Line)
	{
		vector <string> vClient = clsString::SplitString(Line, "#//#");
		return clsBankClients(enMode::UpdateMode,
			vClient[0],
			vClient[1],
			vClient[3],
			vClient[4],
			vClient[5],
		   vClient[6],
			stod(vClient[7]));

	}
	string _PrepareTransferRecord(clsBankClients Distination,double Amount,string UserName)
	{
		string Line = "";
		Line += clsDate::GetSystemDateTimeString() + "#//#";
		Line += _AccountNumber + "#//#";
		Line += Distination.AccountNumber+ "#//#";
		Line += to_string(Amount) + "#//#";
		Line += to_string(_AccountBalance) + "#//#";
		Line += to_string(Distination.AccountBalance) + "#//#";
		Line += UserName;
		return Line;
	}
	static string _ConvertObjectToLine(clsBankClients Client)
	{
			string Line = "";
			Line += Client.FirstName + "#//#";
			Line += Client.LastName + "#//#";
			Line += Client.FullName() + "#//#";
			Line += Client.Email + "#//#";
			Line += Client.PhoneNumber + "#//#";
			Line += Client.AccountNumber + "#//#";
			Line += Client.PinCode + "#//#";
			Line += to_string(Client.AccountBalance);
		return Line;
	}
	static clsBankClients _GetEmptyClients()
	{
		return clsBankClients(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static vector <clsBankClients> _LoadClientDataFromFileToVector()
	{
		fstream File;
		vector <clsBankClients> vClient;
		File.open("Clients.txt", ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				vClient.push_back(_ConvertLineToObject(Line));
			}
			return vClient;
		}
		
    }	

	static void _SaveClientDataFromVectorToFile(vector <clsBankClients> vClient)
	{
		fstream File;
		File.open("Clients.txt", ios::out);
		if (File.is_open())
		{
			for (clsBankClients& i : vClient)
			{
				if(!i.MarkForDelete)
				File << _ConvertObjectToLine(i) << endl;
			}
		}
		
    }
	void _AddDateLineToFile(string Line)
	{
		fstream File;
		File.open("Clients.txt", ios::app);
		if (File.is_open())
		{
			File << Line <<endl;
			File.close();
		}
	}
	void _Update()
	{
		vector <clsBankClients> vClients = _LoadClientDataFromFileToVector();

		for (clsBankClients& i : vClients)
		{
			if (i.AccountNumber == AccountNumber)
			{
				i = *this;
			}
		}
		_SaveClientDataFromVectorToFile(vClients);
	}

	void _AddClient()
	{
		_AddDateLineToFile(_ConvertObjectToLine(*this));
	}

		
public :
	
	clsBankClients(
		enMode Mode,
		string FirstName,
		string LastName,
		string Email,
		string PhoneNumber,
		string AccountNumber,
		string PinCode,
		double AccountBalance) : clsPerson(FirstName, LastName, Email, PhoneNumber)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	static enum enSave { enSaveDone = 1, enSaveFaild = 2 };
	string getAccountNumber()
	{
		return _AccountNumber;
	}	
	__declspec(property(get = getAccountNumber, put = setAccountNumber))string AccountNumber;
	

	void setPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string getPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = getPinCode, put = setPinCode))string PinCode;

	void setAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	double getAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountBalance))double AccountBalance;

	string FullName()
	{
		return FirstName + " " + LastName;
	}
	 bool  isEmptyMode()
	{
		return (_Mode == enMode::EmptyMode);
	}
	static clsBankClients Find(string AccountNumber)
	{
		vector <clsBankClients> vClient =  _LoadClientDataFromFileToVector();
		for (clsBankClients& i : vClient)
		{
			if (i.AccountNumber == AccountNumber)
			{
				return i;
			}
		}
		return _GetEmptyClients();
	}
	static clsBankClients Find(string AccountNumber, string PinCode)
	{
		clsBankClients Client = Find(AccountNumber);
		if (!Client.isEmptyMode() && (PinCode == Client.PinCode))
				return Client;
		return _GetEmptyClients();
	}

	static bool isUserExist(string AccountNumber)
	{
		clsBankClients Client = Find(AccountNumber);
		return(!Client.isEmptyMode());
	}
	 static clsBankClients GetAddNewClient(string AccountNumber)
	 {
		 return clsBankClients(clsBankClients::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	 }	


	enSave Save()
	{
		switch (_Mode)
		{
		case clsBankClients::EmptyMode:
			return enSaveFaild;

		case clsBankClients::UpdateMode:
			_Update();
			return enSaveDone;

		case clsBankClients::AddNewMode:
			_AddClient();
			_Mode = UpdateMode;
			return enSaveDone;
		}
	}
	 void Deposit(double Amount)
	 {
		_AccountBalance += Amount;
		Save();
	 }
	 void WithDraw(double Amount)
	 {
		 _AccountBalance -= Amount;
		 Save();
	 }
	 void RegistreTransfer(clsBankClients Distination, double Amount,string UserName)
	 {
		 fstream File;
		 File.open("TransferFile.txt", ios::out | ios::app);
		 if (File.is_open())
		 {
			 string Line = _PrepareTransferRecord(Distination, Amount, UserName);
			 File << Line << endl;
			 File.close();
		 }
	 }
	 bool Transfer(double Amount, clsBankClients& DistinationClient,string UserName)
	 {
		 if (Amount > _AccountBalance)
			 return false;
		 DistinationClient.Deposit(Amount);
		 WithDraw(Amount);
		 RegistreTransfer(DistinationClient, Amount,UserName);
		 return true;
	 }
	static vector <clsBankClients>  GetClientsList()
	{
		return _LoadClientDataFromFileToVector();
		 
	}
	bool Delete()
	{
		vector <clsBankClients> vClient = _LoadClientDataFromFileToVector();
		for (auto& c : vClient)
		{
			if (c.AccountNumber == AccountNumber)
			{
				c.MarkForDelete = true;
				break;
			}
		}
		_SaveClientDataFromVectorToFile(vClient);
		*this = _GetEmptyClients();
		return true;
	}
	static double GetTotaleBalances()
	{
		vector <clsBankClients> vClients = GetClientsList();
		double TotaleBalances = 0;
		for (clsBankClients &C : vClients)
		{
			TotaleBalances += C.AccountBalance;
			cout << endl;
		}
		return TotaleBalances;
	}


};

