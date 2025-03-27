#include <iostream> 
#include <string>
#include <algorithm>

using namespace std;

class sinhvien{
    protected:
        string id;
        string name;
    public:
        sinhvien() : id(""), name("") {};
        void input();
        void output();
};

void sinhvien::input(){
    cout << "Nhap ma sinh vien: ";
    getline(cin, id);
    cout << "Nhap ten sinh vien: ";
    getline(cin, name);
}

void sinhvien::output(){
    cout << "Ma sinh vien: " << id << endl;
    cout << "Ten sinh vien: " << name << endl;
}

class svai:public sinhvien{
    private:
        float mark;
    public:
        svai() : sinhvien(), mark() {};
        void input();
        void output();
        void range(svai ai[1000], int n);
        bool operator <(svai& other){
            return this->mark < other.mark;
        }
};


void svai::input(){
    cin.ignore();
    sinhvien::input();
    cout << "Nhap diem cua sinh vien: "; 
    cin >> mark;
}

void svai::output(){
    sinhvien::output();
    cout << "Diem cua sinh vien: " << mark << endl;
}

void svai::range(svai ai[1000], int n){
    for(int i = 0; i < n - 1; i ++){
        for( int j = i + 1; j < n; j ++){
            if(ai[i].mark < ai[j].mark){
                swap(ai[i], ai[j]);
            }
        }
    }

}


int main(){
    sinhvien sv;
    sv.input();
    sv.output();


    svai ai[1000];

    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for(int i = 0; i < n; i ++){
        ai[i].input();
    }

    cout << "Danh sach sinh vien " << endl;
    for(int i = 0; i < n; i ++){
        ai[i]. output();
    }

    ai[1000].range(ai, n);

    cout << "Danh sach sau khi sap xep" << endl;

    for(int i = 0; i < n;i ++){
        ai[i].output();
    }



}






