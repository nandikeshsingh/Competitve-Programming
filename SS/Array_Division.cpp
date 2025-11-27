#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int n,k;
vector<int>x;
signed main()
{
    speed;
    cin>>n>>k;
    x.resize(n);
    int sum=0;
    for(int i=0;i<n;i++)cin>>x[i],sum+=x[i];
    int lo=*max_element(all(x)),hi=1e15;
    while(lo<hi)
    {
        int mid=(lo+hi)>>1;
        int cnt=0;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            if(cur+x[i]<=mid)
            {
                cur+=x[i];
            }
            else 
            {
                cur=x[i];
                cnt++;
            }
        }
        cnt++;
        if(cnt>k)lo=mid+1;
        else hi=mid;
    }
    cout<<lo<<endl;
    return 0;
}


