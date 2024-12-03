#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    while(b != 0){
        int x = a % b;
        a = b;
        b = x;
    }
    return a;
}

class PS1{
    protected:
        int ts, ms;
    public:
        void nhap(){
            cout << "Nhap tu so: ";
            cin >> ts;
            do{
                cout << "Nhap mau so: ";
                cin >> ms;
                if(ms == 0){
                    cout << "Nhap mau so khac 0, vui long nhap lai.";
                }
            }
            while(ms == 0);
        }

        void xuat(){
            cout << ts << "/" << ms;
        }

        void toigian(){
            int ucln = gcd(abs(ts), abs(ms));
            ts /= ucln;
            ms /= ucln;
            if(ms < 0){
                ts = -ts;
                ms = -ms;
            }
        }
};

class PS2 : public PS1{
    public:
        PS2 operator = (PS2 a){
            ts = a.ts;
            ms = a.ms;
            return *this;
        }

        bool operator > (PS2 a){
            return ts * a.ms > a.ts * ms;
        }
};

int main(){
    PS2 ps[10];
    int n;
    do{
        cout << "Nhap so luong phan so (toi da 10 phan so): ";
        cin >> n;
    }
    while(n < 1 || n > 10);

    for(int i = 0; i < n; i++){
        ps[i].nhap();
        ps[i].toigian();
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(ps[j] > ps[i]){
                PS2 tmp = ps[i];
                ps[i] = ps[j];
                ps[j] = tmp;
            }
        }
    }

    cout << "Sap xep theo trat tu giam dan: " << endl;
    for(int i = 0; i < n; i++){
        ps[i].xuat();
        cout << endl;
    }
    return 0;
}