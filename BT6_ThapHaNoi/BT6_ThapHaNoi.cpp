#include <iostream>
using namespace std;

// Hàm di chuyển một đĩa từ nguồn tới đích và in ra thông báo
void moveDisk(char nguon, char dich) {
    cout << nguon << " ==> " << dich << "\n";
}

// Hàm dịch chuyển các đĩa từ trục nguồn sang trục đích sử dụng trụ trống trong suốt quá trình di chuyển
void moveTower(int chieucao, char nguon, char tamtrung, char dich) {
    if (chieucao == 1) {
        // Nếu trục nguồn chỉ còn một đĩa thì di chuyển đĩa đó từ trục nguồn sang trục đích và hiển thị thông báo
        moveDisk(nguon, dich);
    }
    else {
        // Nếu chưa di chuyển xong, di chuyển toàn bộ những đĩa ở trên trục nguồn sang trục tamtrung
        moveTower(chieucao - 1, nguon, dich, tamtrung);
        // Di chuyển đĩa còn lại (lớn nhất) từ trục nguồn sang trục đích và hiển thị thông báo
        moveDisk(nguon, dich);
        // Di chuyển toàn bộ những đĩa ở trên trục tamtrung sang trục đích
        moveTower(chieucao - 1, tamtrung, nguon, dich);
    }
}

int main() {
    int chieucao;
    cout << "Nhap chieu cao cua thap Ha Noi: ";
    cin >> chieucao;
    // Di chuyển toàn bộ chương trình
    moveTower(chieucao, 'A', 'B', 'C');

    return 0;
}
