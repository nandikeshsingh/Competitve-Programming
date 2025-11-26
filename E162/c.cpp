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
        int n,q;
        cin>>n>>q;
        vector<int>c(n+1,0);
        vector<int>pre(n+1,0),cnt(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
            pre[i]=pre[i-1]+c[i];
            cnt[i]=cnt[i-1]+(c[i]==1);
        }
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            if(l==r)
            {
                cout<<"NO"<<endl;
                continue;
            }
            int sum=pre[r]-pre[l-1];
            int tot=cnt[r]-cnt[l-1];
            int left=sum-((r-l+1)-tot);
            if(tot*2>left)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}


