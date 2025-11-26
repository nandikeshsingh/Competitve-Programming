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
        vector<int>a(n+1);
        set<int>st;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            st.insert(a[i]);
        }
        int mex=0;
        while(st.count(mex)!=0)mex++;
        // cout<<"mex="<<mex<<endl;
        if(mex==0)
        {
            cout<<2<<endl;
            cout<<1<<" "<<1<<endl;
            cout<<2<<" "<<n<<endl;
            continue;
        }
        vector<pair<int,int>>ans;
        int aa=-1,bb=-1;
        set<int>cm;
        bool ok=1;
        int j=1;
        while(sz(cm)<mex)
        {
            if(a[j]<mex)
            {
                cm.insert(a[j]);
            }
            j++;
            if(j>n)break;
        }
        cm.clear();
        aa=j-1;
        j=n;
        while(sz(cm)<mex)
        {
            if(a[j]<mex)
            {
                cm.insert(a[j]);
            }
            j--;
            if(j<0)break;
        }
        bb=j+1;
        if(aa>=bb)cout<<-1<<endl;
        else 
        {
            cout<<2<<endl;
            cout<<1<<" "<<aa<<endl;
            cout<<aa+1<<" "<<n<<endl;
        }
    }
    return 0;
}


