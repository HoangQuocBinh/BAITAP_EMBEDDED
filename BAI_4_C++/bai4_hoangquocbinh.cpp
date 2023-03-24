#include <stdio.h>
// #include <cstdlib>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <cctype>

using namespace std;


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
    void set_Name(const char *_student_name);
    void set_Sex(const char *_student_sex);
    void set_Age(uint8_t Student_Age);
    void set_Mark_Math(double _math_mark);
    void set_Mark_Physical(double _physical_mark);
    void set_Mark_Chemical(double _chemical_mark);
    
    uint8_t getID();
    char *get_Name();
    char *get_Sex();
    uint8_t get_Age();
    double get_Mark_Math();
    double get_Mark_Physical();
    double get_Mark_Chemical();
    double get_Average_Mark();
    char *get_Student_Ability();

};

void Student::setID(uint8_t _id){
    this->_id = _id;
}

void Student::set_Name(const char *_student_name){
    strcpy(this->_student_name, _student_name);
}

void Student::set_Sex(const char *_student_sex){
    strcpy(this->_student_sex, _student_sex);
}

void Student::set_Age(uint8_t _student_age){
    this->_student_age = _student_age;
}

void Student::set_Mark_Math(double _math_mark){
    this->_math_mark = _math_mark;

}

void Student::set_Mark_Physical(double _physical_mark){
  
    this->_physical_mark = _physical_mark;
}

void Student::set_Mark_Chemical(double _chemical_mark){
        this->_chemical_mark = _chemical_mark;
}

uint8_t Student::getID(){
    return _id;
}

char *Student::get_Name(){
    return _student_name;
}

char *Student::get_Sex(){
    return _student_sex;
}

