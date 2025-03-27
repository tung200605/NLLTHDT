#include <iostream>
#include <string>

using namespace std;

class hanghoa {
protected:
    int id;
     string name;

public:
    void input();
    void output();
};


void hanghoa::input() {
    cout << "Nhap ma hang: ";
    cin >> id;
    cout << "Nhap ten hang: ";
    cin.ignore();
    getline(cin, name);
}

void hanghoa::output() {
    cout << "Ma hang: " << id << endl;
    cout << "Ten hang: " << name << endl;
}


class maytinh : public hanghoa {
private:
    string nsx;
    int year;
    float gianiemyet;
    static float giamgia;

public:
    maytinh() : nsx(""), year(0), gianiemyet(0.0) {}

    void input();
    void output();
    double gia() ;
    
    static void setgiamgia(double rate) {
        giamgia = rate;
    }

    bool samsung();
};

float maytinh::giamgia = 0.1;
bool maytinh::samsung(){
    return (name == "SAMSUNG");}

void maytinh::input(){
    hanghoa::input();
    cout << "Nhap nha san xuat: ";
    cin.ignore();
    getline(cin, nsx);
    cout << "Nhap nam san xuat: ";
    cin >> year;
    cout << "Nhap gia niem yet: ";
    cin >> gianiemyet;
}

void maytinh::output() {
    hanghoa::output();
    cout << "Nha san xuat: " << nsx << endl;
    cout << "Nam san xuat: " << year << endl;
    cout << "Gia niem yet: " << gianiemyet << endl;
    cout << "Gia thuc: " << gia() << endl;
}

double maytinh::gia() {
    return gianiemyet - (gianiemyet * giamgia);
}


int main(){
    hanghoa hh;
    hh.input();
    hh.output();

    int n;
    cout << "Nhap so luong may tinh: ";
    cin >> n;

    maytinh mt[n];
    for( int i = 0; i < n; i ++){
        mt[i].input();
    }

    cout << "Danh sach may tinh" << endl;
    for(int i = 0; i < n; i ++){
        mt[i].output();
    }

    cout << "Danh sach may sam sung" << endl;
    for( int i = 0; i < n; i ++){
        if(mt[i].samsung()){
            mt[i].output();
        }
    }


    int min = 0;
    for (int i = 1; i < n; i++) {
        if (mt[i].gia() < mt[min].gia()) {
            min = i;
        }
    
    cout << "May tinh co gia ban thuc te thap nhat: " << endl;
    mt[min].output();
    }
}