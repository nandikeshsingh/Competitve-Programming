#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int l,r;
    cin>>l>>r;
    vector<pair<int,int>>ans;
    if(l==0)
    {
        int s=1;
        while(2*s<=r)
        {
            s*=2;
        }
        ans.push_back({0,s});
        l=s;
    }
    while(l!=r)
    {
        int bst=1;
        while(l%(2*bst)==0 && l+(2*bst)<=r)
        {
            bst*=2;
        }
        ans.push_back({l,l+bst});
        l+=bst;
    }
    cout<<sz(ans)<<endl;
    for(auto& u : ans)cout<<u.first<<" "<<u.second<<endl;
    // else 
    // {
    //     while(s<l)
    //     {
    //         s*=2;
    //     }
    //     if(s<=r)
    //     {
    //         int rim=s-l;
    //         for(int bit=0;bit<=61;bit++)
    //         {
    //             if((1LL<<bit)&rim)
    //             {
    //                 ans.push_back({l,l+(1LL<<bit)});
    //                 l+=(1LL<<bit);
    //             }
    //         }
    //         while(l*2<=r)
    //         {
    //             ans.push_back({l,l*2});
    //             l*=2;
    //         }
    //     }

    // }

    // cout<<"l="<<l<<"r="<<r<<endl;
    // int rim=r-l;
    // for(int bit=0;bit<=61;bit++)
    // {
    //     if((1LL<<bit)&rim)
    //     {
    //         ans.push_back({l,l+(1LL<<bit)});
    //         l+=(1LL<<bit);
    //     }
    // }
    // cout<<"lafter="<<l<<endl;
    // assert(l==r);
    // cout<<sz(ans)<<endl;
    // for(auto& u : ans)cout<<u.first<<" "<<u.second<<endl;
    return 0;
}


