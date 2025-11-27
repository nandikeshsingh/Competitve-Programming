#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=1e9+7;
signed main()
{
    speed;
    int h,w;
    cin>>h>>w;
    vector<vector<int>>a(h,vector<int>(w));
    vector<vector<int>>b(h,vector<int>(w));
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        cin>>a[i][j];
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        cin>>b[i][j];
    }
    vector<int>r(h),c(w);
    int cnt=0;
    for(int i=0;i<h;i++)r[i]=cnt++;
    cnt=0;
    for(int i=0;i<w;i++)c[i]=cnt++;
    int ans=1e18;
    do
    {
        do
        {
            bool ok=1;
            for(int i=0;i<h;i++)
            {
                for(int j=0;j<w;j++)
                {
                    ok&= a[r[i]][c[j]]==b[i][j];
                }
            }
            if(ok)
            {
                int cur=0;
                vector<int>vec(h);
                for(int i=0;i<h;i++)vec[r[i]]=i;
                for(int i=1;i<h;i++)
                {
                    for(int j=0;j<i;j++)
                    cur+=(vec[j]>vec[i]);
                }
                for(int i=0;i<w;i++)vec[c[i]]=i;
                for(int i=1;i<w;i++)
                {
                    for(int j=0;j<i;j++)
                    cur+=(vec[j]>vec[i]);
                }
                ans=min(ans,cur);
            }
        } while (next_permutation(all(r)));
        
    } while (next_permutation(all(c)));
    if(ans==1e18)ans=-1;
    cout<<ans<<endl;
    return 0;
}
// signed main()
// {
//     speed;
//     int h,w;
//     cin>>h>>w;
//     int a[h][w],b[h][w];
//     vector<int>har,hac,hbr,hbc;
//     for(int i=0;i<h;i++)
//     {
//         vector<int>vec;
//         for(int j=0;j<w;j++)
//         cin>>a[i][j],vec.push_back(a[i][j]);
//         sort(all(vec));
//         int x=0;
//         for(int j=0;j<w;j++)
//         {
//             x*=101;
//             x+=vec[j];
//             x%=mod;
//         }
//         har.push_back(x);
//     }
//     for(int j=0;j<w;j++)
//     {
//         int y=0;
//         vector<int>vec;
//         for(int i=0;i<h;i++)vec.push_back(a[i][j]);
//         sort(all(vec));
//         for(int i=0;i<h;i++)
//         {
//             y*=101;
//             y+=vec[i];
//             y%=mod;
//         }
//         hac.push_back(y);
//     }
//     for(int i=0;i<h;i++)
//     {
//         vector<int>vec;
//         for(int j=0;j<w;j++)
//         cin>>b[i][j],vec.push_back(b[i][j]);
//          int x=0;
//          sort(all(vec));
//         for(int j=0;j<w;j++)
//         {
//             x*=101;
//             x+=vec[j];
//             x%=mod;
//         }
//         hbr.push_back(x);
//     }    
//     for(int j=0;j<w;j++)
//     {
//         int y=0;
//         vector<int>vec;
//         for(int i=0;i<h;i++)vec.push_back(b[i][j]);
//         sort(all(vec));
//         for(int i=0;i<h;i++)
//         {
//             y*=101;
//             y+=vec[i];
//             y%=mod;
//         }
//         hbc.push_back(y);
//     }
//     vector<int>ar,ac,br,bc;
//     ar=har;ac=hac;br=hbr;bc=hbc;
//     sort(all(har));
//     sort(all(hbr));
//     sort(all(hac));
//     sort(all(hbc));
//     bool ok=1;
//     for(int i=0;i<h;i++)
//     {
//         if(har[i]!=hbr[i])
//         {
//             ok=0;
//             break;
//         }
//     }
//     for(int j=0;j<w;j++)
//     {
//         if(hac[j]!=hbc[j])
//         {
//             ok=0;
//             break;
//         }
//     }
//     if(!ok)cout<<-1<<endl;
//     else
//     {
//         int ans=0;
//         map<int,int>mp;
//         int cur=1;
//         for(int i=0;i<h;i++)
//         {
//             mp[br[i]]=cur++;
//         }
//         for(int i=0;i<h;i++)
//         {
//             ar[i]=mp[ar[i]];
//         }
//         for(int i=1;i<h;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(ar[j]>ar[i])ans++;
//             }
//         }
//         map<int,int>mpc;
//          cur=1;
//         for(int i=0;i<w;i++)
//         {
//             mpc[bc[i]]=cur++;
//         }
//         for(int i=0;i<w;i++)
//         {
//             ac[i]=mpc[ac[i]];
//         }
//         for(int i=1;i<w;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(ac[j]>ac[i])ans++;
//             }
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }


