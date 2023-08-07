#pragma once
#include "clsDate.h"

class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = DateTo;

    }

    static bool isOverLap(clsPeriod Period1, clsPeriod Period2)
    {
        return (clsDate::isDate1AfterDate2(Period1.StartDate, Period2.EndDate) || clsDate::isDate1BeforeDate2(Period1.EndDate, Period2.StartDate)) ? false : true;
    }


    bool IsOverLapWith(clsPeriod Period2)
    {
        return isOverLap(*this, Period2);
    }
   static short PeriodLength(clsPeriod Period1, bool includeEndDay = false)
    {
        return clsDate::countDayDeffBetweenTwoDate(Period1.StartDate, Period1.EndDate, includeEndDay);
    }
   short PeriodLength(bool includeEndDay = false)
   {
       return PeriodLength(*this, includeEndDay);
   }

  static bool isDateWithinPeriod(clsPeriod Period, clsDate Date3)
   {
       return (clsDate::isDate1AfterDate2(Date3, Period.StartDate) && clsDate::isDate1BeforeDate2(Date3, Period.EndDate) || clsDate::isDate1EqualDate2(Date3, Period.EndDate));
   }
  bool isDateWithinPeriod (clsDate Date3)
  {
      return isDateWithinPeriod(*this,Date3);
  }
    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();


    }

};

