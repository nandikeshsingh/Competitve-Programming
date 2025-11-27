#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int tot=0;
        for(auto& u : s)
        tot+=(u=='1');
        int ans=tot;
        for(int i=0;i<k;i++)
        {   
            int cur=0;
            int mn=0;
            int mx=0;
            for(int j=i;j<n;j+=k)
            {   
                if(s[j]=='1')cur++;
                else cur--;
                mx=max(mx,cur-mn);
                mn=min(mn,cur);
            }   
            ans=min(ans,tot-mx);
        }
        cout<<ans<<endl;
    }
    return 0;
}