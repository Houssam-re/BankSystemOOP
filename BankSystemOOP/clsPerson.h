#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _PhoneNumber;

public:
    clsPerson(string FirstName,
        string LastName,
        string Email,
        string PhoneNumber)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _PhoneNumber = PhoneNumber;
    }

    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string getFirstName()
    {
        return _FirstName;
    }

    __declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    string getLastName()
    {
        return _LastName;
    }
    string FullName()
    {
        return FirstName + " " + LastName;
    }
    __declspec(property(get = getLastName, put = setLastName)) string LastName;  

    void setEmail(string Email)
    {
        _Email = Email;
    }

    string getEmail()
    {
        return _Email;
    }

    __declspec(property(get = getEmail, put = setEmail)) string Email; 

    void setPhoneNumber(string PhoneNumber)
    {
        _PhoneNumber = PhoneNumber;
    }

    string getPhoneNumber()
    {
        return _PhoneNumber;
    }

    __declspec(property(get = getPhoneNumber, put = setPhoneNumber)) string PhoneNumber;

};
