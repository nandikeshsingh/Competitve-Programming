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
        int a,b,c;
        cin>>a>>b>>c;
        int ans=a+b/3;
        if(b%3==0)
        cout<<ans+(int)ceil((double)c/(double)3)<<endl;
        else if(b%3==1)
        {
            if(c<2)cout<<-1<<endl;
            else 
            {
                c-=2;
                ans++;
                cout<<ans+(int)ceil((double)c/(double)3)<<endl;
            }
        }
        else if(b%3==2)
        {
            if(c<1)cout<<-1<<endl;
            else 
            {
                c-=1;
                ans++;
                cout<<ans+(int)ceil((double)c/(double)3)<<endl;
            }
        }
    }
    return 0;
}


