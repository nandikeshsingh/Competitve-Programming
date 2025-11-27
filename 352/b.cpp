#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
signed main()
{
    speed;
    string s,t;
    cin>>s>>t;
    int i=0,j=0;
    vector<int>ans;
    for(int i=0;i<s.length();)
    {
        if(s[i]==t[j])
        {
            ans.pb(j+1);
            i++;j++;
        }
        else j++;
    }
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}


