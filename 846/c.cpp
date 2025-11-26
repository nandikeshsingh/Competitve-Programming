#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n),c(m);
        vector<int>cnt(n+1,0);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            cnt[a[i]]++;
        }
        for(int i=0;i<m;i++)cin>>c[i];
        sort(all(c));
        reverse(all(c));
        multiset<int>ms;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i])ms.insert(cnt[i]);
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            if(sz(ms)==0)break;
            int best=*prev(ms.end());
            ms.erase(prev(ms.end()));
            if(best>c[i])
            {
                ans+=c[i];
                best-=c[i];
                ms.insert(best);
            }
            else 
            {
                ans+=best;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


