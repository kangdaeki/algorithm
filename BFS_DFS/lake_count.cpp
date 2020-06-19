#include <iostream>

const int MAX_N=100;
const int MAX_M=100;

using namespace std;

int N=0,M=0;
char field[MAX_N][MAX_M+1];

void read()
{
	scanf("%d ",&N);
	scanf("%d ",&M);
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
			scanf("%c ",&field[i][j]);
}

void print()
{
	printf("%d\n",N);
	printf("%d\n",M);
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<M;j++) printf("%c",field[i][j]);
		printf("\n");
	}
}

void dfs(int x, int y)
{
	field[x][y]='.';
	for (int dx=-1;dx<=1;dx++)
	{
		for (int dy=-1;dy<=1;dy++)
		{
			int nx=x+dx;
			int ny=y+dy;
			if (0<=nx && nx < N && 0<=ny && ny < M && 'W'==field[nx][ny]) dfs(nx,ny);
		}
		
	}
}

int main(int argc, char *argv[])
{
	read();
//	print();
	int res=0;
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<M;j++)
		{
			if ('W'==field[i][j])
			{
				dfs(i,j);
				res++;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}
