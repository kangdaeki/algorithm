#include <stdio.h>
#include <string.h>

char input[]="cabbabccdw"; // t
char s1[]="abac"; // p1
char s2[]="bbc"; // p2
//char s1[]="a"; // p1
//char s2[]="b"; // p2
const int N=100;

int main()
{
    int both_len=strlen(s1)+strlen(s2);
    for (int t=0;t<strlen(input)-both_len+1;t++)
    {
        bool possible[N][N]={};
        possible[0][0]=true; // null matching case
        for (int p1=1;p1<strlen(s1)+1;p1++)
            if ((possible[p1-1][0]) && (input[t+p1-1]==s1[p1-1])) possible[p1][0]=true;
        for (int p2=1;p2<strlen(s2)+1;p2++)
            if ((possible[0][p2-1]) && (input[t+p2-1]==s2[p2-1])) possible[0][p2]=true;
        for (int p1=1;p1<strlen(s1)+1;p1++)
            for (int p2=1;p2<strlen(s2)+1;p2++)
                if ((possible[p1-1][p2]) && (input[t+p1+p2-1]==s1[p1-1])) possible[p1][p2]=true;
                else if ((possible[p1][p2-1]) && (input[t+p1+p2-1]==s2[p2-1])) possible[p1][p2]=true;
        if (possible[strlen(s1)][strlen(s2)]) fprintf(stdout,"Possible at position %d\n",t);
    }
    return 0;
}
