#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>x;
int ans=0;
int n;
const int mod=1e9+7;
void solve(vector<int>vec,int idx)
{
    if(idx>n+1)return;
    cout<<"Printing vec"<<endl;
    for(int i=0;i<sz(vec);i++)cout<<vec[i]<<" ";
    cout<<endl;
    int cur=0;
    vector<int>temp;
    if(sz(vec)==1)
    {
        cur=1;
    }
    else 
    {
        for(int i=0;i<sz(vec);i++)
        {
            if(i==0)temp.push_back(1);
            else if(i==sz(vec)-1)temp.push_back(0);
            else 
            {
                if(vec[i]-vec[i-1]<=vec[i+1]-vec[i])temp.push_back(0);
                else temp.push_back(1);
            }
            if(i>0)
            {
                if(temp[i]==1 && temp[i-1]==0)cur++;
            }
        }
    }
    cout<<"cur="<<cur<<endl;
    ans=(ans+cur)%mod;
    vector<int>cvec=vec;
        vec.push_back(x[idx]);
        solve(vec,idx+1);
    solve(cvec,idx+1);

}
signed main()
{
    speed;
    cin>>n;
    x.resize(n+1);
    for(int i=1;i<=n;i++)cin>>x[i];
    vector<int>vec;
    solve(vec,1);
    cout<<ans<<endl;
    return 0;
}


