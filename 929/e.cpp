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
        int n;
        cin>>n;
        vector<int>a(n+1,0),pre(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
        }
        // cout<<"Prinitng pre"<<endl;
        // for(int i=0;i<=n;i++)
        // {
        //     cout<<i<<" "<<pre[i]<<endl;
        // }
        int q;cin>>q;
        while(q--)
        {
            int l,u;cin>>l>>u;
            // cout<<"val="<<pre[l-1]+u<<endl;
            auto pos=lower_bound(all(pre),pre[l-1]+u);
            if(pos==pre.end())pos=prev(pre.end());
            int r=pos-pre.begin();
            int past=pre[r-1]-pre[l-1];
            // cout<<"past="<<past<<endl;
            int st=u-(past-1);
            // cout<<"st="<<st<<endl;
            int tot=u-past;
            int post=(tot*st-((tot*(tot+1))/2));
            int rtot=pre[r]-pre[r-1]-tot;
            int neg=(rtot*(rtot-1))/2;
            if(post<=neg)
            {
                if(r>l)r--;
            }
            cout<<r<<" ";
        }
        cout<<endl;
    }
    return 0;
}


