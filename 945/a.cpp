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
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if((a+b+c)%2)cout<<-1<<endl;
        else 
        {
            multiset<int>mst;
            if(a)
            mst.insert(a);
            if(b)
            mst.insert(b);
            if(c)
            mst.insert(c);
            int cnt=0;
            while(sz(mst)>1)
            {
                int f=*mst.begin();
                int e=*prev(mst.end());
                mst.erase(mst.begin());
                mst.erase(prev(mst.end()));
                f--;e--;
                cnt++;
                if(f)mst.insert(f);
                if(e)mst.insert(e);
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}


