#include <iostream>
#include <iomanip>
#include <string.h>


using namespace std;


class phuongtiengiaothong{
    protected:
        string brand;
        string name;
        int year;
        float maxspeed;
    public:
        void input();
        void output();
};

void phuongtiengiaothong::input(){
    cout << "Nhap ten hang san xuat: "; getline(cin, brand);
    cout << "Nhap ten phuong tien: "; getline(cin, name);
    cout << "Nhap nam san xuat: "; cin >> year;
    cout << "Nhap van toc toi da cua phuong tien: "; cin >> maxspeed;
}

void phuongtiengiaothong::output(){
    cout << setw(20) << brand;
    cout << setw(50) << name;
    cout << setw(4) << year;
    cout << setw(4) << maxspeed;

}

class oto:public phuongtiengiaothong{
    private:
        int place;
        string machine;
    public:
        void input();
        void output();
        float getmaxspeed();
        int honda() {return name == "HONDA";}
};

void oto::input(){
    phuongtiengiaothong::input();
    cout << "Nhap so cho ngoi: "; cin >> place;
    cout << "Nhap kieu dong co: "; getline(cin, machine);
}

void oto::output(){
    phuongtiengiaothong::output();
    cout << "So cho ngoi: " << place << endl;
    cout << "Kieu may: " << machine << endl;
}

float oto::getmaxspeed(){
    return maxspeed/4;
}


int main(){
    phuongtiengiaothong pt;
    pt.input();
    pt.output();

    int n;
    cout << endl << "Nhap so luong xe: ";
    cin >> n;


    oto dsoto[1000];
    for (int i = 0; i < n; i ++){
        dsoto[i].input();
    }

    cout << "Danh sach o to" << endl;
    for( int i = 0; i < n; i < n){
        dsoto[i].output();
    }

    cout << "Danh sach o to Honda" << endl;
    for(int i = 0; i < n; i ++){
        if(dsoto[i].honda()){       
            dsoto[i].output();

        }
    }









    
}