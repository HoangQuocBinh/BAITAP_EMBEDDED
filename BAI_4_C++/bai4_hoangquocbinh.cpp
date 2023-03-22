#include <stdio.h>
// #include <cstdlib>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <cctype>

using namespace std;


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
    void setID(uint8_t ID);
    void setTenSinhVien(const char *ten);
    void setGioiTinh(const char *GioiTinh);
    void setTuoi(uint8_t Tuoi);
    void setDiemToan(double DiemToan);
    void setDiemLy(double DiemLy);
    void setDiemHoa(double DiemHoa);
    
    uint8_t getID();
    char *getTenSinhVien();
    char *getGioiTinh();
    uint8_t getTuoi();
    double getDiemToan();
    double getDiemLy();
    double getDiemHoa();
    double getDiemTrungBinh();
    char *getHocLuc();

};

void Sinhvien::setID(uint8_t ID){
    this->ID = ID;
}

void Sinhvien::setTenSinhVien(const char *ten){
    strcpy(this->TenHocSinh, ten);
}

void Sinhvien::setGioiTinh(const char *GioiTinh){
    strcpy(this->GioiTinh, GioiTinh);
}

void Sinhvien::setTuoi(uint8_t Tuoi){
    this->Tuoi = Tuoi;
}

void Sinhvien::setDiemToan(double DiemToan){
    this->DiemToan = DiemToan;

}

void Sinhvien::setDiemLy(double DiemLy){
  
    this->DiemLy = DiemLy;
}

void Sinhvien::setDiemHoa(double DiemHoa){
        this->DiemHoa = DiemHoa;
}

uint8_t Sinhvien::getID(){
    return ID;
}

char *Sinhvien::getTenSinhVien(){
    return TenHocSinh;
}

char *Sinhvien::getGioiTinh(){
    return GioiTinh;
}

uint8_t Sinhvien::getTuoi(){
    return Tuoi;
}
double Sinhvien::getDiemToan(){
    return DiemToan;
}
double Sinhvien::getDiemLy(){
    return DiemLy;
}
double Sinhvien::getDiemHoa(){
    return DiemHoa;
}
double Sinhvien::getDiemTrungBinh(){
    if(DiemToan < 0 || DiemToan > 10){
        printf("ERROR! CHUA NHAP DIEM TOAN");
        return -1;
    }

    if(DiemLy < 0 || DiemLy > 10){
        printf("ERROR! CHUA NHAP DIEM TOAN");
        return -1;
    }

    if(DiemHoa < 0 || DiemHoa > 10){
        printf("ERROR! CHUA NHAP DIEM TOAN");
        return -1;
    } 

    DiemTrungBinh = (DiemHoa + DiemLy + DiemToan) / 3;
    return (DiemTrungBinh);
}

char *Sinhvien::getHocLuc(){
    if(Sinhvien::getDiemTrungBinh() >= 8){
        strcpy(HocLuc, (const char *)"Gioi");
    }
    else if(Sinhvien::getDiemTrungBinh() >= 6.5){
        strcpy(HocLuc, (const char *)"Kha");
    }
    else if(Sinhvien::getDiemTrungBinh() >= 5){
        strcpy(HocLuc, (const char *)"Trung Binh");
    }
    else{
        strcpy(HocLuc, (const char *)"Trung Binh");
    }
    return HocLuc;
}


class Menu
{
private:
    /* data */
    vector<Sinhvien> danhsachSinhVien;
    static uint8_t _SoSinhVien; //KIEM TRA SO SINH VIEN DE THEM ID
    int _Kiemtra_GioiTinh(const char* gioitinh);//KIEM TRA NHAP GIOI TINH
    int _Kiemtra_Diem(char *str);// KIEM TRA KHI NHAP DIEM
public:
    int _Kiemtra_Exit(char* str); //KIEM TRA KHI MUON EXIT
    int _Kiemtra_chuso(char *str);//KIEM TRA SO
    void HienThiDanhSachLenh();
    void ThemSinhVien();
    void CapNhatSinhVienTheoID();
    void XoaSinhVien();
    void TimKiemSinhVienTheoTen();
    void SapXepSinhVienTheoGPA();
    void SapxepSinhVienTheoTen();
    void HienThiDanhSach();
};
uint8_t Menu::_SoSinhVien = 0;

