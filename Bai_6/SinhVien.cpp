#include "SinhVien.h"
//Hàm constructor mặc định của lớp sinh viên
SinhVien::SinhVien() {};
//Hàm constructor có truyền tham số của lớp sinh viên
SinhVien::SinhVien(string mssv, string ho_ten, string dia_chi, int tong_so_tin_chi, double diem_trung_binh) : mssv(mssv), ho_ten(ho_ten), dia_chi(dia_chi), tong_so_tin_chi(tong_so_tin_chi), diem_trung_binh(diem_trung_binh) {};
//Hàm nhập và kiểm tra dữ liệu đầu vào các thông tin chung của một sinh viên
void SinhVien::Nhap()
{
	cout << "Nhap ma so sinh vien: ";
	cin >> mssv;
	cout << "Nhap ho ten: ";
	cin.ignore();
	getline(cin, ho_ten);
	cout << "Nhap dia chi: ";
	getline(cin, dia_chi);
	cout << "Nhap tong so tin chi: ";
	cin >> tong_so_tin_chi;
	while (cin.fail() || tong_so_tin_chi < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap tong so tin chi: ";
		cin >> tong_so_tin_chi;
	}
	cout << "Nhap diem trung binh: ";
	cin >> diem_trung_binh;
	while (cin.fail() || diem_trung_binh < 0 || diem_trung_binh > 10)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap diem trung binh: ";
		cin >> diem_trung_binh;
	}
}
//Hàm xuất các thông tin chung của một sinh viên
void SinhVien::Xuat() const
{
	cout << "Ma so sinh vien: " << mssv << endl;
	cout << "Ho va ten: " << ho_ten << endl;
	cout << "Dia chi: " << dia_chi << endl;
	cout << "Tong so tin chi: " << tong_so_tin_chi << endl;
	cout << "Diem trung binh: " << diem_trung_binh << endl;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, SinhVien& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const SinhVien& x)
{
	x.Xuat();
	return os;
}
//Hàm getter lấy và trả về điểm trung bình của một sinh viên
double SinhVien::getDTB() const
{
	return diem_trung_binh;
}
//Hàm getter lấy và trả về mã số sinh viên
string SinhVien::getMSSV() const
{
	return mssv;
}
//Hàm getter lấy và trả về địa chỉ của sinh viên
string SinhVien::getDiaChi() const
{
	return dia_chi;
}
//Hàm getter lấy và trả về họ tên của sinh viên
string SinhVien::getHoTen() const
{
	return ho_ten;
}
//Hàm getter lấy và trả về tổng số tín chỉ của một sinh viên
int SinhVien::getTSTC() const
{
	return tong_so_tin_chi;
}
//Hàm constructor mặc định của lớp sinh viên cao đẳng
svCaoDang::svCaoDang() {};
//Hàm constructor có truyền tham số của lớp sinh viên cao đẳng
svCaoDang::svCaoDang(double diem_thi_tot_nghiep) : diem_thi_tot_nghiep(diem_thi_tot_nghiep) {};
//Hàm tính xem sinh viên có tốt nghiệp chưa, trả về giá trị bool
bool svCaoDang::totNghiep()
{
	return tong_so_tin_chi >= 110 && diem_trung_binh >= 5 && diem_thi_tot_nghiep >= 5;
}
//Hàm getter lấy và trả về điểm thi tốt nghiệp của sinh viên
double svCaoDang::getDiemTN() const
{
	return diem_thi_tot_nghiep;
}
//Hàm nhập và kiểm tra dữ liệu đầu vào của một sinh viên cao đẳng
void svCaoDang::Nhap()
{
	SinhVien::Nhap();
	cout << "Nhap diem thi tot nghiep: ";
	cin >> diem_thi_tot_nghiep;
	while (cin.fail() || diem_thi_tot_nghiep < 0 || diem_thi_tot_nghiep > 10)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap diem thi tot nghiep: ";
		cin >> diem_thi_tot_nghiep;
	}
}
//Hàm xuất các thông tin chung và riêng của sinh viên cao đẳng
void svCaoDang::Xuat() const
{
	SinhVien::Xuat();
	cout << "Diem thi tot nghiep: " << diem_thi_tot_nghiep << endl;
}
//Hàm getter trả về hệ sinh viên là cao đẳng
string svCaoDang::getLoai() const
{
	return "Cao dang";
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, svCaoDang& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const svCaoDang& x)
{
	x.Xuat();
	return os;
}
//Hàm constructor mặc định của lớp sinh viên đại học
svDaiHoc::svDaiHoc() {};
//Hàm constructor có truyền tham số của lớp sinh viên đại học
svDaiHoc::svDaiHoc(string ten_luan_van, double diem_luan_van) : ten_luan_van(ten_luan_van), diem_luan_van(diem_luan_van) {};
//Hàm getter lấy và trả về tên luận văn của sinh viên đại học
string svDaiHoc::getTenLuanVan()
{
	return ten_luan_van;
}
//Hàm getter lấy và trả về điểm luận văn của sinh viên đại học
double svDaiHoc::geDiemLuanVan()
{
	return diem_luan_van;
}
//Hàm nhập và kiểm tra dữ liệu đầu vào của lớp sinh viên đại học
void svDaiHoc::Nhap()
{
	SinhVien::Nhap();
	cout << "Nhap ten luan van: ";
	cin.ignore();
	getline(cin, ten_luan_van);
	cout << "Nhap diem luan van: ";
	cin >> diem_luan_van;
	while (cin.fail() || diem_luan_van < 0 || diem_luan_van > 10)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap diem luan van: ";
		cin >> diem_luan_van;
	}
}
//Hàm xuất các thông tin chung và riêng của một sinh viên đại học
void svDaiHoc::Xuat() const
{
	SinhVien::Xuat();
	cout << "Ten luan van: " << ten_luan_van << endl;
	cout << "Diem luan van: " << diem_luan_van << endl;
}
//Hàm trả về kiểu sinh viên là sinh viên đại học
string svDaiHoc::getLoai() const
{
	return "Dai hoc";
}
//Hàm tính xem sinh viên đại học đủ điều kiện tốt nghiệp của sinh viên đại học và trả về giá trị bool
bool svDaiHoc::totNghiep()
{
	return tong_so_tin_chi >= 145 && diem_trung_binh >= 5 && diem_luan_van >= 5;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, svDaiHoc& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const svDaiHoc& x)
{
	x.Xuat();
	return os;
}
