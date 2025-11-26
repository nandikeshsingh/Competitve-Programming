#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int get(set<int>&st,int v)
{
    int ret=-1;
    for(auto& u : st)
    {
        if(u!=v)
        {
            ret=u;
            break;
        }
    }
    if(ret!=-1)
    st.erase(ret);
    return ret;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>p(n);
        for(int i=0;i<n;i++)cin>>p[i];
        if(n==1)cout<<-1<<endl;
        else
        {
            vector<int>ans(n,-1);
            set<int>st;
            for(int i=1;i<=n;i++)st.insert(i);
            for(int i=0;i<n;i++)
            {
                ans[i]=get(st,p[i]);
            }
            if(ans[n-1]==-1)
            {
                ans[n-1]=n;
                swap(ans[n-1],ans[n-2]);
            }
            for(auto& u : ans)cout<<u<<" ";
            cout<<endl;
        }
    }
    return 0;
}

