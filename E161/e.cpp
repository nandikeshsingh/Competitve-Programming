#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int msb(int n)
{
int ans = 1;
    while (n) {
        ans *= 2;
        n /= 2;
    }
      ans/=2;
    return ans;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int x;cin>>x;
        x--;
        vector<int>ans;
        int v=log2(msb(x));
        int cur=1;
        int s=0;
        for(int i=0;i<v;i++)
        {
            ans.push_back(s);
            s+=100;
            cur*=2;
        }
        x-=(1LL<<v);
        while(x)
        {
            int v=log2(msb(x));
            ans.push_back(100*(v-1)+1);
            x-=(1LL<<v);
        }
        ans.push_back(-1e9);
        cout<<sz(ans)<<endl;
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


