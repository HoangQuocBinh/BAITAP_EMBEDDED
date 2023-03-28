/*
* File: bai5_hoangquocbinh.cpp
* Author: HOANG QUOC BINH
* Date: 27/03/2023
* Description: This is file for restaurant management
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <cctype>

using namespace std;

#define ENTER_INFORMATION(thongtin, dinhdang, noidung, dieukien)\
    do{                                                         \
        printf(thongtin);                                       \
        scanf(dinhdang, noidung);                               \
    }while(dieukien);  

#define SHOW_INFORMATION(infor, list)\
    printf(infor);\
    for(int index = 0; index < list.size(); index++){\
        printf("%d\t %s\t\t %.2lf\n", list[index].get_ID(), list[index].get_NameDish(), list[index].get_Prices());    \
    }\
    printf("\n");
  
/*
* Function: check_Exit
* Description: This function use for get list dishes of tables
* Input:
*   command - value which use for check
* Output:
*   return state of Exit. 1 is Exit and 0 is not Exit
*/
uint8_t check_Exit(uint8_t command){
    if(command == 0) return 1;
    return 0;
}

uint8_t check_Exit(const char* command){
    uint8_t tam = -1;
    sscanf(command, "%d", &tam);
    if(tam == 0) return 1;
    return 0;
}

/**********************************Class Dish*********************************/
class Dish
{
private:
    /* data */
    uint8_t _id;
    char _nameofDish[50];
    double _prices;
    uint8_t _numofDish;
    double _totalPrices;
public:
    Dish();
    Dish(const uint8_t id, const char* namedish, const double prices);
    void set_ID(const uint8_t id);
    void set_NameDish(const char* namedish);
    void set_Prices(const double prices);
    void set_NumofDish(uint8_t numberofdish);

    uint8_t get_ID();
    char* get_NameDish();
    uint8_t get_NumofDish();
    double get_Prices();
    double get_totalPrices();
};

Dish::Dish(){}

Dish::Dish(const uint8_t id, const char* namedish, const double prices){
    this->_id = id;
    // this->_nameofDish = namedish;
    strcpy(this->_nameofDish, namedish);
    this->_prices = prices;
}

/*
* Class: Dish
* Function: set_ID
* Description: This function use for set ID of a dish
* Input:
*   id - ID of dish
* Output:
*   Not returns value
*/
void Dish::set_ID(const uint8_t id){
    this->_id = id;
}

/*
* Class: Dish
* Function: set_NameDish
* Description: This function use for set name of a dish
* Input:
*   namedish - Name of dish
* Output:
*   Not returns value
*/
void Dish::set_NameDish(const char* namedish){
    // this->_nameofDish = namedish;
    strcpy(this->_nameofDish, namedish);
}

/*
* Class: Dish
* Function: set_Prices
* Description: This function use for set price of a dish
* Input:
*   prices - price of dish
* Output:
*   Not returns value
*/
void Dish::set_Prices(const double prices){
    this->_prices = prices;
}

/*
* Class: Dish
* Function: set_NumofDish
* Description: This function use for set order quantity of a dish
* Input:
*   prices - price of dish
* Output:
*   Not returns value
*/
void Dish::set_NumofDish(uint8_t numberofdish){
    this->_numofDish = numberofdish;
}

/*
* Class: Dish
* Function: get_ID
* Description: This function use for get ID of a dish
* Input:
*   Dont have input parameters
* Output:
*   return the ID of a dish
*/
uint8_t Dish::get_ID(){
    return _id;
}

/*
* Class: Dish
* Function: get_NameDish
* Description: This function use for get name of a dish
* Input:
*   Dont have input parameters
* Output:
*   return name of a dish
*/
char* Dish::get_NameDish(){
    return _nameofDish;
}

/*
* Class: Dish
* Function: get_NumofDish
* Description: This function use for get order quantity of a dish
* Input:
*   Dont have input parameters
* Output:
*   return order quantity of a dish
*/
uint8_t Dish::get_NumofDish(){
    return _numofDish;
}

/*
* Class: Dish
* Function: get_Prices
* Description: This function use for get price of a dish
* Input:
*   Dont have input parameters
* Output:
*   return price of a dish
*/
double Dish::get_Prices(){
    return _prices;
}

