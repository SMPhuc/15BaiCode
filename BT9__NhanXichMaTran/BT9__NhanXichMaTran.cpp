#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

// Hàm nhập vào ma trận
void inputMatrix(int matrix[][COLS]) {
    cout << "Nhap vao ma tran " << ROWS << "x" << COLS << ":" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Hàm in ra ma trận
void outputMatrix(int matrix[][COLS]) {
    cout << "Ma tran ket qua la:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Hàm nhân 2 ma trận và lưu kết quả vào ma trận result
void multiplyMatrix(int ma[][COLS], int mb[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += ma[i][k] * mb[k][j];
            }
        }
    }
}

int main() {
    int ma[ROWS][COLS], mb[ROWS][COLS], result[ROWS][COLS];
    inputMatrix(ma);
    inputMatrix(mb);

    // Nhân 2 ma trận và lưu kết quả vào ma trận result
    multiplyMatrix(ma, mb, result);

    outputMatrix(result);

    return 0;
}
