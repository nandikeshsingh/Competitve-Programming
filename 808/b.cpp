#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        vector<int>ans(n);
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            int lo=ceil((double)l/(double)i);
            int hi=r/i;
            if(hi>=lo)
            {
                ans[i-1]=i*lo;
            }
            else
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

