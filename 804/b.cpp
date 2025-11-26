#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
        vector<vector<int>>ans;
        vector<int>up(m),down(m);
        int cnt=0;
        int last=1;
        for(int j=0;j<m;j++)
        {
            if(j==0)up[j]=1;
            else 
            {   
                if(cnt<2)
                {
                    up[j]=1-last;
                    cnt++;
                }
                if(cnt==2)
                {
                    cnt=0;
                    last=1-last;
                }
            }
        }
        for(int j=0;j<m;j++)
        {
            down[j]=1-up[j];
        }
        int p=1;
        for(int i=0;i<n;i+=2)
        {
            if(p)
            {
                ans.push_back(up);
                ans.push_back(down);
                p=1-p;
            }
            else 
            {
                ans.push_back(down);
                ans.push_back(up);
                p=1-p;
            }
        }
        for(int i=0;i<n;i++)

        {
            for(int j=0;j<m;j++)
            cout<<ans[i][j]<<" ";
            cout<<endl;
        }

    }
    return 0;
}

