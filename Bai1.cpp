#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>

using namespace std;

class sinhvien{
    protected:
        char id[10];
        char name[50];
    public:
        void input();
        void output();
};

void sinhvien :: input(){
    getchar();
    cout << "ma sinh vien: ";
    cin >> id;

    cout << "ho va ten sinh vien: ";
    cin >> name;
}

void sinhvien :: output(){
    cout << setw(5) << id;
    cout << setw(15) << name;

}

class svtmdt:public sinhvien{
    private:
        float mark;
    public:
        void input();
        void output();
        float getmark(){ return mark; }
        
};

void svtmdt::input(){
    sinhvien::input();
    cout << "nhap diem sinh vien: ";
    cin >> mark;

}

void svtmdt::output(){
    sinhvien::output();
    cout << setw(10) << mark << endl;
}

void sort(svtmdt dssv[], int n){
    for( int i = 0; i <n; i ++){
        for(int j = i + 1; j < n; j ++){
            if(dssv[i].getmark() < dssv[j].getmark()){
                swap(dssv[i], dssv[j]);
            }
        }
    }
}

int main(){
    svtmdt dssv[20];

    int n;
    cout << "nhap so sinh vien: ";
    cin >> n;
    
    cout << "nhap thong tin sinh vien" << endl;
    for( int i = 0; i < n; i ++){
        dssv[i].input();
    }

        cout << "thong tin sinh vien" << endl;
        cout << setw(5) << "msv";
        cout << setw(15) << "ten sinh vien";
        cout << setw(10) << "diem:" << endl;

    for( int i = 0; i < n; i ++){
        dssv[i].output();
    }

    sort(dssv, n);
    cout << "danh sach sinh vien sau khi gap xep giam dan theo diem: " << endl;
    cout << setw(5) << "msv";
    cout << setw(15) << "ho va ten";
    cout << setw(10) << "diem" << endl;

    for ( int i = 0; i < n; i ++){
        dssv[i].output();
    }

    return 0;
}
