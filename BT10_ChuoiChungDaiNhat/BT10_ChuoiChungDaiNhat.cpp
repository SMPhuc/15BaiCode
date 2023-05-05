#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int lookup[100][100];

// Đổ dữ liệu cho mảng lookup bằng cách tìm độ dài của dãy con chung
int LCSLength(string s1, string s2, int l1, int l2) {
    // Hàng đầu tiên và cột đầu tiên của mảng lookup bằng 0 vì mảng lookup đã được khai báo toàn cục
    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            // Nếu kí tự hiện tại khớp nhau
            if (s1[i - 1] == s2[j - 1]) lookup[i][j] = lookup[i - 1][j - 1] + 1;
            else lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
        }
    }
    return lookup[l1][l2];
}

string LCS(string s1, string s2, int l1, int l2) {
    // Trả về chuỗi rỗng nếu đã kết thúc chuỗi
    if (l1 == 0 || l2 == 0) return string("");

    // Nếu kí tự cuối cùng của s1, s2 khớp nhau thì
    // thêm kí tự đó vào chuỗi con chung dài nhất của
    // chuỗi con tạo bởi s1[0 đến l1-2] và s2[0 đến l2-2]
    if (s1[l1 - 1] == s2[l2 - 1]) return LCS(s1, s2, l1 - 1, l2 - 1) + s1[l1 - 1];

    // Nếu ô trên cùng của ô hiện tại có nhiều giá trị hơn ô bên trái
    // thì vứt kí tự hiện tại của s1 và tìm chuỗi con chung dài nhất của
    // chuỗi con tạo bởi s1[0 đến l1 - 2], s2[0 đến l2 - 1]
    if (lookup[l1 - 1][l2] > lookup[l1][l2 - 1]) return LCS(s1, s2, l1 - 1, l2);

    // Ngược lại thì vứt kí tự hiện tại của s2 và tìm chuỗi con chung dài nhất của
    // chuỗi con tạo bởi s1[0 đến l1 - 1], s2[0 đến l2 - 2]
    return LCS(s1, s2, l1, l2 - 1);
}

void PrintArray(int arr[100][100], int rows, int cols) {
    for (int i = 0; i <= rows; ++i) {
        for (int j = 0; j <= cols; ++j)
            cout << setw(5) << arr[i][j];
        cout << endl;
    }
}

int main() {
    string s1, s2;

    cout << "Nhap chuoi thu 1: ";
    cin >> s1; // abc1def2ghi3

    cout << "Nhap chuoi thu 2: ";
    cin >> s2; // abcdefghi123

    int l1 = s1.length();
    int l2 = s2.length();

    cout << "\nDo dai lon nhat cua xau con chung la: " << LCSLength(s1, s2, l1, l2);
    cout << "\nChuoi con chung dai nhat la: " << LCS(s1, s2, l1, l2);

    cout << "\nMang tinh do dai: " << endl;
    PrintArray(lookup, l1, l2);
    return 0;
}