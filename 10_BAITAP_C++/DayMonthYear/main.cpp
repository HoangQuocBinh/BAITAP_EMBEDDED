/*
* File: main.cpp
* Author: HOANG QUOC BINH
* Date: 03/04/2023
* Description: This is file for day, month,year
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <vector>
#include <stdarg.h>
#include <string.h>
#include <ctime>

using namespace std;

#define CONDITION(condition, content)\
    if(condition) {\
        format = NOT_CORRECT;\
        printf(content);\
        return;\
    }

/***************************************Class DayMonthYear***************************************/
class DayMonthYear
{
private:
    /* data */
    uint8_t _day;
    uint8_t _month;
    uint16_t _year;

    int _checkleapyear(uint16_t year);
    typedef enum Format{
        NOT_CORRECT = 0,
        CORRECT
    }Format;
    Format format;

public:
    DayMonthYear(uint8_t day, uint8_t month, uint16_t year);

    uint8_t getDay();
    uint8_t getMonth();
    uint16_t getYear();
    void checkHoliday();
};

/*
* Class: DayMonthYear
* Function: _checkleapyear
* Description: This function use for checking a leap year
* Input:
*   year - year for checking
* Output:
*   return: none
*/
int DayMonthYear::_checkleapyear(uint16_t year){ //KIEM TRA NAM NHUAN
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } 
            else {
                return 0;
            }
        } 
        else {
            return 1;
        }
    } 
    else {
        return 0; 
    }
}

DayMonthYear::DayMonthYear(uint8_t day, uint8_t month, uint16_t year)
{

    switch (month)
    {
    case 2:
        /* code */
        if(_checkleapyear(year) == 1){
            CONDITION(day > 29 || day < 0, "NGAY KHONG DUNG\n");
            this->_day = day; 
        }
        else{
            CONDITION(day > 28 || day < 0, "NGAY KHONG DUNG\n");
            this->_day = day;
        }
        break;
    case 4:
        /* code */
        CONDITION(day > 30 || day < 0, "NGAY KHONG DUNG\n");
        this->_day = day;
        break;
    case 6:
        /* code */
        CONDITION(day > 30 || day < 0, "NGAY KHONG DUNG\n");
        this->_day = day;
        break;
    case 9:
        /* code */
        CONDITION(day > 30 || day < 0, "NGAY KHONG DUNG\n");
        this->_day = day;
        break;
    case 11:
        /* code */
        CONDITION(day > 30 || day < 0, "NGAY KHONG DUNG\n");
        this->_day = day;
        break;
    default:
        CONDITION(month > 12 || month < 0, "THANG KHONG DUNG\n");
        CONDITION(day > 31 || day < 0, "NGAY KHONG DUNG\n");
        this->_day = day;
        break;
    }
    this->_month = month;
    this->_year = year;
}

/*
* Class: DayMonthYear
* Function: getDay
* Description: This function use for getting day
* Input:
*   Dont have input parameters
* Output:
*   return: day
*/
uint8_t DayMonthYear::getDay(){
    if(format == NOT_CORRECT){
        printf("DINH DANG KHONG DUNG\n");
        return -1;
    }
    return _day;
}

/*
* Class: DayMonthYear
* Function: getMonth
* Description: This function use for getting month
* Input:
*   Dont have input parameters
* Output:
*   return: month
*/
uint8_t DayMonthYear::getMonth(){
    if(format == NOT_CORRECT){
        printf("DINH DANG KHONG DUNG\n");
        return -1;
    }
    return _month;
}

/*
* Class: DayMonthYear
* Function: getYear
* Description: This function use for getting year
* Input:
*   Dont have input parameters
* Output:
*   return: year
*/
uint16_t DayMonthYear::getYear(){
    if(format == NOT_CORRECT){
        printf("DINH DANG KHONG DUNG\n");
        return -1;
    }
    return _year;
}

/*
* Class: DayMonthYear
* Function: checkHoliday
* Description: This function use for checking holiday
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void DayMonthYear::checkHoliday(){
    if(_day == 1 && _month == 1){
        printf("TET DUONG LICH\n");
    }
    else if(_day == 1 && _month == 5){
        printf("QUOC TE LAO DONG\n");
    }
    else if(_day == 1 && _month == 6){
        printf("QUOC TE THIEU NHI\n");
    }
    else if(_day == 8 && _month == 3){
        printf("QUOC TE PHU NU\n");
    }
    else if(_day == 19 && _month == 11){
        printf("QUOC TE NAM GIOI\n");
    }
    else{
        printf("KHONG PHAI NGAY LE QUOC TE\n");
    }
}

/******************************************Class Person***********************************/
class Person : public DayMonthYear
{
private:
    /* data */
    
public:
    Person(uint8_t day, uint8_t month, uint16_t year) : DayMonthYear(day, month, year) {}
    void calculateAge();
};

/*
* Class: Person
* Function: calculateAge
* Description: This function use for calculating age
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Person::calculateAge(){
    //LAY THOI GIAN THUC
    time_t now = time(0);
    tm *ltm = localtime(&now);
    uint16_t year = 1900 + ltm->tm_year;
    uint8_t month = 1 + ltm->tm_mon;
    uint8_t day = ltm->tm_mday;

    //TINH TOAN TUOI
    if(DayMonthYear::getDay() <= day && DayMonthYear::getMonth() <= month){
        printf("TUOI LA: %d\n", (year - DayMonthYear::getYear()));
    }
    else{
        printf("TUOI LA: %d\n", (year - DayMonthYear::getYear() - 1));
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    Person binh(1,5,1999);
    binh.calculateAge();
    binh.checkHoliday();
    return 0;
}
