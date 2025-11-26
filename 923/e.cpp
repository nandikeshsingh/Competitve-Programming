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
        int n,k;
        cin>>n>>k;
        set<int>st;
        for(int i=1;i<=n;i++)st.insert(i);
        vector<int>ans(n+1,0);
        bool p=1;
        for(int i=1;i<=k;i++)
        {
            if(p)
            {
                int j=i;
                while(j<=n)
                {
                    ans[j]=*st.begin();
                    st.erase(st.begin());
                    j+=k;
                }
                p=0;
            }
            else 
            {
                int j=i;
                while(j<=n)
                {
                    ans[j]=*prev(st.end());
                    st.erase(prev(st.end()));
                    j+=k;
                }
                p=1;  
            }
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}