/*
* Class: Dish
* Function: get_totalPrices
* Description: This function use for get total prices of dishes
* Input:
*   Dont have input parameters
* Output:
*   return total prices of dishes
*/
double Dish::get_totalPrices(){
    return (_numofDish * _prices);
}

/*******************************Class Tables********************************/
class Tables
{
private:
    /* data */
    uint8_t _id;
    uint8_t _status;
    vector<Dish> _list_Dish;
public:
    Tables();
    Tables(const uint8_t id, const uint8_t status);
    void set_ID(const uint8_t id);
    void set_Status(const uint8_t status);
    void set_ListDish(Dish dish, const uint8_t command);

    uint8_t get_ID();
    uint8_t get_Status();
    vector<Dish> get_ListDish();

};
Tables::Tables(){}

Tables::Tables(const uint8_t id, const uint8_t status){
    this->_id = id;
    this->_status = status;
}

/*
* Class: Tables
* Function: set_ID
* Description: This function use for set ID of table
* Input:
*   id - ID of table
* Output:
*   Not return
*/
void Tables::set_ID(const uint8_t id){
    this->_id = id;
}

/*
* Class: Tables
* Function: set_Status
* Description: This function use for set status of table
* Input:
*   status - status of table
* Output:
*   Not return
*/
void Tables::set_Status(const uint8_t status){
    this->_status = status;
}

/*
* Class: Tables
* Function: set_ListDish
* Description: This function use for set list of tables
* Input:
*   dish - dish of table
*   command - value for set or clear a list
* Output:
*   Not return
*/
void Tables::set_ListDish(Dish dish, const uint8_t command){
    enum Command{
        CLEAR = 0,
        ORDER
    };
    
    switch (command)
    {
    case CLEAR:
        _list_Dish.clear();
        break;
    case ORDER:
        _list_Dish.push_back(dish);
        break;
    default:
        break;
    }
}

/*
* Class: Tables
* Function: get_ID
* Description: This function use for get id of tables
* Input:
*   Dont have input parameters
* Output:
*   return id of table
*/
uint8_t Tables::get_ID(){
    return _id;
}

/*
* Class: Tables
* Function: get_Status
* Description: This function use for get status of tables
* Input:
*   Dont have input parameters
* Output:
*   return status of table
*/
uint8_t Tables::get_Status(){
    return _status;
}

/*
* Class: Tables
* Function: get_ListDish
* Description: This function use for get list dishes of tables
* Input:
*   Dont have input parameters
* Output:
*   return list dishes of table
*/
vector<Dish> Tables::get_ListDish(){
    return _list_Dish;
}

/***********************************Class Manager*******************************/
class Manager
{
private:
    /* data */
    static uint8_t _numberTables;
    static uint8_t _id_Dish;
    static vector<Tables> _list_Table;
    static vector<Dish> _list_Dish;
public:
    void set_NumberTables();
    void add_Dish();
    void update_Dish();
    void remove_Dish();
    void set_Table(const uint8_t stt_id, Dish dish, const uint8_t command);
    
    uint8_t show_Dishes();
    uint8_t get_NumberTables();
    vector<Tables> get_List_Table();
    vector<Dish> get_List_Dish();

};

/******************Defination static variable in Class Manager*******************/
uint8_t Manager::_id_Dish = 0;
uint8_t Manager::_numberTables = 0;
vector<Tables> Manager::_list_Table;
vector<Dish> Manager::_list_Dish;

/*
* Class: Manager
* Function: set_NumberTables
* Description: This function use for set number of tables
* Input:
*   Dont have input parameters
* Output:
*   No return
*/
void Manager::set_NumberTables(){
    uint8_t scanf_numTable = 0; //LUU GIA TRI NHAP TU BAN PHIM
    ENTER_INFORMATION("MOI NHAP SO LUONG BAN: ", "%d", &scanf_numTable, scanf_numTable < 0);
    if(check_Exit(scanf_numTable) == 1) return; //KIEM TRA LENH EXIT
    if(_numberTables < scanf_numTable){ //NEU SO BAN NHAP VAO LON HON SO BAN HIEN TAI
        for(int i=0; i< (scanf_numTable - _numberTables); i++){
            Tables table(i+1, 0); //TAO 1 BAN VOI STATUS LA DANG TRONG
            _list_Table.push_back(table); //THEM BAN VUA TAO VAO TRONG LIST
        }
    }
    else if(_numberTables > scanf_numTable){ //NEU SO BAN NHAP NHO HON SO BAN HIEN TAI
        for(int i=scanf_numTable + 1; i<=_numberTables; i++){
            _list_Table.erase(_list_Table.begin() + i); //XOA CAC BAN O PHIA CUOI CHO TOI KHI DUNG SO BAN VUA NHAP
        }
    }
    _numberTables = scanf_numTable; //LUU LAI GIA TRI SO BAN

}

