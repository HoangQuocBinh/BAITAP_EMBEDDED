/*
* File: main.cpp
* Author: HOANG QUOC BINH
* Date: 02/04/2023
* Description: This is file for person
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <vector>
#include <stdarg.h>
#include <string.h>

class Person
{
private:
    /* data */
    char _name[50];
    uint8_t _age;
    char _addr[50];
public:
    Person(const char* name, uint8_t age, const char* addr);
    char* getName();
    char* getAddr();
    uint8_t getAge();
    void display();
};

Person::Person(const char* name, uint8_t age, const char* addr)
{
    strcpy(this->_name, name);
    strcpy(this->_addr, addr);
    this->_age = age;
}

/*
* Class: Person
* Function: getName
* Description: This function use for get name of person
* Input:
*   Don't have input parameters
* Output:
*   return: name of person
*/
char* Person::getName(){
    return _name;
}

/*
* Class: Person
* Function: getAddr
* Description: This function use for get address of person
* Input:
*   Don't have input parameters
* Output:
*   return: address of person
*/
char* Person::getAddr(){
    return _addr;
}

/*
* Class: Person
* Function: getAge
* Description: This function use for get age of person
* Input:
*   Don't have input parameters
* Output:
*   return: age of person
*/
uint8_t Person::getAge(){
    return _age;
}

/*
* Class: Person
* Function: display
* Description: This function use for display information of person
* Input:
*   Don't have input parameters
* Output:
*   return: none
*/
void Person::display(){
    printf("Ten: %s\n", _name);
    printf("Tuoi: %d\n", _age);
    printf("Dia chi: %s\n", _addr);
}

int main(int argc, char const *argv[])
{
    /* code */
    Person ps("Binh", 23, "Dong Nai");
    ps.display();
    return 0;
}
