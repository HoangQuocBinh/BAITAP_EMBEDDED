/*
* File: main.cpp
* Author: HOANG QUOC BINH
* Date: 02/04/2023
* Description: This is file for animal
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <vector>
#include <stdarg.h>
#include <string.h>

using namespace std;

/**********************************Class Animal*******************************/
class Animal
{
private:
    /* data */
    char _name[50];
    uint8_t _age;
    uint16_t _weigth;
    uint16_t _height;

public:
    Animal(){}
    Animal(const char* name, uint8_t age, uint16_t weigth, uint16_t height);
    char* getName();
    uint8_t getAge();
    uint8_t getWeight();
    uint8_t getHeight();
    double getBMI();


};

Animal::Animal(const char* name, uint8_t age, uint16_t weigth, uint16_t height){
    strcpy(this->_name, name);
    this->_age = age;
    this->_weigth = weigth;
    this->_height = height;
}

/*
* Class: Animal
* Function: getName
* Description: This function use for get name of animal
* Input:
*   Don't have input parameters
* Output:
*   return: name of animal
*/
char* Animal::getName(){
    return _name;
}

/*
* Class: Animal
* Function: getAge
* Description: This function use for get age of animal
* Input:
*   Don't have input parameters
* Output:
*   return: age of animal
*/
uint8_t Animal::getAge(){
    return _age;
}

/*
* Class: Animal
* Function: getWeight
* Description: This function use for get weight of animal
* Input:
*   Don't have input parameters
* Output:
*   return: weight of animal
*/
uint8_t Animal::getWeight(){
    return _weigth;
}

/*
* Class: Animal
* Function: getHeight
* Description: This function use for get height of animal
* Input:
*   Don't have input parameters
* Output:
*   return: height of animal
*/
uint8_t Animal::getHeight(){
    return _height;
}

/*
* Class: Animal
* Function: getBMI
* Description: This function use for get BMI of animal
* Input:
*   Don't have input parameters
* Output:
*   return: BMI of animal
*/
double Animal::getBMI(){
    return (double)(_weigth / (_height * _height));
}

/**********************************Class Compare***********************************/
class Compare
{
private:
    /* data */
public:
    Compare(/* args */);
    void cmpAnimalAge(int num, ...);
    void cmpAnimalWeight(int num, ...);
};

Compare::Compare(/* args */)
{
}

/*
* Class: Compare
* Function: cmpAnimalAge
* Description: This function use for compare age of animals
* Input:
*   num - number of animals
*   ... - Animal for compare
* Output:
*   return: None
*/
void Compare::cmpAnimalAge(int num, ...){
    uint8_t max_age = 0;
    uint8_t is_have_first_animal = 0;
    Animal animal;
    va_list args;

    va_start(args, num);
    max_age = va_arg(args, Animal).getAge();
    for(int i=0; i < num - 1; i++){
        animal = va_arg(args, Animal);
        if(max_age < animal.getAge()){
            max_age = animal.getAge();
        }
    }

    va_end(args);

    va_start(args, num);
    for(int i=0; i<num; i++){
        animal = va_arg(args, Animal);
        if(max_age == animal.getAge()){
            if(is_have_first_animal == 1) printf("va ");
            printf("%s ",animal.getName());
            is_have_first_animal = 1;
        }
    }
    va_end(args);
    printf("co tuoi cao nhat\n");

}

/*
* Class: Compare
* Function: cmpAnimalAge
* Description: This function use for compare weight of animals
* Input:
*   num - number of animals
*   ... - Animal for compare
* Output:
*   return: None
*/
void Compare::cmpAnimalWeight(int num, ...){
    uint8_t max_weight = 0;
    uint8_t is_have_first_animal = 0;
    Animal animal;
    va_list args;

    va_start(args, num);
    max_weight = va_arg(args, Animal).getWeight();
    for(int i=0; i < num - 1; i++){
        animal = va_arg(args, Animal);
        if(max_weight < animal.getWeight()){
            max_weight = animal.getWeight();
        }
    }

    va_end(args);

    va_start(args, num);
    for(int i=0; i<num; i++){
        animal = va_arg(args, Animal);
        if(max_weight == animal.getWeight()){
            if(is_have_first_animal == 1) printf("va ");
            printf("%s ",animal.getName());
            is_have_first_animal = 1;
        }
    }
    va_end(args);
    printf("co trong luong cao nhat\n");
}


int main(int argc, char const *argv[])
{
    /* code */
    Animal Meo("Meo", 2, 3, 4);
    Animal Cho("Cho", 5, 3, 4);
    Animal Voi("Voi", 5, 10, 10);

    Compare cmp;
    cmp.cmpAnimalAge(3, Meo, Cho, Voi);
    cmp.cmpAnimalWeight(3, Meo, Cho, Voi);
    return 0;
}
