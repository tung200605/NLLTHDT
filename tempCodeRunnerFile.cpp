#include <iostream>
#include <string>

using namespace std;

class hocvien{
    protected:
        string id;
        string name;
    public:
        hocvien() : id(""), name("") {}
        void input();
        void output();
        ~hocvien();
};


void hocvien::input(){
    cout << "Nhap ma hoc vien: ";
    getline(cin, id);
    cout << "Nhap ten hoc vien: ";
    getline(cin, name);
}


void hocvien::output(){
    cout << "Ma hoc vien: " << id << endl;
    cout << "Ten hoc vien: " << name << endl;
}

class hvcntt:public hocvien{
    protected:
        float mark;
    public:
        hvcntt(): hocvien(), mark(0) {}
        void input();
        void output();
        void range(hvcntt ai[1000], int n);
        bool operator <(hvcntt& other){
            return this->mark < other.mark;
        }

};

void hvcntt::input(){
    cin.ignore();
    hocvien::input();
    cout << "Nhap diem cua sinh vien: ";
    cin >> mark;
}

void hvcntt::output(){
    hocvien::output();
    cout << "Diem cua sinh vien: " << mark << endl;
}

int main(){
    hocvien hv;
    hv.input();
    hv.output();

    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    hvcntt cntt[1000];

    for(int i = 0; i < n; i ++){
        cntt[i].input();
    }

    cout << "Danh sach sinh vien " << endl;
    for(int i = 0; i < n; i ++){
        cntt[i].output();
    }

    cntt[1000].range(&cntt[1000], n);
    cout << "Danh sach sinh vien sap xep theo thu tu diem giam dan" << endl;
    for(int i = 0; i < n; i ++){
        cntt[i].output();
    }


}