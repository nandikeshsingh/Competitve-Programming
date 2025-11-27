#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        if(a>n)
        {
            cout<<"No"<<endl;
        }
        else 
        {
            int last=0;
            int s=1;
            if(n%2)s=2;
            vector<bool>rook(n+1,0);
            int cnt=a;
            if(cnt>0)
            {
                for(int i=s;i<=n;i+=2)
                {
                    rook[i]=1;
                    if(last<i)last=i;
                    cnt--;
                    if(cnt==0)break;
                }
            }
            if(cnt>0)
            {
                if(n%2)s=1;
                else s=2;
                for(int i=s;i<=n;i+=2)
                {
                    rook[i]=1;
                    if(last<i)last=i;
                    cnt--;
                    if(cnt==0)break;
                }
            }
            int r=n-last;
            int tot=((r+1)/2)*r;
            for(int i=1;i<=last;i++)
            {
                if(rook[i]==0)
                {
                    tot+=(n-a);
                }
            }
            tot+=(last-a)*((r+1)/2);
            // cout<<"tot="<<tot<<endl;
            if(tot<b)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}


