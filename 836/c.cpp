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
        int n,x;
        cin>>n>>x;
        if(x==n)
        {
            vector<int>ans(n+1);
            for(int i=1;i<=n;i++)ans[i]=i;   
            ans[1]=n;
            ans[n]=1;
            for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
            cout<<endl;       
        }
        else if(n%x==0)
        {
            vector<int>ans(n+1);
            for(int i=1;i<=n;i++)ans[i]=i;
            ans[1]=x;
            ans[n]=1;
            int f=n/x;
            vector<int>div;
            for(int i=2;i*i<=f;i++)
            {
                if(f%i==0)
                {
                    while(f%i==0)
                    {
                        f/=i;
                        div.push_back(i);
                    }
                }
            }
            if(f>1)div.push_back(f);
            sort(all(div));
            int cur=x;
            for(int i=0;i<sz(div);i++)
            {
                ans[cur]=cur*div[i];
                cur*=div[i];
            }
            for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}

