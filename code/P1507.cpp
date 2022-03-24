#include <iostream>
#include <string.h>
#define N 1010
using namespace std;
int dp[N][N],t[N][N];
int a[N][3];
int main() {
    int n,m;
    int k;
    scanf("%d",&k);
    for (int i = 1;i <= k;i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    scanf("%d%d",&n,&m);
   // memset(dp,0x3f,sizeof(dp));
    dp[0][0] = t[0][0] = 0;
    for (int i = 1;i <= k;i++) {
        for (int j = n;j >= a[i][0];j--)
            for (int z = m;z >= a[i][1];z--){
               if(dp[j-a[i][0]][z-a[i][1]] + 1 > dp[j][z]) {
                    dp[j][z] = dp[j-a[i][0]][z-a[i][1]] + 1;
                    t[j][z] = t[j-a[i][0]][z-a[i][1]] + a[i][2];
               }  
               else if (dp[j][z] == dp[j-a[i][0]][z-a[i][1]] + 1) {
                    t[j][z] = min(t[j-a[i][0]][z-a[i][1]]+a[i][2],t[j][z]);
               }
            }
    }
    printf("%d\n",t[n][m]);
}
