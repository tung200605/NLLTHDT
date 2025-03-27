#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


class date{
    protected:
        int dd,mm,yyyy;
    public: 
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
    cout << fixed << setprecision(2) << dd << "/" << fixed << setprecision(2) << mm << "/" << fixed << setprecision(4) << yyyy << endl;
}

class muontra:public date{
    private:
        string iddocgia;
        string idbook;
        int soluong;
        float phi = 500;
    public:
        muontra() : iddocgia(""), idbook(""), soluong(0) {}
        void input();
        void output();
        float tinhtien() {return soluong * phi;}
        int muon();
};


void muontra::input(){
    cin.ignore();
    cout << "Nhap ma doc gia: ";
    getline(cin, iddocgia);
    cout << "Nhap ma sach: ";
    getline(cin, idbook);
    cout << "Nhap so luong: ";
    cin >> soluong;

}


void muontra::output(){
    cout << "Ma doc gia: " << iddocgia << endl;
    cout << "Ma sach: " << idbook << endl;
    cout << "So luong: " << soluong << endl;
    cout << "Tien phai tra: " << tinhtien() << endl;
}

int muontra::muon(){
    return date::yyyy < 2020;
    
}

int main(){
    date d;
    d.input();
    d.output();

    muontra mt[1000];
    
    int n;
    cout << "Nhap so luong nguoi muon " << endl;
    cin >> n;

    for(int i = 0; i < n; i ++){
        mt[i].input();
    }


    cout << "Danh sach nguoi muon";
    for(int i = 0; i < n; i ++){
        mt[i].output();
    }

    cout << "Danh sach nguoi muon truoc 1/1/2020" << endl;
    for(int i = 0; i < n; i ++){
        if(mt[i].muon()){
            mt[i].output();
        }
    }

    cout << "Doc gia nhieu tien" << endl;
    float max = mt[0].tinhtien();
    int indx;
    for(int i = 0; i < n; i ++){
        if( max < mt[i].tinhtien()){
            max = mt[i].tinhtien();
            indx = i;
        }
        
    }
    mt[indx].output();
}