#include <bits/stdc++.h>
using namespace std;
class Matran{
    private:
        int soHang, soCot;
        int a[100][100];
    public:
        void nhap(){
            cout << "Nhap so hang: ";
            cin >> soHang;
            cout << "Nhap so cot: ";
            cin >> soCot;
            cout << "Nhap phan tu: " << endl;
            for(int i = 0; i < soHang; i++){
                for(int j = 0; j < soCot; j++){
                    cout << "a[" << i << "][" << j << "] = ";
                    cin >> a[i][j];
                }
            }
        }

        void xuat(){
            cout << "Ma tran vua nhap la: " << endl;
            for(int i = 0; i < soHang; i++){
                for(int j = 0; j < soCot; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }

        friend int tongvien(Matran x);
};

int tongvien(Matran x){
    int sum = 0;

    //Tính tổng hàng đầu và hàng cuối
    for(int j = 0; j < x.soCot; j++){           
        sum += x.a[0][j];
        sum += x.a[x.soHang - 1][j];
    }

    //Cộng các phần tử trên cột đầu và cột cuối, bỏ qua các góc đã cộng
    for(int i = 1; i < x.soHang - 1; i++){
        sum += x.a[i][0];
        sum += x.a[i][x.soCot - 1];
    }

    return sum;
}

int main(){
    Matran mt;
    mt.nhap();
    mt.xuat();
    cout << "Tong vien cua ma tran la: " << tongvien(mt) << endl;
    return 0;
}