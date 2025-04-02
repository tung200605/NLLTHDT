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


class svcnpm: public sinhvien{
    private:
        float diemtb;
    public:
        svcnpm(): sinhvien(), diemtb(0) {}
        ~svcnpm() {}
        void input();
        void output();
        float diem85(){
            return diemtb >= 8.5;
        }
};

void svcnpm::input(){
    cin.ignore();
    sinhvien::input();
    cout << "Nhap diem trung binh: ";
    cin >> diemtb;
}

void svcnpm::output(){
    sinhvien::output();
    cout << "Diem trung binh: " << diemtb << endl;
}

int main(){
    sinhvien sv;
    sv.input();
    sv.output();

    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;

    svcnpm cnpm[n];
    for(int i = 0; i < n; i++){
        cnpm[i].input();

    }

    cout << "Danh sach sinh vien: " << endl;
    for(int i = 0; i < n; i++){
        cnpm[i].output();
    }

    cout << "Danh sach sinh vien co diem trung binh >= 8.5: " << endl;
    for(int i = 0; i < n; i++){
        if(cnpm[i].diem85()){
            cnpm[i].output();
        }
    }


}