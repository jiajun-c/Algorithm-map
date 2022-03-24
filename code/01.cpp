#include <iostream>
#define N 1010
using namespace std;
int n, m, p;
int boost[N], price[N];
int vis[N], dp[N];
struct node {
    int a1,a2;
    int harm;
}E[N];
int main() {
    scanf("%d%d%d",&n,&m,&p);
    for (int i = 1;i <= n;i++) scanf("%d",&boost[i]);
    for (int i = 1;i <= n;i++) scanf("%d",&price[i]);
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        E[i].a1 = x; E[i].a2 = y;E[i].harm = z; 
        vis[x] = vis[y] = 1;
    }
    for (int i = 1;i <= n;i++) {
      if(!vis[i]) E[++m].a1 = i,E[m].a2 = 0;  
    }
    for (int i = 1;i <= m;i++) {
        for (int j = p;j >= 1;j--) {
            int a1 = E[i].a1;
            if(price[a1] <= j) dp[j] = max(dp[j],dp[j-price[a1]] + boost[a1]);
            int a2 = E[i].a2;
            if(E[i].a2) {
                if(price[a2] <= j) dp[j] = max(dp[j], dp[j - price[a2]] + boost[a2]);
                if(price[a1] + price[a2] <= j) dp[j] = max(dp[j], dp[j - price[a1] - price[a2]] + boost[a1] + boost[a2] - E[i].harm);
            }
        }
    }
    printf("%d\n",dp[p]);
}
