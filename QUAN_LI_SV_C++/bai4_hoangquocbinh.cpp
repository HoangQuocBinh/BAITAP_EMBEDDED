//TEST

/*
* File: bai4_hoangquocbinh.cpp
* Author: HOANG QUOC BINH
* Date: 24/03/2023
* Description: This is file for student management
*/

#include <stdio.h>
// #include <cstdlib>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <cctype>

using namespace std;

#define ENTER_INFORMATION(thongtin, dinhdang, noidung, dieukien)\
    do\
    {\
        printf(thongtin);\
        scanf(dinhdang, noidung);\
        if(checkExit(noidung) == 1)\
            return;\
    }while(dieukien);

#define SHOW_INFORMATION(index, list_student)\
    printf("\nID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HOCLUC\n");                                                                                                                                                               \
    for(int index = 0; index < list_student.size(); index++){                                                                                                                                                                                   \
        printf("%d\t %s\t\t %s\t\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %s\n", list_student[index].getID(), list_student[index].getName(), list_student[index].getSex(),                                                                          \
        list_student[index].getAge(), list_student[index].getMarkMath(), list_student[index].getMarkPhysical(), list_student[index].getMarkChemical(), list_student[index].getAverageMark(), list_student[index].getStudentAbility());   \
    }                                                                                                                                                                                                                                               \
    printf("\n");

/********************************************Class Student*****************************************/
class Student
{
private:
    /* data */
    uint8_t _id;
    char _student_name[20];
    char _student_sex[4];
    uint8_t _student_age;
    double _math_mark;
    double _physical_mark;
    double _chemical_mark;
    double _average_mark;
    char _student_ability[20];

public:
    void setID(uint8_t _id);
    void setName(const char *_student_name);
    void setSex(const char *_student_sex);
    void setAge(uint8_t Student_Age);
    void setMarkMath(double _math_mark);
    void setMarkPhysical(double _physical_mark);
    void setMarkChemical(double _chemical_mark);
    
    uint8_t getID();
    char *getName();
    char *getSex();
    uint8_t getAge();
    double getMarkMath();
    double getMarkPhysical();
    double getMarkChemical();
    double getAverageMark();
    char *getStudentAbility();

};

/*
* Class: Student
* Function: setID
* Description: This function use for set ID of a Student
* Input:
*   _id - ID of Student
* Output:
*   return: None
*/
void Student::setID(uint8_t _id){
    this->_id = _id;
}

/*
* Class: Student
* Function: setName
* Description: This function use for set name of a Student
* Input:
*   _student_name - name of Student
* Output:
*   return: None
*/
void Student::setName(const char *_student_name){
    strcpy(this->_student_name, _student_name);
}

/*
* Class: Student
* Function: setSex
* Description: This function use for set sex of a Student
* Input:
*   _student_sex - sex of Student
* Output:
*   return: None
*/
void Student::setSex(const char *_student_sex){
    strcpy(this->_student_sex, _student_sex);
}

/*
* Class: Student
* Function: setAge
* Description: This function use for set age of a Student
* Input:
*   _student_age - age of Student
* Output:
*   return: None
*/
void Student::setAge(uint8_t _student_age){
    this->_student_age = _student_age;
}

/*
* Class: Student
* Function: setMarkMath
* Description: This function use for set mark of Math
* Input:
*   _math_mark - mark of Math
* Output:
*   return: None
*/
void Student::setMarkMath(double _math_mark){
    this->_math_mark = _math_mark;

}

/*
* Class: Student
* Function: setMarkPhysical
* Description: This function use for set mark of Physical
* Input:
*   _physical_mark - mark of Physical
* Output:
*   return: None
*/
void Student::setMarkPhysical(double _physical_mark){
  
    this->_physical_mark = _physical_mark;
}

/*
* Class: Student
* Function: setMarkChemical
* Description: This function use for set mark of Chemical
* Input:
*   _chemical_mark - mark of Chemical
* Output:
*   return: None
*/
void Student::setMarkChemical(double _chemical_mark){
        this->_chemical_mark = _chemical_mark;
}

