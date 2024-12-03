#include <bits/stdc++.h>
using namespace std;
class Matranvuong{
    private:
        int capmt;
        int a[100][100];
    public:
        void nhap(){
            cout << "Nhap cap ma tran: ";
            cin >> capmt;
            cout << "Nhap cac phan tu ma tran: " << endl;
            for(int i = 0; i < capmt; i++){
                for(int j = 0; j < capmt; j++){
                    cout << "a[" << i << "][" << j << "] = ";
                    cin >> a[i][j];
                }
            }
        }

        void xuat(){
            cout << "Ma tran vua nhap la: " << endl;
            for(int i = 0; i < capmt; i++){
                for(int j = 0; j < capmt; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }

        // int getCapmt(){
        //     return capmt;
        // }

        // int getPhantu(int i, int j){
        //     return a[i][j];
        // }
        friend void tinhtong(Matranvuong x);
};
void tinhtong(Matranvuong x){
    int sumcc = 0;
    int sumcp = 0;
    for(int i = 0; i < x.capmt; i++){
        sumcc += x.a[i][i];
        sumcp += x.a[i][x.capmt - i - 1];
    } 
    cout << "Tong duong cheo chinh la: " << sumcc << endl;
    cout << "Tong duong cheo phu la: " << sumcp << endl;
}


int main(){
    Matranvuong mtv;
    mtv.nhap();
    mtv.xuat();
    tinhtong(mtv);
    
    // int sumcc = 0;
    // int sumcp = 0;
    // for(int i = 0; i < mtv.getCapmt(); i++){
    //     sumcc += mtv.getPhantu(i, i);
    //     sumcp += mtv.getPhantu(i, mtv.getCapmt() - i - 1);
    // }

    // cout << "Tong duong cheo chinh la: " << sumcc << endl;
    // cout << "Tong duong cheo phu la: " << sumcp << endl;
    
    return 0;
}