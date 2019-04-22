#include <fstream>
#include <iostream>
using namespace std;

int docfile(int a[], int &n)
{
	ifstream f("BAI4a.inp");
	if (f.fail())
		return 0;
	f>>n;
	for (int i=0; i<n; ++i) {
		f>>a[i];
	}
	f.close();
	return 1;
}

void ghifile(int n)
{
	ofstream f("BAI4.out");
	f<<n<<endl;
	f.close();
}


int bai4(int a[], int n, int tong)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] + a[j] == tong)
				dem++;
	return dem;
}

int main()
{
	int n, a[10000];
	int tong = 36142 ;
	if (docfile(a, n))
	{
		ghifile(bai4(a, n, tong));
	}
	else
	{
		cout<<"Khong tim thay file input."<<endl;
	}
	return 0;
}