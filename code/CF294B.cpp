#include <iostream>
#define N 1010
using namespace std;
int sum, dp[N],t[N],w[N]; 
int main() {
    int n;

    scanf("%d",&n);
    for (int i = 1;i <= n;i++) {
        scanf("%d%d",&t[i],&w[i]);
        w[i] += t[i];
        sum += t[i];
    }
    for (int i = 1;i <= n;i++) 
        for (int j = sum;j >= w[i];j--) 
            dp[j] = max(dp[j], dp[j-w[i]]+t[i]);
    printf("%d\n",sum - dp[sum]);
}
