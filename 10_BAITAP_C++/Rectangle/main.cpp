/*
* File: main.cpp
* Author: HOANG QUOC BINH
* Date: 01/04/2023
* Description: This is file for rectangle
*/


#include <stdio.h>
#include <stdint.h>
#include <math.h>

class Rectangle
{
private:
    /* data */
    double _length;
    double _width;
    typedef enum Format{
        NOT_CORRECT = 0,
        CORRECT
    }Format;
    Format format;
public:
    Rectangle(double length, double width);
    double getLength();
    double getWidth();
    double calculatePerimeter();
    double calculateArea();
    double calculateDiagonalLine();
    void checkSquare();
};

Rectangle::Rectangle(double length, double width){
    if (length <= 0 || width <= 0){
        printf("KHONG DUNG DINH DANG DO DAI\n");
        format = NOT_CORRECT;
        return;
    }
    this->_length = length;
    this->_width = width;
}

/*
* Class: Rectangle
* Function: getLength
* Description: This function use for get length of rectangle
* Input:
*   Don't have input parameters
* Output:
*   return: length of rectangle
*/
double Rectangle::getLength(){
    if (format == NOT_CORRECT){
        printf("KHONG DUNG DINH DANG DO DAI\n");
        return -1;
    }
    return _length;
}

/*
* Class: Rectangle
* Function: getWidth
* Description: This function use for get width of rectangle
* Input:
*   Don't have input parameters
* Output:
*   return: width of rectangle
*/
double Rectangle::getWidth(){
    if (format == NOT_CORRECT){
        printf("KHONG DUNG DINH DANG DO DAI\n");
        return -1;
    }
    return _width;
}

/*
* Class: Rectangle
* Function: calculatePerimeter
* Description: This function use for get perimeter of rectangle
* Input:
*   Don't have input parameters
* Output:
*   return: perimeter of rectangle
*/
double Rectangle::calculatePerimeter(){
    if (format == NOT_CORRECT){
        printf("KHONG DUNG DINH DANG DO DAI\n");
        return -1;
    }
    return (double)((_length + _width) * 2);
}

/*
* Class: Rectangle
* Function: calculateArea
* Description: This function use for get area of rectangle
* Input:
*   Don't have input parameters
* Output:
*   return: area of rectangle
*/
double Rectangle::calculateArea(){
    if (format == NOT_CORRECT){
        printf("KHONG DUNG DINH DANG DO DAI\n");
        return -1;
    }
    return (double)(_length * _width);
}

/*
* Class: Rectangle
* Function: calculateDiagonalLine
* Description: This function use for get diagonal line distance of rectangle
* Input:
*   Don't have input parameters
* Output:
*   return: diagonal line distance of rectangle
*/
double Rectangle::calculateDiagonalLine(){
    if (format == NOT_CORRECT){
        printf("KHONG DUNG DINH DANG DO DAI\n");
        return -1;
    }
    return (double)(sqrt(pow(_length, 2) + pow(_width, 2)));
}

/*
* Class: Rectangle
* Function: checkSquare
* Description: This function use for check if it is a square or not
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/
void Rectangle::checkSquare(){
    if (format == NOT_CORRECT){
        printf("KHONG DUNG DINH DANG DO DAI\n");
        return;
    }
    if(_length == _width){
        printf("DAY LA HINH VUONG\n");
    }
    else{
        printf("DAY KHONG PHAI LA HINH VUONG\n");
    }
}
 int main(int argc, char const *argv[])
 {
    /* code */
    Rectangle rec(3, 3);
    printf("CHIEU DAI: %.2lf\n", rec.getLength());
    printf("CHIEU RONG: %.2lf\n", rec.getWidth());
    printf("CHU VI: %.2lf\n", rec.calculatePerimeter());
    printf("DIEN TICH: %.2lf\n", rec.calculateArea());
    printf("DUONG CHEO: %.2lf\n", rec.calculateDiagonalLine());
    rec.checkSquare();
    return 0;
 }
 



