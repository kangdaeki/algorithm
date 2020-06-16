#include <stdio.h>
#include <limits.h>

const int N=32;

// 입력 메모리 : input memory
// 점근적 복잡도 계산에서는 무시함.
int board[3][N]={
    {6,7,12,-5,5,3,11,3,6,7,12,-5,5,3,11,3,11,12,7,4,8,-2,9,4,-8,10,14,9,7,13,8,5},
    {-8,10,14,9,7,13,8,5,11,12,7,4,8,-2,9,4,6,7,12,-5,5,3,11,3,6,7,12,-5,5,3,11,3},
    {11,12,7,4,8,-2,9,4,-8,10,14,9,7,13,8,5,6,7,12,-5,5,3,11,3,6,7,12,-5,5,3,11,3},
};

int pebble_cache[N][4]={};  // all are 0

int visited[N][4]={}; // 계산했으면 1, 아니면 0

int w(int i, int p)
{
    switch (p)
    {
        case 0:
            return board[0][i];
            break;
        case 1:
            return board[1][i];
            break;
        case 2:
            return board[2][i];
            break;
        case 3:
            return board[0][i]+board[2][i];
            break;
    }
}

int compliance[4][4]=
{
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,0},
    {0,1,0,0},
};

int pebble(int i, int p)
{
    if (0==i) return w(i,p);
    else 
    {
        if (1==visited[i][p]) return pebble_cache[i][p];
        int max_p=INT_MIN;
        for (int q=0;q<4;q++)
        {
            if (compliance[p][q])
            {
                int tmp=pebble(i-1,q);
                if (0==q) max_p=tmp;
                else if (tmp>max_p) max_p=tmp;
            }
        }
        visited[i][p]=1;
        pebble_cache[i][p]=w(i,p)+max_p;
        return pebble_cache[i][p];
    }
}

int pebbleSum(int n)
{
    int maxsum=pebble(n,0);
    for (int i=1;i<4;i++) 
    {
        int sum=pebble(n,i);
        if (maxsum<sum) maxsum=sum;
    }
    return maxsum;
}

int main()
{
    fprintf(stdout, "%d\n",pebbleSum(N-1)); // i=0..7
    return 0;
}
