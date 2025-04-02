#include <iostream>
#include <string>
using namespace std;

class DATE {
private:
    int ngay, thang, nam;
public:
    DATE() : ngay(1), thang(1), nam(1900) {}
    
    void nhap() {
        cout << "Nhap ngay: "; cin >> ngay;
        cout << "Nhap thang: "; cin >> thang;
        cout << "Nhap nam: "; cin >> nam;
    }
    
    void xuat() const {
        cout << ngay << "/" << thang << "/" << nam;
    }
    
    bool truocNgay(const DATE& other) const {
        if (nam != other.nam) return nam < other.nam;
        if (thang != other.thang) return thang < other.thang;
        return ngay < other.ngay;
    }
};

class MUONTRA : public DATE {
private:
    string maDocGia;
    string maSach;
    int soLuong;
    static float phiCuoc;
public:
    MUONTRA() : soLuong(0) {}
    
    void nhap() {
        cout << "Nhap ma doc gia: "; cin >> maDocGia;
        cout << "Nhap ma sach: "; cin >> maSach;
        DATE::nhap();
        cout << "Nhap so luong: "; cin >> soLuong;
    }
    
    void xuat() const {
        cout << "Ma doc gia: " << maDocGia << endl;
        cout << "Ma sach: " << maSach << endl;
        cout << "Ngay muon: "; DATE::xuat(); cout << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "Tien cuoc: " << tinhTienCuoc() << endl;
    }
    
    float tinhTienCuoc() const {
        return soLuong * phiCuoc;
    }
    
    string getMaDocGia() const { return maDocGia; }
    
    static void setPhiCuoc(float phi) {
        phiCuoc = phi;
    }
};

float MUONTRA::phiCuoc = 0;

int main() {
    DATE ngay;
    cout << "Nhap thong tin ngay thang nam:\n";
    ngay.nhap();
    
    cout << "\nNgay vua nhap: ";
    ngay.xuat();
    cout << endl;
    
    int n;
    cout << "\nNhap so luong muon tra: ";
    cin >> n;
    
    MUONTRA* dsMuonTra = new MUONTRA[n];
    MUONTRA::setPhiCuoc(5000);
    
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin muon tra thu " << i + 1 << ":\n";
        dsMuonTra[i].nhap();
    }
    
    cout << "\nDanh sach muon tra:\n";
    for (int i = 0; i < n; i++) {
        dsMuonTra[i].xuat();
        cout << "-----------------\n";
    }
    
    DATE ngayChuan;
    ngayChuan.nhap();
    
    cout << "\nCac doc gia muon truoc ngay 1/1/2020:\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (dsMuonTra[i].truocNgay(ngayChuan)) {
            cout << dsMuonTra[i].getMaDocGia() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co doc gia nao muon truoc ngay 1/1/2020\n";
    }
    
    float maxTien = 0;
    for (int i = 0; i < n; i++) {
        if (dsMuonTra[i].tinhTienCuoc() > maxTien) {
            maxTien = dsMuonTra[i].tinhTienCuoc();
        }
    }
    
    cout << "\nMa doc gia co so tien cuoc nhieu nhat (" << maxTien << "):\n";
    for (int i = 0; i < n; i++) {
        if (dsMuonTra[i].tinhTienCuoc() == maxTien) {
            cout << dsMuonTra[i].getMaDocGia() << endl;
        }
    }
    
    return 0;
}
