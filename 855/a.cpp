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
        string s;
        cin>>s;
        for(auto& u : s)
        u=tolower(u);
        string ans;
        ans+=s[0];
        for(int i=1;i<sz(s);i++)
        {
            if(s[i]!=s[i-1])ans+=s[i];
        }
        if(ans=="meow")cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


