/*
* File: Bai3_HoangQuocBinh.c
* Author: HOANG QUOC BINH
* Date: 06/03/2023
* Description: This is file for string handling
*/

#include <stdio.h>
#include <stdlib.h>

char arr[] = "The Grammy award-winning  singer. \" \"who has been less active on digital platforms in recent weeks. explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";

//Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//cau 2: In Hoa chu cai dau tien sau dau cham
//Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//Cau 4: Chuyen doi tat ca doan van thanh chu hoa

/*****************************HÀM TÍNH ĐỘ DÀI CHUỖI************************************/

/*
* Function: length
* Description: This function use for get length of string
* Input:
*   str - input string
* Output:
*   return: length of string
*/
int length(char *str){
    int len = 0; //BIẾN TRẢ VỀ ĐỘ DÀI CHUỖI
    int i=0; // BIẾN DÙNG ĐỂ DUYỆT TỪNG KÍ TỰ TRONG CHUỖI
    while(str[i] != '\0'){ //DUYỆT CHUỖI TỪ ĐẦU TỚI CUỐI ĐẾN KHI GẶP KÍ TỰ \0
        ++len;
        ++i;
    }
    return len;
}

/***************************HÀM ĐÀO NGƯỢC CHUỖI*********************************/

/*
* Function: reverseString
* Description: This function use for reversing string
* Input:
*   str - input string
* Output:
*   return: none
*/
void reverseString(char *str){
    int len = length(str); //BIẾN LƯU ĐỘ DÀI CHUỖI
    char *sub_str = (char*)malloc((len+1) * sizeof(char)); //CẤP PHÁT MỘT MẢNG ĐỂ LƯU CHUỐI ĐẢO NGƯỢC.
    sub_str[len] = '\0'; //GIÁ TRỊ CUỐI CỦA CHUỖI LÀ \0
    int vitri = len-1;  //BIẾN LƯU VỊ TRÍ KÍ TỰ CUỐI CỦA TỪNG TỪ 

    for(int i=len - 1; i>=0;--i){  //DUYỆT CHUỐI TỪ CUỐI LÊN ĐẦU
        if(((str[i] >= 'a' && str[i] <= 'z') | (str[i] >= 'A' && str[i] <= 'Z')) == 0){ //NẾU KÍ TỰ KHÔNG PHẢI KÍ TỰ CHỮ\
        HÀM IF NÀY ĐANG PHÁT HIỆN ĐÃ DUYỆT XONG ĐƯỢC MỘT TỪ TRONG CHUỖI

            for(int k=0; k<=vitri - i; k++){  // DUYỆT LẠI CÁC KÍ TỰ TRONG TỪ ĐÃ ĐƯỢC DUYỆT QUA TỪ VỊ TRÍ HIỆN TẠI ĐẾN VỊ TRÍ ĐƯỢC LƯU TRONG vitri
                sub_str[k + (len-1 - vitri)] = str[k + (i + 1)]; // COPY KÍ TỰ CỦA TỪ TƯƠNG ỨNG TỪ CHUỖI BAN ĐẦU QUA MẢNG \
                GIẢI THÍCH MỘT CHÚT Ở ĐÂY:\
                    + Ở VÒNG FOR TA CÓ (vitri - i) SẼ BIẾT ĐƯỢC SỐ LƯỢNG KÍ TỰ TRONG 1 TỪ\
                    + (k + (len-1-vitri)) SẼ CHO RA ĐƯỢC INDEX TƯƠNG ỨNG ĐỂ LƯU KÍ TỰ TRONG MẢNG sub_str\
                    + Ở HIỆN TẠI KÍ TỰ TẠI VỊ TRÍ i KHÔNG PHẢI KÍ TỰ CHUỖI NÊN PHẢI BẮT ĐẦU LƯU TỪ KÍ TỰ PHÍA SAU ĐỂ HOÀN THÀNH LƯU ĐƯỢC 1 TỪ
            }
            sub_str[len - 1 - i] = str[i]; //SAU KHI ĐÃ LƯU ĐƯỢC TỪ THÌ TIẾP TỤC LƯU KÍ TỰ HIỆN TẠI Ở VỊ TRÍ i
            vitri = i - 1; //TIẾP TỤC THAY ĐỔI GIÁ TRỊ VỊ TRÍ VỀ KÍ TỰ CUỐI CỦA TỪ TIẾP THEO
        }

        if(i == 0){ //KHI MỘT CHUỖI ĐÃ DUYỆT XONG THÌ LƯU TIẾP TỪ ĐẦU TIÊN CỦA CHUỖI VÀO CUỐI MẢNG
            for(int k = 0; k <= vitri - i; k++){ 
                sub_str[k + (len-1-vitri)] = str[k + i];
            }
        }
    }
    printf("CHUOI CAU 1: %s\n\n", sub_str);
    free(sub_str);
}

/****************HÀM VIẾT HOA CHỮ CÁI ĐẦU TIÊN SAU DẤU CHẤM******************/

