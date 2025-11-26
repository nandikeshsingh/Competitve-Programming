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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string aux="";
        set<char>st;
        rep(i,0,n-1)st.insert(s[i]);
        for(auto& u : st)aux+=u;
        map<char,int>mp;
        for(int i=0;i<aux.length();i++)mp[aux[i]]=i;
        int len=aux.length();
        string ans="";
        rep(i,0,n-1)
        {
            ans+=aux[len-mp[s[i]]-1];
        }
        cout<<ans<<endl;
    }
    return 0;
}


