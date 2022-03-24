#include <iostream>
#include <string.h>
#define N 1010
#include <algorithm>
using namespace std;
int n, m, dp[N], f[N],a[N];
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
    dp[0] = 1;f[0] = 1;
    for (int i = 1;i <= n;i++) { 
        for (int j = m;j >= a[i];j--) {
            f[j] += f[j-a[i]];
            f[j] %= 10;
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if(j >= a[i]) dp[j] = (f[j] - dp[j-a[i]]+10)%10;
            else dp[j] = f[j]%10;
            printf("%d",dp[j]);
        }
        printf("\n");
    }
}
