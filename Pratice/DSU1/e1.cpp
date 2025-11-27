#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int maxn=500010;
signed main()
{
    speed;
    int q;
    cin>>q;
    vector<int>final(maxn,0);
    for(int i=0;i<maxn;i++)final[i]=i;
    vector<int>ans;
    vector<int>t(q),x(q),y(q);
    for(int i=0;i<q;i++)
    {
        cin>>t[i];
        if(t[i]==1)cin>>x[i];
        if(t[i]==2)cin>>x[i]>>y[i];
    }
    for(int i=q-1;i>=0;i--)
    {
        if(t[i]==1)ans.push_back(final[x[i]]);
        else final[x[i]]=final[y[i]];
    }
    reverse(all(ans));
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}




