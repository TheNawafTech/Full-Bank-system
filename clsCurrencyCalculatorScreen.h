#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsCurrncy.h";
#include<string>
#include"ClsInputValidate.h";

using namespace std;

class clsCurrencyCalculator : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency, string Title)
	{
		cout << Title << endl;

		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static float _ReadAmount()
	{
		float Amount;
		cout << "\nEnter Amount to Exchange : ";
		Amount = clsInputValidate::ReadNumber<float>();

		return Amount;
	}

	static void PrintCalculationResult(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		_PrintCurrency(CurrencyFrom, "\nConvert From :");

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = ";
		cout << AmountInUSD << " USD " << endl;

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}


		_PrintCurrency(CurrencyTo, "\nConverting from USD to :");

		float AmountExchangeCurrencyTo = CurrencyFrom.ConvertCurrncyToOther(CurrencyTo, Amount);;

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = ";
		cout << AmountExchangeCurrencyTo << " " << CurrencyTo.CurrencyCode() << endl;
	}

public:

	static void ShowCurrencyCalculator()
	{
		float Amount;
		char YesOrNo;

		do 
		{
			system("cls");

			_DrawScreenHeader("Currency Calculator Screen");


			clsCurrency Currency1 = clsCurrency::GetCurrency("\nPlease Enter Currency Code1 : \n");

			clsCurrency Currency2 = clsCurrency::GetCurrency("\nPlease Enter Currency Code2 : \n");

			Amount = _ReadAmount();

			PrintCalculationResult(Currency1, Currency2, Amount);

			cout << "\nDo you want to Perform another calculation? y/n? ";
			cin >> YesOrNo;

		} while (toupper(YesOrNo) == 'Y');
		
	}


};

