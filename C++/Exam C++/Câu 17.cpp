#include <bits/stdc++.h>
using namespace std;
class Diem{
    private:
        float x, y;
    public:
        Diem(){
            x = y = 0;
        }

        Diem(float x, float y){
            this->x = x;
            this->y = y;
        }

        void nhap(){
            cout << "Nhap toa do x: ";
            cin >> x;
            cout << "Nhap toa do y: ";
            cin >> y;
        }

        void xuat(){
            cout << "(" << x << ", " << y << ")";
        }

        friend float khoangCach(Diem a, Diem b);
};

float khoangCach(Diem a, Diem b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

class Tamgiac{
    private:
        Diem A, B, C;
        float AB, AC, BC;
    public:
        void nhap(){
            cout << "Toa do diem A " << endl;
            A.nhap();
            cout << "Toa do diem B" << endl;
            B.nhap();
            cout << "Toa do diem C" << endl;
            C.nhap();

        }
        void tinhKhoangcach(){
            AB = khoangCach(A, B);
            AC = khoangCach(A, C);
            BC = khoangCach(B, C);
        }

        void xuat(){
            cout << "AB = " << AB << endl
                 << "AC = " << AC << endl
                 << "BC = " << BC << endl;
        }

        void ktraTG(){
            if(AB + BC > AC && AB + AC > BC && AC + BC > AB){
                if(AB == AC && AC == BC){
                    cout << "Tam giac deu" << endl;
                }
                else if(AB == AC || AB == BC || AC == BC){
                    if(AB * AB + AC * AC == BC * BC || AB * AB + BC * BC == AC * AC || AC * AC + BC * BC == AB * AB){
                        cout << "Tam giac vuong can" << endl;
                    }
                    else{
                        cout << "Tam giac can" << endl;
                    }
                }
                else if(AB * AB + AC * AC == BC * BC || AB * AB + BC * BC == AC * AC || AC * AC + BC * BC == AB * AB){
                    cout << "Tam giac vuong" << endl;
                }
                else{
                    cout << "Tam giac thuong" << endl;
                }
            }
            else{
                cout << "Khong phai tam giac" << endl;
            }
        }
};

int main(){
    Tamgiac tg;
    tg.nhap();
    tg.tinhKhoangcach();
    tg.xuat();
    tg.ktraTG();
    return 0;
}
