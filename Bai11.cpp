#include "iostream"
using namespace std;

class monhoc
{
private:
    int mamh;
    char tenmh[30];
    float dtb;
    int sotc;

public:
    monhoc()
    {
        int mamh = 0;
        char tenmh[0];
        float dtb = 0;
        int sotc = 0;
    };
    ~monhoc()
    {
        int mamh = 0;
        char tenmh[0];
        float dtb = 0;
        int sotc = 0;
    };
    void nhap1();
    void xuat1();
    int tinchi()
    {
        return sotc;
    };
    float DTB()
    {
        return dtb;
    };
};

void monhoc::nhap1()
{
    cout << "Nhap ma mon hoc:";
    cin >> mamh;
    cout << "Nhap ten mon hoc:";
    cin.ignore();
    cin.getline(tenmh, 30);
    cout << "Nhap diem TB:";
    cin >> dtb;
    cout << "Nhap so tc:";
    cin >> sotc;
}

void monhoc::xuat1()
{
    cout << "Ma mon hoc: " << mamh << endl;
    cout << "Ten mon hoc: " << tenmh << endl;
    cout << "Diem trung binh: " << DTB() << endl;
    cout << "So tin chi: " << sotc << endl;
}

class sinhvien
{
private:
    int masv;
    char tensv[30];
    int somh;
    monhoc arr[100];

public:
    sinhvien()
    {
        int masv = 0;
        char tensv[30];
        int somh = 0;
        monhoc arr[100];
    };
    ~sinhvien()
    {
        int masv = 0;
        char tensv[30];
        int somh = 0;
        monhoc arr[100];
    };
    void nhap2();
    void xuat2();
    float dtk();
};

void sinhvien::nhap2()
{
    cout << "nhap ma sinh vien:";
    cin >> masv;
    cout << "nhap ten sv:";
    cin.ignore();
    cin.getline(tensv, 30);
    cout << "nhap so luong mon hoc:";
    cin >> somh;
    for (int i = 0; i < somh; i++)
    {
        cout << "Nhap thong tin mon hoc thu: " << i+1 << endl; 
        arr[i].nhap1(); 
    }
}

void sinhvien::xuat2()
{
    cout << " Ma sinh vien: " << masv << endl;
    cout << " Ten sinh vien: " << tensv << endl;
    cout << " So luong mon hoc: " << somh << endl;
    for (int i = 0; i < somh; i++)
    {
        cout << "Thong tin mon hoc thu: " << i+1 << endl; 
        arr[i].xuat1(); 
    }
    cout << "Diem tong ket: " << dtk() << endl; 
}

float sinhvien::dtk()
{
    float dtk1 = 0;
    float tongdiem = 0;
    int tongtc = 0;
    for (int i = 0; i < somh; i++)
    {
        tongtc += arr[i].tinchi();
    }
    for (int i = 0; i < somh; i++)
    {
        tongdiem += arr[i].DTB() * arr[i].tinchi();
    }
    if(tongtc > 0){
        dtk1 = tongdiem / tongtc;
    } 
    return dtk1;
}

int main(){
    monhoc MONHOC;
    MONHOC.nhap1();
    MONHOC.xuat1();
    
    sinhvien dssv[50]; 
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    
    for(int i=0 ; i<n ; i++)
    {	
        cout << "Nhap thong tin sinh vien thu: " << i+1 << endl;
        dssv[i].nhap2(); 	
    }
    
    cout << "Danh sach sinh vien vua nhap cung voi diem tong ket: " << endl;
    for(int i=0 ; i<n ; i++)
    {	
        dssv[i].xuat2(); 	
    }
    
    cout << "Danh sach sinh vien bi hoc lai: " << endl;
    int count = 0; 
    for(int i=0 ; i<n ; i++)
    {
        if(dssv[i].dtk() < 4)
        {
            dssv[i].xuat2();
            count++; 
        }		 	
    }
    cout << "So luong sinh vien bi hoc lai: " << count << endl; 
    return 0;
}
