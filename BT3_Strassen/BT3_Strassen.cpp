#include <iostream>
#include <vector>

using namespace std;

// Hàm nhân hai ma trận
vector<vector<int>> matrixMultiplication(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

// Hàm cộng hai ma trận
vector<vector<int>> addMatrices(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

// Hàm trừ hai ma trận
vector<vector<int>> subtractMatrices(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }

    return result;
}

// Hàm chia ma trận thành 4 ma trận con
void divideMatrix(vector<vector<int>> a, vector<vector<int>>& a11, vector<vector<int>>& a12, vector<vector<int>>& a21, vector<vector<int>>& a22)
{
    int n = a.size();

    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = 0; j < n / 2; ++j)
        {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + n / 2];
            a21[i][j] = a[i + n / 2][j];
            a22[i][j] = a[i + n / 2][j + n / 2];
        }
    }
}

// Hàm gộp lại 4 ma trận con thành một ma trận
vector<vector<int>> combineMatrices(vector<vector<int>> a11, vector<vector<int>> a12, vector<vector<int>> a21, vector<vector<int>> a22)
{
    int n = a11.size();
    vector<vector<int>> result(n * 2, vector<int>(n * 2, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = a11[i][j];
            result[i][j + n] = a12[i][j];
            result[i + n][j] = a21[i][j];
            result[i + n][j + n] = a22[i][j];
        }
    }

    return result;
}

// Hàm tính tích của hai ma trận bằng giải thuật Strassen
vector<vector<int>> strassen(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    // Trường hợp cơ bản khi n=1
    if (n == 1)
    {
        result[0][0] = a[0][0] * b[0][0];
        return result;
    }

    // Chia ma trận A thành các ma trận con
    vector<vector<int>> a11(n / 2, vector<int>(n / 2, 0));
    vector<vector<int>> a12(n / 2, vector<int>(n / 2, 0));
    vector<vector<int>> a21(n / 2, vector<int>(n / 2, 0));
    vector<vector<int>> a22(n / 2, vector<int>(n / 2, 0));
    divideMatrix(a, a11, a12, a21, a22);

    // Chia ma trận B thành các ma trận con
    vector<vector<int>> b11(n / 2, vector<int>(n / 2, 0));
    vector<vector<int>> b12(n / 2, vector<int>(n / 2, 0));
    vector<vector<int>> b21(n / 2, vector<int>(n / 2, 0));
    vector<vector<int>> b22(n / 2, vector<int>(n / 2, 0));
    divideMatrix(b, b11, b12, b21, b22);

    // Tính các ma trận con theo công thức Strassen
    vector<vector<int>> m1 = strassen(addMatrices(a11, a22), addMatrices(b11, b22));
    vector<vector<int>> m2 = strassen(addMatrices(a21, a22), b11);
    vector<vector<int>> m3 = strassen(a11, subtractMatrices(b12, b22));
    vector<vector<int>> m4 = strassen(a22, subtractMatrices(b21, b11));
    vector<vector<int>> m5 = strassen(addMatrices(a11, a12), b22);
    vector<vector<int>> m6 = strassen(subtractMatrices(a21, a11), addMatrices(b11, b12));
    vector<vector<int>> m7 = strassen(subtractMatrices(a12, a22), addMatrices(b21, b22));

    // Tính ma trận kết quả
    vector<vector<int>> c11 = addMatrices(subtractMatrices(addMatrices(m1, m4), m5), m7);
    vector<vector<int>> c12 = addMatrices(m3, m5);
    vector<vector<int>> c21 = addMatrices(m2, m4);
    vector<vector<int>> c22 = addMatrices(subtractMatrices(addMatrices(m1, m3), m2), m6);

    // Gộp các ma trận con thành ma trận kết quả
    result = combineMatrices(c11, c12, c21, c22);

    return result;
}

int main()
{
    // Khởi tạo ma trận 4x4
    vector<vector<int>> a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    vector<vector<int>> b = {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}
    };

    // Tính tích hai ma trận bằng giải thuật Strassen
    vector<vector<int>> c = strassen(a, b);

    // Hiển thị ma trận kết quả
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
