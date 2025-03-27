#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class monhoc{
    private:
        string mamh;
        string tenmh;
        float diemtb;
        int sotc;
        
    public:
        void input();
        void output();
        int gettc() { return sotc;}
        float getdtb() {return diemtb;}
};



void monhoc:: input(){
    cout << "Nhap ma mon hoc: ";
    getline(cin, mamh);
    cout << "Nhap ten mon hoc: ";
    getline(cin, tenmh);
    cout << "Nhap diem trung binh: ";
    cin >> diemtb;
    cout << "Nhap so tin chi: ";
    cin >> sotc;
}


void monhoc:: output(){
    cout << "Ma mon hoc: " << mamh << endl;
    cout << "Ten mon hoc: " << tenmh << endl;
    cout << "Diem trung binh: " << diemtb << endl;
    cout << "So tin chi: " << sotc << endl;
}


class sinhvien:public monhoc{
    public: 
        void input();
        void output();
        float diemtk();
        bool hocbong();
    private:
        string id;
        string name;
        int somh;
        monhoc arr[500];
        

};


void sinhvien::input(){
    cin.ignore();
    cout << "Nhap ma sinh vien: ";
    getline(cin, id);
    cout << "Nhap ten sinh vien: ";
    getline(cin, name);
    cout << "Nhap so luong mon hoc: ";
    cin >> somh;
    for(int i = 0; i < somh; i ++){
        cout << "Nhap mon hoc thu " << i + 1 << ": ";
        cin.ignore();
        arr[i].input();
    }
}


void sinhvien:: output(){
    cout << "Ma sinh vien: " << id << endl;
    cout << "Ten sinh vien: " << name << endl;
    cout << "So luong mon hoc: " << somh << endl;
    cout << "Cac mon hoc dang ky: " << endl;
    for(int i = 0; i < somh; i ++){
        arr[i].output();
    cout << endl << "Diem tong ket: " << diemtk() << endl;
    }
}

float sinhvien::diemtk(){
    float sumdiem = 0, sumtc = 0;
    for(int i = 0; i < somh; i ++){
        sumdiem += arr[i].getdtb() * arr[i].gettc();
        sumtc += arr[i].gettc();
    }
    return sumdiem / sumtc;
}

bool sinhvien::hocbong(){
    return diemtk() >= 8.5;
}

int main(){
    monhoc mh;
    mh.input();
    mh.output();
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    sinhvien dssv[n];

        for (int i = 0; i < n; i ++){
            dssv[i].input();
        }
    cout << "DANH SACH SINH VIEN" << endl;
    for(int i = 0; i < n; i ++){
        dssv[i].output();
    }

    cout << "\nDanh sach sinh vien duoc hoc bong:\n";
    for (int i = 0; i < n; i++) {
        if (dssv[i].hocbong()) {
            dssv[i].output();
        }
    }
}

