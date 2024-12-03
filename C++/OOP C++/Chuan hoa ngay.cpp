#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year; // Các thuộc tính lưu trữ ngày, tháng, năm

public:
    // Hàm tạo không đối (default constructor)
    Date() : day(1), month(1), year(2000) {}

    // Hàm tạo có đối (constructor with parameters)
    Date(int d, int m, int y) : day(d), month(m), year(y) { normalize(); }

    // Phương thức nhập ngày, tháng, năm
    void nhap() {
        cout << "Nhap ngay, thang, nam: ";
        cin >> day >> month >> year;
        normalize();
    }

    // Phương thức xuất ngày, tháng, năm theo định dạng dd-mm-yyyy
    void xuat() {
        cout << (day < 10 ? "0" : "") << day << "-"
             << (month < 10 ? "0" : "") << month << "-"
             << year << endl;
    }

    // Toán tử hậu tố A++ (tăng ngày sau khi trả về giá trị hiện tại)
    Date operator++(int) {
        Date temp = *this; // Lưu trữ giá trị hiện tại
        day++; // Tăng ngày
        normalize(); // Chuẩn hóa ngày
        return temp; // Trả về giá trị trước khi tăng
    }

    // Toán tử tiền tố ++A (tăng ngày trước khi trả về giá trị)
    Date operator++() {
        day++; // Tăng ngày
        normalize(); // Chuẩn hóa ngày
        return *this; // Trả về đối tượng hiện tại
    }

    // Toán tử hậu tố A-- (giảm ngày sau khi trả về giá trị hiện tại)
    Date operator--(int) {
        Date temp = *this; // Lưu trữ giá trị hiện tại
        day--; // Giảm ngày
        normalize(); // Chuẩn hóa ngày
        return temp; // Trả về giá trị trước khi giảm
    }

    // Toán tử tiền tố --A (giảm ngày trước khi trả về giá trị)
    Date operator--() {
        day--; // Giảm ngày
        normalize(); // Chuẩn hóa ngày
        return *this; // Trả về đối tượng hiện tại
    }

    // Kiểm tra năm nhuận
    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // Số ngày trong một tháng
    int daysInMonth(int m, int y) {
        if (m == 2) return isLeapYear(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }

    // Chuẩn hóa ngày, tháng, năm
    void normalize() {
        while (day > daysInMonth(month, year)) {
            day -= daysInMonth(month, year); // Giảm ngày vượt quá số ngày trong tháng
            month++; // Tăng tháng
            if (month > 12) { // Nếu tháng vượt quá 12
                month = 1; // Đặt lại tháng
                year++; // Tăng năm
            }
        }
        while (day < 1) {
            month--; // Giảm tháng
            if (month < 1) { // Nếu tháng nhỏ hơn 1
                month = 12; // Đặt lại tháng
                year--; // Giảm năm
            }
            day += daysInMonth(month, year); // Cập nhật lại ngày
        }
    }
};

int main() {
    Date d; // Tạo một đối tượng Date
    d.nhap(); // Nhập ngày, tháng, năm
    cout << "Ngay vua nhap: ";
    d.xuat(); // Xuất ngày vừa nhập

    cout << "Ngay sau khi tang (A++): ";
    Date oldDate1 = d++; // Tăng ngày bằng toán tử hậu tố
    oldDate1.xuat();
    d.xuat(); // Xuất ngày sau khi tăng

    cout << "Ngay sau khi tang (++A): ";
    Date oldDate2 = ++d; // Tăng ngày bằng toán tử tiền tố
    oldDate2.xuat();
    d.xuat(); // Xuất ngày sau khi tăng

    cout << "Ngay sau khi giam (A--): ";
    Date oldDate3 = d--; // Giảm ngày bằng toán tử hậu tố
    oldDate3.xuat();
    d.xuat(); // Xuất ngày sau khi giảm

    cout << "Ngay sau khi giam (--A): ";
    Date oldDate4 = --d; // Giảm ngày bằng toán tử tiền tố
    oldDate4.xuat();
    d.xuat(); // Xuất ngày sau khi giảm

    return 0; // Kết thúc chương trình
}
