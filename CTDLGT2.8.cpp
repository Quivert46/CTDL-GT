#include <iostream>
using namespace std;
struct sv
{
	int ma;
	char ten[50];
	char lop[20];
	float diem;
};

void nhap(sv *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Nhap thong tin sv " << i+1 << endl;
		cout << "Nhap ma SV: ";
		cin >> a[i].ma;
		cin.ignore();
		
		cout << "Nhap ten SV: ";
		cin.getline(a[i].ten, 50);
		
		cout << "Nhap lop: ";
		cin.getline(a[i].lop, 20);
		
		cout << "Diem tong ket: ";
		cin >> a[i].diem;
		cin.ignore();
	}
}

void hienthi(sv *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Ma SV: " << a[i].ma << endl;
		cout << "Ten SV:: " << a[i].ten << endl;
		cout << "Lop: " << a[i].lop << endl;
		cout << "Diem tong ket: " << a[i].diem << endl;
	}
}

void sx(sv *a, int n)
{
	int i, j, tg;
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j<i;j--)
		if(a[j].diem < a[j-1].diem)
		{
			tg = a[j].diem;
			a[j] = a[j-1];
			a[j-1].diem = tg;
		}
	}
}

void timkiem(sv *a, int n, float x)
{
	int l = 0;
	int r = n-1;
	bool found = false;
	
	while(l <= r)
	{
		int m = (l+r) / 2;
		
		if(a[m].diem == x)
		{
			int i = m;
			
			while(i>=0 && a[i].diem == x)
			{
				i--;
			}
			
			i++;
			
			while(i<n && a[i].diem == x)
			{
				cout << "Ma SV: " << a[i].ma << endl;
				cout << "Ten SV: " << a[i].ten << endl;
				cout << "Lop: " << a[i].lop << endl;
				cout << "Diem tong ket: " << a[i].diem << endl;
				
				found = true;
				i++;
			}
			
			break;
		}
		else if(a[m].diem < x)
			l = m + 1;
		else
			r = m - 1;
	}
	if(!found)
	{
		cout << "Khong tim thay sinh vien co diem = " << x << endl;
	}
}

int main()
{
	int n;
	do
	{
		cout << "Nhap so SV: ";
		cin >> n;
	}
	while(n<=0);
	cin.ignore();
	
	sv *a = new sv[n];
	
	nhap(a, n);
	cout << "Danh sach SV: \n";
	hienthi(a, n);
	sx(a, n);
	cout << "Danh sach sau sap xep: \n";
	hienthi(a, n);
	
	float x;
	cout << "Nhap diem tong ket muon tim: ";
	cin >> x;
	
	cout << "Danh sach SV co diem " << x << endl;
	timkiem(a, n, x);
	
	return 0;
}
