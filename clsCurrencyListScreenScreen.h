#pragma once

#include<iostream>
#include"clsScreen.h";
#include"clsCurrncy.h";
#include<vector>

using namespace std;

class clsCurrencyListScreen :protected clsScreen
{
private:

	static void _PrintCurrenyRecordLine(clsCurrency Currency)
	{
		cout << "| " << left << setw(30) << Currency.CurrencyName();
		cout << "| " << left << setw(8) << Currency.CurrencyCode();
		cout << "| " << left << setw(45) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();
		cout << endl;
	}

public:


	static void  ShowCurrencyList()
	{
		vector<clsCurrency>VCurrnices;
		
		VCurrnices = clsCurrency::GetCurrenices();

		string Title = "\tCurrencies List Screen";
		string SubTitle = "\t   (" + to_string(VCurrnices.size()) + ") " + "Currency";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n_____________________________________________________________________________________________________\n";
		cout << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";

		if (VCurrnices.size() == 0)
		{
			system("cls");
			cout << "\t\t\t\tNo Currencies avaiable In the sysyem!\n";
		}
		
		else
		{
			cout << "\n_____________________________________________________________________________________________________\n";

			for (clsCurrency& Currency : VCurrnices)
			{
				_PrintCurrenyRecordLine(Currency);
			}
			cout << "\n_____________________________________________________________________________________________________\n";

		}
	}
};