/*
* Class: Student
* Function: getID
* Description: This function use for get id of student
* Input:
*   Dont have input parameters
* Output:
*   return: ID of Student
*/
uint8_t Student::getID(){
    return _id;
}

/*
* Class: Student
* Function: getName
* Description: This function use for get name of student
* Input:
*   Dont have input parameters
* Output:
*   return: Name of Student
*/
char *Student::getName(){
    return _student_name;
}

/*
* Class: Student
* Function: getSex
* Description: This function use for get sex of student
* Input:
*   Dont have input parameters
* Output:
*   return: Sex of Student
*/
char *Student::getSex(){
    return _student_sex;
}

/*
* Class: Student
* Function: getAge
* Description: This function use for get age of student
* Input:
*   Dont have input parameters
* Output:
*   return: Age of Student
*/
uint8_t Student::getAge(){
    return _student_age;
}

/*
* Class: Student
* Function: getMarkMath
* Description: This function use for get mark of Math
* Input:
*   Dont have input parameters
* Output:
*   return: Mark of Math
*/
double Student::getMarkMath(){
    return _math_mark;
}

/*
* Class: Student
* Function: getMarkPhysical
* Description: This function use for get mark of Physical
* Input:
*   Dont have input parameters
* Output:
*   return: Mark of Physical
*/
double Student::getMarkPhysical(){
    return _physical_mark;
}

/*
* Class: Student
* Function: getMarkChemical
* Description: This function use for get mark of Chemical
* Input:
*   Dont have input parameters
* Output:
*   return: Mark of Chemical
*/
double Student::getMarkChemical(){
    return _chemical_mark;
}

/*
* Class: Student
* Function: getAverageMark
* Description: This function use for get average mark
* Input:
*   Dont have input parameters
* Output:
*   return: Average mark
*/
double Student::getAverageMark(){
    if(_math_mark < 0 || _math_mark > 10){
        printf("ERROR! CHUA NHAP DIEM TOAN");
        return -1;
    }

    if(_physical_mark < 0 || _physical_mark > 10){
        printf("ERROR! CHUA NHAP DIEM LY");
        return -1;
    }

    if(_chemical_mark < 0 || _chemical_mark > 10){
        printf("ERROR! CHUA NHAP DIEM HOA");
        return -1;
    } 

    _average_mark = (_chemical_mark + _physical_mark + _math_mark) / 3;
    return (_average_mark);
}

/*
* Class: Student
* Function: getStudentAbility
* Description: This function use for get ability of Student
* Input:
*   Dont have input parameters
* Output:
*   return: Ability of Student
*/
char *Student::getStudentAbility(){
    if(Student::getAverageMark() >= 8){
        strcpy(_student_ability, (const char *)"GIOI");
    }
    else if(Student::getAverageMark() >= 6.5){
        strcpy(_student_ability, (const char *)"KHA");
    }
    else if(Student::getAverageMark() >= 5){
        strcpy(_student_ability, (const char *)"TRUNG BINH");
    }
    else{
        strcpy(_student_ability, (const char *)"YEU");
    }
    return _student_ability;
}


/*********************************Class Menu********************************/
class Menu
{
private:
    /* data */
    vector<Student> _list_student;
    static uint8_t _num_student; //KIEM TRA SO SINH VIEN DE THEM _id
    int _checksex(const char* sex);//KIEM TRA NHAP GIOI TINH
    int _checkmark(const char *str);// KIEM TRA KHI NHAP DIEM
public:
    int checkExit(const char* str); //KIEM TRA KHI MUON EXIT
    int checkNumber(const char *str);//KIEM TRA SO
    void showListCommand();
    void addStudent();
    void updateStudentByID();
    void removeStudent();
    void searchStudentByName();
    void sortListStudentByGPA();
    void sortListStudentByName();
    void showListStudent();
};
uint8_t Menu::_num_student = 0; //KHOI TAO STATIC CLASS

