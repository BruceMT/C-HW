//
// Created by MWB20 on 10/01/2019.
// 
#include <iostream>

#include <time.h>

using namespace std;

class JulianDate {
private:
    static int EPOCH;
    int mon, day, year, hour, min, second;
    // this representation would make difference VERY UGLY
    // diff between Jan. 1 2001 12:03:04  and Feb 26 2028 11:19:02
    double jday; // number of days since epoch
public:

    JulianDate(int year,int mth,int dy,int hrs,int mins,int secs ):
  year(year),mon(mth),day(dy),hour(hrs),min(mins),second(secs){
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        jday= 365 * (year - 2000) + year/4+(year-2000)/400-(year-2000)/100;
        if(isLeapYear(year)) months[1]=29;
        for(int i=0;i<mon-1;i++){
            jday+=months[i];}
        jday+=day;

    }

    JulianDate(){
        time_t rawtime=time(NULL);
        tm *ct = localtime(&rawtime);
        second=ct->tm_sec;
        min=ct->tm_min;
        hour=ct->tm_hour;
        day=ct->tm_mday;
        mon=ct->tm_mon+1;
        year=ct->tm_year+1900;
        jday= 365 * (year - 2000) + year/4+(year-2000)/400-(year-2000)/100;
    }

    JulianDate(int year){
      this->year=year;mon=1;day=1;hour=0;min=0;second=0;
      jday= 365 * (year - 2000) + year/4+(year-2000)/400-(year-2000)/100;
    }

    bool isLeapYear(int year){
      if(year%100==0){
          if(year%400==0)return true;
          else return false;
      }
      else if (year%4==0)
      {
          return true;
      }
      else{
          return false;
      }
    }

    int leftDaysOfYear(){return isLeapYear(year)?366:365-day;};

    int getYear(){return year;}
    int getMonth(){return mon;}
    int getDay(){return day;}
    int getHour(){return hour;}
    int getMin(){return min;}
    int getSec(){return second;}

    friend  ostream& operator <<(ostream& s, const JulianDate& d){
          string pday[] ={"","January","February","March","April","May","June","July","August","September","October","November","December" };

        s<<"("<<d.year<<","<<pday[d.mon]<<","<<d.day<<" "<<d.hour<<":"<<d.min<<":"<<d.second<<")"<<endl;
        return s;
    }

    JulianDate operator=(int year){return JulianDate(year);}

    double operator-(const JulianDate &d){
        return jday-d.jday+(hour-d.hour)/24.0+(min-d.min)/24.0/60.0+(second-d.second)/24.0/60.0/60.0;
    }

    JulianDate operator+(int days){
        int year1=year,month=mon,day1=day;
        int leftdays=leftDaysOfYear();

        if(days>leftdays){
            days-=leftdays;
            year1++;
            int num=isLeapYear(year1)?366:365;
            while(days>num){
                days-=num;
                year1++;
                num=isLeapYear(year1)?366:365;
            }
        }

        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(isLeapYear(year1)) months[1]=29;
        days+=day;
        if(days-(months[mon-1])>0){
            days-=months[mon-1];
            int i=mon;
            for(;i<12;i++){
                if(days-months[i]<=0) break;
                days-=months[i];
            }
            month=i+1;
        }

        return JulianDate(year,month,days,hour,min,second);
    }
};

/*
	how many days in a year? 365
	leap year: if year MOD 4 == 0 LEAP EXCEPT
	           if year MOD 100 == 0 NOT LEAP YEAR Except
						 if year MOD 400 == 0 LEAP
Leap years:
 NO 1900
 YES 1904
 YES 1908
 YES 2000
 NO 2100
 YES 2400
    days since EPOCH = 365 * (year - 2000) + years/4 - ....
2018 - 2000 = 18
seconds in a day = 24*60*60 = 86400
hh:mm:ss
00:00:00  0.0
12:00:00  0.5
http://aa.usno.navy.mil/faq/docs/JD_Formula.php
http://www.math.harvard.edu/~knill/3dprinter/exhibits/bc/Meeus1988.pdf
 */



int JulianDate::EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0

int main() {
    JulianDate newyear(2018, 1, 1, 0,0,0);
    JulianDate valentine(2018, 2, 14, 12,0,0); // 0.5
    JulianDate today; // get it from the system time: time(nullptr)
    // localtime

    double days = valentine - newyear;
   // cout<<days<<endl;
    JulianDate due = today + 7;
    cout << due << '\n';

    cout << "\nyear: " << newyear.getYear()
         << "\nmonth: " << newyear.getMonth()
         << "\nday: " << newyear.getDay()
         << "\nhour: " << newyear.getHour()
         << "\nmin: " << newyear.getMin()
         << "\nsec: " << newyear.getSec() << '\n';
    JulianDate d1(2019, 1, 1, 0,0,0);
    for (int i = 0; i < 100; i++)
        cout << d1 + i;

}

