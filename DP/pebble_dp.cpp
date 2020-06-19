#include <stdio.h>

const int N=32;

// 입력 메모리 : input memory
// 점근적 복잡도 계산에서는 무시함.
int board[3][N]={
    {6,7,12,-5,5,3,11,3,6,7,12,-5,5,3,11,3,11,12,7,4,8,-2,9,4,-8,10,14,9,7,13,8,5},
    {-8,10,14,9,7,13,8,5,11,12,7,4,8,-2,9,4,6,7,12,-5,5,3,11,3,6,7,12,-5,5,3,11,3},
    {11,12,7,4,8,-2,9,4,-8,10,14,9,7,13,8,5,6,7,12,-5,5,3,11,3,6,7,12,-5,5,3,11,3},
};

int w(int i, int p)
{
    switch (p)
    {
        case 0: return board[0][i];
        case 1: return board[1][i];
        case 2: return board[2][i];
        case 3: return board[0][i]+board[2][i];
    }
}

bool compliance[4][4]=
{
    {false,true,true,false},
    {true,false,true,true},
    {true,true,false,false},
    {false,true,false,false},
};

int pebble[N][4]={};  // all are 0

int pebbleSum(int n)
{
    for (int p=0;p<4;p++) pebble[0][p]=w(0,p);
    for (int i=1;i<n;i++)
    {
        for (int p=0;p<4;p++)
        {
            int max_prev_q=0;
            bool first=true;
            for (int q=0;q<4;q++)
            {
                if (compliance[p][q])
                {
                    if (first) 
                    {
                        first=false;
                        max_prev_q=pebble[i-1][q];
                    }
                    else
                    {
                        if (max_prev_q<pebble[i-1][q]) max_prev_q=pebble[i-1][q];
                    }
                }
            }
            pebble[i][p]=w(i,p)+max_prev_q;
        }
    }
    int maxsum=pebble[n-1][0];
    for (int i=1;i<4;i++) 
    {
        if (maxsum<pebble[n-1][i]) maxsum=pebble[n-1][i];
    }
    return maxsum;
}

int main()
{
    fprintf(stdout, "%d\n",pebbleSum(N)); // i=0..7
    return 0;
}

