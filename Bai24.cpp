#include <iostream>
#include <string>

using namespace std;

class thisinh {
    protected:
        string sobaodanh;
        string name;
        string address;
        float diemuutien;
    public:
        thisinh(): sobaodanh(""), name(""), address(""), diemuutien(0) {}
        ~thisinh() {}
        void input();
        void output();
};

void thisinh::input(){
    cout << "Nhap so bao danh: ";
    getline(cin, sobaodanh);
    cout << "Nhap ho ten: ";
    getline(cin, name);
    cout << "Nhap dia chi: ";
    getline(cin, address);
    cout << "Nhap diem uu tien: ";
    cin >> diemuutien;
}

void thisinh::output(){
    cout << "So bao danh: " << sobaodanh << endl;
    cout << "Ho ten: " << name << endl;
    cout << "Dia chi: " << address << endl;
    cout << "Diem uu tien: " << diemuutien << endl;
}


class thisinhkhoia : public thisinh {
    private:
        float toan;
        float ly;
        float hoa;
    public:
        thisinhkhoia(): toan(0), ly(0), hoa(0) {}
        ~thisinhkhoia() {}
        void input();
        void output();
        float tongdiem() const {
            return toan + ly + hoa + diemuutien;
        }
        bool operator<(const thisinhkhoia& other) const {
            return this->tongdiem() < other.tongdiem();
        }

        void range(thisinhkhoia* arr, int n) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (arr[i] < arr[j]) {
                        thisinhkhoia temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
};

void thisinhkhoia::input(){
    cin.ignore();
    thisinh::input();
    cout << "Nhap diem toan: ";
    cin >> toan;
    cout << "Nhap diem ly: ";
    cin >> ly;
    cout << "Nhap diem hoa: ";
    cin >> hoa;
}

void thisinhkhoia::output(){
    thisinh::output();
    cout << "Diem toan: " << toan << endl;
    cout << "Diem ly: " << ly << endl;
    cout << "Diem hoa: " << hoa << endl;
    cout << "Tong diem: " << toan + ly + hoa + diemuutien << endl;
}

int main(){
    thisinh ts;
    ts.input();
    ts.output();

    int n;  
    cout << "Nhap so luong thi sinh khoi A: ";
    cin >> n;

    thisinhkhoia tsinhkhoia[n];
    for (int i = 0; i < n; i++){
        tsinhkhoia[i].input();
    }

    cout << "Danh sach thi sinh khoi A:" << endl;
    for (int i = 0; i < n; i++){
        tsinhkhoia[i].output();
    }

    cout << "Danh sach thi sinh khoi A da duoc sap xep theo diem:" << endl;
    tsinhkhoia[0].range(tsinhkhoia, n);
    for(int i = 0; i < n; i++){
        tsinhkhoia[i].output();
    }

}
