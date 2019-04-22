#include <algorithm>
#include <fstream.h>
#include <iostream.h>
#include <math.h>
#include <string>
#include <iomanip>
#define M 444000 
int readFile(int a[], int &n)
{
	ifstream fin("bai2.inp");
	if (fin.fail())
		return 0;
	fin>>n;
	for (int i=0; i<n; ++i) {
		fin>>a[i];
	}
	fin.close();
	return 1;
}

void writeFile(int ans) {
	ofstream fout("BAI2.OUT");
	fout<<ans<<endl;
	fout.close();
}

void pigeonhole (int a[], int n)
{
	int K=0;                   
	for (int i=0; i<n; ++i)
		//K = max(a[i], K);
		if (K<a[i])
		{
			K = a[i];
		}	
	K++;
	int T[K];
	for (int k=0; k<K; k++)
		T[k]=0;
	for (int i=0; i<n; i++)
		T[a[i]]++;
	int i=0;	
	for (int k=0; k<K; k++)
		while (T[k]>0)
		{
			a[i++]=k;
			T[k]--;
		}	
}
int solve(int a[], int n)
{
	pigeonhole(a, n);
	for (int i=0;i<n;i++)
	{
		cout<<a[i];
	}

	int dmin = a[n-1] - a[0];
	for (int i=1; i<n; ++i) {
		//dmin = min(dmin, a[i] - a[i-1]);
		if(dmin>a[i]-a[i-1]) dmin= a[i]-a[i-1];
	}
	return dmin;
}

int main() {
	int n, a[M];
	readFile(a, n);
	writeFile(solve(a, n));
	return 0;
}
