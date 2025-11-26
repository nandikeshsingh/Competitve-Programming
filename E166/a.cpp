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
        string s;cin>>s;
        string d="";
        string c="";
        bool ok=1;
        rep(i,0,n-1)
        {
            if(s[i]>='0' && s[i]<='9')d+=s[i];
            if(s[i]>='a'&& s[i]<='z')c+=s[i];
            if(i>0)
            {
                if(s[i]>='0' && s[i]<='9' && s[i-1]>='a' && s[i-1]<='z')
                {
                    ok=0;
                }
            }
        }
        if(!ok)cout<<"NO"<<endl;
        else 
        {
            bool x=1;bool y=1;
            rep(i,1,(int)d.length()-1)
            {
                if(d[i]<d[i-1])x=0;
            }
            rep(i,1,(int)c.length()-1)
            {
                if(c[i]<c[i-1])y=0;
            }
            if(x==0 || y==0)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}


