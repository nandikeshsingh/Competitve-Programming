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
        int n;cin>>n;
        string s;cin>>s;
        vector<int>cnt(n+1,0);
        int tot=0;
        for(int i=0;i<n;i++)
        {
            tot+=(s[i]=='0');
            cnt[i+1]=cnt[i]+(s[i]=='0');
        }
        double mn=(double)1e9;
        int idx=-1;
        for(int i=0;i<=n;i++)
        {
            int l=cnt[i];
            int r=(n-i-(tot-cnt[i]));
            if(l>=(int)ceil((double)i/(double)2) && r>=(int)ceil((double)(n-i)/(double)2))
            {
                {
                    double nn=n;
                    nn/=(double)2.0;
                    nn-=(double)i;
                    if(nn<(double)0.0)nn*=(double)-1.0;
                    if(mn-nn>(double)0.000001)
                    {
                        mn=nn;
                        idx=i;
                    }            
                }
            }
        }   
        assert(idx>=0&&idx<=n);
        cout<<idx<<endl;
    }
    return 0;
}


