/*
* File: Bai1_HoangQuocBinh.c
* Author: HOANG QUOC BINH
* Date: 06/03/2023
* Description: This is file for number handling
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//nhap vao 1 so tu ban phim toi da 7 chu so

uint32_t number; //BIẾN LƯU SỐ ĐƯỢC NHẬP TỪ BÀN PHÍM
uint8_t has_zero = 0; //BIẾN ĐỂ SET LÊN 1 KHI CÓ ZERO

/**********************HÀM ĐỌC SỐ**********************/

/*
* Function: printNum
* Description: This function use for print number
* Input:
*   num - input number
*   vitri - index number in array
* Output:
*   return: none
*/
void printNum(uint8_t num, uint8_t vitri){  
    switch (num)
    {
    case 0: //SỐ 0
        if(vitri % 3 == 1) printf("LINH "); //NẾU LÀ HÀNG CHỤC THÌ ĐỌC LINH
        else printf("KHONG ");
        break;
    case 1://SỐ 1
        if(vitri % 3 != 1) printf("MOT "); //NẾU KHÔNG PHẢI HÀNG CHỤC THÌ ĐƯỢC IN 
        break;
    case 2://SỐ 2
        printf("HAI ");
        break;
    case 3:// SÔ 3
        printf("BA ");
        break;
    case 4:// SỐ 4
        printf("BON ");
        break;
    case 5: //SỐ 5
        if((vitri % 3 == 0) && has_zero == 0) printf("LAM "); // KIỂM TRA VỊ TRÍ LÀ HÀNG ĐƠN VỊ VÀ VỊ TRÍ TRƯỚC KHÔNG PHẢI SỐ 0
        else printf("NAM ");
        break;
    case 6: //SỐ 6
        printf("SAU ");
        break;
    case 7: // SỐ 7
        printf("BAY ");
        break;
    case 8: // SỐ 8
        printf("TAM ");
        break;
    case 9: //SỐ 9
        printf("CHIN ");
        break;
    
    default:
        break;
    }
}

/******************HÀM ĐỌC ĐƠN VỊ******************/

/*
* Function: printNum
* Description: This function use for print unit
* Input:
*   num - input number
*   vitri - index number in array
* Output:
*   return: none
*/
void printUnit(uint8_t num, uint8_t vitri){
    switch (vitri % 3)  // XÉT THEO TỪNG VỊ TRÍ 
    {
    case 2: // VỊ TRÍ HÀNG TRĂM
        /* code */
        printf("TRAM ");
        break;

    case 1: // VỊ TRÍ HÀNG CHỤC
        /* code */
        if(num != 0) printf("MUOI "); // NẾU HÀNG CHỤC BẰNG 0 THÌ KHÔNG IN 
        break;

    case 0: //NẾU LÀ HÀNG ĐƠN VỊ
        if(vitri / 3 == 1) printf("NGAN "); //NẾU LÀ HÀNG ĐƠN VỊ NGÀN
        else if(vitri / 3 == 2) printf("TRIEU "); //NẾU LÀ HÀNG ĐƠN VỊ TRIỆU
        break;

    default:
        break;
    }
}

/**************************HÀM ĐỌC SỐ**************************/

