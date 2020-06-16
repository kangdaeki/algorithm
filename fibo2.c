#include <stdio.h>
const long long mod = 1000000007LL;

struct Matrix 
{
    long long v[2][2];
};

struct Matrix mypow (struct Matrix a, struct Matrix b) 
{
    static struct Matrix c={};
    for (int i=0; i<2; i++) for (int j=0; j<2; j++) c.v[i][j]=0LL;
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++) 
        {
            for (int k=0; k<2; k++) c.v[i][j] += a.v[i][k] * b.v[k][j];
            c.v[i][j] %= mod;
        }
    return c;
}

int main() 
{
    long long n=0LL;

    fscanf(stdin,"%lld",&n);

    if (1LL>=n) {
        fprintf(stdout,"%lld\n",n);
        return 0;
    }

    struct Matrix ans= {{{1LL, 0LL}, {0LL, 1LL}}};
    struct Matrix a = {{{1LL, 1LL}, {1LL, 0LL}}};

    while (0LL<n) {
        if (1LL==(n%2LL)) ans = mypow(ans,a);
        a = mypow(a,a);
        n /= 2LL;
    }

    fprintf(stdout,"%lld\n",ans.v[0][1]);

    return 0;
}
