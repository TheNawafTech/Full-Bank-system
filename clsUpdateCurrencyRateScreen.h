#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsCurrncy.h";
#include"ClsInputValidate.h";
#include<string>

class clsUpdateCurrencyRateScreen :protected clsScreen
{
private:

	static float _ReadRate()
	{
		float NewRate;

		cout << "\nEnter New Rate : ";
		NewRate = clsInputValidate::ReadNumber<float>();

		return NewRate;
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

	static bool _ShowResult(clsCurrency Currency)
	{
		if (Currency.IsEmpty())
		{
			return 0;
		}

		else
		{
			cout << "Are you sure you want to update the rate of this currency y/n ? ";
			char Answer;

			cin >> Answer;
			
			if (toupper(Answer) == 'Y')
			{
				cout << "\n\nUpdate Currency Rate : \n";
				cout << "_______________________\n";

				Currency.UpdateRate(_ReadRate());

				cout << "\n\nCurrency Rate Updated Successfully :-)\n";

				_PrintCurrency(Currency);
				
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

public:

	static void ShowUpdateRate()
	{
		_DrawScreenHeader("Update Curreny Screen");

		cout << "Please Enter Currency Code : ";
		string CurrncyCodeAnswer;
		
		CurrncyCodeAnswer = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(CurrncyCodeAnswer);

		while (!clsCurrency::IsCurrencyExsist(CurrncyCodeAnswer))
		{
			cout << "\n Currency is not Found , choose another one:";
			CurrncyCodeAnswer = clsInputValidate::ReadString();
		}

		_PrintCurrency(Currency);

		_ShowResult(Currency);
	}

};

