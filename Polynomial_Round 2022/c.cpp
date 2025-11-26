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
        int pre[n];
        pre[0]=1;
        bool f=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1] && f==0)pre[i]=1;
            else pre[i]=2,f=1;
        }
        vector<int>ans;
        for(int x=2;x<=n;x++)
        {
            if(pre[x-2]==2)ans.push_back(x-1);
            else ans.push_back(1);
        }
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


