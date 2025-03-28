#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class date
{
private:
    int dd, mm, yyyy;

public:
    date() : dd(1), mm(1), yyyy(2000) {}
    void input();
    void output();
};

void date::input()
{
    cout << "nhap dd: ";
    cin >> dd;
    cout << "nhap mm: ";
    cin >> mm;
    cout << "nhap yyyy: ";
    cin >> yyyy;
}

void date::output()
{
    cout << dd << "/" << mm << "/" << yyyy << endl;
}

class muontra : public date
{
private:
    string madocgia, masach;
    int soluong;
    static float phicuoc;

public:
    muontra() : date(), madocgia(""), masach(""), soluong(0) {}
    void input();
    void output();
    float tinhtien();
    bool operator<(muontra &mt)
    {
        return soluong < mt.soluong;
    }
};

float muontra::phicuoc = 5000;

void muontra::input()
{
    cout << "nhap ma doc gia: ";
    cin >> madocgia;
    cout << "nhap ma sach: ";
    cin >> masach;
    date::input();
    cout << "nhap so luong sach muon: ";
    cin >> soluong;
}

void muontra::output()
{
    cout << "Ma doc gia: " << madocgia << endl;
    cout << "Ma sach: " << masach << endl;
    date::output();
    cout << "So luong: " << soluong << endl;
    cout <<  "Tien cuoc: " << tinhtien() << endl;
}

float muontra::tinhtien()
{
    return soluong * phicuoc;
}

int main()
{
    date date;
    date.input();
    date.output();

    int n;
    cout << "input so luong phieu muon tra: ";
    cin >> n;

    muontra mt[100];
    for (int i = 0; i < n; i++)
    {
        mt[i].input();
    }

    cout << "\nDanh sach muon tra:\n";
    for (int i = 0; i < n; i++)
    {
        mt[i].output();
    }

    sort(mt, mt + n, [](muontra a, muontra b)
         { return a.tinhtien() > b.tinhtien(); });
    cout << "\nDanh sach muon tra sau khi sap xep theo tien cuoc giam dan:\n";
    for (int i = 0; i < n; i++)
    {
        mt[i].output();
    }

    return 0;
}
