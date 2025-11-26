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
        int n,m;
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        int cnt=0;
        for(int i=1;i<n;i++)
        cnt+=(s[i]==s[i-1]);
        for(int i=1;i<m;i++)
        cnt+=(t[i]==t[i-1]);
        if(cnt>1)cout<<"NO"<<endl;
        else if(cnt==0)cout<<"YES"<<endl;
        else 
        {
            if(s.back()!=t.back())cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}





