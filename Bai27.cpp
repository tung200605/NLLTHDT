#include<iostream>
#include<iomanip>

using namespace std;

class media {
    protected:
        string name;
        float price;
    public:
        media():name(""),price(0.0){}
        ~media(){}
        void input();
        void output(); 
}; 

void media::input() {
    cout<<"Nhap ten media: ";getline(cin,name);
    cout<<"Nhap gia media: ";cin>>price; 
} 

void media::output() {
    cout<<"Ten media: "<<name<<endl;
    cout<<"Gia media: "<<price<<endl; 
} 

class video:public media {
    protected:
        float time;
    public:
        video():time(0.0){}
        void input();
        void output();
        bool find(); 
}; 

void video::input() {
    cin.ignore(); 
    media::input();
    cout<<"Nhap thoi gian chay: ";cin>>time; 
} 

void video::output() {
    media::output();
    cout<<"Thoi gian chay: "<<time<<endl; 
} 

bool video::find() {
    return (name == "huong dan lap trinh python" && time > 10 ); 
} 

int main() {
    media MEDIA;
    MEDIA.input();
    MEDIA.output();
    
    video dsvid[100]; 
    int n;
    cout<<"Nhap so luong video: ";
    cin>>n;
    
    for(int i=0 ; i<n ; i++) {
        cout<<"Nhap thong tin video thu: "<<i+1<<endl; 
        dsvid[i].input(); 
    } 
    
    cout<<"Danh sach thong tin video vua nhap: "<<endl; 
    for(int i=0 ; i<n ; i++) {
        dsvid[i].output(); 
    } 
    
    cout<<"Danh sach nhung cuon sach co ten huong dan lap trinh python co thoi gian chay tren 10 don vi tinh: "<<endl;
    for(int i=0 ; i<n ; i++) {
        if(dsvid[i].find()) {
            dsvid[i].output();
        } 
    }
} 
