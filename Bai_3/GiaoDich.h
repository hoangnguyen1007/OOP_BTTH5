#pragma once
#include <iostream>
#include <string>
#include "NgayThangNam.h"
using namespace std;
class GiaoDich
{
protected:
	string ma_gd;
	NgayThangNam ngay_gd;
	long long don_gia;
	int so_luong;
	long long thanh_tien;
public:
	GiaoDich();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, GiaoDich&);
	friend ostream& operator<<(ostream&, const GiaoDich&);
	long long getThanhTien();
};
class gdVang : public GiaoDich
{
private:
	string loai_vang;
public:
	gdVang();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, gdVang&);
	friend ostream& operator<<(ostream&, const gdVang&);
	string getLoaiVang();
};
class gdTienTe : public GiaoDich
{
private:
	string loai_tien;
	double ti_gia;
public:
	gdTienTe();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, gdTienTe&);
	friend ostream& operator<<(ostream&, const gdTienTe&);
	string getLoaiTien();
	double getTiGia();
};


