#pragma once

#include<iostream>
#include"clsDate.h";

using namespace std;

class clsInputValidate
{
public:
	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

	template<typename T>static bool IsNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(ClsDates Date, ClsDates From, ClsDates To)
	{
		//Date>=From && Date<=To
		if ((ClsDates::IsDate1AfterDate2(Date, From) || ClsDates::IsDate1EqualDate2(Date, From))
			&&
			(ClsDates::IsDate1BeforeDate2(Date, To) || ClsDates::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((ClsDates::IsDate1AfterDate2(Date, To) || ClsDates::IsDate1EqualDate2(Date, To))
			&&
			(ClsDates::IsDate1BeforeDate2(Date, From) || ClsDates::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	template<typename T> static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	template<typename T> static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Number = ReadNumber<T>();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber<T>();
		}
		return Number;
	}

	static bool IsValideDate(ClsDates Date)
	{
		return	ClsDates::IsValidDate(Date);
	}
};