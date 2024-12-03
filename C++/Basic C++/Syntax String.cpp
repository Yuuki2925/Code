// Các syntax string
#include <iostream>
using namespace std;

// length() = size()          xem độ dài của chuỗi
// stoi                       chuyển chuỗi sang dạng số ( kiểu int)
// stoll                      chuyển chuỗi sang dạng số ( kiểu long long)
//to_string                   chuyển số về dạng chuỗi
int main(){
    int n = 1234567;
    string x = "7890";
    string s = "Javascript";
    string a = "237659832753098";
    
    cout << "Chuyen so ve dang chuoi: " << to_string(n) << endl;
    cout << "Xem do dai cua chuoi: " << s.length() << endl;
    cout << "Chuyen chuoi ve dang so (int): " << stoi(x) << endl;
    cout << "Chuyen chuoi ve dang so (long long): " << stoll(a) << endl;


// Cắt chuỗi trong string
    string g = "abcdefghi";
    string b = g.substr(2,5);    
    /*Cắt chuỗi substr(Start, size): bắt đầu cắt từ đâu, lựa chọn số kí tự cần cắt
    Nếu không có size thì mặc định cắt từ vị trí mình chọn đến hết*/ 
    cout << "Chuoi sau khi cat la: " << b << endl;
}