#include <iostream>
#include <string>

using namespace std;

class book{
    protected:
        string id;
        string name;
    public:
        book(): id(""), name(""){};
        void input();
        void output();
};

void book::input(){
    cout << "Nhap ma sach: ";
    getline(cin, id);
    cout << "Nhap ten sach: ";
    getline(cin, name);
}


void book::output(){
    cout << "Ma sach: " << id << endl;
    cout << "Ten sach: " << name << endl;
};


class muontra:public book{
    private: 
        string madocgia;
        int soluong;
        float phicuoc = 500;
    public:
        muontra(): madocgia(""), book(), soluong(0){}
        void input();
        void output();
        float tinhtien(){
            return soluong*phicuoc;
        }

        float muon10(){
            return soluong >10;
        }
};

void muontra::input(){
    cin.ignore();
    cout << "Nhap ma doc gia: ";
    getline(cin, madocgia);
    book::input();
    cout << "Nhap so luong: ";
    cin >> soluong;
}

void muontra::output(){
    cout << "Ma doc gia: " << madocgia << endl;
    book::output();
    cout << "So luong: " << soluong << endl;
    cout << "Tien phai tra: " << tinhtien() << endl;

}

int main(){
    book book;
    book.input();
    book.output();

    int n;
    cout << "Nhap so luong nguoi muon: ";
    cin >> n;

    muontra muontra[1000];

    for(int i = 0; i < n; i ++){
        muontra[i].input();
    }

    cout << "Danh sach nguoi muon tra: " << endl;
    for(int i = 0; i < n; i ++){
        muontra[i].output();
    }

    cout << "Danh sach nguoi muon > 10 cuon la: " << endl;
    for(int i = 0; i < n; i ++){
        if(muontra[i].muon10()){
            muontra[i].output();
        }
    }

    cout << "Nguoi muon co so tien nhieu nhat la: " << endl;
    float high = muontra[0].tinhtien();
    int index;
    for(int i = 0; i < n; i ++){
        if(high < muontra[i].tinhtien()){
            high = muontra[i].tinhtien();
            index = i;
        }
    }
    muontra[index].tinhtien();


}