#pragma once
#include"ClsDates.h";

class ClsPeriod
{

public:

	ClsDates StartDate;
	ClsDates EndDate;

	ClsPeriod(ClsDates StartDate, ClsDates DateTo)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDate;
	}

	static bool IsOverlapPeriods(ClsPeriod Period1, ClsPeriod Period2)
	{

		if (
			ClsDates::CompareDates(Period2.EndDate, Period1.StartDate) == ClsDates::ReturndDate::Before
			||
			ClsDates::CompareDates(Period2.StartDate, Period1.EndDate) == ClsDates::ReturndDate::After
			)
			return false;
		else
			return true;

	}

	bool IsOverLapWith(ClsPeriod Period2)
	{
		return IsOverlapPeriods(*this, Period2);
	}

	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();


		cout << "Period End: ";
		EndDate.Print();
	}

};

