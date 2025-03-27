#include <iostream>
#include <iomanip>
#include <string>


using namespace std;



class date {
protected:
    int dd, mm, yyyy;
public:
    date() : dd(1), mm(1), yyyy(2000) {}
    void input();
    void output();
};


void date::input() {
    cout << "Nhap ngay: "; cin >> dd;
    cout << "Nhap thang: "; cin >> mm;
    cout << "Nhap nam: "; cin >> yyyy;
}



void date::output() {
    cout << setw(7) << dd << "/"
         << setw(2) << mm << "/"
         << setw(4)<< yyyy;
}





class canbo : public date {
private:
    string id, name;
    float luongcb;
    static float phucap;
public:
    void input();
    void output();
    float tinhluong();
    string layten() { return name; }
    float layluong() { return tinhluong(); }
};




float canbo::phucap = 500;

void canbo::input() {
    cin.ignore();
    cout << "Nhap ma can bo: ";
    getline(cin, id);
    cout << "Nhap ten can bo: ";
    getline(cin, name);
    cout << "Nhap ngay sinh:\n";
    date::input();
    cout << "Nhap luong co ban: ";
    cin >> luongcb;
}



void canbo::output() {
    cout << setw(10) << id
         << setw(25) << name;
    date::output();
    cout << setw(15) << fixed << setprecision(2) << luongcb
         << setw(15) << tinhluong() << endl;
}

float canbo::tinhluong() {
    return luongcb + phucap;
}

int main() {
    date cal;
    cout << "Nhap ngay thang nam:\n";
    cal.input();
    cout << "Ngay thang nam vua nhap: ";
    cal.output();
    cout << endl;

    int n;
    cout << "\nNhap so luong can bo: ";
    cin >> n;
    canbo dscb[1000];

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin can bo thu " << i + 1 << ":\n";
        dscb[i].input();
    }

    cout << "\nDANH SACH CAN BO\n";
    cout << setw(10) << "Ma CB"
         << setw(25) << "Ten CB"
         << setw(15) << "Ngay sinh"
         << setw(15) << "Luong CB"
         << setw(15) << "Luong nhan" << endl;
    for (int i = 0; i < n; i++) {
        dscb[i].output();
    }

    cout << "\nDANH SACH LUONG\n";
    for (int i = 0; i < n; i++) {
        cout << dscb[i].layten() << ": " << dscb[i].layluong() << " VND" << endl;
    }

    float minLuong = dscb[0].layluong();
    for (int i = 1; i < n; i++) {
        if (dscb[i].layluong() < minLuong) {
            minLuong = dscb[i].layluong();
        }
    }

    cout << "\nDANH SACH CAN BO CO LUONG THAP NHAT\n";
    for (int i = 0; i < n; i++) {
        if (dscb[i].layluong() == minLuong) {
            cout << dscb[i].layten() << endl;
        }
    }

    return 0;
}
