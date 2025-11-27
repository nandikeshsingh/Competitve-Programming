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
using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;
signed main()
{
    speed;
    string s;cin>>s;
    int u=0,l=0;
    int n=s.length();
    rep(i,0,n-1)
    {
        if(s[i]>='a'&&s[i]<='z')l++;
        else u++;
    }
    if(u>l)
    {
        rep(i,0,n-1)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                s[i]-='a';
                s[i]+='A';
            }
        }
    }
    else 
    {
        rep(i,0,n-1)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                s[i]-='A';
                s[i]+='a';
            }  
        }
    }
    cout<<s<<endl;
    return 0;
}


