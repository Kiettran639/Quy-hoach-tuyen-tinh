#include <fstream.h>
#include <iostream.h>
#include <iomanip.h> 
#define M 444000 //1000111

int docFile(int a[], int &n) {
	ifstream fin("bai3.inp");
	if (fin.fail()) 
		return 0;
	fin>>n;
	for (int i=0; i<n; ++i) {
		fin>>a[i];
	}
	fin.close();
	return 1;
}

void ghiFile(int ans) {
	ofstream fout("BAI3.OUT");
	fout<<ans<<endl;
	fout.close();
}

void inMang(int a[], int n) {
	for (int i=0; i<n; ++i) {
		cout<<setw(5)<<a[i];
	}
	cout<<endl;
}

int solve(int a[], int n) {
	int sum[n+10];
	if (0<a[0])
		sum[0] = a[0];
	if (0>a[0])
		sum[0] = 0;
	for (int i=1; i<n; ++i) {
		sum[i] = sum[i-1] + a[i];
		if (sum[i] <= 0) sum[i] = 0;
	}
	int maxsum = 0;
	for (int i=0; i<n; ++i)
	{
		//maxsum = max(maxsum, sum[i]);
		if(maxsum < sum[i])
			maxsum =sum[i];
	}
	if (maxsum == 0) {
		maxsum = a[0];
		for (int i=1; i<n; ++i) {
			//maxsum = max(maxsum, a[i]);
			if(maxsum < a[i])
				maxsum= a[i];
		}
	}
	return maxsum;
}

int main()
	{
	int n, a[M];
	if (docFile(a, n)) {
		ghiFile(solve(a, n));
	}
	else {
		cout<<"Khong tim thay file input."<<endl;
	}
	return 0;
}