/*
* Class: Manager
* Function: add_Dish
* Description: This function use for set new dish
* Input:
*   Dont have input parameters
* Output:
*   No return
*/
void Manager::add_Dish(){
    char namedish[50]; //GIA TRI LUU TEN MON AN
    double price = 0;  //GIA TRI LUU GIA MON AN
    while (1)
    {
        printf("THEM MON AN\t\tNHAP \"0\" DE THOAT\n");
        ENTER_INFORMATION("NHAP TEN MON: ", "%s", namedish, 0); //NHAP TEN MON AN
        if(check_Exit(namedish) == 1) return; // KIEM TRA LENH EXIT

        ENTER_INFORMATION("NHAP GIA: ","%lf", &price, price<0); //NHAP GIA MON AN
        if(check_Exit(price) == 1) return; //KIEM TRA LENH EXIT
        ++_id_Dish; //TANG ID CUA MON AN
        Dish dish(_id_Dish, (const char*)namedish, price); //KHOI TAO MON AN MOI
        _list_Dish.push_back(dish); //LUU VAO TRONG DANH SACH
    }
    
}

/*
* Class: Manager
* Function: update_Dish
* Description: This function use for update dish which has created
* Input:
*   Dont have input parameters
* Output:
*   No return
*/
void Manager::update_Dish(){

    if(_list_Dish.empty()){ //KIEM TRA DANH SACH DA CO DU LIEU CHUA?
        printf("KHONG CO DU LIEU TRONG DANH SACH\n\n");
        return;
    }

    uint8_t id; //LUU ID NHAP TU BAN PHIM 
    char namedish[50]; //LUU GIA TRI TEN MON
    double price; //LUU GIA CUA MON AN
    uint8_t is_have_ID = 0;//KIEM TRA CO DUNG ID MON AN KHONG
    static Dish sub_dish; //MOT MON AN PHU DUOC TAO RA DE THAY DOI CAC GIA TRI CUA MON AN TRUOC KHI CAP NHAT
    uint8_t index = 0;  //LUU GIA TRI VI TRI CUA MON AN TRONG DANH SACH
    uint8_t command; //LENH DUOC NHAP TU BAN PHIM

    enum ListCommand{
        BACK = 0,
        UPDATENAME,
        UPDATEPRICE,
        DONEUPDATE  
    };

    while (1)
    {
        if(is_have_ID == 0){
            show_Dishes();
            printf("THAY DOI MON \t\t NHAP \"0\" DE THOAT\n");
            ENTER_INFORMATION("NHAP ID MON: ", "%d", &id, id<0); //NHAP ID CUA MON MUON THAY DOI
            if(check_Exit(id) == 1) return; //KIEM TRA LENH EXIT

            for(int i = 0; i < _list_Dish.size(); i++){ //DUYET DANH SACH TIM MON CO CUNG ID NHAP
                if(_list_Dish[i].get_ID() == id){ //NEU CO MON AN CUNG ID 
                    is_have_ID = 1; //SET 1 GIA TRI KIEM TRA
                    sub_dish = _list_Dish[i]; //LUU GIA TRI MON AN VAO TRONG MON AN PHU
                    index = i; //LUU GIA TRI VI TRI
                }
            }
            if(is_have_ID == 0){ //NEU KHONG CO ID NHAP TRONG DANH SACH
                printf("ID KHONG DUNG");
            }
        }
        else{
            printf("\nDANH SACH LENH CAP NHAT MON AN: \n");
            printf("1. CAP NHAT TEN MON AN\n");
            printf("2. CAP NHAT GIA\n");
            printf("3. HOAN THANH CAP NHAT\n");
            printf("0. QUAY LAI\n");
            ENTER_INFORMATION("NHAP LENH: ", "%d", &command, command < 0);
            switch (command)
            {
            case UPDATENAME: //THAY DOI TEN MON AN
                /* code */
                ENTER_INFORMATION("NHAP TEN MOI: ", "%s", namedish, 0);
                if(check_Exit(namedish) == 1) break;
                sub_dish.set_NameDish(namedish);
                break;

            case UPDATEPRICE: //THAY DOI GIA MON AN
                /* code */
                ENTER_INFORMATION("NHAP GIA MOI: ", "%lf", &price, price < 0)
                sub_dish.set_Prices(price);
                printf("prices: %.2lf\n", sub_dish.get_Prices());
                if(check_Exit(price) == 1) break;
                break;

            case DONEUPDATE: //HOAN THANH CAP NHAT MON AN
                /* code */
                 printf("DA CAP NHAT MON AN CO ID: %d\n", sub_dish.get_ID());
                is_have_ID = 0;
                _list_Dish[index] = sub_dish;
                break;

            case BACK: //QUAY LAI
                is_have_ID = 0;
                break;

            default:
                printf("KHONG CO LENH\n");
                break;
            }
        }
        
    }
}