/*
* Function: printNum
* Description: This function use for read number
* Input:
*   num - input number
* Output:
*   return: none
*/
void readNumber(uint32_t num){
    uint8_t size = 1; //SỐ LƯỢNG CHỮ SỐ TRONG SỐ ĐƯỢC GHI VÀO
    uint8_t *ptr = (uint8_t *)malloc(size*sizeof(uint8_t)); //CẤP PHÁT ĐỘNG MẢNG ĐỂ LƯU TỪNG CHỮ SỐ 
    uint8_t check_num_first = 0; //KIỂM TRA VỊ TRÍ SỐ ĐẦU TIÊN Ở HÀNG NÀO

    /***********THỰC HIỆN ĐỂ TÁCH SỐ***********/
    while(1){
        *(ptr + size - 1) = num % 10; //TÁCH TỪNG CHỮ SỐ VÀ VÀO VỊ TRÍ TƯƠNG ỨNG TRONG MẢNG
        num /= 10; //GIẢM CHỮ SỐ ĐI 10 ĐỂ TÁCH TIẾP
        if(num == 0) break; // NẾU TÁCH XONG THÌ BREAK
        ++size; //TĂNG SỐ LƯỢNG CHỮ SỐ SAU MỖI LẦN TÁCH
        realloc(ptr, size*sizeof(uint8_t)); // TĂNG SỐ LƯỢNG Ô NHỚ CỦA MẢNG LÊN ĐỂ LƯU CHỮ SỐ TIẾP THEO
    }

    /****************THỰC HIỆN ĐỂ ĐỌC SỐ*****************/
    for(int i=size-1; i>=0; i--) //DUYỆT TỪ CUỐI LÊN ĐẦU MẢNG LƯU SỐ ĐÃ ĐƯỢC TÁCH Ở TRÊN
    {
        if(check_num_first > 0){ // NẾU ĐÃ CÓ SỐ ĐẦU TIÊN
            if(*(ptr+i) == 0) //NẾU CHỮ SỐ LÀ 0
            {
                has_zero = 1; //CÓ SỐ 0 THÌ SET BIẾN LÊN 1
                uint8_t vitri_sodautien = check_num_first / 3 * 3; //KIỂM TRA SỐ ĐẦU TIÊN Ở HÀNG NÀO
                if(i == vitri_sodautien) printUnit(*(ptr+i), i); //NẾU ĐÃ DUYỆT XONG MỘT HÀNG VÀ HÀNG ĐÓ CHỨA SỐ ĐẦU TIÊN\
                THÌ ĐỌC ĐƠN VỊ HÀNG ĐÓ
                continue;
            }
            else //NẾU CHỮ SỐ KHÁC 0
            {
                if(has_zero == 1) //NẾU PHÍA TRƯỚC SỐ ĐANG DUYỆT LÀ SỐ 0 THÌ ĐỌC GIÁ TRỊ VÀ ĐƠN VỊ CỦA SỐ PHÍA TRƯỚC ĐÓ
                {
                    printNum(*(ptr+i+1), i+1);
                    printUnit(*(ptr+i+1), i+1);  
                }
                //ĐỌC GIÁ TRỊ VÀ ĐƠN VỊ CỦA SỐ HIỆN TẠI
                printNum(*(ptr+i), i);
                printUnit(*(ptr+i), i);
                has_zero = 0;
                continue;
            }
            
        }
        if(*(ptr+i) != 0 && check_num_first == 0) //NẾU LÀ SỐ ĐẦU TIÊN THÌ SẼ ĐỌC GIÁ TRỊ VÀ ĐƠN VỊ\
        LƯU VỊ TRÍ BAN ĐẦU VÀO BIẾN VỊ TRÍ ĐỂ NẾU TRƯỜNG HỢP SAU SỐ BAN ĐẦU TOÀN BẰNG 0 THÌ VẪN ĐỌC ĐƯỢC\
        ĐƠN VỊ CỦA HÀNG SỐ BAN ĐẦU.
        {
            printNum(*(ptr+i), i); //Chuc va chuc ngan
            printUnit(*(ptr+i), i);
            check_num_first = i;
        }
    }

    if(check_num_first == 0) printf("KHONG"); //NẾU DUYỆT MẢNG MÀ BIẾN check_num_first = 0 THÌ SỐ ĐƯỢC TRUYỀN VÀO LÀ 0
    free(ptr); //XOÁ MẢNG CẤP PHÁT ĐỘNG
}

int main(int argc, char const *argv[])
{
    /* code */
    //NHẬP MỘT SỐ TỪ BÀN PHÍM
    printf("Nhap mot so: ");
    scanf("%lu", &number);

    //IN RA SỐ ĐÃ ĐƯỢC NHẬP
    printf("So duoc nhap: %lu\n", number);

    //ĐỌC SỐ ĐÃ ĐƯỢC NHẬP
    readNumber(number);
    return 0;
}
