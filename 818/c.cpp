// #include<bits/stdc++.h>
// #define int long long
// #define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define all(v) v.begin(),v.end()
// using namespace std;
// int n;
// inline int nxt(int i)
// {
//     i++;
//     if(i>=n)i-=n;
//     return i;
// }
// signed main()
// {
//     speed;
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         cin>>n;
//         vector<int>a(n),b(n);
//         for(int i=0;i<n;i++)cin>>a[i];
//         for(int i=0;i<n;i++)cin>>b[i];
//         bool ok=1;
//         for(int i=0;i<n;i++)
//         {
//             if(a[i]>b[i])ok=0;
//             if(b[i]>b[nxt(i)]+1 && a[i]<b[i])ok=0;
//         }
//         cout<<(ok?"YES":"NO")<<endl;
//     }
//     return 0;
// }
#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int n;
//if a[i]>b[i] answer no;
int nxt(int i)
{
    if(i<n-1)return i+1;
    else return 0;
}
int prev(int i)
{
    if(i==0)return n-1;
    else return i-1;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]>b[i])ok=0;
        }
        int pos=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>a[pos])pos=i;
        }
        if(a[pos]==b[pos])
        {
            //this is fixed;
            int cnt=0;
            for(int i=prev(pos);cnt!=(n-1);)
            {
                int can=a[nxt(i)]-a[i]+1;
                can=max(can,0LL);
                if(a[i]+can>=b[i])
                {
                    a[i]=b[i];
                }
                else 
                {
                    ok=0;
                    break;
                }
                cnt++;
                i=prev(i);
            }
        }
        else 
        {
            // int diff=b[pos]-a[pos];
            // int now=1;
            // int cnt=0;
            // for(int i=nxt(pos);cnt!=(n-1);)
            // {
            //     if(b[i]<b[pos]-now)
            //     {
            //         ok=0;
            //         break;
            //     }
            //     else b[i]=b[pos]-now;
            //     now++;
            //     i=nxt(i);
            //     cnt++;
            // }
            // b[pos]-=diff;
            if(ok)
            {
                int cnt=0;
                bool f=0;
                int pos1=-1;
                for(int i=prev(pos);cnt!=(n-1);)
                {
                    int can=a[nxt(i)]-a[i]+1;
                                    can=max(can,0LL);
                    if(a[i]+can>=b[i])
                    {
                        a[i]=b[i];
                    }
                    else a[i]+=can;
                    if(a[i]==b[i])f=1,pos1=i;
                    cnt++;
                    i=prev(i);
                }
                if(f)
                {
                    int cnt=0;
                    for(int i=prev(pos1);cnt!=(n-1);)
                    {
                        int can=a[nxt(i)]-a[i]+1;
                                        can=max(can,0LL);
                        if(a[i]+can>=b[i])
                        {
                            a[i]=b[i];
                        }
                        else 
                        {
                            ok=0;
                            break;
                        }
                        cnt++;
                        i=prev(i);
                    }
                }
                else 
                {
                    int mn=1e18;
                    int idx=-1;
                    for(int i=0;i<n;i++)
                    {
                        if(mn>b[i]-a[i])
                        {
                            mn=b[i]-a[i];
                            idx=i;
                        }
                        mn=min(mn,b[i]-a[i]);
                    }
                    for(int i=0;i<n;i++)a[i]+=mn;
                    int cnt=0;
                    for(int i=prev(idx);cnt!=(n-1);)
                    {
                        int can=a[nxt(i)]-a[i]+1;
                                        can=max(can,0LL);
                        if(a[i]+can>=b[i])
                        {
                            a[i]=b[i];
                        }
                        else 
                        {
                            ok=0;
                            break;
                        }
                        cnt++;
                        i=prev(i);
                    }
                }
            }
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
 