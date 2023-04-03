/*
* File: main.cpp
* Author: HOANG QUOC BINH
* Date: 02/04/2023
* Description: This is file for fraction
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <vector>
#include <stdarg.h>
#include <string.h>

using namespace std;

/*******************************Class Fraction****************************/
class Fraction
{
private:
    /* data */
    int16_t _numerator; //Tu so
    int16_t _denominator; //Mau so
public:
    Fraction(){}
    Fraction(int16_t numerator, int16_t denominator);
    int16_t getNumerator();
    int16_t getDenominator();
};

Fraction::Fraction(int16_t numerator, int16_t denominator)
{   
    if(denominator == 0){
        printf("KHOI TAO SAI MAU SO\n");
        return;
    }
    this->_denominator = denominator;
    this->_numerator = numerator;
}

/*
* Class: Fraction
* Function: getNumerator
* Description: This function use for get numerator of fraction
* Input:
*   Dont have input parameters
* Output:
*   return: numerator of fraction
*/
int16_t Fraction::getNumerator(){
    return _numerator;
}

/*
* Class: Fraction
* Function: getDenominator
* Description: This function use for get denominator of fraction
* Input:
*   Dont have input parameters
* Output:
*   return: denominator of fraction
*/
int16_t Fraction::getDenominator(){
    return _denominator;
}

/*******************************Class Calulation****************************/
class Calculation
{
private:
    /* data */
    uint16_t _gcd(int16_t numerator, int16_t denominator);
public:
    Calculation(/* args */);
    void add(int num, ...);
    void sub(int num, ...);
    void mul(int num, ...);
    void division(Fraction fr1, Fraction fr2);
};

Calculation::Calculation(/* args */)
{
}

/*
* Class: Calculation
* Function: _gcd
* Description: This function use for get gcd of numbers
* Input:
*   numerator - number 1
*   denominator - number 2
* Output:
*   return: gcd of numbers
*/
uint16_t Calculation::_gcd(int16_t numerator, int16_t denominator){
    int tmp;
    while(denominator != 0) {
        tmp = numerator % denominator;
        numerator = denominator;
        denominator = tmp;
    }
    return numerator;
}

/*
* Class: Calculation
* Function: add
* Description: This function use for add fractions
* Input:
*   num - number of fraction
*   ... - fractions
* Output:
*   return: None
*/
void Calculation::add(int num, ...){
    va_list args;
    int16_t total_numerator = 0;
    int16_t total_denominator = 1;
    va_start(args, num);
    for(int i=0; i<num; i++){
        total_denominator *= va_arg(args, Fraction).getDenominator();
    }
    va_end(args);

    va_start(args, num);
    for(int i=0; i<num; i++){
        Fraction fraction = va_arg(args, Fraction);
        total_numerator += fraction.getNumerator() * (total_denominator / fraction.getDenominator());
    }
    va_end(args);
    printf("Dap an phep cong phan so: ");
    if(total_numerator == 0) {
        printf("0\n");
        return;
    }
    uint16_t gcd = _gcd(total_numerator, total_denominator);
    if(total_numerator % gcd == 0 && total_denominator % gcd == 0){
        if((total_numerator / gcd) == (total_denominator / gcd) || (total_denominator / gcd) == 1)
            printf("%d\n", total_numerator / gcd);
        else 
            printf("%d/%d\n", total_numerator / gcd, total_denominator / gcd);
    }
    else{
        printf("%d/%d\n", total_numerator, total_denominator);
    }

}

/*
* Class: Calculation
* Function: sub
* Description: This function use for sub fractions
* Input:
*   num - number of fraction
*   ... - fractions
* Output:
*   return: None
*/
void Calculation::sub(int num, ...){
    va_list args;
    int16_t total_numerator = 0;
    int16_t total_denominator = 1;
    Fraction fraction;
    va_start(args, num);
    for(int i=0; i<num; i++){
        total_denominator *= va_arg(args, Fraction).getDenominator();
    }
    va_end(args);
    

    va_start(args, num);
    fraction = va_arg(args, Fraction);
    total_numerator = fraction.getNumerator() * (total_denominator / fraction.getDenominator());
    for(int i=0; i<num-1; i++){
        fraction = va_arg(args, Fraction);
        total_numerator -= fraction.getNumerator() * (total_denominator / fraction.getDenominator());
    }
    va_end(args);
    printf("Dap an phep tru phan so: ");
    // printf("total_numerator = %d\n", total_numerator);
    if(total_numerator == 0) {
        printf("0\n");
        return;
    }
    uint16_t gcd = _gcd(total_numerator, total_denominator);
    if(total_numerator % gcd == 0 && total_denominator % gcd == 0){
        if((total_numerator / gcd) == (total_denominator / gcd) ||(total_denominator / gcd) == 1)
            printf("%d\n", total_numerator / gcd);
        else 
            printf("%d/%d\n", total_numerator / gcd, total_denominator / gcd);
    }
    else{
        printf("%d/%d\n", total_numerator, total_denominator);
    }
}

/*
* Class: Calculation
* Function: mul
* Description: This function use for mul fractions
* Input:
*   num - number of fraction
*   ... - fractions
* Output:
*   return: None
*/
void Calculation::mul(int num, ...){
    va_list args;
    int16_t total_numerator = 1;
    int16_t total_denominator = 1;

    va_start(args, num);
    for(int i=0; i<num; i++){
        Fraction fraction = va_arg(args, Fraction);
        total_numerator *= fraction.getNumerator();
        total_denominator *= fraction.getDenominator();
    }
    va_end(args);
    printf("Dap an phep nhan phan so: ");
    uint16_t gcd = _gcd(total_numerator, total_denominator);
    if(total_numerator % gcd == 0 && total_denominator % gcd == 0){
        if((total_numerator / gcd) == (total_denominator / gcd) || (total_denominator / gcd) == 1)
            printf("%d\n", total_numerator / gcd);
        else 
            printf("%d/%d\n", total_numerator / gcd, total_denominator / gcd);
    }
    else{
        printf("%d/%d\n", total_numerator, total_denominator);
    }
}

/*
* Class: Calculation
* Function: division
* Description: This function use for division fractions
* Input:
*   num - number of fraction
*   ... - fractions
* Output:
*   return: None
*/
void Calculation::division(Fraction fr1, Fraction fr2){
    int16_t total_numerator = fr1.getNumerator() * fr2.getDenominator();
    int16_t total_denominator = fr2.getNumerator() * fr1.getDenominator();

    printf("Dap an phep chia 2 phan so: ");
    uint16_t gcd = _gcd(total_numerator, total_denominator);
    if(total_numerator % gcd == 0 && total_denominator % gcd == 0){
        if((total_numerator / gcd) == (total_denominator / gcd) || (total_denominator / gcd) == 1)
            printf("%d\n", total_numerator / gcd);
        else 
            printf("%d/%d\n", total_numerator / gcd, total_denominator / gcd);
    }
    else{
        printf("%d/%d\n", total_numerator, total_denominator);
    }
}   


int main(int argc, char const *argv[])
{
    /* code */
    Fraction fr1(3, 2);
    Fraction fr2(1, 2);
    Calculation calculate;
    calculate.add(2, fr1, fr2);
    calculate.sub(2, fr1, fr2);
    calculate.mul(2, fr1, fr2);
    calculate.division(fr1, fr2);
    return 0;
}
