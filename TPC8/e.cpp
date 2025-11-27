#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>t(n+1),x(n+1);
    for(int i=1;i<=n;i++)cin>>t[i]>>x[i];
    vector<int>tot(n+1),mrk(n+1);
    for(int i=n;i>=1;i--)
    {
        if(t[i]==2)tot[x[i]]++;
        else 
        {
            if(tot[x[i]]>0)
            {
                tot[x[i]]--;
                mrk[i]=1;
            }
        }
    }
    bool ok=1;
    for(auto& u : tot)
    {
        if(u>0)
        {
            ok=0;
            break;
        }
    }
    if(!ok)cout<<-1<<endl;
    else 
    {
        int k=-1e18;
        int cur=0;
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            if(t[i]==1)
            {
                if(mrk[i])ans.push_back(1),cur++;
                else ans.push_back(0);
            }
            else cur--;
            k=max(k,cur);
        }
        cout<<k<<endl;
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


