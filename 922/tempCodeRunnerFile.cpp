#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int cnt;
char ask(int i)
{
    cnt++;
    char ch;
    cout<<"? "<<i<<endl;
    cin>>ch;
    return ch;
}
signed main()
{
    // speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        if(n==1)
        {
            cout<<"! 1"<<endl;
            continue;
        }
        int idx=-1;
        vector<int>pos(n+1);
        for(int i=1;i<=n;i++)
        {
            char ret=ask(i);
            if(ret=='<' || ret=='=')
            {
                idx=i;
                while(ask(i)=='<');
            }
            // else if(ret=='>')
            // {
            //     if(idx!=-1)ask(idx);
            // }
        }
        pos[1]=idx;
        int cur=1;
        set<int>st;
        st.insert(idx);
        int rim=n-1;
        while(rim)
        {
            int nxt=-1;
            for(int i=1;i<=n;i++)
            {
                if(st.count(i))continue;
                char f,s;
                f=ask(i);s=ask(i);
                if(s=='=')
                {
                    nxt=i;
                    break;
                }
                else ask(idx),ask(idx);
            }
            pos[++cur]=nxt;
            st.insert(nxt);
            idx=nxt;
            rim--;
        }
        assert(cnt<=40*n);
        vector<pair<int,int>>ans;
        for(int i=1;i<=n;i++)ans.push_back({pos[i],i});
        sort(all(ans));
        cout<<"! ";
        for(auto& u : ans)cout<<u.second<<" ";
        cout<<endl;
        cnt=0;
    }
    return 0;

}


