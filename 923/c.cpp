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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(n),b(m);
        vector<vector<int>>vec(k+1,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<=k)vec[a[i]][0]=1;
        }
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
            if(b[i]<=k)vec[b[i]][1]=1;
        }
        int cnta=k/2,cntb=k/2;
        bool ok=1;
        vector<int>done(k+1,0);
        for(int i=1;i<=k;i++)
        {
            if(vec[i][0]==1 && vec[i][1]==0)
            {
                cnta--;
                done[i]=1;
            }
            else if(vec[i][0]==0 && vec[i][1]==1)
            {
                cntb--;
                done[i]=1;
            }
            else if(vec[i][0]==0 && vec[i][1]==0)
            {
                ok=0;
                break;
            }
        }
        if(!ok)cout<<"No"<<endl;
        else if(cnta<0)cout<<"No"<<endl;
        else if(cntb<0)cout<<"No"<<endl;
        else 
        {
            for(int i=1;i<=k;i++)
            {
                if(done[i])continue;
                if(cnta>cntb)
                {
                    done[i]=1;
                    cnta--;
                }
                else 
                {
                    done[i]=1;
                    cntb--;
                }
            }
            if(cnta==0 && cntb==0)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}


