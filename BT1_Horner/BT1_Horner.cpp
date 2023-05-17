#include<iostream>
using namespace std;

int horner(int poly[], int n, int x) {
    int result = poly[0];
    for (int i = 1; i < n; i++) {
        result = result * x + poly[i];
    }
    return result;
}

int main() {
    int poly[] = { 2, -6, 7, -1, 8 };
    int n = sizeof(poly) / sizeof(poly[0]);
    int x = 3;
    cout << "Gia tri cua da thuc tại x=" << x << " la " << horner(poly, n, x) << endl;
    return 0;
}
