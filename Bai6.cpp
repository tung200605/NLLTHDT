#include <iostream>
#include <string>

using namespace std;

class sinhvien {
protected:
    string id;
    string name;
public:
    sinhvien() : id(""), name("") {}
    ~sinhvien() {}
    void input();
    void output();
};

void sinhvien::input() {
    cin.ignore();
    cout << "Nhap ma sinh vien: ";
    getline(cin, id);
    cout << "Nhap ten sinh vien: ";
    getline(cin, name);
}

void sinhvien::output() {
    cout << "Ma sinh vien: " << id <<endl;
    cout << "Ten sinh vien: " << name << endl;
}

class svsdh : public sinhvien {
private:
    float hocphi;
public:
    svsdh() : sinhvien(), hocphi(0) {}
    ~svsdh() {}
    void input();
    void output();
    bool money() {
        return hocphi > 9000;
    }
};

void svsdh::input() {
    sinhvien::input();
    cout << "Nhap hoc phi: ";
    cin >> hocphi;
}

void svsdh::output() {
    sinhvien::output();
    cout << "Hoc phi: " << hocphi << endl;
}

int main() {
    sinhvien sinhvien;
    sinhvien.input();
    sinhvien.output();

    int n;
    cout << "Nhap so luong sinh vien sau dai hoc: ";
    cin >> n;

    svsdh svl[100];
    for (int i = 0; i < n; i++) {
        svl[i].input();
    }

    cout << "Danh sach sinh vien:\n";
    for (int i = 0; i < n; i++) {
        svl[i].output();
    }

    cout << "\nDanh sach sinh vien co hoc phi > 9000:\n";
    for (int i = 0; i < n; i++) {
        if (svl[i].money()) {
            svl[i].output();
        }
    }
}
