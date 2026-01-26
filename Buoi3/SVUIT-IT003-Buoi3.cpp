#include <iostream>
#include <vector>
#include <string>

using namespace std;


//Bài tập về vectơ
void bai1(vector<int> array) {
	while (true) {
		int so;
		cin >> so;
		if (so == -1) break;
		array.push_back(so);
	}
	for (int i = 0; i < array.size(); i++) {
		if (array[i] % 2 != 0)
			array.erase(array.begin() + i);
	}
	for (int i : array) cout << i << ' ';
}

//Bài tập về danh sách liên kết đơn 
//Tên dự án: Hệ thống xử lý hàng chờ đơn hàng
//Bối cảnh : Bạn đang viết backend cho một shop.Đơn hàng liên tục đổ về và cần được lưu trữ trong một danh sách liên kết để xử lý dần.

//Yêu cầu : Hãy hoàn thành các hàm còn thiếu để thực hiện kịch bản sau :

//1.Nhận đơn thường : Đơn mới đến thì xếp vào cuối hàng(AddTail).

//2.Nhận đơn VIP : Khách quen gọi điện, cần ưu tiên xếp ngay lên đầu(AddHead).

//3.Kiểm tra đơn : Khách hỏi đơn hàng mã X có trong danh sách không(Search).

//4.Hủy đơn : Khách đổi ý không mua nữa, cần xóa đơn mã K ra khỏi danh sách(RemoveNode).

//5.Sắp xếp kho : Cuối ngày, nhân viên cần sắp xếp lại các đơn hàng theo thứ tự mã số tăng dần để dễ tìm(SortList).

//6.Chèn đơn sót : Sau khi sắp xếp, phát hiện sót một đơn, cần chèn vào đúng vị trí để không làm hỏng thứ tự(InsertSorted).

//7.Chốt ca : Xử lý xong hết, xóa sạch danh sách để nghỉ ngơi(DestroyList).

struct DonHang {
	int maDon;
	DonHang* maDontiepTheo;
};

struct DanhSach {
	DonHang* maDondau;
	DonHang* maDoncuoi;
};

void Init(DanhSach& l) {
	l.maDondau = NULL;
	l.maDoncuoi = NULL;
};

DonHang* taoDonHang(int madonmoi) {
	DonHang* donhangmoi = new DonHang;
	if (donhangmoi == NULL)
		exit(1);
	donhangmoi->maDon = madonmoi;
	donhangmoi->maDontiepTheo = NULL;
	return donhangmoi;
}

void cau1(DanhSach& danhsachmoi, DonHang* donthuong) {   // AddTail
	if (danhsachmoi.maDondau == NULL) {
		danhsachmoi.maDondau = donthuong;
		danhsachmoi.maDoncuoi = danhsachmoi.maDondau;
	}
	else {
		danhsachmoi.maDoncuoi->maDontiepTheo = donthuong;
		danhsachmoi.maDoncuoi = donthuong;
	}
}

void cau2(DanhSach& danhsachmoi, DonHang* donvip) {      // AddHead
	if (danhsachmoi.maDondau == NULL) {
		danhsachmoi.maDondau = donvip;
		danhsachmoi.maDoncuoi = danhsachmoi.maDondau;     // Mã đơn hàng cuối hiện tại cũng là mã đơn hàng đầu do danh sách sau khi thêm chỉ có duy nhất một phần tử
	}
	else {
		donvip->maDontiepTheo = danhsachmoi.maDondau;
		danhsachmoi.maDondau = donvip;
	}
}

bool cau3(DanhSach danhsach, int madonX) {
	if (madonX == NULL || danhsach.maDondau == NULL)
		return false;
	DonHang* cacdonhang = danhsach.maDondau;
	while (cacdonhang != NULL || cacdonhang->maDon != madonX)
		cacdonhang = cacdonhang->maDontiepTheo;

}

int main() {
	DanhSach danhsach;
	Init(danhsach);
	cau1(danhsach, taoDonHang(1));
	cau2(danhsach, taoDonHang(2));
	/*cout << danhsach.maDondau->maDon << endl;
	cout << danhsach.maDoncuoi->maDon << endl;
	cout << danhsach.maDondau->maDontiepTheo->maDon << endl;
	cout << danhsach.maDondau->maDontiepTheo->maDon;*/

	return 0;
}

