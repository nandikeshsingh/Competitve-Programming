#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    // for(int i=1;i<=1001;i++)
    // {
    //     cout<<i<<" -> "<<i*i<<" "<<(i+1)*(i+1)-1<<endl;
    // }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=1;
        int cur=10;
        while((cur*cur)+cur-1<=n)
        {
            ans+=(cur+cur+1);
            cur*=10;
        }
        if(n>=cur*cur-2*cur)ans++;
        if(n>=cur*cur-1)ans+=cur;
        else if(n<cur*cur-1 && n>=cur*cur-cur)ans+=n-(cur*cur-cur-1);
        if(n<cur*cur+cur-1 && n>=cur*cur)ans+=n-(cur*cur-1);
        cout<<ans<<endl;
    }
    return 0;
}


