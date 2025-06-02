#include "SinhVien.h"

int main()
{
	int n1, n2;
	svCaoDang cd[1000];
	svDaiHoc dh[1000];
	cout << "Nhap so luong sinh vien cao dang: ";
	cin >> n1;
	while (cin.fail() || n1 < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so luong sinh vien cao dang: ";
		cin >> n1;
	}
	cout << "Nhap so luong sinh vien dai hoc: ";
	cin >> n2;
	while (cin.fail() || n2 < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so luong sinh vien dai hoc: ";
		cin >> n2;
	}
	if (n1 == 0 && n2 == 0)
	{
		cout << "Khong co sinh vien nao trong danh sach!";
		return 0;
	}
	for (int i = 0; i < n1; i++)
	{
		cout << "-----Nhap sinh vien cao dang thu " << i + 1 << "-----" << endl;
		cin >> cd[i];
	}
	for (int i = 0; i < n2; i++)
	{
		cout << "-----Nhap sinh vien dai hoc thu " << i + 1 << "-----" << endl;
		cin >> dh[i];
	}
	cout << "============KET QUA CAC YEU CAU=============" << endl;
	for (int i = 0; i < n1; i++)
	{
		cout << "----Sinh vien cao dang thu " << i + 1 << "----" << endl;
		cout << cd[i];
	}
	for (int i = 0; i < n2; i++)
	{
		cout << "----Sinh vien dai hoc thu " << i + 1 << "----" << endl;
		cout << dh[i];
	}
	bool found = false;
	cout << "====SINH VIEN TOT NGHIEP====" << endl;
	for (int i = 0; i < n1; i++)
	{
		if (cd[i].totNghiep())
		{
			found = true;
			cout << "-------------------------------" << endl;
			cout << cd[i];
		}
	}
	for (int i = 0; i < n2; i++)
	{
		if (dh[i].totNghiep())
		{
			found = true;
			cout << "-------------------------------" << endl;
			cout << dh[i];
		}
	}
	if (!found) cout << "Khong co sinh vien nao tot nghiep!" << endl;
	//--------------------------------------------------------------------
	cout << "====SINH VIEN CHUA TOT NGHIEP====" << endl;
	bool found1 = false;
	for (int i = 0; i < n1; i++)
	{
		if (!cd[i].totNghiep())
		{
			found1 = true;
			cout << "-------------------------------" << endl;
			cout << cd[i];
		}
	}
	for (int i = 0; i < n2; i++)
	{
		if (!dh[i].totNghiep())
		{
			found1 = true;
			cout << "-------------------------------" << endl;
			cout << dh[i];
		}
	}
	if (!found1) cout << "Tat ca sinh vien trong danh sach da tot nghiep!" << endl;
	//--------------------------------------------------------------------
	int index = -1;
	double maxT = 0;
	for (int i = 0; i < n2; i++)
	{
		if (dh[i].getDTB() > maxT)
		{
			maxT = dh[i].getDTB();
			index = i;
		}
	}
	if (index == -1) cout << "Khong co sinh vien dai hoc nao trong danh sach!";
	else
	{
		cout << "---Sinh vien dai hoc co diem trung binh cao nhat---" << endl;
		cout<<dh[index];
	}
}