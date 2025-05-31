#include "Sach.h"
//Đặt giá trị ban đầu của biến tĩnh thành tiền bằng 0
long long Sach::thanh_tien = 0;
//Hàm constructor mặc định của lớp sách
Sach::Sach() {};
//Hàm nhập và kiểm tra dữ liệu nhập của lớp sách 
void Sach::Nhap()
{
	cout << "Nhap ma sach: ";
	cin.ignore();
	getline(cin, ma_sach);
	ngay_nhap.Nhap();
	cout << "Nhap so luong: ";
	cin >> so_luong;
	while (cin.fail() || so_luong < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so luong: ";
		cin >> so_luong;
	}
	cout << "Nhap don gia: ";
	cin >> don_gia;
	while (cin.fail() || don_gia < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap don gia: ";
		cin >> don_gia;
	}
	cout << "Nhap nha xuat ban: ";
	cin.ignore();
	getline(cin, nha_xb);
}
//Hàm xuất các thông tin chung của 1 quyển sách
void Sach::Xuat() const
{
	cout << "Ma sach: " << ma_sach << endl;
	cout << "Ngay nhap: "; ngay_nhap.Xuat();
	cout << "\nSo luong: " << so_luong << endl;
	cout << "Don gia: " << don_gia << endl;
	cout << "Nha xuat ban: " << nha_xb<<endl;
}
//Hàm getter lấy và trả về mã sách
string Sach::getMaSach() const
{
	return ma_sach;
}
//Hàm getter lấy và trả về ngày nhập sách
NgayThangNam Sach::getNgayNhap() const
{
	return ngay_nhap;
}
//Hàm getter lấy và trả về số lượng sách
int Sach::getSoLuong() const
{
	return so_luong;
}
//Hàm tĩnh lấy và trả về thành tiền của các quyển sách
long long Sach::TinhThanhTien()
{
	return thanh_tien;
}
//Hàm getter lấy và trả về tên nhà xuất bản 
string Sach::getNhaXB() const
{
	return nha_xb;
}
//Hàm setter thay đổi giá trị mã sách
void Sach::setMaSach(string ma_sach)
{
	this->ma_sach = ma_sach;
}
//Hàm setter thay đổi giá trị số lượng sách
void Sach::setSoLuong(int so_luong)
{
	this->so_luong = so_luong;
}
//Hàm setter thay đổi giá trị ngày nhập sách
void Sach::setNgayNhap(NgayThangNam ngay_nhap)
{
	this->ngay_nhap = ngay_nhap;
}
//Hàm setter thay đổi giá trị tên nhà xuất bản
void Sach::setNhaXB(string nha_xb)
{
	this->nha_xb = nha_xb;
}
//Hàm setter thay đổi giá trị đơn giá sách
void Sach::setDonGia(long long don_gia)
{
	this->don_gia = don_gia;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, Sach& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const Sach& x)
{
	x.Xuat();
	return os;
}
//Đặt giá trị ban đầu thành tiền SGK bằng 0
long long Sach_GK::thanh_tien_SGK = 0;
//Hàm constructor mặc định của lớp SGK
Sach_GK::Sach_GK() {};
//Hàm nhập và kiểm tra dữ liệu nhập của lớp SGK
void Sach_GK::Nhap()
{
	Sach::Nhap();
	cout << "Nhap tinh trang: ";
	cin >> tinh_trang;
	while (cin.fail() || (tinh_trang != "cu" && tinh_trang != "moi"))
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai" << endl;
		cout << "Nhap tinh trang: ";
		cin >> tinh_trang;
	}
	if (tinh_trang == "moi")
	{
		long long tien = so_luong * don_gia;
		thanh_tien_SGK += tien;
		thanh_tien += tien;
	}
	else
	{
		long long tien = (so_luong * don_gia * 0.5);
		thanh_tien_SGK += tien;
		thanh_tien += tien;
	}
}
//Hàm xuất các thông tin chung và riêng của SGK
void Sach_GK::Xuat() const
{
	Sach::Xuat();
	cout << "Tinh trang: " << tinh_trang<<endl;
}
//Hàm getter lấy và trả về tình trạng của SGK
string Sach_GK::getTinhTrang()
{
	return tinh_trang;
}
//Hàm getter lấy và trả về thành tiền của các SGK
long long Sach_GK::getThanhTienSGK()
{
	return thanh_tien_SGK;
}
//Hàm setter thay đổi tình trạng của SGK
void Sach_GK::setTinhTrang(string tinh_trang)
{
	this->tinh_trang = tinh_trang;
}
//Hàm tìm kiếm tên nhà xuất bản và trả về giá trị bool
bool Sach_GK::tim(string NXB)
{
	if (NXB == nha_xb) return 1;
	else return 0;
}
//Hàm bạn nạp chông toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator >>(istream& is, Sach_GK& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chông toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const Sach_GK& x)
{
	x.Xuat();
	return os;
}
//Đặt giá trị ban đầu của biến tĩnh thành tiền các STK bằng 0
long long Sach_TK::thanh_tien_STK = 0;
//Đặt giá trị ban đầu của biến tĩnh đơn giá các STK bằng 0
long long Sach_TK::don_gia_STK = 0;
//Đặt giá trị ban đầu của biến tính đếm STK bằng 0
int Sach_TK::dem = 0;
//Hàm constructor mặc định của lớp sách tham khảo
Sach_TK::Sach_TK() {}
//Hàm nhập và kiểm tra dữ liệu đầu vào của lớp STK
void Sach_TK::Nhap()
{
	Sach::Nhap();
	don_gia_STK += don_gia;
	dem++;
	cout << "Nhap thue: ";
	cin >> thue;
	long long tien = so_luong * don_gia + thue;
	thanh_tien_STK += tien;
	thanh_tien += tien;

}
//Hàm xuất thông tin chung và riêng của sách tham khảo
void Sach_TK::Xuat() const
{
	Sach::Xuat();
	cout << "Thue: " << thue<<endl;
}
//Hàm bạn nạp chồng toán tử nhập, bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, Sach_TK& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất, bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const Sach_TK& x)
{
	x.Xuat();
	return os;
}
//Hàm getter lấy và trả về giá trị thuế của sách tham khảo
double Sach_TK::getThue()
{
	return thue;
}
//Hàm getter lấy và trả về giá trị thành tiền của các sách tham khảo
long long Sach_TK::getThanhTienSTK()
{
	return thanh_tien_STK;
}
//Hàm setter thay đổi giá trị thuế
void Sach_TK::setThue(double thue)
{
	this->thue = thue;
}
//Hàm tính trung bình cộng giá tiền của các sách tham khảo
double Sach_TK::tinh_TBC()
{
	return don_gia_STK / dem;
}