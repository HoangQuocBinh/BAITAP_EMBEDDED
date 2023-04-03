/*
* File: main.cpp
* Author: HOANG QUOC BINH
* Date: 01/04/2023
* Description: This is file for circle
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

class Circle
{
private:
    /* data */
    double _radius;
    typedef enum Format{
        NOT_CORRECT = 0,
        CORRECT
    }Format;
    Format format;
public:
    Circle(double radius);
    double getRadius();
    double calculatePerimeter();
    double calculateArea();
};

Circle::Circle(double radius){
    if(radius <= 0){
        printf("KHONG DUNG DINH DANG DATA\n");
        format = NOT_CORRECT;
        return;
    }
    this->_radius = radius;
}

/*
* Class: Circle
* Function: getRadius
* Description: This function use for get radius of circle
* Input:
*   Don't have input parameters
* Output:
*   return: radius of circle
*/
double Circle::getRadius(){
    if(format == NOT_CORRECT){
        printf("KHONG DUNG DINH DANG DATA\n");
        return -1;
    }
    return _radius;
}

/*
* Class: Circle
* Function: calculatePerimeter
* Description: This function use for get perimeter of circle
* Input:
*   Don't have input parameters
* Output:
*   return: perimeter of circle
*/
double Circle::calculatePerimeter(){
    if(format == NOT_CORRECT){
        printf("KHONG DUNG DINH DANG DATA\n");
        return -1;
    }
    return (double)(2 * 3.14 * _radius);
}

/*
* Class: Circle
* Function: calculateArea
* Description: This function use for get area of circle
* Input:
*   Don't have input parameters
* Output:
*   return: area of circle
*/
double Circle::calculateArea(){
    if(format == NOT_CORRECT){
        printf("KHONG DUNG DINH DANG DATA\n");
        return -1;
    }
    return (3.14* _radius * _radius);
}


int main(int argc, char const *argv[])
{
    /* code */
    Circle circle(2);
    printf("BAN KINH = %.2lf\n", circle.getRadius());
    printf("CHU VI = %.2lf\n", circle.calculatePerimeter());
    printf("DIEN TICH = %.2lf\n", circle.calculateArea());

    return 0;
}

