#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    sort(all(b));
    sort(all(a));
    int cnt=0;
    int pos=0;
    for(int i=0;i<n;)
    {
        if(a[i]<b[pos]-k)i++;
        else if(a[i]>b[pos]+k)pos++;
        else cnt++,i++,pos++;
        if(pos>=m)break;
    }
    cout<<cnt<<endl;
    return 0;
}
