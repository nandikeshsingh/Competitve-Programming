// #include<bits/stdc++.h>
// #define int long long
// #define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define all(v) v.begin(),v.end()
// #define sz(v) (int)v.size()
// using namespace std;
// const int maxn=1e5+2;
// signed main()
// {
//     speed;
//     vector<vector<int>>divisor(maxn+10);
//     for(int i=1;i<=maxn;i++)
//     {
//         for(int j=i;j<=maxn;j+=i)
//         divisor[j].push_back(i);
//     }
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,m;
//         cin>>n>>m;
//         vector<int>a(n);
//         for(int i=0;i<n;i++)cin>>a[i];
//         sort(all(a));
//         int lo=0,hi=n;
//         int ans=1e18;
//         while(lo<hi)
//         {
//             int mid=(lo+hi)>>1;
//             int l=0,r=mid;
//             vector<int>T(m+1,0);
//             int cnt=0;
//             bool f=0;
//             bool first=1;
//             while(r<n)
//             {
                
//                 if(first)
//                 {
//                     for(int i=l;i<=r;i++)
//                     {
//                         for(auto& u : divisor[a[i]])
//                         {
//                             if(u>m)continue;
//                             if(T[u]==0)
//                             {
                            
//                                 cnt++;
//                             }
//                             T[u]++;
//                         }
//                     }
//                     if(cnt==m)
//                     {
//                         f=1;
//                         ans=min(ans,a[r]-a[l]);
//                     }
//                     l++;r++;
//                     first=0;
//                 }
//                 else 
//                 {
//                     for(auto& u : divisor[a[l-1]])
//                     {
//                         if(u>m)continue;
//                         if(T[u]==1)
//                         {
//                             cnt--;
//                         }
//                         T[u]--;
//                     }
//                     for(auto& u : divisor[a[r]])
//                     {
//                         if(u>m)continue;
//                         if(T[u]==0)cnt++;
//                         T[u]++;
//                     }
//                     if(cnt==m)
//                     {
//                         f=1;
//                         ans=min(ans,a[r]-a[l]);
//                     }
//                     l++;r++;
//                 }
//             }
//             if(f)
//             {
//                 hi=mid;
//             }
//             else lo=mid+1;
//         }
//         if(ans==1e18)ans=-1;
//         cout<<ans<<endl;
//     }
//     return 0;
// }
#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int maxn=1e5+2;
signed main()
{
    speed;
    vector<vector<int>>divisor(maxn+10);
    for(int i=1;i<=maxn;i++)
    {
        for(int j=i;j<=maxn;j+=i)
        divisor[j].push_back(i);
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(all(a));
        vector<int>T(m+1,0);
        int l=0,r=-1;
        int ans=1e18;
        int cnt=0;
        while(r<n)
        {
            if(cnt==m)
            {
                ans=min(ans,a[r]-a[l]);
                for(auto& u : divisor[a[l]])
                {
                    if(u>m)continue;
                    if(T[u]==1)cnt--;
                    T[u]--;
                }
                l++;
            }
            else 
            {
                r++;
                if(r==n)break;
                for(auto& u : divisor[a[r]])
                {
                    if(u>m)continue;
                    if(T[u]==0)cnt++;
                    T[u]++;
                }
            }
        }
        if(ans==1e18)ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}




