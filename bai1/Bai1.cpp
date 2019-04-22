#include <fstream.h>
#include <iostream.h>
#include<stdlib.h>
#include <math.h>

#define M 33000

int readFile(int a[], int &n) 
{
	ifstream fin("bai1.inp");
	if (fin.fail())
		return 0;
	fin>>n;
	for (int i=0; i<n; ++i) {
		fin>>a[i];
	}
	fin.close();
	return 1;
}

void writeFile(int ans)
{
	ofstream fout("BAI1.out");
	fout<<ans<<endl;
	fout.close();
}

int solve(int a[], int n)
	{
	int l = 0, r = l+1;
	int maxlen = r-l;
	while (l < n-1)
	{
		r = l+1;
		while (r<n && a[r] >= a[r-1])
			++r;
		//maxlen = max(maxlen, r-l);
		if(maxlen<r-l)
			maxlen=r-l;
		l = r;
		
	}
	return maxlen;
}

int main()
{
	int n, a[M];
	if (readFile(a, n)) 
	{
		writeFile(solve(a, n));
	}
	else 
	{
		cout<<"Khong tim thay file input."<<endl;
	}
	return 0;
}
