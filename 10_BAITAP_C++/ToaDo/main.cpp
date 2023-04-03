/*
* File: main.cpp
* Author: HOANG QUOC BINH
* Date: 31/03/2023
* Description: This is file for calculate distance and area of triangle in 2D Space
*/


#include <stdio.h>
#include <stdint.h>
#include <math.h>


/***********************************Class Point**************************************/
class Point 
{
private:
    /* data */
    double _ordinate; //tung do
    double _abscissa; //hoanh do
public:
    Point(double _ordinate = 0, double _abscissa = 0) : _ordinate(_ordinate), _abscissa(_abscissa){}
    double getOrdinate(){return this->_ordinate;}
    double getAbscissa(){return this->_abscissa;}
};

/***********************************Class Space2D************************************/
class Space2D
{
private:
    /* data */
    Point _first_point;
    Point _second_point;
    Point _third_point;

    typedef enum Math{
        DISTANCE = 0,
        AREA_OF_TRIANGLE
    }Math;
    Math math;

public:
    Space2D(Point first_point, Point second_point);
    Space2D(Point first_point, Point second_point, Point third_point);
    Point getFirstPoint();
    Point getSecondPoint();
    Point getThirdPoint();
    double calculateDistance();
    double calculateAreaTriangle();

};


Space2D::Space2D(Point first_point, Point second_point){
    Space2D::math = DISTANCE;
    this->_first_point = first_point;
    this->_second_point = second_point;
}
Space2D::Space2D(Point first_point, Point second_point, Point third_point){
    Space2D::math = AREA_OF_TRIANGLE;
    this->_first_point = first_point;
    this->_second_point = second_point;
    this->_third_point = third_point;
}

/*
* Class: Space2D
* Function: getFirstPoint
* Description: This function use for get first point
* Input:
*   Don't have input parameters
* Output:
*   return: first point 
*/
Point Space2D::getFirstPoint(){
    return this->_first_point;
}

/*
* Class: Space2D
* Function: getSecondPoint
* Description: This function use for get second point
* Input:
*   Don't have input parameters
* Output:
*   return: second point 
*/
Point Space2D::getSecondPoint(){
    return this->_second_point;
}

/*
* Class: Space2D
* Function: getThirdPoint
* Description: This function use for get third point
* Input:
*   Don't have input parameters
* Output:
*   return: third point 
*/
Point Space2D::getThirdPoint(){
    if(Space2D::math != AREA_OF_TRIANGLE){
        printf("KHONG NHAP VAO DIEM THU 3\n");
        return -1;
    }
    return this->_third_point;
}

/*
* Class: Space2D
* Function: calculateDistance
* Description: This function use for calculate distance of line
* Input:
*   Don't have input parameters
* Output:
*   return: Distance of line
*/
double Space2D::calculateDistance(){
    if(Space2D::math != DISTANCE){
        printf("DU LIEU NHAP VAO KHONG PHU HOP\n");
        return -1;
    }
    return (double)(sqrt(pow(this->_first_point.getOrdinate() - this->_second_point.getOrdinate(),2) \
    + pow(this->_first_point.getAbscissa() - this->_first_point.getAbscissa(),2)));
}

/*
* Class: Space2D
* Function: calculateAreaTriangle
* Description: This function use for calculate area of triangle
* Input:
*   Don't have input parameters
* Output:
*   return: Area of triangle
*/
double Space2D::calculateAreaTriangle(){
    if(Space2D::math != AREA_OF_TRIANGLE){
        printf("KHONG PHAI LA TAM GIAC\n");
        return -1;
    }
    double distance_a = sqrt(pow(this->_first_point.getOrdinate() - this->_second_point.getOrdinate(),2) + pow(this->_first_point.getAbscissa() - this->_second_point.getAbscissa(),2));
    double distance_b = sqrt(pow(this->_first_point.getOrdinate() - this->_third_point.getOrdinate(),2) + pow(this->_first_point.getAbscissa() - this->_third_point.getAbscissa(),2));
    double distance_c = sqrt(pow(this->_third_point.getOrdinate() - this->_second_point.getOrdinate(),2) + pow(this->_third_point.getAbscissa() - this->_second_point.getAbscissa(),2));
    double p = (distance_a + distance_b + distance_c) / 2;
    return (double)(sqrt(p*(p - distance_a)*(p - distance_b)*(p - distance_c)));
}



int main(int argc, char const *argv[])
{
    /* code */
    Point point1(2.3, 3.2);
    Point point2(2.0, 3.0);
    Point point3(2.5, 3.9);

    Space2D space1(point1, point2);
    Space2D space2(point1, point2, point3);

    //-------------Space 1--------------//
    printf("POINT 1(%.2lf,%.2lf)\n", space1.getFirstPoint().getOrdinate(), space1.getFirstPoint().getAbscissa());
    printf("POINT 2(%.2lf,%.2lf)\n", space1.getSecondPoint().getOrdinate(), space1.getSecondPoint().getAbscissa());
    printf("DISTANCE: %.2lf\n\n", space1.calculateDistance());

    //-------------Space 2--------------//
    printf("POINT 1(%.2lf,%.2lf)\n", space2.getFirstPoint().getOrdinate(), space2.getFirstPoint().getAbscissa());
    printf("POINT 2(%.2lf,%.2lf)\n", space2.getSecondPoint().getOrdinate(), space2.getSecondPoint().getAbscissa());
    printf("AREA OF TRIANGLE: %.2lf\n\n", space2.calculateAreaTriangle());

    return 0;
}
