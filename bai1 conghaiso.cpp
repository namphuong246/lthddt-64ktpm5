#include <iostream>
using namespace std;

class Cong{
	private:
		int A,B;
	public:
		Cong(int a, int b){
			A=a;
			B=b;
		}
		int Tong(){
			return A+B;
		}
};

int main(){
	int a,b;
	cin>>a;
	cin>>b;
	Cong so(a,b);
	cout<<so.Tong();
	return 0;
}
