#include <iostream>
#include <string>

using namespace std;

class date{
    protected:
        int dd, mm, yyyy;
    public:
        date() : dd(0), mm(0), yyyy(0) {};
        void input();
        void output();    
};


void date::input(){
    cout << "Nhap ngay: ";
    cin >> dd;
    cout << "Nhap thang: ";
    cin >> mm;
    cout << "Nhap nam: ";
    cin >> yyyy;
}

void date::output(){
    cout << dd << "/" << mm << "/" << yyyy << endl;
}

class maytinh:public date{
    private:
        string id;
        string name;
        float price;
        float sell = 0.2;
    public:
        maytinh () : id(""), name(""), date(), price(0){};
        void input();
        void output();
        float realprice(){
            return price - price * sell;
        }
        int asus(){
            return name == "ASUS";
        }
};

void maytinh::input(){
    cin.ignore();
    cout << "Nhap ma may tinh: ";
    getline(cin, id);
    cout << "Nhap ten may tinh: ";
    getline(cin, name);
    date::input();
    cout << "Nhap gia ban niem yet: ";
    cin >> price;
}

void maytinh::output(){
    cout << "Ma may tinh: " << id << endl;
    cout << "Ten may tinh: " << name << endl;
    date::output();
    cout << "Gia ban thuc te: " << realprice() << endl;
}

int main(){
    date d;
    d.input();
    d.output();

    int n;
    cout << "Nhap so luong may tinh: ";
    cin >> n;

    maytinh mt[1000];
    for(int i = 0; i < n; i ++){
        mt[i].input();
    }

    cout << "Danh sach may tinh" << endl;
    for(int i = 0; i < n; i ++){
        mt[i].output();
    }

    cout << "Danh sach may tinh asus" << endl;
    for(int i = 0; i < n; i ++){
        if(mt[i].asus()){
            mt[i].output();
        }
    }

    cout << "May tinh co gia ban thap nhat" << endl;
    int low = mt[0].realprice();
    int index;
    for(int i = 0; i < n; i ++){
        if(  low > mt[i].realprice()){
            low = mt[i].realprice();
            index = i;

    }
    mt[index].output();


}



