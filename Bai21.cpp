#include <iostream>
#include <string>
using namespace std;

class lophoc {
protected:
    string malophoc;
    string tenlophoc;

public:
    lophoc() : malophoc(""), tenlophoc("") {}
    void nhap();
    void xuat();
};

void lophoc::nhap() {
    cout << "Nhap ma lop hoc: ";
    cin >> malophoc;
    cin.ignore();
    cout << "Nhap ten lop hoc: ";
    getline(cin, tenlophoc);
}

void lophoc::xuat() {
    cout << "Ma lop hoc: " << malophoc << endl;
    cout << "Ten lop hoc: " << tenlophoc << endl;
}

class giangday : public lophoc {
private:
    string magiangvien;
    string mamonhoc;
    int sotinchi;
    static int sotietdagiang;

public:
    giangday() : magiangvien(""), mamonhoc(""), sotinchi(0) {}
    void nhap();
    void xuat();
    int sotietconlai();
    static void setsotietdagiang(int sotiet) { sotietdagiang = sotiet; }
    int getsotinchi() { return sotinchi; }
    string getmagiangvien() { return magiangvien; }
};

int giangday::sotietdagiang = 0;

void giangday::nhap() {
    lophoc::nhap();
    cout << "Nhap ma giang vien: ";
    cin >> magiangvien;
    cout << "Nhap ma mon hoc: ";
    cin >> mamonhoc;
    cout << "Nhap so tin chi: ";
    cin >> sotinchi;
}

void giangday::xuat() {
    lophoc::xuat();
    cout << "Ma giang vien: " << magiangvien << endl;
    cout << "Ma mon hoc: " << mamonhoc << endl;
    cout << "So tin chi: " << sotinchi << endl;
    cout << "So tiet con lai: " << sotietconlai() << endl;
}

int giangday::sotietconlai() {
    return sotinchi * 15 - sotietdagiang;
}

int main() {
    lophoc lh;
    cout << "Nhap thong tin lop hoc:" << endl;
    lh.nhap();
    cout << "Thong tin lop hoc:" << endl;
    lh.xuat();
    
    int n;
    cout << "Nhap so luong giang day: ";
    cin >> n;
    giangday* ds = new giangday[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin giang day thu " << i + 1 << ":" << endl;
        ds[i].nhap();
    }
    
    cout << "\nDanh sach giang day:" << endl;
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }
    
    cout << "\nLop hoc co 3 tin chi:" << endl;
    for (int i = 0; i < n; i++) {
        if (ds[i].getsotinchi() == 3) {
            ds[i].xuat();
        }
    }
    
    int min = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].sotietconlai() < ds[min].sotietconlai()) {
            min = i;
        }
    }
    
    cout << "\nGiang vien co so tiet con lai it nhat: " << ds[min].getmagiangvien() << endl;
    
}
