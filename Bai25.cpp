#include <iostream>
#include <string.h>

using namespace std;


class sinhvien{
    protected:
        string id;
        string name;
    public:
        sinhvien(): id("0"), name(""){}
        void input();
        void output();
};


void sinhvien::input(){
    cout << "Nhap ma sinh vien: ";
    getline(cin, id);
    cout << "Nhap ten sinh vien: ";
    getline(cin, name);
}

void sinhvien::output(){
    cout << "Ma sinh vien: " << id;
    cout << "Ten sinh vien: " << name;
}


class svsdh:public sinhvien{
    private:
        float money;
    public:
        void input();
        void output();
        int hocphi() {return money > 9000;}
};


void svsdh::input(){
    cin.ignore();
    sinhvien::input();
    cout << "Nhap hoc phi: ";
    cin >> money;
}

void svsdh::output(){
    sinhvien::output();
    cout << "Hoc phi: " << money;
}


int main(){
    sinhvien sv;
    sv.input();
    sv.output();

    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    svsdh sdh[n];

    for( int i = 0; i < n; i ++){
        sdh[i].input();
    }

    cout << "Danh sach sinh vien" << endl;
    for(int i = 0; i < n; i ++){
        sdh[i].output();
    }

    cout << "Danh sach sinh vien co hoc phi > 9k" << endl;
    for(int i = 0; i < n; i ++){
        if(sdh[i].hocphi()){
            sdh[i].output();
        }
    }
}