int Menu::_Kiemtra_GioiTinh(const char* gioitinh){
    if((strcmp((const char*)"Nam", gioitinh) != 0) && (strcmp((const char*)"Nu", gioitinh) != 0)){
        printf("ERROR! KHONG THE THEM GIOI TINH");
        return 0;
    }
    else{
        return 1;
    }
}

int Menu::_Kiemtra_Diem(char *str){
    double Diem = 0;
    sscanf(str, "%lf", &Diem);
    if(Diem < 0 || Diem > 10){
        printf("ERROR! KHONG THEM NHAP DIEM");
        return 0;
    }
    else{
        return 1;
    }
}

int Menu::_Kiemtra_Exit(char* str){
    if(strcmp(((const char*)"EXIT"), str) == 0)
        return 1;
    return 0;
}

int Menu::_Kiemtra_chuso(char *str){
    for(int i=0; i< strlen(str); i++){
        // if(str[i] == '\0') break;
        if(isdigit(str[i]) == 0)
            return 0;
    }
    return 1;
}


void Menu::HienThiDanhSachLenh(){
    printf("DANH SACH LENH: \n");
    printf("1. THEM SINH VIEN\n");
    printf("2. CAP NHAT THONG TIN SINH VIEN THEO ID\n");
    printf("3. XOA SINH VIEN THEO ID\n");
    printf("4. TIM KIEM SINH VIEN THEO TEN\n");
    printf("5. SAP XEP SINH VIEN THEO GPA\n");
    printf("6. SAP XEP SINH VIEN THEO TEN\n");
    printf("7. HIEN THI DANH SACH SINH VIEN\n");
    printf("NHAP EXIT DE THOAT");
}

