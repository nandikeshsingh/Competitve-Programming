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
        int n;
        cin>>n;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        int l=1,r=1;
        int ans=0;
        int idx=1;
        map<int,pair<int,int>>mp;
        while(r<=n)
        {
            if(a[r]>=idx)ans+=(r-l+1),r++,idx++;
            else 
            {
                mp[r]={l,idx};
               l++;
               idx--;
            }
        }
        cout<<"ans="<<ans<<endl;
        int q;
        cin>>q;
        while(q--)
        {
            int p,x;
            cin>>p>>x;
            if(x==a[p])cout<<ans<<endl;
            else if(x>a[p])
            {
                int now=ans;
                int tot=max(x-mp[p].second,0LL);
                cout<<now+tot*mp[p].first<<endl;
            }
            else 
            {
                int now=ans;
                cout<<now<<endl;
            }
        }
        // cout<<ans<<endl;
    }
    return 0;
}

