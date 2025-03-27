#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

// Xây dựng lớp người
class nguoi
{
protected:
    string id;
    string name;

public:
    void input();
    void output();
};

// Xây dựng hàm nhập thông tin người
void nguoi::input()
{
    cin.ignore();
    cout << "Nhap ma dinh danh: ";
    getline(cin, id);
    cout << "Ho va ten: ";
    getline(cin, name);
}

// Xây dựng hàm in thông tin nguoi
void nguoi::output()
{
    cout << endl
         << setw(12) << id;
    cout << setw(30) << name;
}

class nhanvien : public nguoi
{
private:
    int year;
    float hesoluong;
    int phucap = 500;

public:
    void input();
    void output();
    float tinhluong();
};

void nhanvien::input()
{
    nguoi::input();
    cout << "Nam sinh: ";
    cin >> year;
    cout << "He so luong: ";
    cin >> hesoluong;
}

float nhanvien::tinhluong()
{
    return hesoluong * 1550 + phucap;
}

void nhanvien::output()
{
    nguoi::output();
    cout << setw(10) << year;
    cout << setw(15) << hesoluong;
    cout << setw(12) << fixed << setprecision(3) << tinhluong() << " VND";
}



void sapxep(nhanvien dsnv[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dsnv[i].tinhluong() < dsnv[j].tinhluong())
            {
                swap(dsnv[i], dsnv[j]);
            }
        }
    }
}

int main()
{
    nhanvien dsnv[50];

    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        dsnv[i].input();
    }

    cout << "\nDanh sach nhan vien:\n";
    cout << setw(12) << "Ma dinh danh";
    cout << setw(30) << "Ho va ten";
    cout << setw(10) << "Nam sinh";
    cout << setw(15) << "He so luong";
    cout << setw(15) << "Tien luong";

    for (int i = 0; i < n; i++)
    {
        dsnv[i].output();
    }

    sapxep(dsnv, n);
    cout << "\n\nDANH SACH NHAN VIEN GIAM DAN THEO LUONG\n";
    cout << setw(12) << "Ma dinh danh";
    cout << setw(30) << "Ho va ten";
    cout << setw(10) << "Nam sinh";
    cout << setw(15) << "He so luong";
    cout << setw(15) << "Tien luong";

    for (int i = 0; i < n; i++)
    {
        dsnv[i].output();
    }

    return 0;
}