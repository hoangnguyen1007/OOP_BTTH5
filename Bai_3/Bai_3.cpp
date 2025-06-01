#include "GiaoDich.h"

int main()
{
	gdVang v[1000];
	cout << "Nhap so giao dich vang: ";
	int n1;
	cin >> n1;
	while (cin.fail() || n1 < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so giao dich vang: ";
		cin >> n1;
	}
	for (int i = 0; i < n1; i++)
	{
		cout << "Nhap thong tin giao dich vang thu "<<i + 1 << ":" << endl;
		cin >> v[i];
	}
	gdTienTe tt[1000];
	cout << "Nhap so giao dich tien te: ";
	int n2;
	cin >> n2;
	while (cin.fail() || n1 < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so giao dich tien te: ";
		cin >> n2;
	}
	for (int i = 0; i < n2; i++)
	{
		cout << "Nhap thong tin giao dich tien te thu " << i + 1 << ":" << endl;
		cin >> tt[i];
	}
	long long maxT = 0;
	int index1 = -1;
	for (int i = 0; i < n1; i++)
	{
		if (v[i].getThanhTien() > maxT)
		{
			maxT = v[i].getThanhTien();
			index1 = i;
		}
	}
	if (index1 == -1) cout << "Khong co giao dich vang nao!" << endl;
	else
	{
		cout << "---------------------------" << endl;
		cout << "Thong tin giao dich vang co thanh tien lon nhat: " << endl;
		cout << v[index1];
		cout << "Thanh tien: " << v[index1].getThanhTien() << endl;
	}
	long long minT = 0;
	int index2 = -1;
	for (int i = 0; i < n2; i++)
	{
		if (tt[i].getLoaiTien() == "Euro")
		{
			if (index2 == -1 || tt[i].getThanhTien() < minT)
			{
				minT = tt[i].getThanhTien();
				index2 = i;
			}
		}
	}
	if (index2 == -1)
	{
		cout << "Khong co giao dich ngoai te Euro nao!" << endl;
	}
	else
	{
		cout << "---------------------------" << endl;
		cout << "Thong tin giao dich Euro co thanh tien thap nhat la: " << endl;
		cout << tt[index2];
		cout << "Thanh tien: " << tt[index2].getThanhTien() << endl;
	}
	bool found = false;
	cout << "=======DACH SACH CAC GIAO DICH TREN 1.000.000.000=======" << endl;
	for (int i = 0; i < n1; i++)
	{
		if (v[i].getThanhTien() > 1000000000)
		{
			cout << "---------------------------" << endl;
			found = true;
			cout << v[i];
			cout << "Thanh tien: " << v[i].getThanhTien() << endl;
		}
	}
	for (int i = 0; i < n2; i++)
	{
		if (tt[i].getThanhTien() > 1000000000)
		{
			cout << "---------------------------" << endl;
			found = true;
			cout << tt[i];
			cout << "Thanh tien: " << tt[i].getThanhTien() << endl;
		}
	}
	if (!found) cout << "Khong co giao dich nao tren 1.000.000.000";
	return 0;
}