/*
* Class: Manager
* Function: remove_Dish
* Description: This function use for remove dish
* Input:
*   Dont have input parameters
* Output:
*   No return
*/
void Manager::remove_Dish(){

    uint8_t is_have_erased = 0; //BIEN KIEM TRA DA XOA CHUA?
    uint8_t id = 0; //ID CAN XOA
    if(_list_Dish.empty()){ //KIEM TRA DANH SACH DA CO DU LIEU CHUA?
        printf("KHONG CO DU LIEU MON AN\n\n");
        return;
    }
    while(1){
        is_have_erased = 0;
        printf("XOA MON AN \t\t NHAP \"0\" DE THOAT\n");
        show_Dishes();
        ENTER_INFORMATION("NHAP ID: ", "%d", &id, id < 0); //NHAP ID MON MUON XOA
        if(check_Exit(id) == 1) return; // KIEM TRA LENH EXIT

        for(int i=0; i<_list_Dish.size(); i++){ // DUYET DANH SACH MON
            if(_list_Dish[i].get_ID() == id){ //NEU ID GIONG VOI ID DA NHAP
                printf("\nDA XOA MON AN CO ID: %d\n\n", _list_Dish[i].get_ID());
                _list_Dish.erase(_list_Dish.begin() + i); //XOA DU LIEU TRONG DANH SACH
                _id_Dish--;  //GIAM SO LUONG MON
                is_have_erased = 1; //SET LEN 1 BEN DA XOA 
            }
            if(is_have_erased == 1){ //NEU DA XOA THANH CONG THI SET LAI ID CHO CAC MON O PHIA SAU MON DA XOA
                uint8_t new_ID = _list_Dish[i].get_ID() - 1;
                _list_Dish[i].set_ID(new_ID);
            }
        }
        if(is_have_erased == 0) printf("\nKHONG DUNG ID\n\n"); //NEU TIM KHONG RA ID DUOC XOA
    }
}

/*
* Class: Manager
* Function: show_Dishes
* Description: This function use for show dishes
* Input:
*   Dont have input parameters
* Output:
*   return state of list dishes
*/
uint8_t Manager::show_Dishes(){
    if(_list_Dish.empty()){ //KIEM TRA DANH SACH DA CO DU LIEU CHUA?
        printf("KHONG CO DU LIEU MON AN\n\n");
        return 0;
    }

    SHOW_INFORMATION("ID\t TENMON\t\t GIA\n", _list_Dish); //HIEN THI DANH SACH MON
    return 1;
}

/*
* Class: Manager
* Function: set_Table
* Description: This function use for set dish when order or caculated
* Input:
*   stt_id - No. id of table
*   dish - dish which is orderd
*   command - value that set 1 when want to order and 0 when want to caculated
* Output:
*   No return
*/
void Manager::set_Table(const uint8_t stt_id, Dish dish, const uint8_t command){

    enum Command{
        CACULATED = 0, //TINH TIEN
        ORDER //DAT MON
    };
    
    // const uint8_t id_table = id_table;
    switch (command)
    {
    case ORDER: //NEU DAT MON AN

        _list_Table[stt_id-1].set_Status((const uint8_t)ORDER); //SET STATUS CUA BAN
        _list_Table[stt_id-1].set_ListDish(dish, (const uint8_t)1); //THEM MON CHO BAN
        printf("DA THEM MON CHO BAN SO %d\n", _list_Table[stt_id-1].get_ID());
        break;
    
    case CACULATED: //TINH TIEN
        _list_Table[stt_id-1].set_Status((const uint8_t)CACULATED); //SET STATUS CHO BAN
        _list_Table[stt_id-1].set_ListDish(dish, (const uint8_t)CACULATED); // XOA TAT CA MON AN BAN DA DAT
        break;
    
    default:
        break;
    }
    
}

