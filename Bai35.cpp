#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class hanghoa{
	protected:
		int mahang;
		string tenhang;
	public:
	void in();
	void nhap();
	hanghoa(){};
};
void hanghoa::nhap(){
	cout<<"nhap ma hang:";
	cin>>mahang;
	cin.ignore();
	cout<<"nhap ten hang:";
	getline(cin,tenhang);
}
void hanghoa::in(){
cout<<left<<"\nmahang:"<<mahang<<"\ntenhang:"<<tenhang;
 }
 class maytinh:public hanghoa{
 	protected:
 		string nsx;
 		int namsx;
 		float gia;
 		static float tlkm;
 	public:
 		maytinh(){};
 		void nhap();
 		void in();
 		float giaban(){return gia-gia*tlkm;}
 	bool operator>(maytinh& mt){
	 return this->giaban()>mt.giaban();}
	 	
 };
 float maytinh::tlkm=0.035;
 void maytinh::nhap(){
 	hanghoa::nhap();
 	cout<<"nhap nam san xuat:";
 	cin>>namsx;
 	cout<<"nhap nha san xuat:";
 	cin.ignore();
 	getline(cin,nsx); 
 	cout<<"nhap gia ban niem yet:";
 	cin>>gia;
 	
 }
 void maytinh::in(){
 	hanghoa::in();
 	cout<<left<<"\nnha san xuat:"<<nsx<<"\n nam san xuat"<<namsx<<fixed<<setprecision(2)<<"\ngia thuc te:"<<giaban()<<endl; 
	 }
 	
 int main(){
 	hanghoa h;
 	cout<<"nhap thong tin mot hang hoa:\n";
 	h.nhap();
 	cout<<"\nthong tin da nhap la:\n";
 
 	h.in();
 	cout<<endl;
 	int n;
 	cout<<"\nnhap so luong may tinh:";
 	cin>>n;
 	maytinh dsmt[20];
 	for(int i=0;i<n;i++){
 		cout<<"\nnhap thong tin may tinh thu"<<i+1<<":\n";
 		dsmt[i].nhap();
	 }
	 cout<<"\ndanh sach may tinh vua nhap la\n";
	 for(int i=0;i<n;i++){
	 	dsmt[i].in();
	 }
	 for(int i=0;i<n-1;i++){
	 	for (int j=i+1;j<n;j++){
	 		if(dsmt[j]>dsmt[i]){
	 			swap(dsmt[j],dsmt[i]);
			 }
		 }
	 } cout<<"\n danh sach may tinh giam dan gia la:\n";
	 for(int i=0;i<n;i++){
	 	dsmt[i].in();}
	 }
	 
	
 
