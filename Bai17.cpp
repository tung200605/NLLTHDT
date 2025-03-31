#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class monhoc {
private:
    string mamonhoc;
    string tenmonhoc;
public:
    void input();
    void output();
};

void monhoc::input() {
    cout << "nhap ma mon hoc: ";
    cin.ignore();
    getline(cin, mamonhoc);
    cout << "nhap ten mon hoc: ";
    getline(cin, tenmonhoc);
}

void monhoc::output() {
    cout << "ma mon hoc: " << mamonhoc << " - ten mon hoc: " << tenmonhoc << endl;
}

class giangday : public monhoc {
private:
    string magiangvien;
    string malop;
    int sotinchi;
    static int sotietdagiangday;
public:
    void input();
    void output();
    int tinhsotietconlai() { return sotinchi * 15 - sotietdagiangday; }
    static void setsotietdagiangday(int tiet) { sotietdagiangday = tiet; }
};

int giangday::sotietdagiangday = 0;

void giangday::input() {
    monhoc::input();
    cout << "nhap ma giang vien: ";
    getline(cin, magiangvien);
    cout << "nhap ma lop: ";
    getline(cin, malop);
    cout << "nhap so tin chi: ";
    cin >> sotinchi;
    cin.ignore();
}

void giangday::output() {
    monhoc::output();
    cout << "ma giang vien: " << magiangvien << " - ma lop: " << malop << " - so tin chi: " << sotinchi << " - so tiet con lai: " << tinhsotietconlai() << endl;
}

int main() {
    monhoc mon;
    cout << "nhap thong tin mot mon hoc:" << endl;
    mon.input();
    cout << endl << "thong tin mon hoc:" << endl;
    mon.output();

    int n;
    cout << endl << "nhap so luong giang day: ";
    cin >> n;
    cin.ignore();
    giangday ds[n];
    
    for (int i = 0; i < n; i++) {
        cout << endl << "nhap thong tin giang day thu " << i + 1 << ":" << endl;
        ds[i].input();
    }

    cout << endl << "danh sach giang day:" << endl;
    for (int i = 0; i < n; i++) {
        ds[i].output();
    }

    cout << endl << "cac mon hoc co 3 tin chi:" << endl;
    for (int i = 0; i < n; i++) {
        if (ds[i].tinhsotietconlai() / 15 == 3) {
            ds[i].output();
        }
    }

    int mintietconlai = ds[0].tinhsotietconlai();
    for (int i = 1; i < n; i++) {
        if (ds[i].tinhsotietconlai() < mintietconlai) {
            mintietconlai = ds[i].tinhsotietconlai();
        }
    }

    cout << endl << "giang vien co so tiet con lai it nhat:" << endl;
    for (int i = 0; i < n; i++) {
        if (ds[i].tinhsotietconlai() == mintietconlai) {
            ds[i].output();
        }
    }
    
    return 0;
}
