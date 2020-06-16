#include <iostream>
#include <vector>

using namespace std;

int n=0;
int k=0;
int *a;

bool dfs(int i, int sum)
{
	if (sum==k) return true;
	if (i==n) return false;
	if (dfs(i+1,sum)) return true;
	if (dfs(i+1,sum+::a[i])) return true;
	return false;
}

int main(int argc, char *argv[])
{
	cin >> ::n;
	::a=new int[n];
	for (int i = 0; i < ::n; i++) cin >> a[i];
	cin >> ::k;

	if (dfs(0,0)) printf("Yes\n"); else printf("No\n");
	delete[] a;
	return 0;
}

