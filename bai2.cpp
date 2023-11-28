#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

class BieuThucSoHoc {
private:
    string bieuThuc;
    int ketQua;

public:
    BieuThucSoHoc(string bt) {
        bieuThuc = bt;
        ketQua = 0;
    }

    void tinhToan() {
        int so = 0;
        char phepToan = '+';
        int i = 0;
        while (i < bieuThuc.size()) {
            char c = bieuThuc[i];

            if (c == ' ') {
                i++;
                continue;
            }

            if (c >= '0' && c <= '9') {
                so = so * 10 + (c - '0');
            }
            else {
                switch (phepToan) {
                    case '+':
                        ketQua += so;
                        break;
                    case '-':
                        ketQua -= so;
                        break;
                    case '*':
                        ketQua *= so;
                        break;
                }

                if (c == 'a' && i + 2 < bieuThuc.size() && bieuThuc.substr(i, 3) == "abs") {
                    int j = i + 3;
                    while (j < bieuThuc.size() && bieuThuc[j] != ')') {
                        j++;
                    }

                    if (j < bieuThuc.size()) {
                        int giaTri = atoi(bieuThuc.substr(i + 4, j - i - 4).c_str());
                        so = abs(giaTri);
                        i = j;
                        continue;
                    }
                }

                so = 0;
                phepToan = c;
            }

            i++;
        }

        switch (phepToan) {
            case '+':
                ketQua += so;
                break;
            case '-':
                ketQua -= so;
                break;
            case '*':
                ketQua *= so;
                break;
        }
    }

    int layKetQua() {
        return ketQua;
    }
};

int main() {
    string bieuThuc;
    cout << "Nhap vao bieu thuc so hoc: ";
    getline(cin, bieuThuc);

    BieuThucSoHoc bt(bieuThuc);
    bt.tinhToan();
    int ketQua = bt.layKetQua();

    cout << "Ket qua: " << ketQua << endl;

    return 0;
}
