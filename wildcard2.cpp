#include <iostream>
#include <string>
using namespace std;

int cache[101][101];
void clearCache()
{
	for (int i=0;i<101;i++)
		for (int j=0;j<101;j++)
			cache[i][j]=-1;
}

string W,S;
bool matchMemoized(int w, int s)
{
	int& ret=cache[w][s];
	if (-1!=ret) return ret;
	while (s<S.size() && w<W.size() && ('?'==W[w] || W[w]==S[s]))
	{
		w++;
		s++;
	}
	if (w==W.size()) return ret=(s==S.size());
	if ('*'==W[w])
		for (int skip=0;skip+s<=S.size();skip++)
			if (matchMemoized(w+1,s+skip)) 
				return ret=1;
	return ret=0;
}

int main(int argc, char *argv[])
{
	int c=0;
	cin >> c;
	string line;
	getline(cin,line);
	for (int index=0;index<c;index++)
	{
		getline(cin,::W);
		int n=0;
		cin >> n;
		getline(cin,line);
		for (int i=0;i<n;i++)
		{
			getline(cin,::S);
			clearCache();
			if (matchMemoized(0,0)) cout << ::S << endl;
		}
	}
	return 0;
}


