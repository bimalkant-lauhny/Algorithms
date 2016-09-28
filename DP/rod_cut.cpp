#include <bits/stdc++.h>
using namespace std;

int n;
int *p, *r, *s;

void bottom_up_cut_rod()
{
	r[0] = 0;

	for(int j=1; j<=n; j++)
	{
		int q = INT_MIN;
		for(int i=1; i<=j; i++)
		{
			if(q < p[i] + r[j-i])
			{
				q = p[i] + r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
}

void print_cut_rod_solution()
{
	cout << "The max revenues are as follows\n";
	cout << "Rod Size\tFirst Cut\n";
	for(int i=1; i<=n; i++)
	{
		cout << "  " <<r[i] << "\t\t  " << s[i] << "\n";
	}
}

int main()
{
	cout << "Enter max length of rod:\n";
	cin >> n;

	p = new int [n+1];
	r = new int [n+1];
	s = new int [n+1];

	cout << "Enter array of prices:\n";
	for(int i=1; i<=n; i++)
		cin >> p[i];

	bottom_up_cut_rod();
	print_cut_rod_solution();

	delete[] p, r, s;
	return 0;
}