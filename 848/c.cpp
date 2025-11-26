#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
void makeCombiUtil(vector<vector<int> >& ans,vector<int>& tmp, int n, int left, int k)
{
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }
    for (int i = left; i <= n; ++i)
    {
        tmp.push_back(i);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);
        tmp.pop_back();
    }
}
vector<vector<int> > makeCombi(int n, int k)
{
    vector<vector<int> > ans;
    vector<int> tmp;
    makeCombiUtil(ans, tmp, n, 1, k);
    return ans;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string a,b;
        cin>>a>>b;
        set<char>st;
        for(auto& u : a)st.insert(u);
        int mx=sz(st);
        if(k>mx)k=mx;
        vector<int>vec;
        for(auto& u : st)vec.push_back(u);
        vector<vector<int>>tot=makeCombi(mx,k);
        int ans=0;
        for(auto& u : tot)
        {
            set<char>ss;
            for(auto& v : u)
            {
                ss.insert(vec[v-1]);
            }
            vector<int>has(n+1);
            for(int i=0;i<n;i++)
            {
                if(ss.count(a[i]))has[i+1]=1;
                else if(a[i]==b[i])has[i+1]=1;
                else has[i+1]=0;
            }
            has.push_back(0);
            int l=1,r=1;
            int cnt=0;
            while(r<=n+1)
            {
                if(has[l]==0 && has[r]==0)l++,r++;
                else if(has[l]==1 && has[r]==1)r++;
                else if(has[l]==1 && has[r]==0)
                {
                    int len=r-l;
                    cnt+=(len*(len+1))/2;
                    l=r;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
}


