#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct KhoaHoc {
    int id; // ID của khóa học
    string ten; // Tên của khóa học
    int thoi_gian_bat_dau; // Thời gian bắt đầu của khóa học
    int thoi_gian_ket_thuc; // Thời gian kết thúc của khóa học
};

bool so_sanh(KhoaHoc a, KhoaHoc b) {
    return a.thoi_gian_ket_thuc < b.thoi_gian_ket_thuc;
}

void sap_xep_khoa_hoc(vector<KhoaHoc> khoa_hoc) {
    // Sắp xếp danh sách các khóa học theo thời gian kết thúc, từ sớm nhất đến muộn nhất
    sort(khoa_hoc.begin(), khoa_hoc.end(), so_sanh);

    // Tạo một lịch học rỗng
    vector<KhoaHoc> lich_hoc;

    // Thêm khóa học đầu tiên vào lịch học
    lich_hoc.push_back(khoa_hoc[0]);

    // Lặp qua các khóa học còn lại và thêm chúng vào lịch học nếu không trùng với các khóa học đã được thêm vào
    for (int i = 1; i < khoa_hoc.size(); i++) {
        // Kiểm tra xem khóa học mới có trùng với khóa học cuối cùng trong lịch học hay không
        if (khoa_hoc[i].thoi_gian_bat_dau >= lich_hoc.back().thoi_gian_ket_thuc) {
            // Khóa học mới không trùng lịch, thêm vào lịch học
            lich_hoc.push_back(khoa_hoc[i]);
        }
    }

    // In ra lịch học
    for (int i = 0; i < lich_hoc.size(); i++) {
        cout << lich_hoc[i].ten << " (" << lich_hoc[i].thoi_gian_bat_dau << " - " << lich_hoc[i].thoi_gian_ket_thuc << ")" << endl;
    }
}

int main() {
    // Các khóa học mẫu
    KhoaHoc kh1 = { 1, "Toan", 9, 11 };
    KhoaHoc kh2 = { 2, "Anh Van", 10, 12 };
    KhoaHoc kh3 = { 3, "Vat Ly", 11, 13 };
    KhoaHoc kh4 = { 4, "Lich Su", 12, 14 };
    KhoaHoc kh5 = { 5, "Hoa Hoc", 13, 15 };

    // Tạo vector chứa các khóa học
    vector<KhoaHoc> khoa_hoc = { kh1, kh2, kh3, kh4, kh5 };

    // Xếp lịch học cho các khóa học
    sap_xep_khoa_hoc(khoa_hoc);

    return 0;
}
