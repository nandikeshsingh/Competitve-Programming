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
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        string s;
        cin>>s;
        map<int,char>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.count(a[i])==0)
            {
                mp[a[i]]=s[i];
            }
        }
        string ans;
        for(int i=0;i<n;i++)
        {
            ans+=mp[a[i]];
        }
        if(ans==s)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


