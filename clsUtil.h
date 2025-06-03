#pragma once
#include<iostream>

using namespace std;

class clsUtil
{
public:

	enum enCharType { CapitalLetter = 1, SmallLetter = 2, Digit = 3, SpecialCharacter = 4, MixChars = 5 };

	static  void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(ClsDates& A, ClsDates& B)
	{
		ClsDates::SwapDates(A, B);

	}

	static void  Srand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}

	static int ReadPositiveNumber(string Massage)
	{
		int Number = 0;

		do {
			cout << Massage;
			cin >> Number;
		} while (Number < 0);

		return Number;
	}

	static string EncriptionText(string Text, short EncritionKey = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncritionKey);
		}

		return Text;
	}

	static string DecritionText(string Text, short EncriptionKey = 2)
	{

		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncriptionKey);
		}

		return Text;
	}

	static int RandomNumber(int From, int To)
	{
		//This equation will makes the range between the (To) and (From) ...

		return rand() % (To - From + 1) + From;
	}
	
	static void PrintSpecialCharacter()
	{
		cout << "Special Character : " << char(RandomNumber(33, 47)) << endl;
	}

	static void PrintSmallLetter()
	{
		cout << "Small Letter : " << char(RandomNumber(97, 122)) << endl;
	}

	static void PrintDigit()
	{
		cout << "Digit : " << RandomNumber(1, 10000) << endl;
	}

	static void PrintCapitalLetter()
	{
		cout << "Capital Letter : " << char(RandomNumber(65, 90)) << endl;
	}

	static char GetCharType(enCharType Char)
	{
		switch (Char)
		{
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
		}
		case enCharType::SmallLetter:
		{
			return char(RandomNumber(97, 122));
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
		}

		}
	}

	static string GenerateWord(enCharType Char, int Length)
	{
		string Word;

		for (int i = 1; i <= Length; i++)
		{
			Word += GetCharType(Char);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType = CapitalLetter)
	{
		string Word;

		Word += GenerateWord(CharType, 4) + "-";
		Word += GenerateWord(CharType, 4) + "-";
		Word += GenerateWord(CharType, 4) + "-";
		Word += GenerateWord(CharType, 4);

		return Word;
	}

	static void GenerateKeys(int NumberOfKeys, enCharType CharType)
	{
		cout << "\n";
		string Word;

		int Counter = 0;

		for (int i = 1; i <= NumberOfKeys; i++)
		{
			Counter++;
			cout << "Key [" << Counter << "] : ";
			cout << GenerateKey() << endl;

		}
	}

	static void FillArrayWithRandomNumbers(int arr[100], int Length, int From, int To)
	{
		cout << "\nEnter number of random numbers : ";
		cin >> Length;

		for (int i = 0; i < Length; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
		cout << "\n";
	}

	static void FillArrayWithRandomWords(string arr[100], int Length, enCharType CharType, int WordLength)
	{
		cout << "\nEnter number of random numbers : ";
		cin >> Length;

		for (int i = 0; i < Length; i++)
		{
			arr[i] = GenerateWord(CharType, WordLength);
		}
		cout << "\n";
	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}

	static int SumArray(int arr[100], int arrLength)
	{
		int Sum = 0;

		for (int i = 0; i < arrLength; i++)
		{
			Sum += arr[i];
		}
		return Sum;
	}

	static  void ShuffleArray(int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static  void ShuffleArray(string arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

};

