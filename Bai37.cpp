#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class DATE {
private:
    int ngay, thang, nam;
public:
    DATE() : ngay(1), thang(1), nam(2000) {}
    void nhap();
    void xuat();
};

void DATE::nhap() {
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
}

void DATE::xuat() {
    cout << setw(2) << ngay << "/" 
         << setw(2) << thang << "/" 
         << setw(4) << nam;
}

class CANBO {
private:
    string maCB;
    string tenCB;
    float luongCoBan;
    DATE ngaySinh; 
    static float phuCap;
public:
    CANBO() : maCB(""), tenCB(""), luongCoBan(0) {}
    void nhap();
    void xuat();
    float tinhLuong();
    string getTenCB();
};

float CANBO::phuCap = 500000;

void CANBO::nhap() {
    cout << "Nhap ma can bo: ";
    cin >> maCB;
    cin.ignore();  
    cout << "Nhap ho ten: ";
    getline(cin, tenCB);
    ngaySinh.nhap();
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
}

void CANBO::xuat() {
    cout << left << setw(8) << maCB
         << setw(15) << tenCB;
    ngaySinh.xuat();
    cout << "   ";  
    cout << setw(12) << fixed << setprecision(0) << luongCoBan
         << setw(12) << fixed << setprecision(0) << tinhLuong() << endl;
}

float CANBO::tinhLuong() {
    return luongCoBan + phuCap;
}

string CANBO::getTenCB() {
    return tenCB;
}

int main() {
	 DATE date;
    cout << "\nNhap thong tin ngay thang nam:\n";
    date.nhap();
    cout << "Ngay thang nam vua nhap: ";
    date.xuat();
    cout << endl;
	
    int n;
    cout << "\nNhap so luong can bo: ";
    cin >> n;
    CANBO dscanbo[20];

    for (int i = 0; i < n; i++) {
        cout << "\nNhap can bo thu " << i + 1 << ":\n";
        dscanbo[i].nhap();
    }

    cout << "\nDanh sach can bo vua nhap:\n";
    cout << left << setw(8) << "Ma CB"
         << setw(15) << "Ho Ten"
         << setw(15) << "Ngay Sinh"
         << setw(12) << "Luong CB"
         << setw(12) << "Luong Thuc" << endl;
    cout << "---------------------------------------------------------------\n";
    
    for (int i = 0; i < n; i++) {
        dscanbo[i].xuat();
    }

    cout << "\nLuong cua cac can bo:\n";
    for (int i = 0; i < n; i++) {
        cout << "Can bo: " << dscanbo[i].getTenCB() 
             << " - Luong: " << fixed << setprecision(0) 
             << dscanbo[i].tinhLuong() << endl;
    }

    float minLuong = dscanbo[0].tinhLuong();
    for (int i = 1; i < n; i++) {
        if (dscanbo[i].tinhLuong() < minLuong) {
            minLuong = dscanbo[i].tinhLuong();
        }
    }

    cout << "\nCan bo co luong thap nhat:\n";
    for (int i = 0; i < n; i++) {
        if (dscanbo[i].tinhLuong() == minLuong) {
            cout << dscanbo[i].getTenCB() << endl;
        }
    }

    return 0;
}