/*
* Class: Manager
* Function: get_NumberTables
* Description: This function use for get number of tables
* Input:
*   Dont have input parameters
* Output:
*   return number of tables
*/
uint8_t Manager::get_NumberTables(){
    return _numberTables;
}

/*
* Class: Manager
* Function: get_List_Table
* Description: This function use for get list of tables
* Input:
*   Dont have input parameters
* Output:
*   return list of tables
*/
vector<Tables> Manager::get_List_Table(){
    return _list_Table;
}

/*
* Class: Manager
* Function: get_List_Dish
* Description: This function use for get list of dishes
* Input:
*   Dont have input parameters
* Output:
*   return list of dishes
*/
vector<Dish> Manager::get_List_Dish(){
    return _list_Dish;
}

/*************************************Class Staff**************************************/
class Staff
{
private:
    /* data */
    Manager mn;
public:
    Staff();
    uint8_t show_ListTable();
    uint8_t check_ID_Table(uint8_t id_table);
    void order(const uint8_t stt_id);
    void show_ListDishes(const uint8_t stt_id);
    void caculated(const uint8_t stt_id);
};

Staff::Staff(){
}

/*
* Class: Staff
* Function: show_ListTable
* Description: This function use for show list tables
* Input:
*   Dont have input parameters
* Output:
*   return state of list tables
*/
uint8_t Staff::show_ListTable(){
    vector<Tables> list_table = mn.get_List_Table();
    if(list_table.empty()){ //KIEM TRA DANH SACH BAN
        printf("KHONG CO DU LIEU BAN \n");
        return 0;
    }

    //IN BAN VA TRANG THAI BAN
    for(int i=0; i<list_table.size(); i++){
        printf("BAN:%d        |", list_table[i].get_ID());
    }
    printf("\n");

    for(int i=0; i<list_table.size(); i++){
        printf("TRANGTHAI:%s  |", (list_table[i].get_Status() == 1) ? (const char*)"X" : (const char*)" ");
    }
    printf("\n");
    return 1;
}

/*
* Class: Staff
* Function: check_ID_Table
* Description: This function use for check id of table
* Input:
*   id_table - id of table
* Output:
*   return No id of table in list 
*/
uint8_t Staff::check_ID_Table(uint8_t id_table){
    vector<Tables> list_table = mn.get_List_Table();
    if(list_table.empty()){ //KIEM TRA DANH SACH BAN
        printf("KHONG CO DU LIEU BAN \n");
        return 0;
    }

    for(int i=0; i<list_table.size(); i++){ //KIEM TRA ID BAN
        if(list_table[i].get_ID() == id_table){
            return i+1; //VI TRI CUA ID TRONG DANH SACH BAN
        }
    }
    return 0;
}

/*
* Class: Staff
* Function: order
* Description: This function use for order dish
* Input:
*   stt_id - No. id of table in list
* Output:
*   Not return 
*/
void Staff::order(const uint8_t stt_id){
    static uint8_t id; //LUU ID MON AN
    static uint8_t quantity; //LUU SO LUONG DAT 
    while (1)
    {

        uint8_t is_have_ID = 0;
        printf("ORDER FOOD\t\t NHAP \"0\" DE THOAT\n");
        if(mn.show_Dishes() == 0) break; //KIEM TRA DANH SACH MON DA THEM TU QUAN LI

        ENTER_INFORMATION("NHAP ID MON: ", "%d", &id, id<0); //NHAP ID MON
        if(check_Exit(id) == 1) break;

        ENTER_INFORMATION("NHAP SO LUONG: ", "%d", &quantity, quantity < 0); //NHAP SO LUONG DAT MON
        if(check_Exit(quantity) == 1) break;
        

        vector<Dish> list_dish = mn.get_List_Dish(); //LAY DANH SACH MON
        for(Dish dish : list_dish){
            if(dish.get_ID() == id){ //TIM MON TRUNG ID
                dish.set_NumofDish(quantity); 
                // printf("sub id: %d\n", id_table);
                mn.set_Table(stt_id, dish, (const uint8_t)1); //THEM MON VAO DANH SACH MON CUA BAN
                is_have_ID = 1;
            }
        }
        if(is_have_ID == 0) printf("KHONG CO MON NAY\n");
    }
    
}

