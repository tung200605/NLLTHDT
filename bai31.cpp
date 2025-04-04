#include <iostream>
#include <string>
using namespace std;

class nhanvien {
protected:
    string manv;
    string hoten;
    int tuoi;

public:
    nhanvien() : manv(""), hoten(""), tuoi(0) {} //ham khoi tao 
    void nhap();
    void xuat();
    bool vehuu();
};

void nhanvien::nhap() {
    cout << "Nhap ma nhan vien: ";
    cin >> manv;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
}

void nhanvien::xuat() {
    cout << "Ma NV: " << manv << endl;
    cout << "Ho ten: " << hoten << endl;
    cout << "Tuoi: " << tuoi << endl;
}

bool nhanvien::vehuu() {
    return tuoi >= 60;
}

class canbo : public nhanvien {
private:
    float hesoluong;
    float phucap;
    string trinhdo;

public:
    canbo() : hesoluong(0), phucap(0), trinhdo("") {}
    void nhap();
    void xuat();
    float tinhluong();
};

void canbo::nhap() {
    nhanvien::nhap();
    cout << "Nhap he so luong: ";
    cin >> hesoluong;
    cout << "Nhap phu cap: ";
    cin >> phucap;
    cin.ignore();
    cout << "Nhap trinh do: ";
    getline(cin, trinhdo);
}

void canbo::xuat() {
    nhanvien::xuat();
    cout << "He so luong: " << hesoluong << endl;
    cout << "Phu cap: " << phucap << endl;
    cout << "Trinh do: " << trinhdo << endl;
    cout << "Luong: " << tinhluong() << endl;
}
/*
float canbo::tinhluong() {
    float luong = hesoluong * 1550 + phucap;
    return vehuu() ? luong * 0.7 : luong;
} */

float canbo::tinhluong(){
	float luong = hesoluong*1550 + phucap; 
	if(vehuu()){
		luong = luong*0.7; // giam 30% neu can bo da ve huu 
	}
	return luong; 
}

int main() {
    nhanvien nv;
    cout << "Nhap thong tin cua mot nhan vien" << endl;
    nv.nhap();
    cout << "Thong tin nhan vien vua nhap" << endl;
    nv.xuat();
    
    int n;
    cout << "Nhap so luong can bo: ";
    cin >> n;
    canbo dscb[100];
    
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin can bo thu: " << i + 1 << endl;
        dscb[i].nhap();
    }
    
    cout << "Danh sach can bo cung voi luong: " << endl;
    for (int i = 0; i < n; i++) {
        dscb[i].xuat();
    }
    
    cout << "Danh sach can bo chua ve huu cung voi luong: " << endl;
    for (int i = 0; i < n; i++) {
        if (!dscb[i].vehuu() && dscb[i].tinhluong()){
            dscb[i].xuat();
        }
    }
    
}
