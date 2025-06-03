#pragma once
#include<iostream>
#include"clsScreen.h";
#include"ClsInputValidate.h";
#include"clsCurrncy.h";

class clsFindCurrenyScreen : protected clsScreen
{
private:

	static string ReadFindCurrencyScreen()
	{
		string Str;

		cout << "\nFind By : [1] code or [2] Country ? ";
		cin >> Str;

		return Str;
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found:-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was Not Found:-(\n";
		}
	}

public:
	static void _ShowFindCurrency()
	{
		_DrawScreenHeader("Find Currency Screen");

		string Answer;

		cout << "\nFind By : [1] code or [2] Country ? ";
		cin >> Answer;

		if (Answer == "1")
		{
			string CurrencyCode;
			cout << "\nPlease Enter Currency Code : ";
			cin >> CurrencyCode;

			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		
			_ShowResult(Currency);
		}

		else if (Answer == "2")
		{
			string CurrencyName;
			cout << "\nPlease Enter Courrency Name : ";
			CurrencyName = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(CurrencyName);

			_ShowResult(Currency);
		}
	}

};

