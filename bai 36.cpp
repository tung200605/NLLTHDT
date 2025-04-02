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
cout<<left<<setw(10)<<mahang<<setw(20)<<tenhang;
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
 		int samsung(){
 			return nsx=="SAMSUNG";
		 }
		 string getnsx(){return nsx;
		 }
 		
	 	
 };
 float maytinh::tlkm=0.035;
 void maytinh::nhap(){
 	hanghoa::nhap();
 	cin.ignore();
 	cout<<"nhap nha san xuat:";
 	getline(cin,nsx);
 	cout<<"nhap nam san xuat:";
 	cin>>namsx;
 	cout<<"nhap gia ban niem yet:";
 	cin>>gia;
 	
 }
 void maytinh::in(){
 	hanghoa::in();
 	cout<<left<<setw(15)<<nsx<<setw(10)<<namsx<<setw(15)<<fixed<<setprecision(2)<<giaban()<<endl; 
	 }
 	
 int main(){
 	hanghoa h;
 	cout<<"nhap thong tin mot hang hoa:\n";
 	h.nhap();
 	cout<<"\nthong tin da nhap la:\n";
 	cout<<left<<setw(10)<<"ma hang"<<setw(20)<<"ten hang"<<endl;
 	cout<<string(30,'-')<<endl;
 	h.in();
 	cout<<endl;
 	int n;
 	cout<<"nhap so luong may tinh:";
 	cin>>n;
 	maytinh dsmt[20];
 	for(int i=0;i<n;i++){
 		cout<<"\nnhap thong tin may tinh thu"<<i+1<<":\n";
 		dsmt[i].nhap();
	 }
	 cout<<"\ndanh sach may tinh vua nhap la\n";
	 cout << left << setw(10) << "Ma hang" << setw(20) << "Ten hang"
         << setw(15) << "Nha san xuat" << setw(10) << "Nam sx"
         << setw(15) << "Gia ban thuc te" << endl;
         cout << string(70, '-') << endl;
	 for(int i=0;i<n;i++){
	 	dsmt[i].in();
	 }
	 cout<<"danh sach cac may tinh samsung la:\n";
	 cout << left << setw(10) << "Ma hang" << setw(20) << "Ten hang"
         << setw(15) << "Nha san xuat" << setw(10) << "Nam sx"
         << setw(15) << "Gia ban thuc te" << endl;
         cout << string(70, '-') << endl;
	 for(int i=0;i<n;i++){
	 	if(dsmt[i].samsung()){
	 		dsmt[i].in();
		 }
	 }
	 float mingia=dsmt[0].giaban();
	 for(int i=0;i<n;i++){
	 	if(dsmt[i].giaban()<mingia){
	 		mingia=dsmt[i].giaban();
		 }
	 }
	 cout<<"may tinh co gia ban thuc te thap nhat la:\n";
	 for(int i=0;i<n;i++){
	 	if(dsmt[i].giaban()==mingia){
	 		cout<<dsmt[i].getnsx()<<endl;}}
			 return 0;}
	 
 
