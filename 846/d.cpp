#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    // speed;
    int t;
    cin>>t;
    while(t--)
    {
        int last=0;
        int ans=0;
        int cnt;cin>>cnt;
        if(cnt==-1)exit(0);
        for(int cc=1;cc<=cnt;cc++)
        {
            cout<<"- "<<last+1<<endl;
            int cur;cin>>cur;
            if(cur==-1)exit(0);
            cur-=(cnt-cc);
            ans+=(1LL<<cur);
            last=(1LL<<cur)-1;
        }
        cout<<"! "<<ans<<endl;

    }
    return 0;
}


