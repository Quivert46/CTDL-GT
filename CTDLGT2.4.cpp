#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

struct Sinhvien
{
	int masv;
	char tensv[50];
	char lop[20];
	float diemtk;
};

void nhap(Sinhvien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap sinh vien thu " << i + 1 << endl;

		cout << "Ma SV: ";
		cin >> a[i].masv;
		cin.ignore();

		cout << "Ten SV: ";
		cin.getline(a[i].tensv, 50);

		cout << "Lop: ";
		cin.getline(a[i].lop, 20);

		cout << "Diem tong ket: ";
		cin >> a[i].diemtk;
	}
}

void hienthi(Sinhvien a[], int n)
{
	cout << "\nDanh sach sinh vien\n";

	for (int i = 0; i < n; i++)
	{
		cout << "Ma SV: " << a[i].masv << endl;
		cout << "Ten SV: " << a[i].tensv << endl;
		cout << "Lop: " << a[i].lop << endl;
		cout << "Diem TK: " << a[i].diemtk << endl;
		cout << "-------------------\n";
	}
}

void sapxep(Sinhvien a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vitri = i;

		for (int j = i + 1; j < n; j++)
		{
			if (a[j].diemtk < a[vitri].diemtk)
			{
				vitri = j;
			}
		}

		if (vitri != i)
		{
			Sinhvien tam = a[i];
			a[i] = a[vitri];
			a[vitri] = tam;
		}
	}
}

void timkiem(Sinhvien a[], int n, float X)
{
	int left = 0;
	int right = n - 1;
	bool found = false;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (a[mid].diemtk == X)
		{
			int i = mid;

			while (i >= 0 && a[i].diemtk == X)
			{
				i--;
			}

			i++;

			while (i < n && a[i].diemtk == X)
			{
				cout << "Ma SV: " << a[i].masv << endl;
				cout << "Ten SV: " << a[i].tensv << endl;
				cout << "Lop: " << a[i].lop << endl;
				cout << "Diem TK: " << a[i].diemtk << endl;
				cout << "-------------------\n";

				found = true;
				i++;
			}

			break;
		}
		else if (a[mid].diemtk < X)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	if (!found)
	{
		cout << "Khong tim thay sinh vien co diem TK = "
			 << X << endl;
	}
}

int main()
{
	Sinhvien a[100];

	int n;
	cout << "Nhap so sinh vien: ";
	cin >> n;
	cin.ignore();

	nhap(a, n);

	cout << "\nDanh sach vua nhap\n";
	hienthi(a, n);

	sapxep(a, n);

	cout << "\nDanh sach sau khi sap xep\n";
	hienthi(a, n);


	float X;
	cout << "\nNhap diem tong ket can tim: ";
	cin >> X;

	cout << "\nSinh vien co diem TK = " << X << endl;
	timkiem(a, n, X);

	return 0;
}