/*
* Class: Menu
* Function: _checksex
* Description: This function use for checking sex of student
* Input:
*   sex - input sex of student
* Output:
*   return: status valid or not
*/
int Menu::_checksex(const char* sex){
    if((strcmp((const char*)"Nam", sex) != 0) && (strcmp((const char*)"Nu", sex) != 0)){
        printf("ERROR! NHAP GIOI TINH KHONG CHINH XAC");
        return 0;
    }
    else{
        return 1;
    }
}

/*
* Class: Menu
* Function: _checkmark
* Description: This function use for checking mark of student
* Input:
*   str - input mark of student
* Output:
*   return: status valid or not
*/
int Menu::_checkmark(const char *str){
    double mark = 0;
    sscanf(str, "%lf", &mark);
    if(mark < 0 || mark > 10){
        printf("ERROR! NHAP DIEM KHONG CHINH XAC");
        return 0;
    }
    else{
        return 1;
    }
}

/*
* Class: Menu
* Function: checkExit
* Description: This function use for checking exit command
* Input:
*   str - input string command to check
* Output:
*   return: status is exit?
*/
int Menu::checkExit(const char* str){
    if(strcmp(((const char*)"EXIT"), str) == 0)
        return 1;
    return 0;
}

/*
* Class: Menu
* Function: checkExit
* Description: This function use for checking number
* Input:
*   str - input string number to check
* Output:
*   return: status is number or not?
*/
int Menu::checkNumber(const char *str){
    for(int i=0; i< strlen(str); i++){
        // if(str[i] == '\0') break;
        if(isdigit(str[i]) == 0)
            return 0;
    }
    return 1;
}

