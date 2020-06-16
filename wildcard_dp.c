#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool match(const string& w, const string& s)
{
	int cache[100][100] = { 1 };	//첫번째 공백과 공백은 True
	for (int wp = 1; wp <= w.size(); wp++)
	{
		for (int sp = wp; sp <= s.size(); sp++) //대각아랫부분은 비교대상에서 제외
		{
			if ((s[sp - 1] == w[wp - 1] || w[wp - 1] == '?') && cache[wp - 1][sp - 1] == 1)	// 비교문자가 같거나 w가 ?인 경우 (대각상속)
				cache[wp][sp] = 1;
			else if (w[wp - 1] == '*' && (cache[wp][sp - 1] == 1 || cache[wp - 1][sp - 1] == 1)) // w문자가 *인경우 (왼쪽or대각 상속)
				cache[wp][sp] = 1;
		}
	}

	if (cache[w.size() - 1][s.size() - 1])
		return true;
}


int main(int argc, char* argv[])
{
	ifstream inputfile("C:/input.dat");
	if (false == inputfile.is_open())	//연결안됐을시
	{
		cerr << "Unable to open()" << endl;	//에러출력
		return -1;
	}
	int c = 0;
	inputfile >> c;
	string line;
	getline(inputfile, line);
	for (int cindex = 0; cindex < c; cindex++)
	{
		string w;
		getline(inputfile, w);
		int n = 0;
		inputfile >> n;
		getline(inputfile, line);
		for (int i = 0; i < n; i++)
		{
			string s;
			getline(inputfile, s);
			if (match(w, s)) cout << s << endl;	//true가 반환되어 검색된 문자를 출력
		}
	}

	return 0;
}
