#include <iostream>
#include <string>

using namespace std;

class monhoc{
    protected:
        string mamonhoc;
        string tenmonhoc;
    public:
        monhoc(): mamonhoc(""), tenmonhoc(""){};
        void input();
        void output();
};

void monhoc::input(){
    cout << "Nhap ma mon hoc: ";
    getline(cin, mamonhoc);
    cout << "Nhap ten mon hoc: ";
    getline(cin, tenmonhoc);
}


void monhoc::output(){
    cout << "Ma mon hoc: " << mamonhoc << endl;
    cout << "Ten mon hoc: " << tenmonhoc << endl;
}


class giangday:public monhoc{
    private:
        string magiangvien;
        string malop;
        int sotinchi;
        int sotietgiangday = 5;
    public:
        giangday(): magiangvien(""), malop(""), monhoc(), sotinchi(0) {};
        void input();
        void output();
        float sotietcon(){
            return sotinchi * 15 - sotietgiangday;
        }

        int batin(){
            return sotinchi >= 3;
        }
};

void giangday::input(){
    cin.ignore();
    cout << "Nhap ma giang vien: ";
    getline(cin, magiangvien);
    cout << "Nhap ma lop: ";
    getline(cin, malop);
    monhoc::input();
    cout << "Nhap so tin chi: ";
    cin >> sotinchi;
}

void giangday::output(){
    cout << "Ma giang vien: " << magiangvien << endl;
    cout << "Ma lop: " << malop << endl;
    monhoc::output();
    cout << "So tin chi: " << sotinchi << endl;
    cout << "Sotiet con lai: " << sotietcon() << endl;
}

int main(){
    monhoc mh;
    mh.input();
    mh.output();
    
    int n;
    cout << "Nhap so luong mon hoc: ";
    cin >> n;

    giangday gd[n];

    for(int i = 0; i < n; i++){
        gd[i].input();
    }

    cout << "Danh sach giang day: " << endl;
    for(int i = 0; i < n; i++){
        gd[i].output();
    }

    cout << "Danh sach mon hoc co so tin chi >= 3: " << endl;
    for(int i = 0; i < n; i++){
        if(gd[i].batin()){
            gd[i].output();
        }
    }

    int dayit = gd[0].sotietcon();
    int index = 0;
    for(int i = 1; i < n; i++){
        if(gd[i].sotietcon() < dayit){
            dayit = gd[i].sotietcon();
            index = i;
        }
    }

    cout << "Giang vien co so tiet con it nhat: " << endl;
    gd[index].output();


}


