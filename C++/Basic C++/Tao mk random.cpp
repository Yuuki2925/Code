#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
using namespace std;

//Tao mk ngau nhien
string generate_password(int length) {
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    random_device rd; // Máy tạo số ngẫu nhiên
    mt19937 gen(rd()); // Sinh số ngẫu nhiên
    uniform_int_distribution<> dist(0, characters.size() - 1);

    string password;
    for (int i = 0; i < length; ++i) {
        password += characters[dist(gen)];
    }
    return password;
}

// Tạo danh sách các mật khẩu có thể có
vector<string> generate_possible_passwords(int length, int count) {
    vector<string> possible_passwords;
    for (int i = 0; i < count; ++i) {
        possible_passwords.push_back(generate_password(length));
    }
    return possible_passwords;
}

// Tìm kiếm mk trong danh sách
bool search_password(const string& generated_password, const vector<string>& possible_passwords) {
    auto it = find(possible_passwords.begin(), possible_passwords.end(), generated_password);
    if (it != possible_passwords.end()) {
        cout << "Password found: " << *it << endl;
        return true;
    } else {
        cout << "Password not found." << endl;
        return false;
    }
}

// Hàm main
int main() {
    int password_length = 8;
    int password_count = 10000;

    // Tạo mk ngẫu nhiên
    string generated_password = generate_password(password_length);
    cout << "Generated password: " << generated_password << endl;

    // Tạo danh sách mk có thể có
    vector<string> possible_passwords = generate_possible_passwords(password_length, password_count);

    // Tìm kiếm mk trong danh sách
    search_password(generated_password, possible_passwords);

    return 0;
}
