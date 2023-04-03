/*
* File: main.cpp
* Author: HOANG QUOC BINH
* Date: 03/04/2023
* Description: This is file for bank
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <vector>
#include <stdarg.h>
#include <string.h>

using namespace std;

/*****************************************Class Bank**********************************/
class Bank
{
private:
    /* data */
    vector<uint8_t> _numberid;
    char _nameaccount[20];
    double _balance;

    typedef enum Format{
        NOT_CORRECT = 0,
        CORRECT
    }Format;
    Format format;
public:
    Bank(uint64_t numberid, const char* nameaccount, double balance);
    void setBalance(double balance);

    uint64_t getNumberID();
    char* getNameAccount();
    double getBalance();
};

Bank::Bank(uint64_t numberid, const char* nameaccount, double balance)
{
    vector<uint8_t> sub_numberid;
    while(1){
        // printf("%d \n", numberid % 10);
        sub_numberid.push_back(numberid % 10); //TÁCH TỪNG CHỮ SỐ VÀ VÀO VỊ TRÍ TƯƠNG ỨNG TRONG MẢNG
        numberid /= 10; //GIẢM CHỮ SỐ ĐI 10 ĐỂ TÁCH TIẾP
        if(numberid == 0) break; // NẾU TÁCH XONG THÌ BREAK
    }
    printf("So = %d\n", sub_numberid.size());
    if(sub_numberid.size() != 9){
        printf("MA SO THE KHONG DUNG 9 SO\n");
        format = NOT_CORRECT;
        return;
    }
    if(balance < 0){
        printf("NHAP SO DU KHONG DUNG\n");
        format = NOT_CORRECT;
        return;
    }
    for(int i=0; i<sub_numberid.size(); i++){
        // printf("%d \n", sub_numberid[i]);
        _numberid.push_back(sub_numberid[i]);
    }
    // _numberid = sub_numberid;
    strcpy(this->_nameaccount, nameaccount);
    this->_balance = balance;
}

/*
* Class: Bank
* Function: setBalance
* Description: This function use for set balance
* Input:
*   balance - balance to set for bank
* Output:
*   return: none
*/
void Bank::setBalance(double balance){
    if(balance < 0){
        printf("NHAP SO DU KHONG DUNG\n");
        return;
    }
    this->_balance = balance;
}

/*
* Class: Bank
* Function: getNumberID
* Description: This function use for get number id 
* Input:
*   Dont have input parameters
* Output:
*   return: number id 
*/
uint64_t Bank::getNumberID(){
    if(format == NOT_CORRECT){
        printf("NHAP THONG TIN KHONG DUNG\n");
        return 0;
    }
    uint64_t numberid = 0;
    for(int i =_numberid.size() - 1; i>=0; i--){
        // printf("%lli \n", (_numberid[i] * pow(10, i)));
        numberid += _numberid[i];
        numberid *= 10;
    }
    numberid /= 10;
    return numberid;
}

/*
* Class: Bank
* Function: getNameAccount
* Description: This function use for get name account
* Input:
*   Dont have input parameters
* Output:
*   return: name account 
*/
char* Bank::getNameAccount(){
    if(format == NOT_CORRECT){
        printf("NHAP THONG TIN KHONG DUNG\n");
        return 0;
    }
    return _nameaccount;
}

/*
* Class: Bank
* Function: getBalance
* Description: This function use for get balance
* Input:
*   Dont have input parameters
* Output:
*   return: balance 
*/
double Bank::getBalance(){
    if(format == NOT_CORRECT){
        printf("NHAP THONG TIN KHONG DUNG\n");
        return 0;
    }
    return _balance;
}

/********************************************Class Manager***********************************/
class Manager
{
private:
    /* data */
    static vector<Bank> _list_bank;
public:
    Manager(/* args */);
    void addBank(Bank bank);

    vector<Bank> &getListBank();
};

vector<Bank> Manager::_list_bank;
Manager::Manager(/* args */)
{
}

/*
* Class: Manager
* Function: addBank
* Description: This function use for add bank into list
* Input:
*   bank - bank want to add into list
* Output:
*   return: none 
*/
void Manager::addBank(Bank bank){
    _list_bank.push_back(bank);
}

/*
* Class: Manager
* Function: getListBank
* Description: This function use for get list bank
* Input:
*  Dont have input parameters
* Output:
*   return: list bank 
*/
vector<Bank>& Manager::getListBank(){
    return _list_bank;
}

/**********************************************Class Client*****************************************/
class Client
{
private:
    /* data */
    Manager manager;
public:
    Client(/* args */);
    void cashWithdrawal(uint64_t numberid, double moneytowitthdraw);
    void cashPayment(uint64_t numberid, double moneytopayment);
    void checkBalance(uint64_t numberid);
};

Client::Client(/* args */)
{
}

/*
* Class: Client
* Function: cashWithdrawal
* Description: This function use for cash withdrawal
* Input:
*  numberid - number id of bank
*  moneytowitthdraw - amount of money want to withdraw
* Output:
*   return: none 
*/
void Client::cashWithdrawal(uint64_t numberid, double moneytowitthdraw){
    vector<Bank> &list_bank = manager.getListBank();
    if(list_bank.empty()){
        printf("CHUA CO DANH SACH NGAN HANG\n");
        return;
    }
    for(Bank &bank : list_bank){
        if(bank.getNumberID() == numberid){
            if(bank.getBalance() < moneytowitthdraw){
                printf("SO DU CON LAI KHONG DU\n");
                return;
            }
            bank.setBalance(bank.getBalance() - moneytowitthdraw);
            printf("DA RUT TIEN THANH CONG\n");
        }
    }
}

/*
* Class: Client
* Function: cashPayment
* Description: This function use for cash payment
* Input:
*  numberid - number id of bank
*  moneytopayment - amount of money want to payment
* Output:
*   return: none 
*/
void Client::cashPayment(uint64_t numberid, double moneytopayment){
    vector<Bank> &list_bank = manager.getListBank();
    if(list_bank.empty()){
        printf("CHUA CO DANH SACH NGAN HANG\n");
        return;
    }
    for(Bank &bank : list_bank){
        if(bank.getNumberID() == numberid){
            bank.setBalance(bank.getBalance() + moneytopayment);
            printf("DA NOP TIEN THANH CONG\n");
        }
    }
}

/*
* Class: Client
* Function: checkBalance
* Description: This function use for check balance
* Input:
*  numberid - number id of bank
* Output:
*   return: none 
*/
void Client::checkBalance(uint64_t numberid){
    vector<Bank> &list_bank = manager.getListBank();
    if(list_bank.empty()){
        printf("CHUA CO DANH SACH NGAN HANG\n");
        return;
    }
    for(Bank &bank : list_bank){
        if(bank.getNumberID() == numberid){
            printf("SO DU: %.2lf\n", bank.getBalance());
        }
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    Bank bank1(102345889, "BINH1", 123000);
    Bank bank2(102345852, "BINH2", 123000);
    Bank bank3(102345856, "BINH3", 123000);
    // printf("number id: %li\n", bank.getNumberID());
    // printf("Ten tk: %s\n", bank.getNameAccount());
    // printf("balance: %.2lf\n", bank.getBalance());
    Manager manager;
    manager.addBank(bank1);
    manager.addBank(bank2);
    manager.addBank(bank3);

    Client client;
    client.checkBalance(102345889);
    client.cashWithdrawal(102345889, 5000000);
    client.checkBalance(102345889);
    client.cashPayment(102345889, 10000);
    client.checkBalance(102345889);
    return 0;
}
