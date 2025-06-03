#pragma once
#include<iostream>
#include"clsScreen.h";
#include<iomanip>
#include"ClsInputValidate.h";
#include "clsScreen.h"
#include"clsCurrencyListScreenScreen.h";
#include"clsFindCurrenyScreen.h";
#include"clsUpdateCurrencyRateScreen.h";
#include"clsCurrencyCalculatorScreen.h";

using namespace std;

class clsCurrencyExchange :protected clsScreen
{

private:
	enum eCurrencyExchangeMenueOption
	{
		eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMeue = 5
	};

	static short  _ReadCurrencyExchangeMeue()
	{
		cout << "\t\t\t\t\tChoose what do you want to do? [1 to 5]?";

		return clsInputValidate::ReadNumberBetween(1, 5);
	}
	
	static void _GoBackToCurrencyMenue()
	{
		cout << "\nPress any Key to go back to Currency Menue...\n";
		system("pause>0");
		ShowCurrencyExchangeMainScreen();
	}

	static void _ShowListCurrencies()
	{
		clsCurrencyListScreen::ShowCurrencyList();
	}

	static void _ShowFindCurrency()
	{
		clsFindCurrenyScreen::_ShowFindCurrency();
	}
	
	static void _ShowUpdateRate()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateRate();
	}

	static void _ShowCurrencyCalculator()
	{
		clsCurrencyCalculator::ShowCurrencyCalculator();
	}

	static void PerformCurrencyExchange(short MenueOption)
	{
		switch (MenueOption)
		{
		case eCurrencyExchangeMenueOption::eListCurrency:
			system("cls");
			_ShowListCurrencies();
			_GoBackToCurrencyMenue();
			break;

		case eCurrencyExchangeMenueOption::eFindCurrency:
			system("cls");
			_ShowFindCurrency();
			_GoBackToCurrencyMenue();
			break;

		case eCurrencyExchangeMenueOption::eUpdateRate:
			system("cls");
			_ShowUpdateRate();
			_GoBackToCurrencyMenue();
			break;

		case eCurrencyExchangeMenueOption::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToCurrencyMenue();
			break;

		case eCurrencyExchangeMenueOption::eMainMeue:
			break;
		}
	}

public:
	
	
	static void ShowCurrencyExchangeMainScreen()
	{
		system("cls");
		_DrawScreenHeader("Curreny Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "\t\t\t\t\t Currency Exchange Menue" << endl;
		cout << setw(37) << left << "" << "===========================================\n";

		cout << setw(37) << left << "" << "\t[1] List Currency.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		PerformCurrencyExchange(_ReadCurrencyExchangeMeue());
	}
};

