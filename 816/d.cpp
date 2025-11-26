#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
// bool cmp(pair<int,pair<int,int>>&p1,pair<int,pair<int,int>>&p2)
// {
//     if(p1.first!=p2.first)return p1.first<p2.first;
//     else return p1.second<
// }
signed main()
{
    speed;
    int n,q;
    cin>>n>>q;
    vector<vector<pair<int,int>>>vec(n,vector<pair<int,int>>(0));
    vector<int>ans(n,(1LL<<30)-1LL);

    for(int i=0;i<q;i++)
    {
        int u,v,x;
        cin>>u>>v>>x;
        --u;--v;
        ans[u]&=x;
        ans[v]&=x;
        vec[u].push_back({v,x});
        vec[v].push_back({u,x});
    }
    for(int i=0;i<n;i++)
    {
        ans[i]=0;
        for(auto[j,x] : vec[i])
        {
            if(i==j)ans[i]=x;
            else 
            {
                ans[i]|=((x^ans[j]));
            }
        }
    }
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}



//TRM issues for review ticket 
//in mainbeam indicator the outputs depend on CONST_ENUM_EXTERIOR_LIGHT_TELLTALE_TYPE but it's not mentioned anywhere in the TRM requirement.
//in auto one enum vs i doubt ask.
//in gui TRM one he should copy paste the images from the confluence.

// e_headlight_status
// GetHeadLightStatRes.e_headlight_status
// GetHeadLightStatReq
// GetHeadLightStatRes.e_signal_status
// E_HEADLIGHT_OFF_TELL_TALE

