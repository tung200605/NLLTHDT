#include <iostream>
#include <string>

using namespace std;

class dichvu {
private:
    string madv;
    string tendv;
    double giacuoc;

public:
    dichvu() : madv(""), tendv(""), giacuoc(0) {}

    void nhap() {
        cout << "nhap ma dich vu: ";
        cin >> madv;
        cout << "nhap ten dich vu: ";
        getline(cin, tendv);
        cout << "nhap gia cuoc: ";
        cin >> giacuoc;
    }

    void xuat() {
        cout << "ma dv: " << madv << endl;
        cout << "ten dv: " << tendv << endl;
        cout << "gia cuoc: " << giacuoc << endl;
    }

    double laygiacuoc(){
         return giacuoc;
    }
};

class nguoi {
private:
    string hoten;
    string diachi;
    string sodt;

public:
    nguoi() : hoten(""), diachi(""), sodt("") {}

    void nhap() {
        cin.ignore();
        cout << "nhap ho ten: ";
        getline(cin, hoten);
        cout << "nhap dia chi: ";
        getline(cin, diachi);
        cout << "nhap so dien thoai: ";
        getline(cin, sodt);
    }

    void xuat() {
        cout << "ho ten: " << hoten << endl;
        cout << "dia chi: " << diachi << endl;
        cout << "so dt: " << sodt << endl;
    }
};

class khachhang : public nguoi {
private:
    int soluongdichvu;
    dichvu dv[100];

public:
    khachhang() : soluongdichvu(0) {}

    void nhap() {
        nguoi::nhap();
        cout << "nhap so luong dich vu da su dung: ";
        cin >> soluongdichvu;
        for (int i = 0; i < soluongdichvu; ++i) {
            cout << "nhap thong tin dich vu thu " << i + 1 << ":" << endl;
            dv[i].nhap();
        }
    }

    void xuat() {
        nguoi::xuat();
        cout << "so luong dich vu da su dung: " << soluongdichvu << endl;
        for (int i = 0; i < soluongdichvu; ++i) {
            cout << "thong tin dich vu thu " << i + 1 << ":" << endl;
            dv[i].xuat();
        }
    }

    double tonggiacuoc() {
        double tong = 0.0;
        for (int i = 0; i < soluongdichvu; ++i) {
            tong += dv[i].laygiacuoc();
        }
        return tong;
    }
};

int main() {
    nguoi nguoi;
    nguoi.nhap();
    nguoi.xuat();

    khachhang khachhang;
    khachhang.nhap();

    khachhang.xuat();

    cout << "\ntong gia cuoc khach hang da su dung: " << khachhang.tonggiacuoc() << endl;

}