#pragma once

#include <stdio.h>
#include <string.h>
#include <stdint.h>


class Sinhvien
{
private:
    /* data */
    uint8_t ID;
    char TenHocSinh[20];
    char GioiTinh[4];
    uint8_t Tuoi;
    double DiemToan;
    double DiemLy;
    double DiemHoa;
    double DiemTrungBinh;
    char HocLuc[20];

public:
    void setTenHocSinh(char ten[]);
    void setGioiTinh(char GioiTinh[]);
    void setTuoi(uint8_t Tuoi);
    void setDiemToan(double DiemToan);
    void setDiemLy(double DiemLy);
    void setDiemHoa(double DiemHoa);
    
    char *getTenHocSinh();
    char *getGioiTinh();
    uint8_t getTuoi();
    double getDiemToan();
    double getDiemLy();
    double getDiemHoa();
    double getDiemTrungBinh();
    char *getHocLuc();

};

