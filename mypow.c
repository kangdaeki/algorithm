#include <stdio.h>
int main()
{
    // 7^11
    int n=11;
    int a=7;

    int ans=1;
    while (0<n) 
    {
        if (1==(n%2)) ans = ans * a;
        a = a * a;
        n /= 2;
    }
    printf("%d\n",ans);
    return 0;
}
