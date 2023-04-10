/*
* File: Bai1_HoangQuocBinh.c
* Author: HOANG QUOC BINH
* Date: 06/03/2023
* Description: This is file for array handling
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


//mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
// sap xep mang theo thu tu tang dan
// liet ke cac phan tu co so lan xuat hien vd: 1 xuat hien 1 lan
//                                             7 xuat hien 2 lan
//                                             8 xuat hien 3 lan

/****************KHAI BÁO TRUCT MẢNG VÀ GÁN GIÁ TRỊ SIZE VÀ GIÁ TRỊ TỪNG Ô NHỚ CỦA MẢNG***************/

typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;

/*
* Function: randomA
* Description: This function use for random number
* Input:
*   minN - number min of range random
*   maxN - number max of range random
* Output:
*   return: number
*/
int randomA(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

/*
* Function: randomArray
* Description: This function use for random array
* Input:
*   value - input array
*   length - length of array
* Output:
*   return: none
*/
void randomArray(typeArray *value, uint8_t length){
    srand((int)time(0));

    value->size = length;

    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size);
    int r;
    for(int i = 0; i < value->size; ++i){
        value->firstAdd[i] = randomA(0,10);
    }    
}

/************************SẮP XẾP MẢNG***********************/

/*
* Function: sortArray
* Description: This function use for sort Array
* Input:
*   a - input array
* Output:
*   return: none
*/
void sortArray(typeArray *a){ // 1 8 8 8 9
    //Ý TƯỞNG LÀ DUYỆT MẢNG ĐỂ TÌM GIÁ TRỊ NHỎ NHẤT Ở TỪNG VỊ TRÍ

    for(int i=0; i<a->size-1; i++){ //DUYỆT MẢNG TỪ ĐẦU TỚI VỊ TRÍ KẾ CUỐI
        for(int j=i+1; j<a->size; j++){ //DUYỆT TIẾP VỊ TRÍ KẾ TIẾP VỊ TRÍ HIỆN TẠI TỚI VỊ TRÍ CUỐI
            if(*(a->firstAdd+i) > *(a->firstAdd+j)){ // NẾU CÓ MỘT GIÁ TRỊ NÀO ĐÓ NHỎ HƠN GIÁ TRỊ HIỆN TẠI 
                //HOÁN ĐỔI 2 GIÁ TRỊ ĐÓ               
                uint8_t temp = *(a->firstAdd+i);
                *(a->firstAdd+i) = *(a->firstAdd+j);
                *(a->firstAdd+j) = temp;
            }
        }
    }
}

/****************************HÀM ĐẾM SỐ LẦN XUẤT HIỆN TRONG MẢNG*************************/

/*
* Function: countArray
* Description: This function use for count Array use for array have been sorted
* Input:
*   a - input array
* Output:
*   return: none
*/
void countArray(typeArray a){ 
    //HÀM NÀY ĐƯỢC SỬ DỤNG KHI MỘT MẢNG ĐÃ ĐƯỢC SẮP XẾP

    uint8_t count = 1; //SỐ LẦN XUẤT HIỆN
    for(int i=0; i<a.size; i++){ //DUYỆT MẢNG TỪ ĐẦU TỚI CUỐI
        if(*(a.firstAdd+i) == *(a.firstAdd+i+1)){ //NẾU 2 VỊ TRÍ KẾ NHAU CÓ GIÁ TRỊ BẰNG NHAHU
            ++count; //TĂNG SỐ LẦN XUẤT HIỆN
        }
        else { //NẾU KHÔNG
            printf("%d xuat hien %d lan\n", *(a.firstAdd+i), count); //IN RA MÀN HÌNH SỐ LẦN XUẤT HIỆN
            count = 1; //SET LẠI GIÁ TRỊ SỐ LẦN 
        }
    }
}

/****************************HÀM ĐẾM SỐ LẦN XUẤT HIỆN TRONG MẢNG*************************/

/*
* Function: countArray
* Description: This function use for count Array use for array have been sorted or not
* Input:
*   a - input array
* Output:
*   return: none
*/
void countArray2(typeArray a){ 
    //HÀM SỬ DỤNG CHO CẢ MẢNG CHƯA SẮP XẾP VÀ MẢNG SẮP XẾP

    uint8_t *arr1 = (uint8_t *)malloc(sizeof(uint8_t)*a.size); //MẢNG SUB ĐỂ KHÔNG LÀM THAY ĐỔI GIÁ TRỊ CỦA MẢNG BAN ĐẦU
    uint8_t count = 0; //SỐ LẦN XUẤT HIỆN

    //GÁN GIÁ TRỊ CỦA MẢNG BAN ĐẦU QUA MẢNG SUB VÀ KIỂM TRA TRONG MẢNG CÓ BAO NHIÊU GIÁ TRỊ 0
    for(int i=0;i<a.size;i++){ //DUYỆT MẢNG TỪ ĐẦU TỚI CUỐI
        *(arr1+i) = *(a.firstAdd+i); //COPY GIÁ TRỊ 
        if(*(arr1+i) == 0) ++count; //KIỂM TRA GIÁ TRỊ 0
    }

    //IN RA MÀN HÌNH
    if(count >0) {
        printf("0 xuat hien %d lan\n",count);
    }
    
    //KIỂM TRA SỐ LẦN XUẤT HIỆN CỦA CÁC GIÁ TRỊ KHÁC 0
    count = 1; //GÁN GIÁ TRỊ SỐ LẦN XUẤT HIỆN BẰNG 1 
    for(int i=0; i<a.size; i++){ //DUYỆT MẢNG TỪ ĐÀU TỚI CUỐI
        if(*(arr1+i) == 0) continue; //BỎ QUA GIÁ TRỊ 0
        for(int j=i+1; j<a.size; j++){ //DUYỆT MẢNG MỘT LẦN NỮA NHƯNG BẮT ĐẦU TỪ VỊ TRÍ HIỆN TẠI + 1 TỚI CUỐI
            if(*(arr1+i) == *(arr1 + j)){ //NẾU CÓ 2 GIÁ TRỊ BẰNG NHAU THÌ TĂNG SỐ LẦN XUẤT HIỆN
                ++count;
                *(arr1+j) = 0; //GÁN LẠI GIÁ TRỊ ĐƯỢC DUYỆT LẦN 2 BẰNG 0
            }
        }
        printf("%d xuat hien %d lan\n", *(arr1+i), count);
        count = 1;
    }
    free(arr1);

}


int main(int argc, char const *argv[])
{
    /* code */

    //KHAI BÁO MẢNG VÀ IN MẢNG BAN ĐẦU
    typeArray arr;
    randomArray(&arr, 20);
    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }

    //ĐẾM SỐ LẦN XUẤT HIỆN TRƯỚC KHI SẮP XẾP MẢNG
    countArray2(arr);
    
    //SẮP XẾP MẢNG VÀ IN MẢNG ĐÃ SẮP XẾP
    sortArray(&arr);
    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }

    //ĐẾM SỐ LẦN XUẤT HIỆN SAU KHI SẮP XẾP
    countArray(arr);
    

    return 0;
}
