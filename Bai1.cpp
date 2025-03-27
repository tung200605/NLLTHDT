#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>

using namespace std;



// Xây dựng lớp sinh viên 
class sinhvien{
    protected:
        char id[10];
        char name[50];
    public:
        void input();
        void output();
};


// Xây dựng hàm nhập thông tin sinh viên
void sinhvien :: input(){
    getchar();
    cout << "Ma sinh vien: ";
    cin >> id;

    cout << "Ho va ten sinh vien: ";
    cin >> name;
}

// Xây dựng hàm in thông tin sinh viên
void sinhvien :: output(){
    cout << setw(5) << id;
    cout << setw(15) << name;

}

// Xây dựng lớp sinh viên thương mại điện tử để mô tả sinh viên thuộc
// chuyên ngành hệ thống thương mại điện tử từ lớp sinh viên 
class svtmdt:public sinhvien{
    private:
        float mark;
    public:
        void input();
        void output();
        float getmark(){ return mark; }
        
};

// Hàm nhập thông tin cho sinh viên tmdt
void svtmdt::input(){
    sinhvien::input();
    cout << "Nhap diem sinh vien: ";
    cin >> mark;

}

// Hàm xuất thông tin sinh viên tmdt
void svtmdt::output(){
    sinhvien::output();
    cout << setw(10) << mark << endl;
}

// Hàm sắp xếp sinh viên theo điểm giảm dần
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
    cout << "Nhap so sinh vien: ";
    cin >> n;
    
    cout << "NHAP THONG TIN SINH VIEN" << endl;
    for( int i = 0; i < n; i ++){
        dssv[i].input();
    }

        cout << "THONG TIN SINH VIEN" << endl;
        cout << setw(5) << "MSV";
        cout << setw(15) << "Ten sinh vien";
        cout << setw(10) << "Diem:" << endl;

    for( int i = 0; i < n; i ++){
        dssv[i].output();
    }

    sort(dssv, n);
    cout << "DANH SACH SINH VIEN SAU KHI GAP XEP GIAM DAN THEO DIEM: " << endl;
    cout << setw(5) << "MSV";
    cout << setw(15) << "Ho va ten";
    cout << setw(10) << "Diem" << endl;

    for ( int i = 0; i < n; i ++){
        dssv[i].output();
    }

    return 0;
}