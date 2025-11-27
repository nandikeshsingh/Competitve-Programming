#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>vec(n),pre(n),cvec(n);
    for(int i=0;i<n;i++)cin>>vec[i],pre[i]=vec[i],cvec[i]=vec[i];
    sort(all(pre));
    for(int i=1;i<n;i++)pre[i]+=pre[i-1];
    sort(all(cvec));
    for(int i=0;i<n;i++)
    {
        int pos=upper_bound(all(cvec),vec[i])-cvec.begin();
        if(pos==0)cout<<pre[n-1]<<" ";
        else cout<<pre[n-1]-pre[pos-1]<<" ";
    }
    cout<<endl;
    return 0;
}


