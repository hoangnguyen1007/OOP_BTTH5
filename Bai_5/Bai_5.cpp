#include "NhanVien.h"

int main()
{
	nvSanXuat sx[1000];
	nvVanPhong vp[1000];
	int n1, n2;
	cout << "Nhap so nhan vien san xuat: ";
	cin >> n1;
	while (cin.fail() || n1 < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so nhan vien san xuat: ";
		cin >> n1;
	}
	cout << "Nhap so nhan vien van phong: ";
	cin >> n2;
	while (cin.fail() || n2 < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so nhan vien van phong: ";
		cin >> n2;
	}
	for (int i = 0; i < n1; i++)
	{
		cout << "---Nhap nhan vien san xuat thu " << i + 1 << "---" << endl;
		cin >> sx[i];
	}
	for (int i = 0; i < n2; i++)
	{
		cout << "---Nhap nhan vien van phong thu " << i + 1 << "---" << endl;
		cin >> vp[i];
	}
	cout << "========THONG TIN VA LUONG CUA TUNG NHAN VIEN========" << endl;
	for (int i = 0; i < n1; i++)
	{
		cout << "--------Nhan vien san xuat thu " << i + 1 << "---------" << endl;
		cout << sx[i];
	}
	for (int i = 0; i < n2; i++)
	{
		cout << "--------Nhan vien van phong thu " << i + 1 << "---------" << endl;
		cout << vp[i];
	}
	cout << "=> Tong luong phai tra cho cac nhan vien la: " << NhanVien::getTongLuong();
}