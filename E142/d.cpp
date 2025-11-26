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
        int n,m;
        cin>>n>>m;
        vector<vector<int>>a(n+1,vector<int>(m+1));
        vector<int>arr[m+1][m+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                arr[j][a[i][j]].push_back(i);
            }
        }
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            int cur=0;
            vector<int>temp=a[i];
            set<int>st;
            for(int j=1;j<=m;j++)
            {
                int u=a[i][j];
                if(sz(arr[u][cur+1])!=0)
                {
                    set<int>nst;
                    for(auto& v : arr[u][cur+1])
                    {
                        if(st.count(v))nst.insert(v);
                    }
                    st=nst;

                    if(sz(st)>0)cur++;
                    else break;
                }
                else break;
            }
            ans.push_back(cur);
        }
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
