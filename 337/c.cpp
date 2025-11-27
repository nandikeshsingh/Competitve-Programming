#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n+1);
    map<int,int>pos;
    int cur=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
        if(a[i]==-1)cur=i;
    }
    vector<int>ans;
    while(sz(ans)<n)
    {
        ans.push_back(cur);
        cur=pos[cur];
    }
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}


