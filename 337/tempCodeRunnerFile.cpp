#include<bits/stdc++.h>
#define int long long
// #define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int msb(int n)
{
    int ans = 1;
    while (n) {
        ans *= 2;
        n /= 2;
    }
      ans/=2;
    return ans;
}
signed main()
{
    // cout<<log2(msb(17))<<endl;
    int n;
    cin>>n;
    int nn=n;
    if(__buitin_popcount(n)==1)
    n--;
    int m=log2(msb(n));
    cout<<m+1<<endl;
    vector<vector<int>>vec(m+1,vector<int>(0));
    for(int b=1;b<=n;b++)
    {
        for(int bit=0;bit<=m;bit++)
        {
            if((b&(1LL<<bit))>0)
            {
                vec[bit].push_back(b);
            }
        }
    }
    for(int i=0;i<=m;i++)
    {
        cout<<(int)vec[i].size()<<" ";
        for(auto& u : vec[i])
        cout<<u<<" ";
        cout<<endl;
    }
    string s;
    cin>>s;
    int ss=(int)s.length();
    int ans=0;
    for(int i=0;i<ss;i++)
    {
        if(s[i]=='1')ans+=(1LL<<i);
    }
    if(ans==0)ans=nn;
    cout<<ans<<endl;
    exit(0);
}

