#include <iostream>
#include <string>

using namespace std;

class sinhvien{
    protected:
        string id;
        string name;
    public:
        sinhvien(): id(""), name("") {}
        ~sinhvien() {}
        void input();
        void output();
};

void sinhvien::input(){
    cout << "Nhap id: ";
    cin >> id;
    cout << "Nhap ten: ";
    getline(cin, name);
}

void sinhvien::output(){
    cout << "ID: " << id << endl;
    cout << "Ten: " << name << endl;
}