/*
* Class: Menu
* Function: showListCommand
* Description: This function use for showing list command
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::showListCommand(){
    printf("DANH SACH LENH: \n");
    printf("1. THEM SINH VIEN\n");
    printf("2. CAP NHAT THONG TIN SINH VIEN THEO ID\n");
    printf("3. XOA SINH VIEN THEO ID\n");
    printf("4. TIM KIEM SINH VIEN THEO TEN\n");
    printf("5. SAP XEP SINH VIEN THEO GPA\n");
    printf("6. SAP XEP SINH VIEN THEO TEN\n");
    printf("7. HIEN THI DANH SACH SINH VIEN\n");
    printf("NHAP \"EXIT\" DE THOAT");
}

/*
* Class: Menu
* Function: addStudent
* Description: This function use for adding student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::addStudent(){
    Student sv;
    char scanf_str[50];
    while (1)
    {
    
    printf("\nTHEM SINH VIEN \t NHAP \"EXIT\" DE THOAT\n");
    ENTER_INFORMATION("NHAP TEN: ", "%s", scanf_str, 0);
    sv.setName(scanf_str); //SET TEN SINH VIEN

    ENTER_INFORMATION("NHAP GIOI TINH (Nam/Nu): ", "%s", scanf_str, _checksex(scanf_str) == 0);
    sv.setSex(scanf_str); //SET GIOI TINH

    ENTER_INFORMATION("NHAP TUOI: ","%s", scanf_str, checkNumber(scanf_str) == 0 || atoi(scanf_str) < 0);
    uint8_t age;
    sscanf(scanf_str, "%d", &age);
    sv.setAge(age); //SET TUOI

    ENTER_INFORMATION("NHAP DIEM TOAN: ","%s", scanf_str, _checkmark(scanf_str) == 0);
    double math_mark = 0;
    sscanf(scanf_str, "%lf", &math_mark); //CHUYEN CHUOI DA NHAP THANH DIEM TOAN
    sv.setMarkMath(math_mark); //SET DIEM TOAN

    ENTER_INFORMATION("NHAP DIEM LY: ","%s", scanf_str, _checkmark(scanf_str) == 0);
    double physical_mark = 0;
    sscanf(scanf_str, "%lf", &physical_mark);
    sv.setMarkPhysical(physical_mark);

    ENTER_INFORMATION("NHAP DIEM HOA: ","%s", scanf_str, _checkmark(scanf_str) == 0);
    double chemical_mark = 0;
    sscanf(scanf_str, "%lf", &chemical_mark);
    sv.setMarkChemical(chemical_mark);

    Menu::_num_student++;
    sv.setID(Menu::_num_student); //SET ID
    Menu::_list_student.push_back(sv); //THEM SINH VIEN VAO DANH SACH
    printf("THEM SINH VIEN THANH CONG\n\n");

    }
}

/*
* Class: Menu
* Function: updateStudentByID
* Description: This function use for adding student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::updateStudentByID(){
    static Student sv;
    uint8_t index = 0; //LUU VI TRI TRUNG VOI _id DUOC NHAP
    uint8_t id = 0; //LUU GIA TRI _id DUOC NHAP
    uint8_t is_rightID = 0; //GIA TRI ID DUOC NHAP CO DUNG KHONG?
    uint8_t scanf_command = 0; //LUU GIA TRI LENH NHAP
    char scanf_str[50];
    int age = 0;
    double math_mark = 0;
    double chemical_mark = 0;
    double physical_mark = 0;
    if(_list_student.empty()){ //KIEM TRA DANH SACH CO SINH VIEN CHUA?
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }
    while(1){
        if(is_rightID == 0){

            ENTER_INFORMATION("NHAP ID: ", "%s", scanf_str, 0);
            sscanf(scanf_str, "%d", &id);// CHUYEN THANH ID

            for(int i=0; i < _list_student.size(); i++){ //DUYET DANH SACH TU DAU TOI CUOI
                if(_list_student[i].getID() == id){ //NEU ID TRUNG VOI ID DUOC NHAP
                    sv = _list_student[i]; //LUU GIA TRI SINH VIEN DO VAO 1 BIEN KHAC DE THAY DOI
                    index = i; //LUU GIA TRI VI TRI 
                    is_rightID = 1; //SET LEN 1 DE BIET LA DUNG ID
                }
            }
            if(is_rightID == 0) { //NEU ID KHONG DUNG
                printf("ID KHONG DUNG\n\n");
                // return;
            }
        }

        else if(is_rightID == 1){ //DA CO ID DE THAY DOI
            /* code */ 
            printf("\nDANH SACH LENH CAP NHAT SINH VIEN: \n");
            printf("1. CAP NHAT TEN SINH VIEN\n");
            printf("2. CAP NHAT GIOI TINH\n");
            printf("3. CAP NHAT TUOI\n");
            printf("4. CAP NHAT DIEM TOAN\n");
            printf("5. CAP NHAT DIEM LY\n");
            printf("6. CAP NHAT DIEM HOA\n");
            printf("7. HOAN THANH CAP NHAT\n");
            printf("NHAP EXIT DE THOAT\n");

            ENTER_INFORMATION("NHAP LENH: ", "%s", scanf_str, 0);
            if(checkNumber(scanf_str) == 1){ //NEU LENH NHAP LA CHU SO
                sscanf(scanf_str, "%d", &scanf_command);
                switch (scanf_command)
                {
                case 1: //THAY DOI TEN

                    ENTER_INFORMATION("NHAP TEN MOI: ", "%s", scanf_str, 0);
                    sv.setName(scanf_str);
                    // is_update_done = 1;
                    break;

                case 2: //THAY DOI GIOI TINH

                    ENTER_INFORMATION("NHAP GIOI TINH MOI: ", "%s", scanf_str, _checksex(scanf_str) == 0);
                    sv.setSex(scanf_str);
                    break;

                case 3: //THAY DOI TUOI

                    ENTER_INFORMATION("NHAP TUOI MOI: ","%s", scanf_str, checkNumber(scanf_str) == 0 || atoi(scanf_str) < 0);
                    sscanf(scanf_str, "%d", &age);
                    sv.setAge(age);
                    break;

                case 4: //THAY DOI DIEM TOAN

                    ENTER_INFORMATION("NHAP DIEM TOAN MOI: ","%s", scanf_str, _checkmark(scanf_str) == 0);
                    sscanf(scanf_str, "%lf", &math_mark);
                    sv.setMarkMath(math_mark);
                    break;
                
                case 5: //THAY DOI DIEM LY

                    ENTER_INFORMATION("NHAP DIEM LY MOI: ","%s", scanf_str, _checkmark(scanf_str) == 0);
                    sscanf(scanf_str, "%lf", &physical_mark);
                    sv.setMarkPhysical(physical_mark);
                    break;

                case 6: //THAY DOI DIEM HOA

                    ENTER_INFORMATION("NHAP DIEM HOA MOI: ","%s", scanf_str, _checkmark(scanf_str) == 0);
                    sscanf(scanf_str, "%lf", &chemical_mark);
                    sv.setMarkChemical(chemical_mark);
                    break;
                
                case 7: //HOAN THANH CAP NHAT DE LUU VAO DANH SACH
                    printf("HOAN THANH CAP NHAP SINH VIEN CO ID: %d\n\n", sv.getID());
                    is_rightID = 0;
                    _list_student[index] = sv;
                    break;
                    
                default:
                    printf("KHONG CO LENH NAY\n\n");
                    break;
                }
            }
        }
    }

}

