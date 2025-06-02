#include "BatDongSan.h"
//Hàm constructor mặc định của lớp bất động sản
BatDongSan::BatDongSan()
{
	ma_gd = "";
	don_gia = 0;
	thanh_tien = 0;
	dien_tich = 0;
}
//Hàm nhập và kiểm tra dữ liệu đầu vào của lớp bất động sản
void BatDongSan::Nhap()
{
	cout << "Nhap ma giao dich: ";
	cin >> ma_gd;
	ngay_gd.Nhap();
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
	cout << "Nhap dien tich: ";
	cin >> dien_tich;
	while (cin.fail() || dien_tich < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap dien tich: ";
		cin >> dien_tich;
	}
}
//Hàm xuất các thông tin chung của các loại bất động sản
void BatDongSan::Xuat() const
{
	cout << "Ma giao dich: " << ma_gd << endl;
	cout << "Ngay giao dich: ";
	ngay_gd.Xuat();
	cout << endl;
	cout << "Don gia: " << don_gia << endl;
	cout << "Dien tich: " << dien_tich << endl;
}
//Hàm getter lấy và trả về giá trị thành tiền của 1 bất động sản
long long BatDongSan::getThanhTien() const
{
	return thanh_tien;
}
//Hàm lấy và trả về ngày giao dịch của 1 bất động sản
NgayThangNam BatDongSan::getNgayGD()
{
	return ngay_gd;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, BatDongSan& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const BatDongSan& x)
{
	x.Xuat();
	return os;
}
//Đặt giá trị ban đầu của số giao dịch đất bằng 0
int gdDat::so_gdDat = 0;
//Hàm constructor mặc định của lớp giao dịch đất
gdDat::gdDat()
{
	loai_dat = "";
}
//Hàm nhập và kiểm tra dữ liệu đầu vào của 1 giao dịch đất
void gdDat::Nhap()
{
	BatDongSan::Nhap();
	cout << "Nhap loai dat: ";
	cin >> loai_dat;
	while (loai_dat != "A" && loai_dat != "B" && loai_dat != "C" && loai_dat != "a" && loai_dat != "b" && loai_dat != "c")
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap loai dat: ";
		cin >> loai_dat;
	}
	if (loai_dat == "A" || loai_dat == "a") thanh_tien = dien_tich * don_gia * 1.5;
	else thanh_tien = dien_tich * don_gia;
	so_gdDat++;
}
//Hàm xuất các giá trị chung và riêng của 1 giao dịch đất
void gdDat::Xuat() const
{
	BatDongSan::Xuat();
	cout << "Loai dat: " << loai_dat << endl;
	cout << "Thanh tien: " << thanh_tien << endl;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, gdDat& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const gdDat& x)
{
	x.Xuat();
	return os;
}
//Hàm getter lấy và trả về loại đất
string gdDat::getLoaiDat() const
{
	return loai_dat;
}
//Hàm tĩnh lấy số giao dịch đất
int gdDat::getSoGDDat()
{
	return so_gdDat;
}
//Đặt giá trị ban đầu của biến tĩnh đếm số giao dịch nhà phố = 0
int gdNhaPho::so_gdNhaPho = 0;
gdNhaPho::gdNhaPho()
{
	dia_chi = "";
	loai_nha = "";
}
//Hàm nhập và kiểm tra dữ liệu đầu vào của một giao dịch nhà phố
void gdNhaPho::Nhap()
{
	BatDongSan::Nhap();
	cout << "Nhap loai nha: ";
	cin.ignore();
	getline(cin, loai_nha);
	while (loai_nha != "thuong" && loai_nha != "cao cap" && loai_nha != "Thuong" && loai_nha != "Cao cap")
	{
		cin.clear();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap loai nha: ";
		getline(cin, loai_nha);
	}
	if (loai_nha == "thuong" || loai_nha == "Thuong") thanh_tien = dien_tich * don_gia * 0.9;
	else thanh_tien = dien_tich * don_gia;
	cout << "Nhap dia chi: ";
	getline(cin, dia_chi);
	so_gdNhaPho++;
}
//Hàm xuất các giá trị chung và riêng của 1 giao dịch nhà phố
void gdNhaPho::Xuat() const
{
	BatDongSan::Xuat();
	cout << "Loai nha: " << loai_nha << endl;
	cout << "Dia chi: " << dia_chi << endl;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, gdNhaPho& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const gdNhaPho& x)
{
	x.Xuat();
	return os;
}
//Hàm getter lấy và trả về loại nhà
string gdNhaPho::getLoaiNha() const
{
	return loai_nha;
}
//Hàm getter lấy và trả về địa chỉ
string gdNhaPho::getDiaChi() const
{
	return dia_chi;
}
//Hàm tĩnh lấy và trả về số giao dịch nhà phố
int gdNhaPho::getSoGDNhaPho()
{
	return so_gdNhaPho;
}
//Đặt giá trị ban đầu cho biến tĩnh đếm số giao dịch chung cư bằng 0
int gdChungCu::so_gdChungCu = 0;
//Hàm constructor mặc định của lớp giao dịch chung cư
gdChungCu::gdChungCu()
{
	tang = 0;
	ma_can = "";
}
//Hàm nhập và kiểm tra dữ liệu đầu vào của một giao dịch chung cư
void gdChungCu::Nhap()
{
	BatDongSan::Nhap();
	cout << "Nhap ma can: ";
	cin >> ma_can;
	cout << "Nhap vi tri tang: ";
	cin >> tang;
	while (cin.fail() || tang < 1)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap vi tri tang: ";
		cin >> tang;
	}
	if (tang == 1) thanh_tien = dien_tich * don_gia * 2;
	else if (tang >= 15) thanh_tien = dien_tich * don_gia * 1.2;
	else thanh_tien = don_gia * dien_tich;
	so_gdChungCu++;
}
//Hàm xuất các thông tin chung và riêng của một giao dịch chung cư
void gdChungCu::Xuat() const
{
	BatDongSan::Xuat();
	cout << "Ma can: " << ma_can << endl;
	cout << "Vi tri tang: " << tang << endl;
}
//Hàm getter lấy và trả về giá trị của mã căn chung cư
string gdChungCu::getMaCan()
{
	return ma_can;
}
//Hàm getter lấy và trả về giá trị của vị trí tầng
int gdChungCu::getTang()
{
	return tang;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, gdChungCu& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const gdChungCu& x)
{
	x.Xuat();
	return os;
}
//Hàm tĩnh lấy và trả về số giao dịch chung cư
int gdChungCu::getSoGDChungCu()
{
	return so_gdChungCu;
}