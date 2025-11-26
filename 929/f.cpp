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
        vector<vector<int>>vec(n,vector<int>(m,0));
        vector<vector<int>>b(n,vector<int>(m,1e18));
        vector<set<int>>rock(m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>vec[i][j];
                if(vec[i][j])rock[j].insert(i);
            }
        }
        cout<<"done"<<endl;
        b[0][0]=0;
        for(int j=0;j<m;j++)
        {
            cout<<"j="<<j<<endl;
            if(j==0)
            {
                if(sz(rock[0])==0)
                {
                    for(int i=1;i<n;i++)
                    b[i][j]=b[i-1][j]+1;
                }
                else
                {
                    int p=*rock[0].begin();
                    int last=-1;
                    for(int i=1;i<n;i++)
                    {
                        int time=i;
                        if(p-time>i)
                        {
                            b[i][j]=b[i-1][j]+1;
                        }
                        else break;
                    }
                }
            }
            else 
            {
                if(sz(rock[j])==0)
                {
                    cout<<"here j ="<<j<<endl;
                    for(int i=0;i<n;i++)
                    {
                        b[i][j]=b[i][j-1]+1;
                    }
                }
                else 
                {
                    for(int i=0;i<n;i++)
                    {
                        if(b[i][j-1]==1e18)b[i][j]=1e18;
                        else 
                        {
                            int time=b[i][j-1]%n;
                            int fi=(i+1)%n;
                            fi=(fi-time+n)%n;
                            if(rock[j].find(fi)==rock[j].end())
                            {
                                b[i][j]=b[i][j-1]+1;
                            }
                        }
                    }
                }
                for(int i=1;i<n;i++)
                {
                    b[i][j]=min(b[i][j],b[(i-1+n)%n][j]);
                }
            }
        }
        cout<<"out"<<endl;
        int ans=1e18;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,b[i][m-1]+min(n-1-i,i+1));
        }
        if(ans==1e18)ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}

// 4 5
// 0 1 0 0 0
// 0 0 1 0 0
// 1 0 1 1 0
// 0 0 0 0 0
