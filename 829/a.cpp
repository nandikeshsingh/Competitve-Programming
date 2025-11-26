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
        int cur=0;
        bool ok=1;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='Q')cur--;
            else cur++;
            if(cur<0)ok=0;
        }
        if(cur>=0 && ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}