/*
* Function: upcaseAfterDot
* Description: This function use for updating upcase first character after dot
* Input:
*   str - input string
* Output:
*   return: none
*/
void upcaseAfterDot(char *str){

    int dot =0; //KIỂM TRA XEM CÓ DẤU CHẤM KHÔNG?
    int len = length(str); // ĐỘ DÀI CỦA CHUỖI
    char *sub_str = (char*)malloc((len+1) * sizeof(char)); //MẢNG LƯU CHUỔI SAU KHI BIẾN ĐỔI
    sub_str[len] = '\0'; //KẾT THÚC CHUỖI BẰNG KÍ TỰ \0
    for(int i=0; i<=len; ++i){  //DUYỆT CHUỖI TỪ ĐẦU TỚI CUỐI
        if(dot == 1){ //NẾU ĐÃ GẶP DẤU CHẤM
            if(str[i] >= 'a' && str[i] <= 'z'){  //KIẾM TRA XEM CÓ PHẢI KÍ TỰ THƯỜNG KHÔNG?
                sub_str[i] = str[i] - 32; //CHUYỂN THÀNH CHỮ IN HOA THEO MÃ ASCII
                dot = 0; //XOÁ BIẾN KIỂM TRA DẤU CHẤM
                continue;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z'){ //KIỂM TRA XEM CÓ PHẢI KÍ TỰ IN HOA KHÔNG?
               sub_str[i] = str[i]; //GIỮ NGUYÊN KÍ TỰ IN HOA
                dot = 0; //XOÁ BIẾN KIỂM TRA DẤU CHẤM
                continue; 
            }
        }
        sub_str[i] = str[i]; //NẾU CHƯA GẶP DẤU CHẤM VÀ CÓ DẤU CHẤM NHƯNG KHÔNG THOẢ 2 ĐIỀU KIỆN BÊN TRONG THÌ GIỮ NGUYÊN
        if(str[i] == '.') dot =1; // NẾU GẶP DẤU CHẤM THÌ SET BIẾN KIỂM TRA DẤU CHẤM LÊN 1
    }
    printf("CHUOI CAU 2: %s\n\n", sub_str);
    free(sub_str);
}


/******************HÀM CHUYỂN ĐỔI TẤT CẢ KÍ TỰ THÀNH IN HOA*******************/

/*
* Function: upcase
* Description: This function use for updating upcase string
* Input:
*   str - input string
* Output:
*   return: none
*/
void upcase(char *str){
    int len = length(str); //ĐỘ DÀI CHUỖI
    char *sub_str = (char*)malloc((len+1) * sizeof(char)); // MẢNG LƯU CHUỖI SAU BIẾN ĐỔI
    sub_str[len] = '\0'; //KẾT THÚC CHUỖI BẰNG KÍ TỰ \0
    for(int i=0; i<=len; ++i){ //DUYỆT CHUỖI TỪ ĐÀU TỚI CUỐI
        if(str[i] >= 'a' && str[i] <= 'z'){ //NẾU LÀ KÍ TỰ THƯỜNG
            sub_str[i] = (str[i] - 32); // CHUYỂN THÀNH KÍ TỰ IN HOA THEO MÃ ASCII
        }
        else sub_str[i] = str[i]; // NẾU KHÔNG THÌ GIỮ NGUYÊN
    }
    printf("CHUOI CAU 4: %s\n\n", sub_str);
    free(sub_str);
}

/*******************HÀM CHUYỂN ĐỔI TẤT CẢ KÍ TỰ THÀNH KÍ TỰ THƯỜNG******************/

/*
* Function: lowcase
* Description: This function use for updating lowcase string
* Input:
*   str - input string
* Output:
*   return: none
*/
void lowcase(char *str){
    int len = length(str); //ĐỘ DÀI CHUỖI
    char *sub_str = (char*)malloc((len+1) * sizeof(char)); //MẢNG LƯU CHUỖI SAU KHI BIẾN ĐỔI
    sub_str[len] = '\0'; //KẾT THÚC CHUỖI BẰNG KÍ TỰ \0
    for(int i=0; i<=len; ++i){ //DUYỆT CHUỖI TỪ TỪ ĐẦU TỚI CUỐI
        if(str[i] >= 'A' && str[i] <= 'Z'){ //NẾU LÀ KÍ TỰ THƯỜNG
            sub_str[i] = (str[i] + 32); //CHUYỂN THÀNH CHỮ IN HOA THEO MÃ ASCII
        }
        else sub_str[i] = str[i]; //KHÔNG THÌ GIỮ NGUYÊN
    }
    printf("CHUOI CAU 3: %s\n\n", sub_str);
    free(sub_str);
}

int main(int argc, char const *argv[])
{
    //IN CHUỖI BAN ĐẦU
    printf("\nCHUOI BAN DAU: %s\n\n", arr);

    //IN CHUỖI ĐẢO NGƯỢC
    reverseString(arr);

    //IN CHUỐI IN HOA SAU DẤU CHẤM
    upcaseAfterDot(arr);

    //IN CHUỖI KÍ TỰ VIẾT THƯỜNG
    lowcase(arr);

    //IN CHUỖI KÍ TỰ VIẾT HOA
    upcase(arr);  

    return 0;
}
