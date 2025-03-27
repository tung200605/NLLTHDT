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

