#pragma once
#include <iostream>
#include <string>
using namespace std;
class SinhVien
{
protected:
	string mssv, ho_ten, dia_chi;
	int tong_so_tin_chi;
	double diem_trung_binh;
public:
	SinhVien();
	SinhVien(string, string, string, int, double);
	void Nhap();
	void Xuat() const;
	string getLoai() const;
	bool totNghiep();
	double getDTB() const;
	string getMSSV() const;
	string getDiaChi() const;
	string getHoTen() const;
	int getTSTC() const;
	friend istream& operator>>(istream&, SinhVien&);
	friend ostream& operator<<(ostream&, const SinhVien&);
};
class svCaoDang : public SinhVien
{
private:
	double diem_thi_tot_nghiep;
public:
	svCaoDang();
	svCaoDang(double);
	double getDiemTN() const;
	void Nhap();
	void Xuat() const;
	string getLoai() const;
	bool totNghiep();
	friend istream& operator>>(istream&, svCaoDang&);
	friend ostream& operator<<(ostream&, const svCaoDang&);
};
class svDaiHoc : public SinhVien
{
private:
	string ten_luan_van;
	double diem_luan_van;
public:
	svDaiHoc();
	svDaiHoc(string, double);
	string getTenLuanVan();
	double geDiemLuanVan();
	void Nhap();
	void Xuat() const;
	string getLoai() const;
	bool totNghiep();
	friend istream& operator>>(istream&, svDaiHoc&);
	friend ostream& operator<<(ostream&, const svDaiHoc&);
};