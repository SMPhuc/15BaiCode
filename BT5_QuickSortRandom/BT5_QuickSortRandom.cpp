#include <iostream>
#include <vector>
#include <ctime>
#include <locale.h>

using namespace std;

// Doi cho gia tri cua 2 phan tu
void hoanVi(int* a, int* b)
{
    int tam = *a;
    *a = *b;
    *b = tam;
}

// Chon ngau nhien mot phan tu trong mang
int chonMocNgauNhien(int low, int high)
{
    srand(time(NULL));
    return low + rand() % (high - low);
}

// Phan hoach mang va tra ve chi so cua phan tu chot (pivot)
int phanHoach(vector<int>& mang, int low, int high)
{
    // Chon ngau nhien mot phan tu lam phan tu chot
    int pivotIndex = chonMocNgauNhien(low, high);
    int pivot = mang[pivotIndex];
    cout << "Phan tu chot (pivot): " << pivot << " duoc chon tu dong tu vi tri " << pivotIndex << endl;

    // Dua phan tu chot ve cuoi mang
    hoanVi(&mang[pivotIndex], &mang[high]);
    cout << "Sau khi hoan doi, mang tro thanh: ";
    for (auto a : mang)
        cout << a << " ";
    cout << endl;

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (mang[j] < pivot)
        {
            i++;
            hoanVi(&mang[i], &mang[j]);

            cout << "Sau khi doi cho " << mang[i] << " va " << mang[j] << ", mang tro thanh: ";
            for (auto a : mang)
                cout << a << " ";
            cout << endl;
        }
    }
    // Dua phan tu chot ve vi tri dung cua no
    hoanVi(&mang[i + 1], &mang[high]);

    cout << "Sau khi phan hoach, mang tro thanh: ";
    for (auto a : mang)
        cout << a << " ";
    cout << endl;

    return (i + 1);
}

// Thuat toan quicksort
void sapXepNhanh(vector<int>& mang, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = phanHoach(mang, low, high);
        sapXepNhanh(mang, low, pivotIndex - 1);
        sapXepNhanh(mang, pivotIndex + 1, high);
    }
}

int main()
{
    setlocale(LC_ALL, "vi_VN.UTF-8");
    vector<int> mang = { 10, 7, 8, 9, 1, 5, 3, 4 };

    cout << "Mang ban dau: ";
    for (auto a : mang)
        cout << a << " ";
    cout << endl;

    sapXepNhanh(mang, 0, mang.size() - 1);

    cout << "Mang sau khi sap xep: ";
    for (auto a : mang)
        cout << a << " ";
    cout << endl;

    return 0;
}
