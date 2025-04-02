#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
using namespace std;
class nguoi{
	protected:
		int mdd;
		string ten;
	public:
	void in();
	void nhap();
	nguoi(){};
	~nguoi(){};
};
void nguoi::nhap(){
	cout<<"ma dinh danh:";
	cin>>mdd;
	cin.ignore();
	cout<<"ho ten:";
	getline(cin,ten);
}
void nguoi::in(){
	cout<<left<<"\nma dinh danh:"<<mdd<<"\nhoten:"<<ten;
	
}
class nhanvien:public nguoi{
	protected:
		int ns;
		float hesoluong;
		static float tienpc;
		public:
			nhanvien(){};
			void nhap();
			void in();
			float tinhluong(){
			return hesoluong*1550+tienpc;}
	
		
};
void nhanvien::nhap(){
	nguoi::nhap();
	cout<<"nhap nam sinh:";
	cin>>ns;
	cout<<"nhap he so luong:";
	cin>>hesoluong;
}
void nhanvien::in(){
	nguoi::in();
	cout<<left<<"\nnam sinh:"<<ns<<"\nhesoluong:"<<hesoluong<<fixed<<setprecision(2)<<"\nluong:"<<tinhluong();
}

float nhanvien::tienpc=500;
int main(){
	nguoi ng;
	cout<<"nhap thong tin mot nguoi:\n";
	ng.nhap();
	cout<<"\n thong tin vua nhap la:";
	ng.in();
	cout<<endl;
	int n;
	cout<<"\nnhap so luong nhan vien:";
	cin>>n;
	nhanvien dsnv[20];
	for(int i=0;i<n;i++){
		cout<<"\n nhap nhan vien thu"<<i+1<<":\n";
		dsnv[i].nhap();
	}
	cout<<"\ndanh sach nhan vien vua nhap la:\n";
	for(int i=0;i<n;i++){
		dsnv[i].in();
	}
	
	float luongcaonhat=dsnv[0].tinhluong();
	for(int i=0;i<n;i++){
		if(dsnv[i].tinhluong()>luongcaonhat){
			luongcaonhat=dsnv[i].tinhluong();
		}
	}
	cout<<"\ndanh sach nhan vien co luong cao nhat la:\n";
	for(int i=0;i<n;i++){
		if(dsnv[i].tinhluong()==luongcaonhat){
			dsnv[i].in();
			cout<<"\n"<<string(40,'-');
		}
	}
	

}