void Menu::ThemSinhVien(){
    Sinhvien sv;
    char chuoiduocnhap[50];
    while (1)
    {
        /* code */
    // char *chuoiduocnhap = (char*)malloc(50 * sizeof(char));
    
    uint8_t cnt = 0;
    uint8_t _is_scanf = 0;
    printf("\nTHEM SINH VIEN \t NHAP EXIT DE THOAT\n");
    printf("NHAP TEN: ");
    scanf("%s", chuoiduocnhap);
    if(_Kiemtra_Exit(chuoiduocnhap) == 1) { //KIEM TRA NHAP VAO EXIT
        return;
    }
    sv.setTenSinhVien(chuoiduocnhap); //SET TEN SINH VIEN

    do{
        printf("NHAP GIOI TINH (Nam/Nu): ");
        scanf("%s", chuoiduocnhap);
        if(_Kiemtra_Exit(chuoiduocnhap) == 1) return; // KIEM TRA EXIT
    }while(_Kiemtra_GioiTinh(chuoiduocnhap) == 0); //KIEM TRA NHAP GIOI TINH CO DUNG KHONG
    sv.setGioiTinh(chuoiduocnhap); //SET GIOI TINH

    int tuoi = 0;
    do{
        printf("NHAP TUOI: ");
        scanf("%s", chuoiduocnhap);
        if(_Kiemtra_Exit(chuoiduocnhap) == 1) return; //KIEM TRA EXIT
        sscanf(chuoiduocnhap, "%d", &tuoi); //CHUYEN CHUOI DA NHAP THANH TUOI
    }while(_Kiemtra_chuso(chuoiduocnhap) == 0 || tuoi < 0); //KIEM TRA CHUOI CO PHAI LA SO LON HON 0?
    sv.setTuoi(tuoi); //SET TUOI

    do{
        printf("NHAP DIEM TOAN: ");
        scanf("%s", chuoiduocnhap);
        if(_Kiemtra_Exit(chuoiduocnhap) == 1) return; //KIEM TRA EXIT
    }while(_Kiemtra_Diem(chuoiduocnhap) == 0); //KIEM TRA DIEM NHAP VAO
    double DiemToan = 0;
    sscanf(chuoiduocnhap, "%lf", &DiemToan); //CHUYEN CHUOI DA NHAP THANH DIEM TOAN
    sv.setDiemToan(DiemToan); //SET DIEM TOAN

    do{
        printf("NHAP DIEM LY: ");
        scanf("%s", chuoiduocnhap);
        if(_Kiemtra_Exit(chuoiduocnhap) == 1) return;
    }while(_Kiemtra_Diem(chuoiduocnhap) == 0);
    double DiemLy = 0;
    sscanf(chuoiduocnhap, "%lf", &DiemLy);
    sv.setDiemLy(DiemLy);

    do{
        printf("NHAP DIEM HOA: ");
        scanf("%s", chuoiduocnhap);
        if(_Kiemtra_Exit(chuoiduocnhap) == 1) return;
    }while(_Kiemtra_Diem(chuoiduocnhap) == 0);
    double DiemHoa = 0;
    sscanf(chuoiduocnhap, "%lf", &DiemHoa);
    sv.setDiemHoa(DiemHoa);

    Menu::_SoSinhVien++;
    sv.setID(Menu::_SoSinhVien); //SET ID
    Menu::danhsachSinhVien.push_back(sv); //THEM SINH VIEN VAO DANH SACH
    printf("DA THEM SINH VIEN THANH CONG\n\n");
    // free(chuoiduocnhap);
    }

}
void Menu::CapNhatSinhVienTheoID(){
    static Sinhvien sv;
    uint8_t index = 0; //LUU VI TRI TRUNG VOI ID DUOC NHAP
    uint8_t ID = 0; //LUU GIA TRI ID DUOC NHAP
    uint8_t is_rightID = 0; //GIA TRI ID DUOC NHAP CO DUNG KHONG?
    uint8_t Lenh_nhap = 0; //LUU GIA TRI LENH NHAP
    // uint8_t is_update_done = 0; //
    char chuoiduocnhap[50];
    // char* chuoiduocnhap = (char*)malloc(50 * sizeof(char));
    int tuoi = 0;
    double DiemToan = 0;
    double DiemHoa = 0;
    double DiemLy = 0;
    if(danhsachSinhVien.empty()){ //KIEM TRA DANH SACH CO SINH VIEN CHUA?
        printf("KHONG CO DU LIEU SINH VIEN\n\n");
        return;
    }
    while(1){
        if(is_rightID == 0){
            printf("MOI NHAP ID: ");
            scanf("%s", chuoiduocnhap); //NHAP ID
            if(_Kiemtra_Exit(chuoiduocnhap) == 1) return; //KIEM TRA EXIT
            sscanf(chuoiduocnhap, "%d", &ID);// CHUYEN THANH ID

            for(int i=0; i < danhsachSinhVien.size(); i++){ //DUYET DANH SACH TU DAU TOI CUOI
                if(danhsachSinhVien[i].getID() == ID){ //NEU ID TRUNG VOI ID DUOC NHAP
                    sv = danhsachSinhVien[i]; //LUU GIA TRI SINH VIEN DO VAO 1 BIEN KHAC DE THAY DOI
                    index = i; //LUU GIA TRI VI TRI 
                    is_rightID = 1; //SET LEN 1 DE BIET LA DUNG ID
                }
            }
            if(is_rightID == 0) { //NEU ID KHONG DUNG
                printf("ID KHONG CHINH XAC\n\n");
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
            printf("MOI NHAP LENH: ");
            scanf("%s", chuoiduocnhap); //NHAP LENH DE THUC HIEN
            if(_Kiemtra_Exit(chuoiduocnhap) == 1) return; //KIEM TRA EXIT
            if(_Kiemtra_chuso(chuoiduocnhap) == 1){ //NEU LENH NHAP LA CHU SO
                sscanf(chuoiduocnhap, "%d", &Lenh_nhap);
                switch (Lenh_nhap)
                {
                case 1: //THAY DOI TEN
                    printf("NHAP TEN MOI:");
                    scanf("%s", chuoiduocnhap);
                    if(_Kiemtra_Exit(chuoiduocnhap) == 1) return;
                    sv.setTenSinhVien(chuoiduocnhap);
                    // is_update_done = 1;
                    break;

                case 2: //THAY DOI GIOI TINH
                    do{
                        printf("NHAP GIOI TINH: ");
                        scanf("%s", chuoiduocnhap);
                        if(_Kiemtra_Exit(chuoiduocnhap) == 1) return;
                    }while(_Kiemtra_GioiTinh(chuoiduocnhap) == 0);
                    sv.setGioiTinh(chuoiduocnhap);
                    break;

                case 3: //THAY DOI TUOI

                    do{
                        printf("NHAP TUOI: ");
                        scanf("%s", chuoiduocnhap);
                        if(_Kiemtra_Exit(chuoiduocnhap) == 1) return;
                        sscanf(chuoiduocnhap, "%d", &tuoi);
                    }while(_Kiemtra_chuso(chuoiduocnhap) == 0 || tuoi < 0);
                    sv.setTuoi(tuoi);
                    break;

                case 4: //THAY DOI DIEM TOAN
                    do{
                        printf("NHAP DIEM TOAN: ");
                        scanf("%s", chuoiduocnhap);
                        if(_Kiemtra_Exit(chuoiduocnhap) == 1) return;
                        
                    }while(_Kiemtra_Diem(chuoiduocnhap) == 0);
                    sscanf(chuoiduocnhap, "%lf", &DiemToan);
                    sv.setDiemToan(DiemToan);
                    break;
                
                case 5: //THAY DOI DIEM LY
                    do{
                        printf("NHAP DIEM LY: ");
                        scanf("%s", chuoiduocnhap);
                        if(_Kiemtra_Exit(chuoiduocnhap) == 1) return;
                        
                    }while(_Kiemtra_Diem(chuoiduocnhap) == 0);
                    
                    sscanf(chuoiduocnhap, "%lf", &DiemLy);
                    sv.setDiemLy(DiemLy);
                    break;

                case 6: //THAY DOI DIEM HOA
                    do{
                        printf("NHAP DIEM HOA: ");
                        scanf("%s", chuoiduocnhap);
                        if(_Kiemtra_Exit(chuoiduocnhap) == 1) return;
                    }while(_Kiemtra_Diem(chuoiduocnhap) == 0);
                    sscanf(chuoiduocnhap, "%lf", &DiemHoa);
                    sv.setDiemHoa(DiemHoa);
                    break;
                
                case 7: //HOAN THANH CAP NHAT DE LUU VAO DANH SACH
                    printf("DA HOAN THANH CAP NHAT SINH VIEN ID: %d\n\n", sv.getID());
                    is_rightID = 0;
                    danhsachSinhVien[index] = sv;
                    break;
                    
                default:
                    printf("KHONG CO LENH NAY\n\n");
                    break;
                }
            }
        }
    }
    // free(chuoiduocnhap);

}

void Menu::XoaSinhVien(){
    uint8_t _is_have_erased = 0; //BIEN KIEM TRA DA XOA CHUA?
    uint8_t ID = 0; //ID CAN XOA
    char chuoiduocnhap[50];
    if(danhsachSinhVien.empty()){ //KIEM TRA DANH SACH DA CO DU LIEU CHUA?
        printf("\nKHONG CO DU LIEU SINH VIEN\n\n");
        return;
    }
    while(1){
            printf("MOI NHAP ID: ");
            scanf("%s", chuoiduocnhap);
            if(_Kiemtra_Exit(chuoiduocnhap) == 1) return; //KIEM TRA EXIT
            sscanf(chuoiduocnhap, "%d", &ID);

        for(int i=0; i<danhsachSinhVien.size(); i++){ //DUYET DANH SACH TIM SINH VIEN TRUNG ID
            if(danhsachSinhVien[i].getID() == ID){ //NEU ID GIONG VOI ID DA NHAP
                printf("\nDA XOA SINH VIEN CO ID LA %d\n\n", danhsachSinhVien[i].getID());
                danhsachSinhVien.erase(danhsachSinhVien.begin() + i); //XOA DU LIEU TRONG DANH SACH
                _SoSinhVien--;  //GIAM SO SINH VIEN 
                _is_have_erased = 1; //SET LEN 1 BEN DA XOA 
            }
            if(_is_have_erased == 1){ //NEU DA XOA THANH CONG THI SET LAI ID CHO CAC SINH VIEN O PHIA SAU ID DA XOA
                uint8_t new_ID = danhsachSinhVien[i].getID() - 1;
                danhsachSinhVien[i].setID(new_ID);
            }
        }
        if(_is_have_erased == 0) printf("\nID KHONG CHINH XAC\n\n"); //NEU TIM KHONG RA ID DUOC XOA
    }
}

void Menu::TimKiemSinhVienTheoTen(){
    uint8_t _is_have_name = 0; //DA TIM RA TEN CHUA?
    char Tencantim[50];
    if(danhsachSinhVien.empty()){ //KIEM TRA DU LIEU DANH SACH SINH VIEN
        printf("\nKHONG CO DU LIEU SINH VIEN\n\n");
        return;
    }
    while(1){
        printf("MOI NHAP TEN CAN TIM: ");
        scanf("%s", Tencantim);
        if(_Kiemtra_Exit(Tencantim) == 1) return; //KIEM TRA EXIT
        for(int i=0; i<danhsachSinhVien.size(); i++){ //DUYET DANH SACH DE TIM TEN
            if(strcmp(danhsachSinhVien[i].getTenSinhVien(), (const char*)Tencantim) == 0){ // NEU CO TEN CAN TIM THI IN THONG TIN SINH VIEN DO RA
                printf("ID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HocLuc\n");
            printf("%d\t %s\t\t %s\t\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %s\n", danhsachSinhVien[i].getID(), danhsachSinhVien[i].getTenSinhVien(), danhsachSinhVien[i].getGioiTinh(), \
            danhsachSinhVien[i].getTuoi(), danhsachSinhVien[i].getDiemToan(), danhsachSinhVien[i].getDiemLy(), danhsachSinhVien[i].getDiemHoa(), danhsachSinhVien[i].getDiemTrungBinh(), danhsachSinhVien[i].getHocLuc());
            printf("\n");
                _is_have_name = 1; //SET 1 BIEN KIEM TRA CO TEN CHUA
            }
        }

        if(_is_have_name == 0) printf("\nTEN KHONG CHINH XAC\n\n"); //NEU KHONG TEN 
    }

}


void Menu::SapXepSinhVienTheoGPA(){
    if(danhsachSinhVien.empty()){ //KIEM TRA DANH SACH SINH VIEN
        printf("\nKHONG CO DU LIEU SINH VIEN\n\n");
        return;
    }

    vector<Sinhvien> danhsachSinhVien_sortbyGPA; //THEM 1 DANH SACH PHU DE LUU DANH SACH SAU KHI XEP
    danhsachSinhVien_sortbyGPA = danhsachSinhVien; //COPY GIA TRI DANH SACH
    Sinhvien sv;
    for(int i=0; i<danhsachSinhVien_sortbyGPA.size() - 1; i++){ //DUYET DANH SACH PHU TU 0 TOI SIZE - 1
        for(int j=i+1; j<danhsachSinhVien_sortbyGPA.size(); j++){ //DUYET DANH SACH TU VI TRI HIEN TAI + 1 TOI CUOI DANH SACH. MUC DICH DE TIM GIA TRI NHO NHAT TAI TUNG VI TRI
            if(danhsachSinhVien_sortbyGPA[i].getDiemTrungBinh() > danhsachSinhVien_sortbyGPA[j].getDiemTrungBinh()){ 
                sv = danhsachSinhVien_sortbyGPA[i];
                danhsachSinhVien_sortbyGPA[i] = danhsachSinhVien_sortbyGPA[j];
                danhsachSinhVien_sortbyGPA[j] = sv;
            }
        }
    }

    //IN DANH SACH DA SAP XEP RA
    printf("ID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HocLuc\n");
    for(Sinhvien i : danhsachSinhVien_sortbyGPA){
        printf("%d\t %s\t\t %s\t\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %s\n", i.getID(), i.getTenSinhVien(), i.getGioiTinh(), \
        i.getTuoi(), i.getDiemToan(), i.getDiemLy(), i.getDiemHoa(), i.getDiemTrungBinh(), i.getHocLuc());
    }
    printf("\n");

}


void Menu::SapxepSinhVienTheoTen(){
    if(danhsachSinhVien.empty()){ //KIEM TRA DU LIEU DANH SACH
        printf("\nKHONG CO DU LIEU SINH VIEN\n\n");
        return;
    }

    vector<Sinhvien> danhsachSinhVien_sortbyName; // THEM DANH SACH PHU DE LUU DANH SACH DA SAP XEP
    danhsachSinhVien_sortbyName = danhsachSinhVien;
    Sinhvien sv;
    for(int i=0; i<danhsachSinhVien_sortbyName.size() - 1; i++){ //DUYET DANH SACH TU DAU TOI SIZE - 1
        for(int j=i+1; j<danhsachSinhVien_sortbyName.size(); j++){ //DUYET DANH SACH TU VI TRI HIEN TAI + 1 TOI CUOI DANH SACH
            if(strcmp(danhsachSinhVien_sortbyName[i].getTenSinhVien(), danhsachSinhVien_sortbyName[j].getTenSinhVien()) > 0){
                sv = danhsachSinhVien_sortbyName[i];
                danhsachSinhVien_sortbyName[i] = danhsachSinhVien_sortbyName[j];
                danhsachSinhVien_sortbyName[j] = sv;
            }
        }
    }

    //IN DANH SACH DA SAP XEP
    printf("ID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HocLuc\n");
    for(Sinhvien i : danhsachSinhVien_sortbyName){
        printf("%d\t %s\t\t %s\t\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %s\n", i.getID(), i.getTenSinhVien(), i.getGioiTinh(), \
        i.getTuoi(), i.getDiemToan(), i.getDiemLy(), i.getDiemHoa(), i.getDiemTrungBinh(), i.getHocLuc());
    }
    printf("\n");
}
void Menu::HienThiDanhSach(){
    printf("ID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HocLuc\n");
    for(Sinhvien sv : danhsachSinhVien){
        printf("%d\t %s\t\t %s\t\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %s\n", sv.getID(), sv.getTenSinhVien(), sv.getGioiTinh(), \
        sv.getTuoi(), sv.getDiemToan(), sv.getDiemLy(), sv.getDiemHoa(), sv.getDiemTrungBinh(), sv.getHocLuc());
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    /* code */
    Menu mn;
    char chuoiduocnhap[20];
    uint8_t Lenh_nhap = 0;
    while(1){
        // char *chuoiduocnhap = (char*)malloc(50 * sizeof(char));
        mn.HienThiDanhSachLenh();
        printf("\nMOI NHAP LENH: ");
        scanf("%s", chuoiduocnhap);
        if(mn._Kiemtra_Exit(chuoiduocnhap) == 1) break;
        if(mn._Kiemtra_chuso(chuoiduocnhap) == 1){
            sscanf(chuoiduocnhap, "%d", &Lenh_nhap);
            uint8_t ID = 0;
            switch (Lenh_nhap)
            {
            case 1:
                mn.ThemSinhVien();
                break;
            case 2:
                mn.CapNhatSinhVienTheoID();
                break;

            case 3:
                mn.XoaSinhVien();
                break;
            
            case 4: 
                mn.TimKiemSinhVienTheoTen();
                break;
            
            case 5:
                mn.SapXepSinhVienTheoGPA();
                break;

            case 6: 
                mn.SapxepSinhVienTheoTen();
                break;

            case 7:
                mn.HienThiDanhSach();
                break;

            
            default:
                break;
            }
        }
        else{
            printf("KHONG CO LENH NAY\n\n");
        }
        // free(chuoiduocnhap);
    }
    return 0;
}
