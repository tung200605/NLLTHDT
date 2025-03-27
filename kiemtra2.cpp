#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class hocvien {
protected:
    string id;
    string name;
public:
    hocvien() : id(""), name("") {}
    void input();
    void output();
};

void hocvien::input() {
    cout << "Nhap ma hoc vien: ";
    cin.ignore(); 
    getline(cin, id);
    cout << "Nhap ten hoc vien: ";
    getline(cin, name);
}

void hocvien::output() {
    cout << "Ma hoc vien: " << id << endl;
    cout << "Ten hoc vien: " << name << endl;
}

class hvcntt : public hocvien {
protected:
    float mark;
public:
    hvcntt() : hocvien(), mark(0) {}
    void input();
    void output();
    void range(hvcntt cntt[], int n);
    bool operator<(const hvcntt& other) {
        return this->mark > other.mark; 
    }
};

void hvcntt::input() {
    cin.ignore();
    hocvien::input();
    cout << "Nhap diem cua sinh vien: ";
    cin >> mark;
}

void hvcntt::output() {
    hocvien::output();
    cout << "Diem cua sinh vien: " << mark << endl;
}

void hvcntt::range(hvcntt hvcntt[1000], int n){
    for(int i = 0; i < n - 1; i ++){
        for( int j = i + 1; j < n; j ++){
            if(hvcntt[i].mark < hvcntt[j].mark){
                swap(hvcntt[i], hvcntt[j]);
            }
        }
    }

}

int main() {
    hocvien hv;
    hv.input();
    hv.output();
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    hvcntt cntt[1000];

    for (int i = 0; i < n; i++) {
        cntt[i].input();
    }

    cout << "Danh sach sinh vien truoc khi sap xep:" << endl;
    for (int i = 0; i < n; i++) {
        cntt[i].output();
    }

    cntt[0].range(cntt, n);

    cout << "Danh sach sinh vien sau khi sap xep theo diem giam dan:" << endl;
    for (int i = 0; i < n; i++) {
        cntt[i].output();
    }

    return 0;}
