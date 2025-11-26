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
        int n,w,h;
        cin>>n>>w>>h;//w-a,h-b
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        int mv=a[0]-b[0];
        for(int i=0;i<n;i++)a[i]-=mv;
        mv=abs(a[0]-w-(b[0]-h));
        for(int i=0;i<n;i++)a[i]+=mv;
        bool ok=1;
        int rim=2*(w-h);  
        int cur=0;
        int mx_l=0;  
        for(int i=1;i<n;i++)
        {
            if(b[i]+h>a[i]+w)
            {
                ok=0;
                break;
            }
            else if(b[i]-h<a[i]-w)
            {
                mx_l=max(mx_l,abs(b[i]-h-a[i]+w));
            }
        }
        if(!ok)cout<<"NO"<<endl;
        else 
        {
            for(int i=0;i<n;i++)a[i]-=mx_l;
            for(int i=0;i<n;i++)
            {
                if(b[i]-h<a[i]-w || b[i]+h>a[i]+w)ok=0;
            }
            if(ok)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}