uint8_t Student::get_Age(){
    return _student_age;
}
double Student::get_Mark_Math(){
    return _math_mark;
}
double Student::get_Mark_Physical(){
    return _physical_mark;
}
double Student::get_Mark_Chemical(){
    return _chemical_mark;
}
double Student::get_Average_Mark(){
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

char *Student::get_Student_Ability(){
    if(Student::get_Average_Mark() >= 8){
        strcpy(_student_ability, (const char *)"GIOI");
    }
    else if(Student::get_Average_Mark() >= 6.5){
        strcpy(_student_ability, (const char *)"KHA");
    }
    else if(Student::get_Average_Mark() >= 5){
        strcpy(_student_ability, (const char *)"TRUNG BINH");
    }
    else{
        strcpy(_student_ability, (const char *)"YEU");
    }
    return _student_ability;
}


class Menu
{
private:
    /* data */
    vector<Student> _list_student;
    static uint8_t _num_student; //KIEM TRA SO SINH VIEN DE THEM _id
    int _Check_Sex(const char* sex);//KIEM TRA NHAP GIOI TINH
    int _Check_Mark(const char *str);// KIEM TRA KHI NHAP DIEM
public:
    int Check_Exit(const char* str); //KIEM TRA KHI MUON EXIT
    int Check_Number(const char *str);//KIEM TRA SO
    void Show_List_Command();
    void Add_Student();
    void Update_Student_By_ID();
    void Remove_Student();
    void Search_Student_By_Name();
    void Sort_List_Student_By_GPA();
    void Sort_List_Student_By_Name();
    void Show_List_Student();
};
uint8_t Menu::_num_student = 0;

int Menu::_Check_Sex(const char* sex){
    if((strcmp((const char*)"Nam", sex) != 0) && (strcmp((const char*)"Nu", sex) != 0)){
        printf("ERROR! NHAP GIOI TINH KHONG CHINH XAC");
        return 0;
    }
    else{
        return 1;
    }
}

int Menu::_Check_Mark(const char *str){
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

int Menu::Check_Exit(const char* str){
    if(strcmp(((const char*)"EXIT"), str) == 0)
        return 1;
    return 0;
}

int Menu::Check_Number(const char *str){
    for(int i=0; i< strlen(str); i++){
        // if(str[i] == '\0') break;
        if(isdigit(str[i]) == 0)
            return 0;
    }
    return 1;
}


void Menu::Show_List_Command(){
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

#define ENTER_INFORMATION(thongtin, dinhdang, noidung, dieukien)\
    do\
    {\
        printf(thongtin);\
        scanf(dinhdang, noidung);\
        if(Check_Exit(noidung) == 1)\
            return;\
    }while(dieukien);

#define SHOW_INFORMATION(index, list_student)\
    printf("\nID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HOCLUC\n");                                                                                                                                                               \
    for(int index = 0; index < list_student.size(); index++){                                                                                                                                                                                   \
        printf("%d\t %s\t\t %s\t\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %s\n", list_student[index].getID(), list_student[index].get_Name(), list_student[index].get_Sex(),                                                                          \
        list_student[index].get_Age(), list_student[index].get_Mark_Math(), list_student[index].get_Mark_Physical(), list_student[index].get_Mark_Chemical(), list_student[index].get_Average_Mark(), list_student[index].get_Student_Ability());   \
    }                                                                                                                                                                                                                                               \
    printf("\n");


void Menu::Add_Student(){
    Student sv;
    char scanf_str[50];
    while (1)
    {
        /* code */
    // char *scanf_str = (char*)malloc(50 * sizeof(char));
    
    printf("\nTHEM SINH VIEN \t NHAP \"EXIT\" DE THOAT\n");
    ENTER_INFORMATION("NHAP TEN: ", "%s", scanf_str, 0);
    sv.set_Name(scanf_str); //SET TEN SINH VIEN

    ENTER_INFORMATION("NHAP GIOI TINH (Nam/Nu): ", "%s", scanf_str, _Check_Sex(scanf_str) == 0);
    sv.set_Sex(scanf_str); //SET GIOI TINH

    ENTER_INFORMATION("NHAP TUOI: ","%s", scanf_str, Check_Number(scanf_str) == 0 || atoi(scanf_str) < 0);
    uint8_t age;
    sscanf(scanf_str, "%d", &age);
    sv.set_Age(age); //SET TUOI

    ENTER_INFORMATION("NHAP DIEM TOAN: ","%s", scanf_str, _Check_Mark(scanf_str) == 0);
    double math_mark = 0;
    sscanf(scanf_str, "%lf", &math_mark); //CHUYEN CHUOI DA NHAP THANH DIEM TOAN
    sv.set_Mark_Math(math_mark); //SET DIEM TOAN

    ENTER_INFORMATION("NHAP DIEM LY: ","%s", scanf_str, _Check_Mark(scanf_str) == 0);
    double physical_mark = 0;
    sscanf(scanf_str, "%lf", &physical_mark);
    sv.set_Mark_Physical(physical_mark);

    ENTER_INFORMATION("NHAP DIEM HOA: ","%s", scanf_str, _Check_Mark(scanf_str) == 0);
    double chemical_mark = 0;
    sscanf(scanf_str, "%lf", &chemical_mark);
    sv.set_Mark_Chemical(chemical_mark);

    Menu::_num_student++;
    sv.setID(Menu::_num_student); //SET ID
    Menu::_list_student.push_back(sv); //THEM SINH VIEN VAO DANH SACH
    printf("THEM SINH VIEN THANH CONG\n\n");
    // free(scanf_str);
    }

}
void Menu::Update_Student_By_ID(){
    static Student sv;
    uint8_t index = 0; //LUU VI TRI TRUNG VOI _id DUOC NHAP
    uint8_t id = 0; //LUU GIA TRI _id DUOC NHAP
    uint8_t is_rightID = 0; //GIA TRI ID DUOC NHAP CO DUNG KHONG?
    uint8_t scanf_command = 0; //LUU GIA TRI LENH NHAP
    // uint8_t is_update_done = 0; //
    char scanf_str[50];
    // char* scanf_str = (char*)malloc(50 * sizeof(char));
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
            if(Check_Number(scanf_str) == 1){ //NEU LENH NHAP LA CHU SO
                sscanf(scanf_str, "%d", &scanf_command);
                switch (scanf_command)
                {
                case 1: //THAY DOI TEN

                    ENTER_INFORMATION("NHAP TEN MOI: ", "%s", scanf_str, 0);
                    sv.set_Name(scanf_str);
                    // is_update_done = 1;
                    break;

                case 2: //THAY DOI GIOI TINH

                    ENTER_INFORMATION("NHAP GIOI TINH MOI: ", "%s", scanf_str, _Check_Sex(scanf_str) == 0);
                    sv.set_Sex(scanf_str);
                    break;

                case 3: //THAY DOI TUOI

                    ENTER_INFORMATION("NHAP TUOI MOI: ","%s", scanf_str, Check_Number(scanf_str) == 0 || atoi(scanf_str) < 0);
                    sscanf(scanf_str, "%d", &age);
                    sv.set_Age(age);
                    break;

                case 4: //THAY DOI DIEM TOAN

                    ENTER_INFORMATION("NHAP DIEM TOAN MOI: ","%s", scanf_str, _Check_Mark(scanf_str) == 0);
                    sscanf(scanf_str, "%lf", &math_mark);
                    sv.set_Mark_Math(math_mark);
                    break;
                
                case 5: //THAY DOI DIEM LY

                    ENTER_INFORMATION("NHAP DIEM LY MOI: ","%s", scanf_str, _Check_Mark(scanf_str) == 0);
                    sscanf(scanf_str, "%lf", &physical_mark);
                    sv.set_Mark_Physical(physical_mark);
                    break;

                case 6: //THAY DOI DIEM HOA

                    ENTER_INFORMATION("NHAP DIEM HOA MOI: ","%s", scanf_str, _Check_Mark(scanf_str) == 0);
                    sscanf(scanf_str, "%lf", &chemical_mark);
                    sv.set_Mark_Chemical(chemical_mark);
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
    // free(scanf_str);

}

void Menu::Remove_Student(){
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

void Menu::Search_Student_By_Name(){
    uint8_t is_have_name = 0; //DA TIM RA TEN CHUA?
    char scanf_str[50];
    if(_list_student.empty()){ //KIEM TRA DU LIEU DANH SACH SINH VIEN
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }
    while(1){

        ENTER_INFORMATION("NHAP TEN: ", "%s", scanf_str, 0);
        for(int i=0; i<_list_student.size(); i++){ //DUYET DANH SACH DE TIM TEN
            if(strcmp(_list_student[i].get_Name(), (const char*)scanf_str) == 0){ // NEU CO TEN CAN TIM THI IN THONG TIN SINH VIEN DO RA
                printf("ID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HOCLUC\n");
                printf("%d\t %s\t\t %s\t\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %s\n", _list_student[i].getID(), _list_student[i].get_Name(), _list_student[i].get_Sex(), \
                _list_student[i].get_Age(), _list_student[i].get_Mark_Math(), _list_student[i].get_Mark_Physical(), _list_student[i].get_Mark_Chemical(), _list_student[i].get_Average_Mark(), _list_student[i].get_Student_Ability());
                printf("\n");
                is_have_name = 1; //SET 1 BIEN KIEM TRA CO TEN CHUA
            }
        }

        if(is_have_name == 0) printf("\nKHONG DUNG TEN\n\n"); //NEU KHONG TEN 
    }

}


void Menu::Sort_List_Student_By_GPA(){
    if(_list_student.empty()){ //KIEM TRA DANH SACH SINH VIEN
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }

    vector<Student> list_student_sortbyid; //THEM 1 DANH SACH PHU DE LUU DANH SACH SAU KHI XEP
    list_student_sortbyid = _list_student; //COPY GIA TRI DANH SACH
    Student sv;
    for(int i=0; i<list_student_sortbyid.size() - 1; i++){ //DUYET DANH SACH PHU TU 0 TOI SIZE - 1
        for(int j=i+1; j<list_student_sortbyid.size(); j++){ //DUYET DANH SACH TU VI TRI HIEN TAI + 1 TOI CUOI DANH SACH. MUC DICH DE TIM GIA TRI NHO NHAT TAI TUNG VI TRI
            if(list_student_sortbyid[i].get_Average_Mark() > list_student_sortbyid[j].get_Average_Mark()){ 
                sv = list_student_sortbyid[i];
                list_student_sortbyid[i] = list_student_sortbyid[j];
                list_student_sortbyid[j] = sv;
            }
        }
    }

    //IN DANH SACH DA SAP XEP RA
    SHOW_INFORMATION(index, list_student_sortbyid);

}


void Menu::Sort_List_Student_By_Name(){
    if(_list_student.empty()){ //KIEM TRA DU LIEU DANH SACH
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }

    vector<Student> list_student_sortbyName; // THEM DANH SACH PHU DE LUU DANH SACH DA SAP XEP
    list_student_sortbyName = _list_student;
    Student sv;
    for(int i=0; i<list_student_sortbyName.size() - 1; i++){ //DUYET DANH SACH TU DAU TOI SIZE - 1
        for(int j=i+1; j<list_student_sortbyName.size(); j++){ //DUYET DANH SACH TU VI TRI HIEN TAI + 1 TOI CUOI DANH SACH
            if(strcmp(list_student_sortbyName[i].get_Name(), list_student_sortbyName[j].get_Name()) > 0){
                sv = list_student_sortbyName[i];
                list_student_sortbyName[i] = list_student_sortbyName[j];
                list_student_sortbyName[j] = sv;
            }
        }
    }

    //IN DANH SACH DA SAP XEP
    SHOW_INFORMATION(index, list_student_sortbyName);
}



void Menu::Show_List_Student(){
    SHOW_INFORMATION(index, _list_student);
}

int main(int argc, char const *argv[])
{
    /* code */
    Menu mn;
    char scanf_str[20];
    uint8_t scanf_command = 0;
    while(1){
        // char *scanf_str = (char*)malloc(50 * sizeof(char));
        mn.Show_List_Command();
        printf("\nMOI NHAP LENH: ");
        scanf("%s", scanf_str);
        if(mn.Check_Exit(scanf_str) == 1) break;
        if(mn.Check_Number(scanf_str) == 1){
            sscanf(scanf_str, "%d", &scanf_command);
            uint8_t _id = 0;
            switch (scanf_command)
            {
            case 1:
                mn.Add_Student();
                break;
            case 2:
                mn.Update_Student_By_ID();
                break;

            case 3:
                mn.Remove_Student();
                break;
            
            case 4: 
                mn.Search_Student_By_Name();
                break;
            
            case 5:
                mn.Sort_List_Student_By_GPA();
                break;

            case 6: 
                mn.Sort_List_Student_By_Name();
                break;

            case 7:
                mn.Show_List_Student();
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
