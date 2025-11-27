#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int get(vector<int>vec,int i)
{
    if(i<0)return 0;
    vector<int>one,zero;
    for(auto& u :vec)
    {
        if(u&(1LL<<i))one.push_back(u);
        else zero.push_back(u);
    }
    if((int)one.size()==0)return get(zero,i-1);
    else if((int)zero.size()==0)return get(one,i-1);
    else return (1LL<<i)+min(get(one,i-1),get(zero,i-1));
}
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    cout<<get(vec,30)<<endl;
    // int x=get(vec,30);
    // cout<<"x="<<x<<endl;
    // int ans=0;
    // for(auto& u :vec)ans=max(ans,x^u);
    // cout<<ans<<endl;
    return 0;
}

