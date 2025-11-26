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
        int n,k,b,s;
        cin>>n>>k>>b>>s;
        if((s/k)<b)cout<<-1<<endl;
        else if((s/k)==b)
        {
            vector<int>ans(n,0);
            ans[0]=s;
            for(auto& u : ans)cout<<u<<" ";
            cout<<endl;
        }
        else 
        {
            int div=(s/k);
            int rim=s%k;
            if(b*k+(k-1)*(n)<s)cout<<-1<<endl;
            else 
            {
                vector<int>ans(n,0);
                ans[0]=b*k+k-1;
                s-=ans[0];
                for(int i=1;i<n;i++)
                {
                    if(s>=k-1)
                    {
                        ans[i]=k-1;
                        s-=(k-1);
                    }
                    else 
                    {
                        ans[i]=s;
                        s=0;
                    }
                    if(s==0)break;
                }
                for(auto& u : ans)cout<<u<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}


