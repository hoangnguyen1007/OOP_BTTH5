#pragma once
#include <iostream>
#include <string>
#include "NgayThangNam.h"
using namespace std;
class NhanVien
{
protected:
	string ho_ten;
	NgayThangNam ngay_sinh;
	long long luong;
	static long long tong_luong;
public:
    ~NhanVien();
	NhanVien();
	NhanVien(string, NgayThangNam);
	void Nhap();
	void Xuat() const;
	string getHoTen() const;
	NgayThangNam getNgaySinh() const;
	long long getLuong() const;
	static long long getTongLuong();
	friend istream& operator>>(istream&, NhanVien&);
	friend ostream& operator<<(ostream&, const NhanVien&);
};
class nvVanPhong : public NhanVien
{
private:
	long long luong_can_ban;
	int so_san_pham;
public:
	nvVanPhong();
	nvVanPhong(long long, int);
	void Nhap();
	void Xuat() const;
	long long getLuongCanBan() const;
	int getSoSanPham() const;
	string getLoai() const;
	friend istream& operator>>(istream&, nvVanPhong&);
	friend ostream& operator<<(ostream&, const nvVanPhong&);
};
class nvSanXuat : public NhanVien
{
private:
	int so_ngay_lam_viec;
public:
	nvSanXuat();
	nvSanXuat(int);
	void Nhap();
	void Xuat() const;
	int getSoNgayLamViec() const;
	string getLoai() const;
	friend istream& operator>>(istream&, nvSanXuat&);
	friend ostream& operator<<(ostream&, const nvSanXuat&);
};