#include <stdio.h>
#include <string.h>

char s1[]="execution"; // p1
char s2[]="intention"; // p2
//char s1[]="strong"; // p1
//char s2[]="stone"; // p2
const int N=100;
int distance[N][N]={};

int min3(int a, int b, int c)
{
	int tmp=a;
	if (tmp>b) tmp=b;
	if (tmp>c) tmp=c;
	return tmp;
}

int main()
{
  distance[0][0]=0;
  for (int p1=1;p1<strlen(s1)+1;p1++) distance[p1][0]=distance[p1-1][0]+1;
  for (int p2=1;p2<strlen(s2)+1;p2++) distance[0][p2]=distance[0][p2-1]+1;
  for (int p1=1;p1<strlen(s1)+1;p1++)
    for (int p2=1;p2<strlen(s2)+1;p2++) 
	{
		int ins = distance[p1][p2-1]+1;
		int del = distance[p1-1][p2]+1;
		int rep = distance[p1-1][p2-1];
		if (s1[p1-1]!=s2[p2-1]) rep++;
		distance[p1][p2]=min3(ins,del,rep);
	}
  fprintf(stdout, "min. edit distance (%s, %s)= %d\n",s1,s2,distance[strlen(s1)][strlen(s2)]);
  return 0;
}

