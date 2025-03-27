#include <iostream>
using namespace std;

class sophuc {
private:
    double thuc;
    double ao; 

public:
    sophuc();
    sophuc(double t, double a);
    sophuc operator+(sophuc s);
    sophuc operator-();
    friend istream& operator>>(istream& in, sophuc& c);
    friend ostream& operator<<(ostream& out, const sophuc& c);
};


sophuc::sophuc() : thuc(0), ao(0) {}
sophuc::sophuc(double t, double a) : thuc(t), ao(a) {}

sophuc sophuc::operator+(sophuc s) {
    return sophuc(thuc + s.thuc, ao + s.ao);
}

sophuc sophuc::operator-() {
    return sophuc(-thuc, -ao);
}

istream& operator>>(istream& in, sophuc& c) {
    cout << "Nhap phan thuc: ";
    in >> c.thuc;
    cout << "Nhap phan ao: ";
    in >> c.ao;
    return in;
}

ostream& operator<<(ostream& out, const sophuc& c) {
    out << c.thuc;
    if (c.ao >= 0)
        out << " + " << c.ao << "i";
    else
        out << " - " << -c.ao << "i";
    return out;
}

int main() {
    sophuc s1, s2;

    cout << "Nhap so phuc thu nhat: \n";
    cin >> s1;
    cout << "Nhap so phuc thu hai: \n";
    cin >> s2;

    sophuc sum = s1 + s2;
    sophuc doi = -s1;

    cout << "So phuc thu nhat: " << s1 << endl;
    cout << "So phuc thu hai: " << s2 << endl;
    cout << "Tong hai so phuc: " << sum << endl;
    cout << "So phuc thu nhat doi dau: " << doi << endl;

    return 0;
}
