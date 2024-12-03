#include <iostream>
using namespace std;

class Time {
private:
    int hour, minute, second; // Các thuộc tính lưu trữ giờ, phút, giây

public:
    // Hàm tạo không đối (default constructor)
    Time() : hour(0), minute(0), second(0) {}

    // Hàm tạo có đối (constructor with parameters)
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {
        normalize(); // Chuẩn hóa thời gian
    }

    // Hàm hủy (destructor)
    ~Time() {}

    // Phương thức nhập giờ, phút, giây
    void nhap() {
        cout << "Nhap gio, phut, second: ";
        cin >> hour >> minute >> second;
        normalize(); // Chuẩn hóa sau khi nhập
    }

    // Phương thức xuất giờ, phút, giây theo định dạng hh:mm:ss
    void xuat() {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }

    // Toán tử hậu tố A++ (tăng giây sau khi trả về giá trị hiện tại)
    Time operator++(int) {
        Time temp = *this; // Lưu trữ giá trị hiện tại
        second++; // Tăng giây
        normalize(); // Chuẩn hóa thời gian
        return temp; // Trả về giá trị trước khi tăng
    }

    // Toán tử tiền tố ++A (tăng giây trước khi trả về giá trị)
    Time& operator++() {
        second++; // Tăng giây
        normalize(); // Chuẩn hóa thời gian
        return *this; // Trả về đối tượng hiện tại
    }

    // Toán tử hậu tố A-- (giảm giây sau khi trả về giá trị hiện tại)
    Time operator--(int) {
        Time temp = *this; // Lưu trữ giá trị hiện tại
        second--; // Giảm giây
        normalize(); // Chuẩn hóa thời gian
        return temp; // Trả về giá trị trước khi giảm
    }

    // Toán tử tiền tố --A (giảm giây trước khi trả về giá trị)
    Time& operator--() {
        second--; // Giảm giây
        normalize(); // Chuẩn hóa thời gian
        return *this; // Trả về đối tượng hiện tại
    }

    // Phương thức chuẩn hóa thời gian
    void normalize()
    {
        if (second >= 60)
        {
            minute += second / 60;
            second = second % 60;
        }
        if (minute >= 60)
        {
            hour += minute / 60;
            minute = minute % 60;
        }
        if (hour >= 24)
            hour %= 24;
        while (second < 0)
        {
            second += 60;
            minute--;
        }
        while (minute < 0)
        {
            minute += 60;
            hour--;
        }
        while ( hour < 0){
            hour += 24;
        }
    }
};

int main() {
    Time t; // Tạo một đối tượng Time
    t.nhap(); // Nhập giờ, phút, giây
    cout << "Thoi gian vua nhap: ";
    t.xuat(); // Xuất thời gian vừa nhập

    cout << "Thoi gian sau khi tang (A++): ";
    Time oldTime1 = t++; // Tăng giây bằng toán tử hậu tố
    oldTime1.xuat(); // Xuất thời gian trước khi tăng
    t.xuat(); // Xuất thời gian sau khi tăng

    cout << "Thoi gian sau khi tang (++A): ";
    Time oldTime2 = ++t; // Tăng giây bằng toán tử tiền tố
    oldTime2.xuat(); // Xuất thời gian trước khi tăng
    t.xuat(); // Xuất thời gian sau khi tăng

    cout << "Thoi gian sau khi giam (A--): ";
    Time oldTime3 = t--; // Giảm giây bằng toán tử hậu tố
    oldTime3.xuat(); // Xuất thời gian trước khi giảm
    t.xuat(); // Xuất thời gian sau khi giảm

    cout << "Thoi gian sau khi giam (--A): ";
    Time oldTime4 = --t; // Giảm giây bằng toán tử tiền tố
    oldTime4.xuat(); // Xuất thời gian trước khi giảm
    t.xuat(); // Xuất thời gian sau khi giảm

    return 0; // Kết thúc chương trình
}
