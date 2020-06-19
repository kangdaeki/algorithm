#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000007LL;

matrix operator * (const matrix &a, const matrix &b) 
{
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) 
        {
            for (int k=0; k<n; k++) c[i][j] += a[i][k] * b[k][j];
            c[i][j] %= mod;
        }
    return c;
}

int main() 
{
    long long n=0LL;

    cin >> n;

    if (1LL>=n) 
    {
        cout << n << endl;
        return 0;
    }

    matrix ans = {{1LL, 0LL}, {0LL, 1LL}};
    matrix a = {{1LL, 1LL}, {1LL, 0LL}};

    while (0LL<n) 
    {
        if (1LL==(n%2LL)) ans = ans * a;
        a = a * a;
        n /= 2LL;
    }

    cout << ans[0][1] << endl;

    return 0;
}
