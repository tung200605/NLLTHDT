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
    cout << "Nhap ho ten sinh vien: ";
    getline(cin, name);
}

void sinhvien::output() {
    cout << "Ma sinhvien: " << id << endl;
    cout << "Ho Ten: " << name << endl;
}

class svcnpm : public sinhvien {
private:
    float dtb;
public:
    svcnpm() : sinhvien(), dtb(0) {}
    ~svcnpm() {}
    void input();
    void output();
    bool diem() {
        return dtb >= 8.5;
    }
};

void svcnpm::input() {
    sinhvien::input();
    cout << "Nhap diem trung binh: ";
    cin >> dtb;
}

void svcnpm::output() {
    sinhvien::output();
    cout << "Diem trung binh: " << dtb << endl;
}

int main() {
    sinhvien sv;
    sv.input();
    sv.output();

    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    svcnpm svc[100];
    for (int i = 0; i < n; i++) {
        svc[i].input();
    }

    cout << "\nDanh sach sinh vien chuyen nganh cong nghe phan mem:\n";
    for (int i = 0; i < n; i++) {
        svc[i].output();
    }

    cout << "\nDanh sach sinh vien co diem trung binh >= 8.5:\n";
    for (int i = 0; i < n; i++) {
        if (svc[i].diem()) {
            svc[i].output();
        }
    }
    return 0;
}
