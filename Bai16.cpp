#include<iostream>
#include<string>

using namespace std;
class lophoc {
    protected:
        string malop;
        string tenlop;
    public:
        lophoc():malop(""),tenlop(""){};
        void input();
        void output();
        string getmalop() {
            return malop;
        }
};
void lophoc::input() {
    cout << "nhap ma lop: "; cin >> malop;
    cout << "nhap ten lop: "; cin >> tenlop;
}
void lophoc::output() {
    cout << "ma lop : " << malop << endl;
    cout << "ten lop: " << tenlop << endl;
}
class giangday : public lophoc {
    private:
        string magv;
        string mamonhoc;
        int sotin;
    public:
        giangday():lophoc(),magv(""),mamonhoc(""),sotin(0){};
        void input();
        void output();
        int sotietdd = 30;
        int tinhtiet() {
            return sotin * 15 - sotietdd;
        }
        int lop3tin() {
            return sotin == 3;
        }
        string getmagiangvien() { return magv; }
};
void giangday::input() {
    lophoc::input();
    cout << "nhap ma giang vien: "; cin >> magv;
    cout << "nhap ma mon hoc: "; cin >> mamonhoc;
    cout << "nhap so tin: "; cin >> sotin;;
}
void giangday::output() {
    cout << "ma giang vien: " << magv << endl;
    cout << "ma mon hoc: " << mamonhoc << endl;
    cout << "ma lop: " << getmalop() << endl;
    cout << "so tin: " << sotin << endl;
    cout << "so tien: " << tinhtiet() << endl;
}
int main() {
    lophoc l;
    l.input();
    l.output();
    int n;
    cout << "nhap so luong: "; cin >> n;
    giangday g[1000];
    for (int i = 0; i < n; i++) {
        g[i].input();
    }
    cout << "thong tin da nhap:" << endl;
    for (int i = 0; i < n; i++) {
        g[i].output();
    }
    cout << "lop hoc co 3 tin: " << endl;
    for (int i = 0; i < n; i++) {
        if (g[i].lop3tin()) {
            g[i].output();
        }
    }
    int mintietconlai = g[0].tinhtiet();
    for (int i = 1; i < n; i++) {
        if (g[i].tinhtiet() < mintietconlai) {
            mintietconlai = g[i].tinhtiet();
        }
    }
    cout << "ma cac giang vien co so tiet it nhat:" << endl;
    for (int i = 0; i < n; i++) {
        if (g[i].tinhtiet() == mintietconlai) {
            cout << g[i].getmagiangvien() << endl;
        }
    }
    return 0;
}
