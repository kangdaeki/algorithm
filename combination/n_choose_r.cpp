//#pragma warning(disable:4996)
//#pragma warning(disable:6031)
#include <stdio.h>

#define MAXPICK 100

int picked[MAXPICK] = {};
int n = 0;
int r = 0;

void pick(int pos, int num)
{
   if (pos >= r)
   {
      for (int i=0;i<r;i++) printf("%d ",picked[i]);
      printf("\n");
      return;
   }
   else
   {
      for (int i = num; i < n; i++)
      {
         picked[pos] = i;
         pick(pos + 1, i + 1);
      }
   }

}

// n choose r
int main(int argc, char* argv[])
{
   printf("n:");
   scanf("%d", &n);
   printf("r:");
   scanf("%d", &r);

   int pos = 0;
   for (int i = 0; i < n; i++)
   {
      picked[pos] = i;
      pick(pos+1, i+1);
   }
   return 0;
}