#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 222;
const int inf=1e17;
int a[maxn];
int dp[10010];
int n;
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int t=sum/2;


    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; ++i)
    {
        for(int j=t; j>=a[i]; j--)
        {
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
    }

    int ans=sum-dp[t]-dp[t];

    printf("%d\n",(ans>0?ans:-ans));

    return 0;
}
