#include "BatDongSan.h"

int main()
{
	int n1, n2, n3;
	gdDat d[1000];
	gdNhaPho p[1000];
	gdChungCu c[1000];
	cout << "Nhap so giao dich Dat: ";
	cin >> n1;
	while (cin.fail() || n1 < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so giao dich Dat: ";
		cin >> n1;
	}
	for (int i = 0; i < n1; i++)
	{
		cout << "---Nhap giao dich dat thu " << i + 1 << "---" << endl;
		cin >> d[i];
	}
	cout << "Nhap so giao dich nha pho: ";
	cin >> n2;
	while (cin.fail() || n2 < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so giao dich nha pho: ";
		cin >> n2;
	}
	for (int i = 0; i < n2; i++)
	{
		cout << "---Nhap giao dich nha pho thu " << i + 1 << "---" << endl;
		cin >> p[i];
	}
	cout << "Nhap so giao dich chung cu: ";
	cin >> n3;
	while (cin.fail() || n3 < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so giao dich chung cu: ";
		cin >> n3;
	}
	long long tong_tien_chung_cu = 0;
	for (int i = 0; i < n3; i++)
	{
		cout << "---Nhap giao dich chung cu thu " << i + 1 << "---" << endl;
		cin >> c[i];
		tong_tien_chung_cu += c[i].getThanhTien();
	}
	cout << "=======================================================" << endl;
	cout << "-So giao dich Dat: " << gdDat::getSoGDDat()<<endl;
	cout << "-So giao dich nha pho: " << gdNhaPho::getSoGDNhaPho() << endl;
	cout << "-So giao dich chung cu: " << gdChungCu::getSoGDChungCu() << endl;
	if (n3 > 0)
		cout << "-Trung binh thanh tien cua giao dich chung cu: " << tong_tien_chung_cu / n3 << endl;
	else
		cout << "Khong co giao dich chung cu nao." << endl;
	int index = -1;
	int maxT = 0;
	for (int i = 0; i < n2; i++)
	{
		if (p[i].getThanhTien() > maxT)
		{
			maxT = p[i].getThanhTien();
			index = i;
		}
	}
	if (index == -1) cout << "Khong co giao dich nha pho nao!" << endl;
	else
	{
		cout << "Thong tin cua giao dich nha pho co thanh tien cao nhat la: " << endl;
		cout << p[index];
	}
	bool found = false;
	for (int i = 0; i < n1; i++)
	{
		if (d[i].getNgayGD().getNam() == 2024 && d[i].getNgayGD().getThang() == 12)
		{
			found = true;
			cout << "-------------------------------" << endl;
			cout << d[i];
		}
	}
	for (int i = 0; i < n2; i++)
	{
		if (p[i].getNgayGD().getNam() == 2024 && p[i].getNgayGD().getThang() == 12)
		{
			found = true;
			cout << "-------------------------------" << endl;
			cout << p[i];
		}
	}
	for (int i = 0; i < n3; i++)
	{
		if (c[i].getNgayGD().getNam() == 2024 && c[i].getNgayGD().getThang() == 12)
		{
			found = true;
			cout << "-------------------------------" << endl;
			cout << c[i];
		}
	}
	if (!found) cout << "Khong co giao dich nao trong thang 12 nam 2024" << endl;
	return 0;
}