#include <iostream>
#include <vector>

using namespace std;

// Định nghĩa hàm nhân 2 ma trận vuông
vector<vector<int>> multiplyMatrix(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

// Định nghĩa hàm cộng 2 ma trận cùng kích thước
vector<vector<int>> addMatrix(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

// Định nghĩa hàm trừ 2 ma trận cùng kích thước
vector<vector<int>> subtractMatrix(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }

    return result;
}

// Định nghĩa hàm chia ma trận thành 4 phần bằng nhau
void divideMatrix(vector<vector<int>> a, vector<vector<int>>& a11, vector<vector<int>>& a12, vector<vector<int>>& a21, vector<vector<int>>& a22) {
    int n = a.size();
    int m = n / 2;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + m];
            a21[i][j] = a[i + m][j];
            a22[i][j] = a[i + m][j + m];
        }
    }
}

// Định nghĩa hàm ghép 4 phần trong ma trận
void mergeMatrix(vector<vector<int>>& a, vector<vector<int>> a11, vector<vector<int>> a12, vector<vector<int>> a21, vector<vector<int>> a22) {
    int n = a.size();
    int m = n / 2;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = a11[i][j];
            a[i][j + m] = a12[i][j];
            a[i + m][j] = a21[i][j];
            a[i + m][j + m] = a22[i][j];
        }
    }
}

// Giải thuật Strassen
vector<vector<int>> strassenMatrix(vector<vector<int>> a, vector<vector<int>> b, int n) {
    // Nếu kích thước ma trận nhỏ hơn 2x2 thì sử dụng giải thuật nhân thông thường
    if (n <= 2) {
        return multiplyMatrix(a, b);
    }

    // Tính giá trị m
    int m = n / 2;

    // Tạo 8 ma trận con
    vector<vector<int>> a11(m, vector<int>(m));
    vector<vector<int>> a12(m, vector<int>(m));
    vector<vector<int>> a21(m, vector<int>(m));
    vector<vector<int>> a22(m, vector<int>(m));
    vector<vector<int>> b11(m, vector<int>(m));
    vector<vector<int>> b12(m, vector<int>(m));
    vector<vector<int>> b21(m, vector<int>(m));
    vector<vector<int>> b22(m, vector<int>(m));

    // Chia ma trận thứ nhất và ma trận thứ hai thành 4 phần bằng nhau
    divideMatrix(a, a11, a12, a21, a22);
    divideMatrix(b, b11, b12, b21, b22);

    // Tính 7 ma trận trung gian P1, P2, P3, P4, P5, P6, P7
    vector<vector<int>> P1 = strassenMatrix(addMatrix(a11, a22), addMatrix(b11, b22), m);
    vector<vector<int>> P2 = strassenMatrix(addMatrix(a21, a22), b11, m);
    vector<vector<int>> P3 = strassenMatrix(a11, subtractMatrix(b12, b22), m);
    vector<vector<int>> P4 = strassenMatrix(a22, subtractMatrix(b21, b11), m);
    vector<vector<int>> P5 = strassenMatrix(addMatrix(a11, a12), b22, m);
    vector<vector<int>> P6 = strassenMatrix(subtractMatrix(a21, a11), addMatrix(b11, b12), m);
    vector<vector<int>> P7 = strassenMatrix(subtractMatrix(a12, a22), addMatrix(b21, b22), m);

    // Tính các ma trận con C11, C12, C21, C22
    vector<vector<int>> C11(m, vector<int>(m));
    vector<vector<int>> C12(m, vector<int>(m));
    vector<vector<int>> C21(m, vector<int>(m));
    vector<vector<int>> C22(m, vector<int>(m));

    C11 = addMatrix(subtractMatrix(addMatrix(P1, P4), P5), P7);
    C12 = addMatrix(P3, P5);
    C21 = addMatrix(P2, P4);
    C22 = addMatrix(subtractMatrix(addMatrix(P1, P3), P2), P6);

    // Ghép các ma trận con lại thành ma trận C
    vector<vector<int>> C(n, vector<int>(n));
    mergeMatrix(C, C11, C12, C21, C22);

    // Trả về ma trận kết quả
    return C;
}

int main() {
    int n;
    cout << "Nhap kich thuoc cua ma tran: ";
    cin >> n;

    // Khởi tạo 2 ma trận A và B
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    // Nhập giá trị cho 2 ma trận A và B
    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    // Tính ma trận kết quả C
    vector<vector<int>> C(n, vector<int>(n));
    C = strassenMatrix(A, B, n);

    // Xuất ma trận kết quả C
    cout << "Ma tran ket qua C:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
