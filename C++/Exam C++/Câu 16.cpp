#include <bits/stdc++.h>
using namespace std;

class HinhVuong {
protected:
    float canh; // Độ dài cạnh

public:
    // Constructor không đối
    HinhVuong() {
        canh = 0;
    }

    // Constructor có đối
    HinhVuong(float canh) {
        this->canh = canh;
    }

    // Nhập độ dài cạnh
    void nhap(){
        cout << "Nhap do dai canh hinh vuong: ";
        cin >> canh;
    }

    // Xuất thông tin hình vuông
    void xuat(){
        cout << "Hinh vuong: canh = " << canh << endl
             << "Dien tich = " << dientichhv() << endl;
    }

    float chuvihv(){
        return canh * 4;
    }
    float dientichhv(){
        return canh * canh;
    }
};

class HinhChuNhat : public HinhVuong {
private:
    float canh2; // Độ dài cạnh thứ 2

public:
    // Constructor không đối
    HinhChuNhat(){
        canh2 = 0;
    }

    // Constructor có đối
    HinhChuNhat(float canh, float canh2) : HinhVuong(canh) {
        this->canh2 = canh2;
    }

    // Nhập độ dài hai cạnh
    void nhap() {
        HinhVuong::nhap(); // Nhập cạnh thứ nhất
        cout << "Nhap do dai canh thu hai: ";
        cin >> canh2;
    }

    // Xuất thông tin hình chữ nhật
    void xuat(){
        cout << "Hinh chu nhat: canh = " << canh << ", canh 2 = " << canh2 << endl;
    }

    float chuvihcn(){
        return (canh + canh2) *2; 
    }
    float dientichhcn(){
        return canh * canh2;
    }
};

int main(){
    int n;
    cout << "Nhap so luong hinh vuong: ";
    cin >> n;
    HinhVuong a[n];
    for(int i = 0; i < n; i++){
        a[i].nhap();
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        if(a[i].dientichhv() > a[max].dientichhv()){
            max = i;
        }
    }
    cout << "Dien tich hinh vuong lon nhat la: \n";
    a[max].xuat();
    cout << "Vi tri hinh vuong: " << max + 1 << endl;
    return 0;
}
