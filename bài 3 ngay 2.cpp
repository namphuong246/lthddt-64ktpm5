#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TimBieuThuc {
public:
    string timBieuThuc(vector<long long>& daySo, long long tongMucTieu) {
        string toanTu = "-~+.";
        string ketQua;
        if (taoBieuThuc(daySo, tongMucTieu, 0, "", toanTu, ketQua)) {
            return ketQua;
        } else {
            return "impossible";
        }
    }

private:
    bool tinhBieuThuc(vector<long long>& daySo, string& bieuThuc, long long tongMucTieu) {
        long long ketQua = daySo[0];
        int j = 0;
        for (int i = 0; i < bieuThuc.length(); ++i) {
            if (bieuThuc[i] == '+') {
                ketQua += daySo[j + 1];
            } else if (bieuThuc[i] == '-') {
                ketQua -= daySo[j + 1];
            } else if (bieuThuc[i] == '~') {
                ketQua = -daySo[j + 1];
            } else if (bieuThuc[i] == '.') {
                ketQua = ketQua * 10 + daySo[j + 1];
            }
            j++;
        }
        return ketQua == tongMucTieu;
    }

    bool taoBieuThuc(vector<long long>& daySo, long long tongMucTieu, int viTriHienTai, string bieuThucHienTai, string& toanTu, string& ketQua) {
        if (viTriHienTai == daySo.size() - 1) {
            if (tinhBieuThuc(daySo, bieuThucHienTai, tongMucTieu)) {
                ketQua = bieuThucHienTai;
                return true;
            }
            return false;
        }

        for (int i = 0; i < toanTu.length(); ++i) {
            string bieuThucMoi = bieuThucHienTai + toanTu[i];
            if (taoBieuThuc(daySo, tongMucTieu, viTriHienTai + 1, bieuThucMoi, toanTu, ketQua)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    int N;
    long long S;
    cin >> N >> S;

    vector<long long> daySo(N);
    for (int i = 0; i < N; ++i) {
        cin >> daySo[i];
    }

    TimBieuThuc timKiem;
    string ketQua = timKiem.timBieuThuc(daySo, S);

    cout << ketQua << endl;

    return 0;
}

