#include <iostream>  
#include <vector>  
#include <limits>  
  
using namespace std;  
  
class NGUOI {  
private:  
    string HoTen;  
    int Tuoi;  
  
public:  
    NGUOI() : HoTen(""), Tuoi(0) {}  
  
    NGUOI(string hoTen, int tuoi) : HoTen(hoTen), Tuoi(tuoi) {}  
  
    virtual ~NGUOI() {}  
  
    virtual void Nhap() {  
        cout << "Nhap Ho ten: ";  
        getline(cin, HoTen);  
  
        cout << "Nhap Tuoi: ";  
        cin >> Tuoi;  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    }  
  
    virtual void Xuat() const {  
        cout << "Ho ten: " << HoTen << "\nTuoi: " << Tuoi << endl;  
    }  
  
    int GetTuoi() const {  
        return Tuoi;  
    }  
};  
  
class BAC_SI : public NGUOI {  
private:  
    string MaBS;  
    float SoNgayLamViec;  
    float TienCongNgay;  
  
public:  
    BAC_SI() : NGUOI(), MaBS(""), SoNgayLamViec(0), TienCongNgay(0) {}  
  
    BAC_SI(string hoTen, int tuoi, string maBS, float soNgayLamViec, float tienCongNgay)  
        : NGUOI(hoTen, tuoi), MaBS(maBS), SoNgayLamViec(soNgayLamViec), TienCongNgay(tienCongNgay) {}  
  
    void Nhap() override {  
        NGUOI::Nhap();  
  
        cout << "Nhap Ma BS: ";  
        getline(cin, MaBS);  
  
        cout << "Nhap So ngay lam viec: ";  
        cin >> SoNgayLamViec;  
  
        cout << "Nhap Tien cong ngay: ";  
        cin >> TienCongNgay;  
    }  
  
    void Xuat() const override {  
        NGUOI::Xuat();  
        cout << "Ma BS: " << MaBS << "\nSo ngay lam viec: " << SoNgayLamViec  
             << "\nTien cong ngay: " << TienCongNgay << endl;  
    }  
  
    float TienCongThang() const {  
        return SoNgayLamViec * TienCongNgay;  
    }  
};  
  
class BENH_NHAN : public NGUOI {  
private:  
    string MaBN;  
    string Benh;  
  
public:  
    BENH_NHAN() : NGUOI(), MaBN(""), Benh("") {}  
  
    BENH_NHAN(string hoTen, int tuoi, string maBN, string benh)  
        : NGUOI(hoTen, tuoi), MaBN(maBN), Benh(benh) {}  
  
    void Nhap() override {  
        NGUOI::Nhap();  
  
        cout << "Nhap Ma BN: ";  
        getline(cin, MaBN);  
  
        cout << "Nhap Benh: ";  
        getline(cin, Benh);  
    }  
  
    void Xuat() const override {  
        NGUOI::Xuat();  
        cout << "Ma BN: " << MaBN << "\nBenh: " << Benh << endl;  
    }  
};  
  
int main() {  
    int n;  
    vector<NGUOI*> danhSachNguoi;  
  
    cout << "Nhap so luong nguoi: ";  
    cin >> n;  
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
  
    for (int i = 0; i < n; ++i) {  
        cout << "Chon loai nguoi (1: BENH_NHAN, 2: BAC_SI): ";  
        int choice;  
        cin >> choice;  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
  
        if (choice == 1) {  
            BENH_NHAN* benhNhan = new BENH_NHAN();  
            benhNhan->Nhap();  
            danhSachNguoi.push_back(benhNhan);  
        } else if (choice == 2) {  
            BAC_SI* bacSi = new BAC_SI();  
            bacSi->Nhap();  
            danhSachNguoi.push_back(bacSi);  
        }  
    }  
  
    cout << "\nDanh sach nguoi:\n";  
    for (const auto& nguoi : danhSachNguoi) {  
        nguoi->Xuat();  
        cout << endl;  
    }  
  
    cout << "\nThong tin BENH_NHAN co tuoi <= 10:\n";  
    for (const auto& nguoi : danhSachNguoi) {  
        const BENH_NHAN* benhNhan = dynamic_cast<const BENH_NHAN*>(nguoi);  
        if (benhNhan != nullptr && benhNhan->GetTuoi() <= 10) {  
            benhNhan->Xuat();  
            cout << endl;  
        }  
    }  
  
    cout << "\nThong tin va tinh tien cong thang cho BAC_SI:\n";  
    for (const auto& nguoi : danhSachNguoi) {  
        BAC_SI* bacSi = dynamic_cast<BAC_SI*>(nguoi);  
        if (bacSi != nullptr) {  
            bacSi->Xuat();  
            cout << "Tien cong thang: " << bacSi->TienCongThang() << endl;  
            cout << endl;  
        }  
    }  
  
    float maxSoNgay = 0;  
    BAC_SI* maxBacSi = nullptr;  
  
    for (const auto& nguoi : danhSachNguoi) {  
        BAC_SI* bacSi = dynamic_cast<BAC_SI*>(nguoi);  
        if (bacSi != nullptr && bacSi->TienCongThang() > maxSoNgay) {  
            maxSoNgay = bacSi->TienCongThang();  
            maxBacSi = bacSi;  
        }  
    }  
  
    if (maxBacSi != nullptr) {  
        cout << "\nThong tin BAC_SI co so ngay lam viec nhieu nhat:\n";  
        maxBacSi->Xuat();  
        cout << "Tien cong thang: " << maxBacSi->TienCongThang() << endl;  
    } else {  
        cout << "\nKhong co BAC_SI trong danh sach.\n";  
    }  
  
    for (auto& nguoi : danhSachNguoi) {  
        delete nguoi;  
    }  
  
    return 0;  
}  
