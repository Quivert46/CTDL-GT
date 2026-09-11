#include <iostream>
using namespace std;
struct sv
{
	int ma;
	char ten[50];
	char lop[20];
	float diem;
};

void nhap(sv *p, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Nhap thong tin SV thu " << i+1 << endl;
		cout << "Nhap ma SV: ";
		cin >> p[i].ma;
		cin.ignore();
		
		cout << "Nhap ten SV: ";
		cin.getline(p[i].ten, 50);
		
		cout << "Nhap lop: ";
		cin.getline(p[i].lop, 20);
		
		cout << "Nhap diem tong ket: ";
		cin >> p[i].diem;
		cin.ignore();
	}
}

void hienthi(sv *p, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Ma SV: " << p[i].ma << endl;
		cout << "Ten SV: " << p[i].ten << endl;
		cout << "Lop: " << p[i].lop << endl;
		cout << "Diem tong ket: " << p[i].diem << endl;
	}
}

void sx(sv *p, int n)
{
	int po, i, x;
	for(i=1;i<n;i++)
	{
		x = p[i].diem;
		po = i-1;
		while((po>=0)&&(p[po].diem>x))
		{
			p[po+1] = p[po];
			po--;
		}
		p[po+1].diem = x;
	}
}

void timkiem(sv *p, int n, float x)
{
	int l = 0;
	int r = n-1;
	bool found = false;
	
	while(l <= r)
	{
		int m = (l+r) / 2;
		
		if(p[m].diem == x)
		{
			int i = m;
			
			while(i >= 0 && p[i].diem == x)
			{
				i--;
			}
			
			i++;
			
			while(i<n && p[i].diem == x)
			{
				cout << "Ma SV: " << p[i].ma << endl;
				cout << "Ten SV: " << p[i].ten << endl;
				cout << "Lop: " << p[i].lop << endl;
				cout << "Diem tong ket: " << p[i].diem << endl;
				
				found = true;
				i++;
			}
			
			break;
		}
		else if(p[m].diem < x)
			l = m + 1;
		else
			r = m - 1;
	}
	
	if(!found)
	{
		cout << "Khong tim thay SV co diem tk = " << x << endl;
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
	
	sv *p = new sv[n];
	
	nhap(p, n);
	cout << "Danh sach SV: \n";
	hienthi(p, n);
	
	sx(p, n);
	
	cout << "Danh sach sau sx: \n";
	hienthi(p, n);
	
	float x;
	cout << "Nhap diem can tim: ";
	cin >> x;
	
	cout << "Danh sach co diem tk = " << x << endl;
	timkiem(p, n, x);
	
	return 0;
}

