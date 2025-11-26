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
        int n;
        cin>>n;
        vector<vector<int>>ans(n+1,vector<int>(n+1));
        int f=1,l=n*n;
        if(n%2)
        {
            bool cur=1;
            for(int j=1;j<=n;j++)
            {
                for(int i=1;i<=n;i++)
                {
                    if(cur)
                    {
                        ans[i][j]=f++;
                        cur=1-cur;
                    }
                    else 
                    {
                        ans[i][j]=l--;
                        cur=1-cur;
                    }
                }
            }        
        }
        else 
        {
            bool cur=1;
            for(int j=1;j<=n;j++)
            {
                int i=j;
                do
                {
                    if(cur)
                    {
                        ans[i][j]=f++;
                        cur=1-cur;
                    }
                    else 
                    {
                        ans[i][j]=l--;
                        cur=1-cur;
                    }
                    i++;
                    if(i>n)i-=n;
                } while (i!=j);
                
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            cout<<ans[i][j]<<" ";
            cout<<endl;
        }

    }
    return 0;
}


