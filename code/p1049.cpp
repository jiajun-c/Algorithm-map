#include <iostream>
#define N 200100
using namespace std;
int a[40],v;
int dp[N];
int main() {
    int n;
    scanf("%d%d",&v,&n);
    for (int i = 1;i <= v;i++) dp[i] = i;
    for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
    for (int i = 1;i <= n;i++) {
        for (int j = v;j >= a[i];j--) {
            dp[j] = min(dp[j],dp[j-a[i]]);
        }
    }
    printf("%d",dp[v]);
}
