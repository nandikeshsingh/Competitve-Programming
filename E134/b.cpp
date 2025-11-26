#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
 int n,m,x,y,d;
bool check(int i,int j)
{
    if(abs(i-x)+abs(j-y)<=d)return 0;
    else return 1;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
       
        cin>>n>>m>>x>>y>>d;
        if(abs(x-n)+abs(y-m)<=d)
        {
            cout<<-1<<endl;
            continue;
        }
        else 
        {
            bool up=1,dn=1;
            for(int j=1;j<=m;j++)
            {
                if(!check(1,j))
                {
                    up=0;
                }
                if(!check(n,j))
                {
                    dn=0;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(!check(i,1))
                {
                    dn=0;

                }
                if(!check(i,m))
                {
                    up=0;
                }
            }
            if(up|dn)cout<<n+m-2<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}


