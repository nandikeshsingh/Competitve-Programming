#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
bool get(int n,int m,vector<int>a,int k)
{
    sort(all(a));
    reverse(all(a));
    for(auto& u : a)u=(u/m);
    bool ok=1;
    int tot=0;
    for(int i=0;i<k;i++)
    {
        tot+=a[i];

    }
    if(tot<n)return 0;
    else 
    {
        tot=0;
        int pos=0;
        for(int i=0;i<k;i++)
        {
            if(a[i]+tot<n)tot+=a[i];
            else 
            {
                pos=i;
                break;
            }
        }
        int rim=n-tot;
        // cout<<"rim="<<rim<<endl;
        if(rim==1 && a[0]==2)return 0;
        else if(rim==1 && a[pos]==1)return 0;
        else return 1;
    }
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        // if(n<m)swap(n,m);
        vector<int>a(k);
        int sum=0;
        for(int i=0;i<k;i++)cin>>a[i],sum+=a[i];
        if(sum<n*m)
        {
            cout<<"No"<<endl;
            continue;
        }
        else 
        {
            if(get(n,m,a,k)||get(m,n,a,k))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}

