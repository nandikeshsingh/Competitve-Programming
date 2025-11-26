#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>a,pre;

int find_best(int x,int y)
{
    if(x==y)
    {
        if(a[x]>=0)return 1;
        else return 0;
    }
    int ans=0;
    if(pre[y]-pre[x-1]>=0)ans=y-x+1;
    else 
    {
        for(int i=x+1;i<=y;i++)
        {
            ans=max(ans,find_best(x,i-1)+find_best(i,y));
        }
    }
    return ans;
}
signed main()
{
    speed;
    int n;
    cin>>n;
    a.resize(n+1);
    pre.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    cout<<find_best(1,n)<<endl;
    return 0;
}


