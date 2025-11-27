#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>vec;
int find(int l,int r,int h)
{
    if(l>r)return 0;
    if(l==r)return min(1LL,vec[l]-h);
    int mn=1e18;
    int idx=-1;
    for(int i=l;i<=r;i++)
    {
        if(vec[i]<mn)
        {
            mn=vec[i];
            idx=i;
        }
    }
    return min(r-l+1,mn-h+find(l,idx-1,mn)+find(idx+1,r,mn));
}
signed main()
{
    speed;
    int n;
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    cout<<find(0,n-1,0)<<endl;
    return 0;
}

