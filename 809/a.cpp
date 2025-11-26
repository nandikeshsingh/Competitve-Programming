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
        int n,m;
        cin>>n>>m;
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        string s;
        for(int i=0;i<m;i++)s+='B';
        for(int i=0;i<n;i++)
        {
            int a=vec[i];
            int b=m+1-vec[i];
            int mn=min(a,b);
            int mx=max(a,b);
            if(s[mn-1]=='B')s[mn-1]='A';
            else s[mx-1]='A';
        }
        cout<<s<<endl;
    }
    return 0;
}