/*
* Class: Menu
* Function: removeStudent
* Description: This function use for adding student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::removeStudent(){
    uint8_t is_have_erased = 0; //BIEN KIEM TRA DA XOA CHUA?
    uint8_t id = 0; //_id CAN XOA
    char scanf_str[50];
    if(_list_student.empty()){ //KIEM TRA DANH SACH DA CO DU LIEU CHUA?
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }
    while(1){
            ENTER_INFORMATION("NHAP ID: ", "%s", scanf_str, 0);
            sscanf(scanf_str, "%d", &id);// CHUYEN THANH ID

        for(int i=0; i<_list_student.size(); i++){ //DUYET DANH SACH TIM SINH VIEN TRUNG _id
            if(_list_student[i].getID() == id){ //NEU ID GIONG VOI ID DA NHAP
                printf("\nDA XOA SINH VIEN CO ID: %d\n\n", _list_student[i].getID());
                _list_student.erase(_list_student.begin() + i); //XOA DU LIEU TRONG DANH SACH
                _num_student--;  //GIAM SO SINH VIEN 
                is_have_erased = 1; //SET LEN 1 BEN DA XOA 
            }
            if(is_have_erased == 1){ //NEU DA XOA THANH CONG THI SET LAI ID CHO CAC SINH VIEN O PHIA SAU ID DA XOA
                uint8_t new_ID = _list_student[i].getID() - 1;
                _list_student[i].setID(new_ID);
            }
        }
        if(is_have_erased == 0) printf("\nKHONG DUNG ID\n\n"); //NEU TIM KHONG RA ID DUOC XOA
    }
}

/*
* Class: Menu
* Function: searchStudentByName
* Description: This function use for adding student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::searchStudentByName(){
    uint8_t is_have_name = 0; //DA TIM RA TEN CHUA?
    char scanf_str[50];
    if(_list_student.empty()){ //KIEM TRA DU LIEU DANH SACH SINH VIEN
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }
    while(1){

        ENTER_INFORMATION("NHAP TEN: ", "%s", scanf_str, 0);
        for(int i=0; i<_list_student.size(); i++){ //DUYET DANH SACH DE TIM TEN
            if(strcmp(_list_student[i].getName(), (const char*)scanf_str) == 0){ // NEU CO TEN CAN TIM THI IN THONG TIN SINH VIEN DO RA
                printf("ID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HOCLUC\n");
                printf("%d\t %s\t\t %s\t\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %s\n", _list_student[i].getID(), _list_student[i].getName(), _list_student[i].getSex(), \
                _list_student[i].getAge(), _list_student[i].getMarkMath(), _list_student[i].getMarkPhysical(), _list_student[i].getMarkChemical(), _list_student[i].getAverageMark(), _list_student[i].getStudentAbility());
                printf("\n");
                is_have_name = 1; //SET 1 BIEN KIEM TRA CO TEN CHUA
            }
        }

        if(is_have_name == 0) printf("\nKHONG DUNG TEN\n\n"); //NEU KHONG TEN 
    }

}

/*
* Class: Menu
* Function: sortListStudentByGPA
* Description: This function use for adding student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::sortListStudentByGPA(){
    if(_list_student.empty()){ //KIEM TRA DANH SACH SINH VIEN
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }

    vector<Student> list_student_sortbyid; //THEM 1 DANH SACH PHU DE LUU DANH SACH SAU KHI XEP
    list_student_sortbyid = _list_student; //COPY GIA TRI DANH SACH
    Student sv;
    for(int i=0; i<list_student_sortbyid.size() - 1; i++){ //DUYET DANH SACH PHU TU 0 TOI SIZE - 1
        for(int j=i+1; j<list_student_sortbyid.size(); j++){ //DUYET DANH SACH TU VI TRI HIEN TAI + 1 TOI CUOI DANH SACH. MUC DICH DE TIM GIA TRI NHO NHAT TAI TUNG VI TRI
            if(list_student_sortbyid[i].getAverageMark() > list_student_sortbyid[j].getAverageMark()){ 
                sv = list_student_sortbyid[i];
                list_student_sortbyid[i] = list_student_sortbyid[j];
                list_student_sortbyid[j] = sv;
            }
        }
    }

    //IN DANH SACH DA SAP XEP RA
    SHOW_INFORMATION(index, list_student_sortbyid);

}

/*
* Class: Menu
* Function: sortListStudentByName
* Description: This function use for adding student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::sortListStudentByName(){
    if(_list_student.empty()){ //KIEM TRA DU LIEU DANH SACH
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }

    vector<Student> list_student_sortbyName; // THEM DANH SACH PHU DE LUU DANH SACH DA SAP XEP
    list_student_sortbyName = _list_student;
    Student sv;
    for(int i=0; i<list_student_sortbyName.size() - 1; i++){ //DUYET DANH SACH TU DAU TOI SIZE - 1
        for(int j=i+1; j<list_student_sortbyName.size(); j++){ //DUYET DANH SACH TU VI TRI HIEN TAI + 1 TOI CUOI DANH SACH
            if(strcmp(list_student_sortbyName[i].getName(), list_student_sortbyName[j].getName()) > 0){
                sv = list_student_sortbyName[i];
                list_student_sortbyName[i] = list_student_sortbyName[j];
                list_student_sortbyName[j] = sv;
            }
        }
    }

    //IN DANH SACH DA SAP XEP
    SHOW_INFORMATION(index, list_student_sortbyName);
}

/*
* Class: Menu
* Function: showListStudent
* Description: This function use for adding student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::showListStudent(){
    SHOW_INFORMATION(index, _list_student);
}

int main(int argc, char const *argv[])
{
    /* code */
    Menu mn;
    char scanf_str[20];
    uint8_t scanf_command = 0;
    while(1){
        mn.showListCommand();
        printf("\nMOI NHAP LENH: ");
        scanf("%s", scanf_str);
        if(mn.checkExit(scanf_str) == 1) break;
        if(mn.checkNumber(scanf_str) == 1){
            sscanf(scanf_str, "%d", &scanf_command);
            uint8_t _id = 0;
            switch (scanf_command)
            {
            case 1:
                mn.addStudent();
                break;
            case 2:
                mn.updateStudentByID();
                break;

            case 3:
                mn.removeStudent();
                break;
            
            case 4: 
                mn.searchStudentByName();
                break;
            
            case 5:
                mn.sortListStudentByGPA();
                break;

            case 6: 
                mn.sortListStudentByName();
                break;

            case 7:
                mn.showListStudent();
                break;

            
            default:
                break;
            }
        }
        else{
            printf("KHONG CO LENH NAY\n\n");
        }
        // free(scanf_str);
    }
    return 0;
}
