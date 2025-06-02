#pragma once
#include "NgayThangNam.h"
#include <iostream>
#include <string>
using namespace std;
class BatDongSan
{
protected:
	string ma_gd;
	NgayThangNam ngay_gd;
	long long don_gia, thanh_tien;
	double dien_tich;
public:
	BatDongSan();
	void Nhap();
	void Xuat() const;
	long long getThanhTien() const;
	NgayThangNam getNgayGD();
	friend istream& operator>>(istream&, BatDongSan&);
	friend ostream& operator<<(ostream&, const BatDongSan&);
};
class gdDat : public BatDongSan
{
private:
	string loai_dat;
	static int so_gdDat;
public:
	gdDat();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, gdDat&);
	friend ostream& operator<<(ostream&, const gdDat&);
	string getLoaiDat() const;
	static int getSoGDDat();
};
class gdNhaPho : public BatDongSan
{
private:
	string loai_nha, dia_chi;
	static int so_gdNhaPho;
public:
	gdNhaPho();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, gdNhaPho&);
	friend ostream& operator<<(ostream&, const gdNhaPho&);
	string getLoaiNha() const;
	string getDiaChi() const;
	static int getSoGDNhaPho();
};
class gdChungCu : public BatDongSan
{
private:
	string ma_can;
	int tang;
	static int so_gdChungCu;
public:
	gdChungCu();
	void Nhap();
	void Xuat() const;
	string getMaCan();
	int getTang();
	friend istream& operator>>(istream&, gdChungCu&);
	friend ostream& operator<<(ostream&, const gdChungCu&);
	static int getSoGDChungCu();
};
