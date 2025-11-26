#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,f,k;cin>>n>>f>>k;
        vi a(n);
        rep(i,0,n-1)cin>>a[i];
        int val=a[f-1];
        sort(all(a));
        reverse(all(a));
        int first=-1,last=-1;
        rep(i,0,n-1)
        {
            if(a[i]==val)
            {
                first=i;
                break;
            }
        }
        per(i,n-1,0)
        {
            if(a[i]==val)
            {
                last=i;
                break;
            }
        }
        if(last<=k-1)cout<<"YES"<<endl;
        else if(first>k-1)cout<<"NO"<<endl;
        else cout<<"MAYBE"<<endl;
    }
    return 0;
}


