#include "GiaoDich.h"
//Hàm constructor mặc định của lớp giao dịch
GiaoDich::GiaoDich()
{
	ma_gd = "MS000";
    don_gia = 0;
    so_luong = 0;
    thanh_tien = 0;
}
//Hàm nhập thông tin chung của các loại giao dịch
void GiaoDich::Nhap()
{
    cout << "Nhap ma giao dich: ";
    cin.ignore();
    getline(cin, ma_gd);
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
}
//Hàm xuất thông tin chung của các loại giao dịch
void GiaoDich::Xuat() const
{
    cout << "Ma giao dich: " << ma_gd << endl;
    cout << "Ngay giao dich: ";
    ngay_gd.Xuat();
    cout << endl;
    cout << "Don gia: " << don_gia<< endl;
    cout << "So luong: " << so_luong<< endl;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, GiaoDich& x)
{
    x.Nhap();
    return is;
}
//Hàm bạn xuất chồng toán tử nhập bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const GiaoDich& x)
{
    x.Xuat();
    return os;
}
//Hàm getter lấy và trả về thành tiền của giao dịch
long long GiaoDich::getThanhTien()
{
    return thanh_tien;
}
//Hàm constructor mặc định của lớp giao dịch vàng
gdVang::gdVang()
{
    loai_vang = "";
}
//Hàm nhập các thông tin chung và riêng của lớp giao dịch vàng và tính thành tiền
void gdVang::Nhap()
{
    GiaoDich::Nhap();
    cout << "Nhap loai vang: ";
    cin.ignore();
    getline(cin, loai_vang);
    thanh_tien = so_luong * don_gia;
}
//Hàm xuất các thông tin chung và riêng của lớp giao dịch vàng
void gdVang::Xuat() const
{
    GiaoDich::Xuat();
    cout << "Loai vang: " << loai_vang << endl;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, gdVang& x)
{
    x.Nhap();
    return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const gdVang& x)
{
    x.Xuat();
    return os;
}
//Hàm getter lấy và trả về loại vàng
string gdVang::getLoaiVang()
{
    return loai_vang;
}
//Hàm constructor mặc định của lớp giao dịch tiền tệ
gdTienTe::gdTienTe()
{
    loai_tien = "";
    ti_gia = 0;
}
//Hàm nhập và kiểm tra điều kiện nhập của lớp giao dịch tiền tệ, tính toán thành tiền
void gdTienTe::Nhap()
{
    GiaoDich::Nhap();
    cout << "Nhap ti gia: ";
    cin >> ti_gia;
    while (cin.fail() || ti_gia < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "Khong hop le! Vui long nhap lai!" << endl;
        cout << "Nhap ti gia: ";
        cin >> ti_gia;
    }
    cout << "Nhap loai tien: ";
    cin.ignore();
    getline(cin, loai_tien);
    while (loai_tien != "Viet Nam" && loai_tien != "USD" && loai_tien != "Euro")
    {
        cin.clear();
        cout << "Khong hop le! Vui long nhap lai!" << endl;
        cout << "Nhap loai tien: ";
        getline(cin, loai_tien);
    }
    if (loai_tien == "Viet Nam") thanh_tien = so_luong * don_gia;
    else thanh_tien = so_luong * don_gia * ti_gia;
}
//Hàm xuất các giá trị chung và riêng của lớp giao dịch tiền tệ
void gdTienTe::Xuat() const
{
    GiaoDich::Xuat();
    cout << "Ti gia: " << ti_gia << endl;
    cout << "Loai tien: " << loai_tien << endl;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, gdTienTe& x)
{
    x.Nhap();
    return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const gdTienTe& x)
{
    x.Xuat();
    return os;
}
//Hàm getter lấy và trả về loại tiền 
string gdTienTe::getLoaiTien()
{
    return loai_tien;
}
//Hàm getter lấy và trả về giá trị tỉ giá của giao dịch tiền tệ
double gdTienTe::getTiGia()
{
    return ti_gia;
}