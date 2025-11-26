#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>pos;
int n,x,y;
vector<vector<int>>dp;
int get (int i,int j)
{
    if(i+1==j)return min((pos[j]-pos[i])*x,y);
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=1e18;
    ans=min(ans,min((pos[i+1]-pos[i])*x,y)+get(i+2,j));
    ans=min(ans,min((pos[j]-pos[j-1])*x,y)+get(i,j-2));
    ans=min(ans,min((pos[j]-pos[i])*x,y)+get(i+1,j-1));
    return dp[i][j]=ans;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y;
        if(x>=y)
        {
            if(x>2*y)x=2*y;
            string a,b;
            cin>>a>>b;
            int cnt_a=0,cnt_b=0;
            for(auto& u : a)cnt_a+=(u=='1');
            for(auto& u : b)cnt_b+=(u=='1');
            if(abs(cnt_a-cnt_b)%2)cout<<-1<<endl;
            else 
            {
                pos.clear();
                for(int i=0;i<n;i++)
                {
                    if(a[i]!=b[i])pos.push_back(i);
                }
                int ans=0;
                if((int)pos.size()==2)
                {
                    if(abs(pos[0]-pos[1])==1)ans+=x;
                    else ans+=y;
                }
                else 
                {
                    int sz=(int)pos.size();
                    sz/=2;
                    ans+=(sz*y);
                }
                cout<<ans<<endl;
            }
        }
        else 
        {
            string a,b;
            cin>>a>>b;
            int cnt_a=0,cnt_b=0;
            for(auto& u : a)cnt_a+=(u=='1');
            for(auto& u : b)cnt_b+=(u=='1');
            if(abs(cnt_a-cnt_b)%2)cout<<-1<<endl;
            else 
            {
                pos.clear();
                for(int i=0;i<n;i++)
                {
                    if(a[i]!=b[i])pos.push_back(i);
                }
                if((int)pos.size()==0)
                {
                    cout<<0<<endl;
                    continue;
                }
                else 
                {
                    int len=(int)pos.size();
                    dp.clear();
                    dp.resize(len,vector<int>(len));
                    for(int i=0;i<len;i++)
                    for(int j=0;j<len;j++)
                    dp[i][j]=-1;
                    cout<<get(0,(int)pos.size()-1)<<endl;
                }
            }           
        }
    }
    return 0;
}