/*
* Class: Staff
* Function: show_ListDishes
* Description: This function use for list dishes which have orderd
* Input:
*   stt_id - No. id of table in list
* Output:
*   Not return 
*/
void Staff::show_ListDishes(const uint8_t stt_id){

    uint8_t index = 0;
    vector<Tables> list_table = mn.get_List_Table(); //LAY DANH SACH BAN TU QUAN LI
    vector<Dish> list_dish = list_table[stt_id-1].get_ListDish(); //LAY DANH SACH MON DA DAT CUA BAN

    if(list_dish.empty()){ //KIEM TRA BAN DO DA GOI MON CHUA
        printf("BAN NAY CHUA GOI MON\n");
        return;
    }

    int i = 0;
    //IN RA DANH SACH MON BAN DA DAT
    printf("\nSTT\t ID\t TENMON\t\t SOLUONG\t GIA\n");
    for(Dish dish : list_dish){
        printf("%d\t %d\t %s\t\t %d\t\t %.2lf\n", i+1, dish.get_ID(), dish.get_NameDish(), dish.get_NumofDish(), dish.get_totalPrices());
    }
}

/*
* Class: Staff
* Function: caculated
* Description: This function use for caculated
* Input:
*   stt_id - No. of id table in list
* Output:
*   Not return 
*/
void Staff::caculated(const uint8_t stt_id){

    uint8_t command;
    vector<Tables> list_table = mn.get_List_Table(); //LAY DANH SACH BAN TU QUAN LI
    vector<Dish> list_dish = list_table[stt_id-1].get_ListDish(); //LAY DANH SACH MON DA DAT CUA BAN

    
    if(list_dish.empty()){ //KIEM TRA BAN DA DAT MON CHUA
        printf("BAN NAY CHUA GOI MON\n");
        return;
    }

    show_ListDishes(stt_id); //IN RA DANH SACH MON DA DAT
    double total = 0;
    for(Dish dish : list_dish){
        total += dish.get_totalPrices(); //TINH TONG SO TIEN BAN DO DA DAT MON
    }
    printf("TONG TIEN BAN SO %d la %.2lf\n", list_table[stt_id-1].get_ID(),total); //IN RA TONG SO TIEN

    ENTER_INFORMATION("NHAP \"1\" DE TIEP TUC\t\t NHAP \"0\" DE THOAT\n", "%d", &command, command < 0); //NHAP LENH TRA TIEN HAY THOAT
    if(check_Exit(command) == 1) return;
    Dish dish;
    mn.set_Table(stt_id, dish, (const uint8_t)0); // TINH TIEN CHO BAN
    printf("DA TINH TIEN BAN SO %d\n", list_table[stt_id-1].get_ID()); 
    printf("XIN CHAO VA HEN GAP LAI\n");

}

/*************************************Class Menu**********************************/
class Menu
{
private:
    /* data */
    Manager mn;
    Staff sf;
public:
    void manager();
    void staff();
    void show_ListCommandMenu();
    void show_ListCommandManager();
    void show_ListCommandTables();
};

/*
* Class: Menu
* Function: show_ListCommandMenu
* Description: This function use for show list command of menu
* Input:
*   Dont have input parameters
* Output:
*   Not return 
*/
void Menu::show_ListCommandMenu(){
    printf("\nDANH SACH LENH MENU:\n");
    printf("NHAP 1: QUAN LI\n");
    printf("NHAP 2: NHAN VIEN\n");
    printf("NHAP 0: THOAT\n");
}

/*
* Class: Menu
* Function: show_ListCommandManager
* Description: This function use for show list command of manager
* Input:
*   Dont have input parameters
* Output:
*   Not return 
*/
void Menu::show_ListCommandManager(){
    printf("\nDANH SACH LENH QUAN LI:\n");
    printf("NHAP 1: DAT SO LUONG BAN\n");
    printf("NHAP 2: THEM MON AN\n");
    printf("NHAP 3: SUA MON AN\n");
    printf("NHAP 4: XOA MON AN\n");
    printf("NHAP 5: HIEN THI DANH SACH MON AN\n");
    printf("NHAP 0: QUAY LAI\n");
}

