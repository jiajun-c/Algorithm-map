#include <iostream>
#include <algorithm>
#define N 201010
#define mid ((l+r)>>1)
using namespace std;
int n;
int a[N];
int d_c(int l,int r) {
    if(l == r) return a[l];
    int ln = 0,la = -9999999,rn = 0, ra = -9999999;
    for (int i = mid;i >= l;i--) {ln += a[i];la = max(la,ln);}
    for (int i = mid+1;i <= r;i++) {rn += a[i];ra = max(ra,rn);}
    int ans = max(d_c(l,mid),d_c(mid+1,r));
    ans = max(ans,la+ra);
    return ans;
}
int main() {
    scanf("%d",&n);
    for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
    printf("%d",d_c(1,n));
}
