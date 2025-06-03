#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"ClsInputValidate.h";
#include"clsBankClient.h";
#include<fstream>

class clsWireTransfer : protected clsScreen
{
private:

	static double ReadTransferAmount(clsBankClient Client)
	{
		double Amount;

		cout << "Enter Transfer Amount? ";
		cin >> Amount;

		while (Amount > Client.GetAccountBalance())
		{
			cout << "Amount Exceeds the available Balance , Enter Another Amount : ";
			cin >> Amount;
		}
		return Amount;
	}

	

	static string _ReadAccountNumber()
	{
		 string AccountNumber;

		 cout << "\nPlease Enter Acount Number to Transfer From : ";
		 cin >> AccountNumber;

		 return AccountNumber;
	}

	
public:

	static void ShowTransferScreen()
	{
		string AccountNumber;
		char YesOrNo;

		_DrawScreenHeader("\tTransfer Screen");

		//Account Number 1 :
		clsBankClient Client1 = clsBankClient::Find(_ReadAccountNumber());

		while (Client1.IsEmpty())
		{
			cout << "Account Number is false ,  Enter another one : ";
			cin >> AccountNumber;
			
			Client1 = clsBankClient::Find(AccountNumber);
		}


		Client1.ClientCard(Client1);


		// Account Numeber 2 :

		clsBankClient Client2 = clsBankClient::Find(_ReadAccountNumber());

		while (Client2.IsEmpty())
		{
			cout << "Account Number is false ,  Enter another one : ";
			cin >> AccountNumber;

			Client2 = clsBankClient::Find(AccountNumber);
		}

		Client2.ClientCard(Client2);

		double Amount = ReadTransferAmount(Client1);
		string StrLine = "";
	

		cout << "Are you sure you want to perform this operation? ";
		cin >> YesOrNo;

		if (YesOrNo == 'y' || YesOrNo == 'Y')
		{
			if (Client1.Transfer(Amount, Client2))
			{

				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer was Faild \n";
			}

		}

		Client1.ClientCard(Client1);

		Client2.ClientCard(Client2);

	}

};