/*
* Class: Menu
* Function: show_ListCommandTables
* Description: This function use for show list command of table
* Input:
*   Dont have input parameters
* Output:
*   Not return 
*/
void Menu::show_ListCommandTables(){
    printf("\nDANH SACH LENH BAN:\n");
    printf("NHAP 1: GOI MON\n");
    printf("NHAP 2: HIEN THI DANH SACH MON DA DAT\n");
    printf("NHAP 3: TINH TIEN\n");
    printf("NHAP 0: QUAY LAI\n");
}

/*
* Class: Menu
* Function: manager
* Description: This function use for manager to control
* Input:
*   Dont have input parameters
* Output:
*   Not return 
*/
void Menu::manager(){
    uint8_t scanf_cmd;

    enum Command{
        BACK = 0,
        SET_NUM_TABLES,
        ADD_DISH,
        UPDATE_DISH,
        REMOVE_DISH,
        SHOW_DISHES
    };
    while(1){
        show_ListCommandManager();
        ENTER_INFORMATION("MOI NHAP LENH: ", "%d", &scanf_cmd, scanf_cmd < 0); //NHAP LENH DIEU KHIEN
        if(check_Exit(scanf_cmd) == 1) return;
        switch (scanf_cmd)
        {
        case BACK:
            /* code */
            return;
            break;
        case SET_NUM_TABLES:
            mn.set_NumberTables();
            break;
        case ADD_DISH:
            mn.add_Dish();
            break;

        case UPDATE_DISH:
            mn.update_Dish();
            break;
        
        case REMOVE_DISH: 
            mn.remove_Dish();
            break;
        
        case SHOW_DISHES:
            mn.show_Dishes();
            break;
        default:
            printf("KHONG CO LENH NAY\n");
            break;
        }
    }

}

/*
* Class: Menu
* Function: staff
* Description: This function use for staff to control
* Input:
*   Dont have input parameters
* Output:
*   Not return 
*/
void Menu::staff(){
    static uint8_t id_table = 100; //LUU GIA TRI ID BAN
    static uint8_t stt_ID = 100; //LUU GIA TRI VI TRI ID BAN TRONG DANH SACH
    uint8_t is_have_id = 0; //KIEM TRA CO DUNG ID KHONG
    uint8_t cmd = 100; //LUU GIA TRI LENH NHAP TU BAN PHIM
    enum Command{
        BACK = 0,
        ORDER,
        SHOW_ORDERD_DISHES,
        CACULATED
    };

    while (1)
    {
        if(is_have_id == 0){
            if(sf.show_ListTable() == 0) return; //KIEM TRA DANH SACH BAN
            ENTER_INFORMATION("NHAP BAN: ", "%d", &id_table, id_table < 0); //NHAP ID BAN
            if(check_Exit(id_table) == 1) return;
            stt_ID = sf.check_ID_Table(id_table); //KIEM TRA GIA TRI ID BAN DA NHAP. NEU CO THI TRA VE VI TRI CUA ID BAN TRONG DANH SACH
            if(stt_ID == 0) continue;
            
        }

        show_ListCommandTables(); //IN RA LENH CUA BAN
        ENTER_INFORMATION("NHAP LENH BAN: ", "%d", &cmd, cmd < 0); //NHAP LENH
        if(check_Exit(cmd) == 1) {
            is_have_id = 0;
            continue;
        }

        switch (cmd)
        {
        case BACK:
            /* code */
            is_have_id = 0;
            continue;
            // break;

        case ORDER:
            sf.order((const uint8_t)stt_ID);
            break;
        
        case SHOW_ORDERD_DISHES:
            sf.show_ListDishes(stt_ID);
            break;
        
        case CACULATED:
            sf.caculated(stt_ID);
            break;
        
        default:
            break;
        }
        is_have_id = 1;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    Menu menu;
    uint8_t command;
    enum Command{
        BACK = 0,
        MANAGER,
        STAFF
    };

    while(1){
        // printf("command: %d\n", command);
        menu.show_ListCommandMenu();
        ENTER_INFORMATION("NHAP LENH: ", "%d", &command, command < 0);

        switch (command)
        {
        case BACK:
            return 0;
            break;

        case MANAGER:
            menu.manager();
            break;

        case STAFF:
            menu.staff();
            break;
        default:
            printf("KHONG CO LENH NAY\n");
            break;
        }

        }
    return 0;
}
