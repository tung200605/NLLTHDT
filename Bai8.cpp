#include <iostream>
#include <string>

using namespace std;

class media {
protected:
    string name;
    float price;
public:
    media() : name(""), price(0) {}
    ~media() {}
    void input();
    void output();
};

void media::input() {
    cin.ignore();
    cout << "nhap ten phuong tien: ";
    getline(cin, name);
    cout << "nhap gia ban: ";
    cin >> price;
}

void media::output() {
    cout << "Ten: " << name << endl;
    cout << "Gia: " << price << endl;
}

class video : public media {
private:
    int thoigianchay;
public:
    video() : media(), thoigianchay(0) {}
    ~video() {}
    void input();
    void output();
    bool check();
};

void video::input() {
    media::input();
    cout << "nhap thoi gian chay: ";
    cin >> thoigianchay;
}

void video::output() {
    media::output();
    cout << "Thoi gian chay: " << thoigianchay << endl;
}

bool video::check() {
    return name == "Python" && thoigianchay > 10;
}

int main() {
    media media;
    cout << "nhap thong tin cho mot phuong tien truyen thong:\n";
    media.input();
    cout << "Thong tin phuong tien vua input:\n";
    media.output();

    int n;
    cout << "nhap so luong bang video: ";
    cin >> n;

    video videos[100];
    for (int i = 0; i < n; i++) {
        videos[i].input();
    }

    cout << "\nDanh sach bang video:\n";
    for (int i = 0; i < n; i++) {
        videos[i].output();
    }

    cout << "\nDanh sach video ten 'Python' va thoi gian chay > 10:\n";
    for (int i = 0; i < n; i++) {
        if (videos[i].check()) {
            videos[i].output();
        }
    }
}
