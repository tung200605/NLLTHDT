#include <iostream>
#include <string.h>

using namespace std;


class media{
    protected:
        string name;
        float price;
    public:
        void input();
        void output();

};


void media::input() {
    cin.ignore();
    cout << "Nhap ten sach/bang video: ";
    getline(cin, name);
    cout << "Nhap gia ban: ";
    cin >> price;
}

void media::output(){
    cout << "Ten sach/bang video: " << name << endl;
    cout << "Gia ban: " << price << endl;
}

class book:public media{
    private:
        int page;
        string auth;
    public:
        void input();
        void output();
        int filter();
};

void book::input(){
    media::input();
    cout << "Nhap so trang: ";
    cin >> page;
    cout << "Nhap tac gia: ";
    getline(cin, auth);
    cin.ignore();
}

void book::output(){
    media::output();
    cout << "So trang: " << page << endl;
    cout << "Tac gia: " << auth << endl;
}

int book::filter(){
    return (name == "LAP TRINH C" && auth == "NGUYEN THANH THUY");
}


int main(){
    media m;
    m.input();
    m.output();

    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;

    book b[100];
    for(int i = 0; i < n; i ++){
        cout << "Nhap thong tin thu " << i+1 << ": ";
        b[i].input();
    }

    cout << "DANH SACH" << endl;
    for(int i = 0; i < n; i ++){
        b[i].output();
    }

        cout <<endl << "Sach co ten 'Lap trinh C++' va tac gia la 'Nguyen Thanh Thuy'" << endl;
        for (int i = 0; i < n; i ++){
            if(b[i].filter()){
                b[i].output();
            }
        }




}






