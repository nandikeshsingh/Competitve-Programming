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
        char c;cin>>c;
        string s;cin>>s;
        if(c=='g')
        {
            cout<<0<<endl;
            continue;
        }
        vector<int>gpos,rpos,ypos;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='g')
            gpos.push_back(i);
            if(s[i]=='r')
            rpos.push_back(i);
            if(s[i]=='y')
            ypos.push_back(i);
        }
        int len=sz(gpos);
        for(int i=0;i<len;i++)gpos.push_back(gpos[i]+n);
        int ans=0;
        if(c=='r')
        {
            for(auto& u : rpos)
            {
                auto itr=upper_bound(gpos.begin(),gpos.end(),u);
                ans=max(ans,abs(u-*itr));
            }
        }
        else if(c=='y')
        {
             for(auto& u : ypos)
            {
                auto itr=upper_bound(gpos.begin(),gpos.end(),u);
                ans=max(ans,abs(u-*itr));
            }           
        }
        cout<<ans<<endl;
    }
    return 0;
}


