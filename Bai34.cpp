#include <iostream>
#include <string.h>

using namespace std;

class sach{
    protected:
        string masach;
        string tensach;
    public:
        sach() : masach(""), tensach("")  {}
        void nhap();
        void xuat();
};


void sach::nhap(){
    cout << "Nhap ma sach: ";
    getline(cin, masach);
    cout << "Nhap ten sach: ";
    getline(cin, tensach);
}

void sach::xuat(){
    cout << "Ma sach: " << masach << endl;
    cout << "Ten sach: " << tensach << endl;
}

class muontra:public sach{
    private:
        string madocgia;
        int soluong;
        float cuoc = 500;
    public:
        muontra() : madocgia(""), sach(), soluong(0) {}
        void nhap();
        void xuat();
        float tinhtien() {return soluong * cuoc;}
        int muon() {return soluong > 10;}
};

void muontra::nhap(){
    cin.ignore();
    cout << "Nhap ma doc gia: ";
    getline(cin, madocgia);
    sach::nhap();
    cout << "Nhap so luong: ";
    cin >> soluong;
}

void muontra::xuat(){
    cout << "Ma doc gia: " << madocgia;
    sach::xuat();
    cout << "So luong: " << soluong;
    cout << "Tong tien: " << tinhtien();

}

int main(){
    sach s;
    s.nhap();
    s.xuat();
    muontra mt[1000];

    int n;
    cout << "Nhap so luong nguoi muon tra: ";
    cin >> n;

    for( int i = 0; i < n; i++){
        mt[i].nhap();
    }

    cout << endl << "Danh sach nguoi muon tra " << endl;
    for( int i = 0; i < n; i++){
        mt[i].xuat();
    }

    cout << endl << "Danh sach nguoi muon hon 10 cuon" << endl;
    for( int i = 0; i < n; i++){
        if(mt[i].muon()){
            mt[i].xuat();
        }
    }

    float max = mt[0].tinhtien();
    int vitri;
    for(int i = 0; i < n; i ++){
        if( max < mt[i].tinhtien()){
            max = mt[i].tinhtien();
            vitri = i;
        }
    }

    cout << "Doc gia nhieu tien" << endl;
        mt[vitri].xuat();


}


