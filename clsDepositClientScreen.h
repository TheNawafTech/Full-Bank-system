#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsBankClient.h";
#include"ClsInputValidate.h";

class clsDepositScreen :protected clsScreen
{
private:

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\tDeposit Screen");


		string ClientAccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(ClientAccountNumber))
		{
			cout << "\nClient with [" << ClientAccountNumber << "] does not exist.\n";
			ClientAccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(ClientAccountNumber);
		_Print(Client);

		cout << "\nPlease enter deposit amount? ";
		double DepositAmount = clsInputValidate::ReadNumber<double>();

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client.Deposit(DepositAmount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << Client.AccountBalance;

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}

};