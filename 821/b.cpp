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
        int n,x,y;
        cin>>n>>x>>y;
        if(x!=0 && y!=0)cout<<-1<<endl;
        else 
        {
            int md=max(x,y);
            if(md==0)
            {
                cout<<-1<<endl;
                continue;
            }
            if((n-1)%md==0)
            {
                int win=2;
                int tot=md;
                for(int i=2;i<=n;i++)
                {
                    tot--;
                    cout<<win<<" ";
                    if(tot==0)
                    {
                        tot=md;
                        win+=(md);
                    }
                }
                cout<<endl;
            }
            else cout<<-1<<endl;
        }
    }
    return 0;
}


