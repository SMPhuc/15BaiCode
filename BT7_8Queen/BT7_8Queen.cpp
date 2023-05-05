#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int n = 8;// Kích thước của bàn cờ
int solutionCount = 0;//Đếm số lượng các giải pháp thu được

//Hàm xuất bàn cờ ra màn hình
void HienThiSolution(int bang[][8], int randomSolution) {
	if (solutionCount == randomSolution) {
		cout << "Phuong an " << solutionCount << ":" << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << bang[i][j] << " ";

			}
			cout << endl;
		}
		cout << endl;
	}
}

//Hàm kiểm tra vị trí đặt quân hậu trên bàn cờ
bool check(int bang[][8], int hangNgang, int Cot) {
	int i, j;
	//Kiểm tra hàng và cột
	for (i = 0; i < Cot; ++i) {
		if (bang[hangNgang][i]) {
			return false;
		}
	}

	for (i = hangNgang, j = Cot; i >= 0 && j >= 0; --i, --j) {
		if (bang[i][j]) {
			return false;
		}
	}

	for (i = hangNgang, j = Cot; j >= 0 && i < n; ++i, --j) {
		if (bang[i][j]) {
			return false;
		}
	}
	//Nếu quân cờ bị tấn cống thì trả về false, ngược lại trả về true 
	return true;
}

//Hàm đệ quy lui.
bool DeQuyLui(int bang[][8], int Cot, int& randomSolution) {
	if (Cot == n) {
		if (++solutionCount == randomSolution) {
			HienThiSolution(bang, randomSolution);
			return true;
		}
		return false;
	}
	//Vòng lặp để thử đặt quân hậu vào mỗi hàng trên cột hiện tại
	bool TraVe = false;
	for (int i = 0; i < n; ++i) {
		if (check(bang, i, Cot)) {
			//Nếu quân hậu không bị tấn công sẽ trả về giá trị là true
			//Đồng thời điền 1 vào bàn cờ
			bang[i][Cot] = 1;
			TraVe = DeQuyLui(bang, Cot + 1, randomSolution) || TraVe;
			//Ngược lại false sẽ điền 0
			//Xóa quân hậu vừa đặt để thử vị trí khác
			bang[i][Cot] = 0;
		}
	}
	return TraVe;
}

int main() {
	//Tạo mảng 2 chiều rỗng
	int bang[8][8] = { {0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0} };

	//Hàm tạo số ngẫu nhiên theo thời gian thực
	srand(time(NULL));
	int randomSolution = rand() % 92 + 1;//Giới hạn giá trị ngẫu nhiên từ 1 đến 92

	//Gọi lại hàm để hiẻn thị giải pháp được chọn lên màn hình
	DeQuyLui(bang, 0, randomSolution);
	return 0;
}