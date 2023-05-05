#include <iostream>
#include <vector>

using namespace std;

// Doi cho gia tri cua 2 phan tu
void hoanVi(int* a, int* b)
{
    int tam = *a;
    *a = *b;
    *b = tam;
}

// Phan hoach mang va tra ve chi so cua phan tu chot (pivot)
int phanHoach(vector<int>& mang, int thap, int cao)
{
    int pivot = mang[cao];
    int i = (thap - 1);

    for (int j = thap; j <= cao - 1; j++)
    {
        if (mang[j] < pivot)
        {
            i++;
            hoanVi(&mang[i], &mang[j]);
        }
    }
    hoanVi(&mang[i + 1], &mang[cao]);
    return (i + 1);
}

// Thuat toan QuickSort
void sapXepNhanh(vector<int>& mang, int thap, int cao)
{
    if (thap < cao)
    {
        int pivotIndex = phanHoach(mang, thap, cao);
        cout << "Phan tu chot (Pivot): " << mang[pivotIndex] << endl;
        for (auto a : mang)
            cout << a << " ";
        cout << endl;
        sapXepNhanh(mang, thap, pivotIndex - 1);
        sapXepNhanh(mang, pivotIndex + 1, cao);
    }
}

int main()
{
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
