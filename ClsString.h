#pragma once

#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

class ClsString
{

private:
	string _Value;
	vector<string> _Words;

	vector<string> ConvertLineToRecord(string Str, string Spreator)
	{
		vector<string>VRecord;

		VRecord = Split(Str, Spreator);

		return VRecord;
	}


public:
	static vector<string>Split(string Str, string Delimeter)
	{
		vector<string>VNames;

		short Pos = 0;
		string SWord;

		while ((Pos = Str.find(Delimeter)) != std::string::npos)
		{
			SWord = Str.substr(0, Pos);

			VNames.push_back(SWord);

			Str.erase(0, Pos + Delimeter.length());
		}

		if (Str != "")
		{
			VNames.push_back(Str);
		}

		return VNames;
	}

	void Split()
	{
		_Words = Split(_Value, " ");
	}

	void PrintSplitingString()
	{
		for (string Word : _Words)
		{
			cout << Word << endl;
		}
	}

	static int CountWords(string Words)
	{
		int Counter = 0;
		vector<string>VRecord;

		VRecord = Split(Words, " ");

		for (string Word : VRecord)
		{
			Counter++;
		}

		return Counter;
	}

	int CountWords()
	{
		int Count = 0;
		vector<string>VWords = ConvertLineToRecord(_Value, " ");

		for (string Word : VWords)
		{
			Count++;
		}
		return Count;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	static short Length(string Str)
	{
		return Str.length();
	}

	short Length()
	{
		return _Value.length();
	}

	//Here we look again : 
	void ReadText(string Massage)
	{
		string Str;

		cout << Massage;
		getline(cin, Str);

		_Value = Str;
	}

	static string UpperFirstLetterOfEachWord(string Str)
	{
		bool isFairstLetter = true;

		for (int i = 0; i < Str.length(); i++)
		{
			if (Str[i] != ' ' && isFairstLetter)
			{
				Str[i] = toupper(Str[i]);
			}

			isFairstLetter = (Str[i] == ' ' ? true : false);
		}
		return Str;
	}
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerAllLetters(string Str)
	{
		for (short i = 0; i < Str.length(); i++)
		{
			Str[i] = tolower(Str[i]);
		}

		return Str;
	}
	void LowerAllLetters()
	{
		_Value = LowerAllLetters(_Value);
	}

	static string UpperAllStrings(string Str)
	{
		for (short j = 0; j < Str.length(); j++)
		{
			Str[j] = toupper(Str[j]);
		}
		return Str;
	}
	void UpperAllStrings()
	{
		_Value = UpperAllStrings(_Value);
	}


	static char InvertCharacterCase(char Letter)
	{
		return isupper(Letter) ? tolower(Letter) : toupper(Letter);
	}
	static string InvertAllLettersCase(string Str)
	{
		for (short i = 0; i < Str.length(); i++)
		{
			Str[i] = InvertCharacterCase(Str[i]);
		}

		return Str;
	}
	void InvertAllLetters()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetter(string Str, enWhatToCount WhatToCount = All)
	{
		short Counter = 0;

		if (WhatToCount == enWhatToCount::All)
		{
			return Str.length();
		}

		for (short i = 0; i < Str.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters)
			{
				Counter++;
			}

			if (WhatToCount == enWhatToCount::SmallLetters)
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountLetter()
	{
		return CountLetter(_Value, All);
	}

	static short CountCapitalLetters(string Str)
	{
		short Counter = 0;
		for (short i = 0; i < Str.length(); i++)
		{
			if (isupper(Str[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string Str)
	{
		short Counter = 0;

		for (short i = 0; i < Str.length(); i++)
		{
			if (iswlower(Str[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountSmallLetters()
	{
		return  CountSmallLetters(_Value);
	}

	static string TrimLeft(string Str)
	{
		for (short i = 0; i < Str.length(); i++)
		{
			if (Str[i] != ' ')
			{
				return Str.substr(i, Str.length() - i);
			}
		}
		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string Str)
	{
		for (short i = Str.length() - 1; i >= 0; i--)
		{
			if (Str[i] != ' ')
			{
				return Str.substr(0, i + 1);
			}
		}
		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string TrimAll(string Str)
	{
		return TrimLeft(TrimRight(Str));
	}
	void TrimAll()
	{
		_Value = TrimAll(_Value);
	}

	static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}

		}

		return Counter;
	}
	short CountSpecificLetter(char Letter)
	{
		return CountSpecificLetter(_Value, Letter, false);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

	}

	static short CountVowels(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (IsVowel(S1[i]))
				Counter++;

		}

		return Counter;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static string JoinString(string arrString[], short Length, string Delim)
	{
		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}
	static string JoinString(vector<string> vString, string Delim)
	{

		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string ReverseWordsInString(string S1)
	{
		vector<string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}
	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (LowerAllLetters(s) == LowerAllLetters(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}

		return JoinString(vString, " ");
	}
	string ReplaceWord(string StringToReplace, string ReplaceTo)
	{
		return ReplaceWord(_Value, StringToReplace, ReplaceTo);
	}

	static string RemovePunctuations(string S1)
	{
		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2;
	}
	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}
};