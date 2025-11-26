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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(n),b(m);
        multiset<int>mst;
        map<int,int>mp,mpb;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
            mst.insert(b[i]);
            mpb[b[i]]++;
        }
        int ans=0;
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            mp[a[i]]++;
        }
        for(auto& u : mp)
        {
            cnt+=min(u.second,mpb[u.first]);
        }
        if(cnt>=k)ans++;
        int s=0,e=m-1;
        while(e+1<n)
        {
            
            if(mp[a[s]]<=mpb[a[s]] && mp[a[s]]>=1)
            {
                cnt--;
                mp[a[s]]--;
            }
            else 
            {
                if(mp[a[s]]>=1)mp[a[s]]--;
            }
            if(mp[a[e+1]]<mpb[a[e+1]])
            {
                cnt++;
                mp[a[e+1]]++;
            }
            else mp[a[e+1]]++;
            s++;e++;
            if(cnt>=k)
            {
                ans++;
            }
    
        }
        cout<<ans<<endl;
    }
    return 0;
}


