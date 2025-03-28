#include<iomanip>
#include<iostream>
#include<string>

using namespace std;

class NGUOI{
	protected:
		string hoten;
		string gioitinh;
		int namsinh;
	public:
		NGUOI():hoten(""),gioitinh(""),namsinh(0){};
		~NGUOI(){};
		void input();
		void output();
		int tuoi(){
			return 2020-namsinh;
		}	
};
void NGUOI::input(){
	cout<<"Nhap ho ten: ";cin>>hoten;
	cout<<"Nhap gioi tinh: ";cin>>gioitinh;
	cout<<"Nhap nam sinh: ";cin>>namsinh;
}
void NGUOI::output(){
	cout<<"Ho ten: "<<hoten<<endl;
	cout<<"Gioi tinh: "<<gioitinh<<endl;
	cout<<"Nam sinh: "<<namsinh<<endl;
	cout<<"Tuoi: "<<tuoi()<<endl;
}
class NHANVIEN:public NGUOI{
	private:
		float HSTN;
		float mucluong;
		float tienan;
		float luong;
	public:
		NHANVIEN():NGUOI(),HSTN(0),mucluong(0),tienan(0){};
		~NHANVIEN(){};
		void input();
		void output();
		int nghihuu(){
			return tuoi()>=60;
		}
		float luonglau(){
			if(nghihuu()){
				return luong = 0.75*mucluong*HSTN;
			}
			else{
				return luong=mucluong*HSTN+tienan;
			}
		}	
};
void NHANVIEN::input(){
	NGUOI::input();
	cout<<"Nhap he so tham nien: ";cin>>HSTN;
	cout<<"Nhap muc luong: ";cin>>mucluong;
	cout<<"Nhap tien an: ";cin>>tienan;
}
void NHANVIEN::output(){
	NGUOI::output();
	cout<<"He so tham nien: "<<HSTN<<endl;
	cout<<"Muc luong: "<<mucluong<<endl;
	cout<<"Tien an: "<<tienan<<endl;
	cout<<"luong: "<<luonglau()<<endl;
}
int main(){
	NGUOI ng;
	ng.input();
	ng.output();
	int n;
	cout<<"Nhap so luong: ";
	cin>>n;
	NHANVIEN nv[1000];
	cout<<"Nhap thong tin nv:"<<endl;
	for(int i = 0 ; i < n ; i ++){
		nv[i].input();
	}
	cout<<"Danh sach nhan vien:"<<endl;
	for(int i = 0 ; i < n ; i++){
		nv[i].output();
	}
	cout<<"danh sach nghi huu:"<<endl;
	for(int i = 0 ; i < n ; i++){
		if(nv[i].nghihuu()){
			nv[i].output();
		}
	}
}
