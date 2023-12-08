#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LaiXe {
private:
    static int nextMaLX;
    int maLX;
    string hoTen;
    string diaChi;
    string soDT;
    string trinhDo;

public:
    LaiXe(const string& hoTen, const string& diaChi, const string& soDT, const string& trinhDo)
        : maLX(nextMaLX++), hoTen(hoTen), diaChi(diaChi), soDT(soDT), trinhDo(trinhDo) {}

    int getMaLX() const {
        return maLX;
    }

    string getHoTen() const {
        return hoTen;
    }

    string getDiaChi() const {
        return diaChi;
    }

    string getSoDT() const {
        return soDT;
    }

    string getTrinhDo() const {
        return trinhDo;
    }
};

int LaiXe::nextMaLX = 10000;

class Tuyen {
private:
    static int nextMaTuyen;
    int maTuyen;
    int khoangCach;
    int soDiemDung;

public:
    Tuyen(int khoangCach, int soDiemDung)
        : maTuyen(nextMaTuyen++), khoangCach(khoangCach), soDiemDung(soDiemDung) {}

    int getMaTuyen() const {
        return maTuyen;
    }

    int getKhoangCach() const {
        return khoangCach;
    }

    int getSoDiemDung() const {
        return soDiemDung;
    }
};

int Tuyen::nextMaTuyen = 100;

class BangPhanCong {
private:
    struct PhanCong {
        const LaiXe* laiXe;
        const Tuyen* tuyen;
        int soLuot;

        PhanCong(const LaiXe* laiXe, const Tuyen* tuyen, int soLuot)
            : laiXe(laiXe), tuyen(tuyen), soLuot(soLuot) {}
    };

    vector<PhanCong> danhSachPhanCong;

public:
    void themPhanCong(const LaiXe* laiXe, const Tuyen* tuyen, int soLuot) {
        danhSachPhanCong.push_back(PhanCong(laiXe, tuyen, soLuot));
    }

    void sapXepTheoHoTen() {
        sort(danhSachPhanCong.begin(), danhSachPhanCong.end(), [](const PhanCong& a, const PhanCong& b) {
            return a.laiXe->getHoTen() < b.laiXe->getHoTen();
        });
    }

    void sapXepTheoSoLuotTuyen() {
        sort(danhSachPhanCong.begin(), danhSachPhanCong.end(), [](const PhanCong& a, const PhanCong& b) {
            return a.soLuot > b.soLuot;
        });
    }

    void inDanhSachPhanCong() const {
        for (const PhanCong& phanCong : danhSachPhanCong) {
            cout << "Lai xe: " << phanCong.laiXe->getHoTen() << endl;
            cout << "Tuyen: " << phanCong.tuyen->getMaTuyen() << endl;
            cout << "So luot: " << phanCong.soLuot << endl;
            cout << "-------------------------" << endl;
        }
    }

    void lapBangKeKhoangCach() const {
        vector<pair<const LaiXe*, int>> bangKeKhoangCach;

        for (const PhanCong& phanCong : danhSachPhanCong) {
            bool daTonTai = false;
            for (pair<const LaiXe*, int>& pair : bangKeKhoangCach) {
                if (pair.first == phanCong.laiXe) {
                    pair.second += phanCong.tuyen->getKhoangCach() * phanCong.soLuot;
                    daTonTai = true;
                    break;
                }
            }
            if (!daTonTai) {
                bangKeKhoangCach.push_back(make_pair(phanCong.laiXe, phanCong.tuyen->getKhoangCach() * phanCong.soLuot));
            }
        }

        cout << "Bang ke tong khoang cach chay xe trong ngay:" << endl;
        for (const pair<const LaiXe*, int>& pair : bangKeKhoangCach) {
            cout << "Lai xe: " << pair.first->getHoTen() << endl;
            cout << "Tong khoang cach: " << pair.second << " km" << endl;
            cout << "-------------------------" << endl;
        }
    }
};

int main() {
    int nLaiXe;
    int nTuyen;
    int nPhanCong;

    cout << "Nhap so luong lai xe: ";
    cin >> nLaiXe;

    vector<LaiXe> danhSachLaiXe;
    for (int i = 0; i < nLaiXe; i++) {
        string hoTen, diaChi, soDT, trinhDo;
        cout << "Nhap thong tin lai xe " << i + 1 << ":" << endl;
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Dia chi: ";
        getline(cin, diaChi);
        cout << "So dien thoai: ";
        getline(cin, soDT);
        cout << "Trinh do: ";
        getline(cin, trinhDo);

        danhSachLaiXe.push_back(LaiXe(hoTen, diaChi, soDT, trinhDo));
    }

    cout << "Danh sach lai xe da co:" << endl;
    for (const LaiXe& laiXe : danhSachLaiXe) {
        cout << "Ma LX: " << laiXe.getMaLX() << endl;
        cout << "Ho ten: " << laiXe.getHoTen() << endl;
        cout << "Dia chi: " << laiXe.getDiaChi() << endl;
        cout << "So dien thoai: " << laiXe.getSoDT() << endl;
        cout << "Trinh do: " << laiXe.getTrinhDo() << endl;
        cout << "-------------------------" << endl;
    }

    cout << "Nhap so luong tuyen: ";
    cin >> nTuyen;

    vector<Tuyen> danhSachTuyen;
    for (int i = 0; i < nTuyen; i++) {
        int khoangCach, soDiemDung;
        cout << "Nhap thong tin tuyen " << i + 1 << ":" << endl;
        cout << "Khoang cach: ";
        cin >> khoangCach;
        cout << "So diem dung: ";
        cin >> soDiemDung;

        danhSachTuyen.push_back(Tuyen(khoangCach, soDiemDung));
    }

    cout << "Danh sach tuyen da co:" << endl;
    for (const Tuyen& tuyen : danhSachTuyen) {
        cout << "Ma tuyen: " << tuyen.getMaTuyen() << endl;
        cout << "Khoang cach: " << tuyen.getKhoangCach() << " km" << endl;
        cout << "So diem dung: " << tuyen.getSoDiemDung() << endl;
        cout << "-------------------------" << endl;
    }

    cout << "Nhap so luong phan cong: ";
    cin >> nPhanCong;

    BangPhanCong bangPhanCong;
    for (int i = 0; i < nPhanCong; i++) {
        int maLX, maTuyen, soLuot;
        cout << "Nhap thong tin phan cong " << i + 1 << ":" << endl;
        cout << "Ma LX: ";
        cin >> maLX;
        cout << "Ma tuyen: ";
        cin >> maTuyen;
        cout << "So luot: ";
        cin >> soLuot;

        const LaiXe* laiXe = nullptr;
        const Tuyen* tuyen = nullptr;
        for (const LaiXe& lx : danhSachLaiXe) {
            if (lx.getMaLX() == maLX) {
                laiXe = &lx;
                break;
            }
        }
        for (const Tuyen& t : danhSachTuyen) {
            if (t.getMaTuyen() == maTuyen) {
                tuyen = &t;
                break;
            }
        }

        if (laiXe != nullptr && tuyen !=
