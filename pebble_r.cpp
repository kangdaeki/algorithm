#include <stdio.h>
#include <limits.h>

int board[3][8]={
    {6,7,12,-5,5,3,11,3},
    {-8,10,14,9,7,13,8,5},
    {11,12,7,4,8,-2,9,4}
};


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
        return w(i,p)+max_p;
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
    fprintf(stdout, "%d\n",pebbleSum(7)); // i=0..7
    return 0;

}
