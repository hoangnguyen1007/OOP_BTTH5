#include "NhanVien.h"
//Khởi tạo giá trị ban đầu của biến tĩnh tính tổng lương bằng 0
long long NhanVien::tong_luong = 0;
//Hàm destructor của lớp nhân viên
NhanVien::~NhanVien() {};
//Hàm constructor mặc định của lớp nhân viên
NhanVien::NhanVien() {
	ho_ten = "";
	luong = 0;
}
//Hàm constructor có truyền tham số của lớp nhân viên
NhanVien::NhanVien(string ho_ten, NgayThangNam ngay_sinh) : ho_ten(ho_ten), ngay_sinh(ngay_sinh) {};
//Hàm nhập và kiểm tra dữ liệu đầu vào các thông tin chung của các nhân viên
void NhanVien::Nhap()
{
	cout << "Nhap ho ten: ";
	cin.ignore();
	getline(cin, ho_ten);
	cout << "Nhap ngay sinh: " << endl;
	ngay_sinh.Nhap();
}
//Hàm xuất các thông tin chung của lớp nhân viên
void NhanVien::Xuat() const
{
	cout << "Ho ten: " << ho_ten << endl;
	cout << "Ngay sinh: ";
	ngay_sinh.Xuat();
	cout << endl;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, NhanVien& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const NhanVien& x)
{
	x.Xuat();
	return os;
}
//Hàm getter lấy và trả về họ tên nhân viên
string NhanVien::getHoTen() const
{
	return ho_ten;
}
//Hàm getter lấy và trả về thông tin ngày sinh của nhân viên
NgayThangNam NhanVien::getNgaySinh() const
{
	return ngay_sinh;
}
//Hàm getter lấy và trả vê giá trị lương của nhân viên
long long NhanVien::getLuong() const
{
	return luong;
}
//Hàm lấy và trả về tổng lương trả cho nhân viên
long long NhanVien::getTongLuong()
{
	return tong_luong;
}
//Hàm constructor mặc định của lớp nhân viên văn phòng
nvVanPhong::nvVanPhong() {};
//Hàm constructor có truyền tham số của lớp nhân viên văn phòng
nvVanPhong::nvVanPhong(long long luong_can_ban, int so_san_pham) : luong_can_ban(luong_can_ban), so_san_pham(so_san_pham) {};
//Hàm nhập và kiểm tra dữ liệu đầu vào các thông tin riêng của lớp nhân viên văn phòng
void nvVanPhong::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap luong can ban: ";
	cin >> luong_can_ban;
	while (cin.fail() || luong_can_ban < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap luong can ban: ";
		cin >> luong_can_ban;
	}
	cout << "Nhap so san pham: ";
	cin >> so_san_pham;
	while (cin.fail() || so_san_pham < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so san pham: ";
		cin >> so_san_pham;
	}
	luong = luong_can_ban + so_san_pham * 5000;
	tong_luong += luong;
}
//Hàm xuất các thông tin chung và riêng của lớp nhân viên văn phòng
void nvVanPhong::Xuat() const
{
	NhanVien::Xuat();
	cout << "Luong: " << luong << endl;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, nvVanPhong& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const nvVanPhong& x)
{
	x.Xuat();
	return os;
}
//Hàm getter lấy và trả về giá trị lương cơ bản của nhân viên văn phòng
long long nvVanPhong::getLuongCanBan() const
{
	return luong_can_ban;
}
//Hàm getter lấy và trả về số sản phẩm bán được của lớp nhân viên văn phòng
int nvVanPhong::getSoSanPham() const
{
	return so_san_pham;
}
//Hàm getter trả về loại nhân viên là nhân viên văn phòng
string nvVanPhong::getLoai() const
{
	return "Van phong";
}
//Hàm constructor mặc dịnh của lớp nhân viên sản xuất
nvSanXuat::nvSanXuat() {};
//Hàm constructor có truyền tham số của lớp nhân viên sản xuất
nvSanXuat::nvSanXuat(int so_ngay_cong) : so_ngay_lam_viec(so_ngay_cong) {};
//Hàm nhập và kiểm tra dữ liệu đầu vào của lớp nhân viên sản xuất
void nvSanXuat::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap so ngay lam viec: ";
	cin >> so_ngay_lam_viec;
	while (cin.fail() || so_ngay_lam_viec < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so ngay lam viec: ";
		cin >> so_ngay_lam_viec;
	}
	luong = so_ngay_lam_viec * 100000;
	tong_luong += luong;
}
//Hàm xuất các thông tin chung và riêng của lớp nhân viên sản xuất
void nvSanXuat::Xuat() const
{
	NhanVien::Xuat();
	cout << "Luong: " << luong << endl;
}
//Hàm getter lấy và trả về số ngày làm việc của nhân viên sản xuất
int nvSanXuat::getSoNgayLamViec() const
{
	return so_ngay_lam_viec;
}
//Hàm getter lấy và trả về loại nhân viên là nhân viên sản xuất
string nvSanXuat::getLoai() const
{
	return "San xuat";
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, nvSanXuat& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const nvSanXuat& x)
{
	x.Xuat();
	return os;
}