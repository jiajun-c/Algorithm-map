#include <iostream>
#include <string.h>
#define N 2010
#define ll long long 
using namespace std;
ll t[N], c[N], sum,dp[N*N],ans;
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n;i++) scanf("%lld%lld",&t[i],&c[i]);
    for (int i = 1;i <= n;i++) t[i]++,sum = max(sum,t[i]),ans += c[i];
    sum += n;
    memset(dp,0x3f,sizeof dp); dp[0] = 0; 
    for (int i = 1;i <= n;i++)
        for (int j = sum;j >= t[i];j--)
            dp[j] = min(dp[j-t[i]]+c[i],dp[j]);
    ll fina = INT64_MAX;
    for (int i = n;i <= sum;i++) fina = min(fina,dp[i]); 
    printf("%lld",fina);
}
