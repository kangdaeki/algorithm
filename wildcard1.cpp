#include <iostream>
#include <string>
using namespace std;

bool match(const string& w, const string& s)
{
	int pos=0;
	while (pos<s.size() && pos<w.size() && ('?'==w[pos] || w[pos]==s[pos])) pos++;
	if (pos==w.size()) return pos==s.size();
	if ('*'==w[pos])
		for (int skip=0;pos+skip<=s.size();skip++)
			if (match(w.substr(pos+1),s.substr(pos+skip)))
				return true;
	return false;
}

int main(int argc, char *argv[])
{
	int c=0;
	cin >> c;
	string line;
	getline(cin,line);
	for (int index=0;index<c;index++)
	{
		string w; // wildcard
		getline(cin,w);
		int n=0;
		cin >> n;
		getline(cin,line);
		for (int i=0;i<n;i++)
		{
			string s;
			getline(cin,s);
			if (match(w,s)) cout << s << endl;
		}
	}
	return 0;
}

