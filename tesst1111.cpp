#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class NGUOI{
	protected:
		string hoten;
		int namsinh;
	public:
		void nhap_thong_tin_nguoi()
		{
			cout<<"Nhap ho ten: "; getline(cin,hoten);
			cout<<"Nhap nam sinh: "; cin>>namsinh; cin.ignore();
		}
		void xuat_thong_tin_nguoi()
		{
			cout<< setw(20)<<left<< hoten<<setw(20)<<left<<namsinh<<endl;
		}
};

class SINH_VIEN : public NGUOI{
	private:
		string MSV;
	public:
		void nhap_thong_tin_sv(){
			nhap_thong_tin_nguoi();
			cout << "Nhap ma sinh vien: "; getline(cin,MSV);
		}
		void xuat_thong_tin_sv(){
        	cout<< setw(20)<< left << MSV;
        	xuat_thong_tin_nguoi();
		}
		string getMSV()
		{
 			return MSV;
		}
		string getHoTenSV()
		{
 			return hoten;
		}	
		void getDL()
		{
			cout << setw(20) << left << getMSV() << setw(20) << left << getHoTenSV() << endl;
		}
};

static void xuat_bang()
{
 	cout << setfill('-');
 	cout << setw(120) << '-' << endl;
 	cout << setfill(' ');
 	cout << setw(65) << right << "BANG DANH SACH SINH VIEN" << endl;
 	cout << setfill('-');
 	cout << setw(120) << '-' << endl;
 	cout << setfill(' ');
 	cout << setw(20) << left << "Ma Sinh Vien" << setw(20) << left << "Ho Ten"<< setw(20) << left << "Nam Sinh";
 	cout << endl;
 	cout << setfill('-');
 	cout << setw(120) << '-' << endl;
 	cout << setfill(' ');
}
// Dieu kien sap xep theo MSV
	bool sosanhmsv(SINH_VIEN a, SINH_VIEN b)
	{
		return a.getMSV() < b.getMSV();
	}
// Dieu kien sap xep theo Ten
	bool sosanhten(SINH_VIEN a, SINH_VIEN b)
	{	
		 return a.getHoTenSV() < b.getHoTenSV();
	}	
int main() {
	vector<SINH_VIEN> ListSV;
    vector<NGUOI> ListN;
 	int SLSV;
 	cout << "Nhap so luong sinh vien: "; cin >> SLSV; cin.ignore();
 	ListSV.resize(SLSV);
 	for (int i = 0; i < SLSV; i++)
 	{
		cout << "Sinh vien thu " << i+1 << ": " << endl;
 		ListSV[i].nhap_thong_tin_sv();
 		cin.ignore();
 	}
 	if (SLSV > 0) xuat_bang();
 	for (int i = 0; i < SLSV; i++)
 	{
 		ListSV[i].xuat_thong_tin_sv();
 	}
    // SAP XEP THEO MA SINH VIEN
	sort(ListSV.begin(), ListSV.end(), sosanhmsv);
	cout <<"\n";
	cout << "SAP XEP THEO MA SINH VIEN" << endl;
	if (ListSV.size() > 0) xuat_bang();
	for (int i = 0; i < ListSV.size(); i++)
	{
		ListSV[i].xuat_thong_tin_sv();
	}
	// SAP XEP THEO TEN
	sort(ListSV.begin(), ListSV.end(), sosanhten);
	cout <<"\n";
	cout << "SAP XEP THEO TEN" << endl;
	if (ListSV.size() > 0) xuat_bang();
	for (int i = 0; i < ListSV.size(); i++)
	{
		ListSV[i].xuat_thong_tin_sv();
	}
	system("pause");
 	system("cls");
    return 0;
}
