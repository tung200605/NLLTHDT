#include <iostream>
#include <string.h>

using namespace std;

class nguoi{
    protected:
        string name;
        string gender;
        int year;
    public:
        void input();
        void output();
        int age();
};


void nguoi::input(){
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap gioi tinh: ";
    cin.ignore();
    getline(cin,gender);
    cout << "Nhap nam sinh: ";  cin >> year;
}

void nguoi::output(){
    cout << "Ten: " << name << endl;
    cout << "Gioi tinh: " << gender << endl;
    cout << "Nam sinh: " << year << endl;
}

int nguoi::age(){
    return 2020 - year;
}

class nhanvien:public nguoi{
    private:
        int hesothamnien;
        float mucluong;
        float tienanca;
        float luong;
    public:
        void input();
        void output();
        void tinhluong();
        bool nghihuu();
        float getluong();
};

void nhanvien::input(){
    nguoi::input();
    cout << "Nhap he so tham nien: "; cin >> hesothamnien;
    cout << "Nhap muc luong: "; cin >> mucluong;
    cout << "Nhap tien an ca: "; cin >> tienanca;
}

void nhanvien::output(){
    nguoi::output();
    cout << "He so tham nien: " << hesothamnien << endl;
    cout << "Muc luong: " << mucluong << endl;
    cout << "Tien an ca: " << tienanca << endl;
}

bool nhanvien::nghihuu(){
    return age() >= 60;
};

void nhanvien::tinhluong(){
    if (nghihuu())
    {
        luong = 0.75 * mucluong + hesothamnien;
    }
    else{
        luong = mucluong*hesothamnien + tienanca;
    }
    }
float nhanvien::getluong(){
    return luong;
}

int main(){
    nguoi ng;
    ng.input();
    ng.output();

    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    nhanvien nv[1000];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin nhan vien thu " << i+1 << endl;
        nv[i].input();
    }
    for(int i = 0; i < n; i ++){
        nv[i].output();
        nv[i].tinhluong();
        cout << "Luong: " << nv[i].getluong() << endl;
        }

        cout << "Danh sach nhan vien den tuoi nghi huu" << endl;
        for(int i = 0; i < n; i++){
        if(nv[i].nghihuu()){
            nv[i].output();
            nv[i].tinhluong();
            cout << "Luong: " << nv[i].getluong() << endl;
        }
    }



}