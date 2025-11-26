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
        int n;
        cin>>n;
        vector<int>ans(n+1);
        for(int i=1;i<=n;i++)ans[i]=i;
        for(int i=n;i>=2;i-=2)
        {
            swap(ans[i],ans[i-1]);
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}


