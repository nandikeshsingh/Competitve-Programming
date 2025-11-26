#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>cnt(20000001);
vector<int>mul(20000001);
vector<long long>tot(20000001);
long long ans;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    for(int g=20000000;g>=1;g--)
    {
        mul[g]=cnt[g];
        for(int j=g+g;j<=20000000;j+=g)
        {
            if(mul[j])
            {
                mul[g]+=cnt[j];
                tot[g]=max(tot[g],tot[j]-mul[j]*(long long)g);
            }
        }
        tot[g]+=mul[g]*(long long)g;
        ans=max(ans,tot[g]);
    }
    printf("%lld",ans);
    return 0;
}

