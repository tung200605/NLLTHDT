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
        char tenmh[30];
        float dtb = 0;
        int sotc = 0;
    };
    ~monhoc()
    {
        int mamh = 0;
        char tenmh[30];
        float dtb = 0;
        int sotc = 0;
    };
    void nhap1();
    void xuat1();
    int tinchi()
    {
        return sotc;
    };
    int DTB()
    {
        return dtb;
    };
};
void monhoc::nhap1()
{
    cout << "nhap ma mon hoc:";
    cin >> mamh;
    cout << "nhap ten mon hoc:";
    cin.ignore();
    cin.getline(tenmh, 30);
    cout << "nhap diem TB:";
    cin >> dtb;
    cout << "nhap so tc:";
    cin >> sotc;
}
void monhoc::xuat1()
{
    cout << "ma mon hoc la:" << mamh << endl;
    cout << "ten mon hoc la:" << tenmh << endl;
    cout << "diem tb la:" << dtb << endl;
    cout << "so tc  la:" << sotc << endl;
}
class sinhvien : public monhoc
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
        arr[i].monhoc::nhap1();
    }
}
void sinhvien::xuat2()
{
    cout << " ma sinh vien la:" << masv << endl;
    cout << " ten sv la:" << tensv << endl;
    cout << "so luong mon hoc la:" << somh << endl;
    for (int i = 0; i < somh; i++)
    {
        arr[i].monhoc::xuat1();
    }
}
float sinhvien::dtk()
{
    float dtk1 = 0;
    float tongdiem;
    int tongtc = 0;
    for (int i = 0; i < somh; i++)
    {
        tongtc += arr[i].tinchi();
    }
    for (int i = 0; i < somh; i++)
    {
        tongdiem += arr[i].DTB() * arr[i].tinchi();
    }
    dtk1 = tongdiem / tongtc;
    return dtk1;
}
