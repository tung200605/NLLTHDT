#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<iostream> 
using namespace std;
class ptgt{
	protected:
	string hsx;
	string tpt;
	int nsx;
	float vt;
	public:
		void nhap();
		void in();
		string gethsx(){return hsx;
		}
	
};
void ptgt::nhap(){
	cout<<"hang san xuat:";
	cin>>hsx;
	cin.ignore();
	cout<<"ten phuong tien:";
	getline(cin,tpt);
	cout<<"nam san xuat:";
	cin>>nsx;
	cout<<" van toc toi da:";
	cin>>vt;
}
void ptgt::in(){
	cout<<setw(15)<<hsx<<setw(15)<<tpt<<setw(6)<<nsx<<setw(10)<<vt;
}
class oto:public ptgt{
	protected:
		int chongoi;
		string kdc;
		public:
			void nhap();
			void in();
			float vtcs();
			
		
};
void oto::nhap(){
ptgt::nhap();
cout<<"so cho ngoi:";
cin>>chongoi;
cin.ignore();
cout<<"kieu dong co:";
getline(cin,kdc);
}
void oto::in(){
	
	ptgt::in(); 
	cout<<setw(12)<<chongoi<<setw(18)<<kdc<<setw(12)<<vtcs()<<endl;
}
float oto::vtcs(){
	return vt/4;
}
int main(){
	cout<<"nhap thong tin phuong tien:\n";
	ptgt p;
	p.nhap();
	cout<<"thong tin da nhap la:\n";
	cout<<left<<setw(15)<<"hang san xuat"
              <<setw(15)<<"ten pt"	        
	          <<setw(6)<<"nsx"
	          <<setw(10)<<"van toc"<<endl;
			  cout<<string(50,'-')<<endl; 
	p.in();
	int n;
	cout<<"\nnhap so luong oto:";
	cin>>n;
	oto dsoto[20];
	for(int i=0;i<n;i++){
		dsoto[i].nhap();
	}
	cout<<"\n danh sach o to vua nhap la:\n";
	cout<<left<<setw(15)<<"hang san xuat"
	           <<setw(15)<<"ten pt"
	          <<setw(6)<<"nsx"
	          <<setw(10)<<"van toc"
	          <<setw(12)<<"so cho ngoi"
	          <<setw(18)<<"kieu dong co"
	          <<setw(12)<<"van toc co so"<<endl;
	cout<<string(80,'-')<<endl;
	for (int i=0;i<n;i++){
		dsoto[i].in();
	}
	cout<<"danh sach cac doi tuong oto giam dan la:\n";
	for (int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(dsoto[i].vtcs()<dsoto[j].vtcs()){
				oto tmp=dsoto[i];
				dsoto[i]=dsoto[j];
				dsoto[j]=tmp;
			}
		}
	}
	cout<<left<<setw(15)<<"hang san xuat"
	           <<setw(15)<<"ten pt"
	          <<setw(6)<<"nsx"
	          <<setw(10)<<"van toc"
	          <<setw(12)<<"so cho ngoi"
	          <<setw(18)<<"kieu dong co"
	          <<setw(12)<<"van toc co so"<<endl;
	cout<<string(80,'-')<<endl;
	for (int i=0;i<n;i++){
		dsoto[i].in();}}


