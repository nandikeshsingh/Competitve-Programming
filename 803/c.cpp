#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
        vector<int>vec(n);
        int pos=0,neg=0;
        int z=0;
        unordered_set<int>st;
        vector<int>cvec;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            // if(vec[i]!=0)
            // st.insert(vec[i]);
            if(vec[i]>0)pos++,cvec.push_back(vec[i]);
            else if(vec[i]<0)neg++,cvec.push_back(vec[i]);
            else z++;
        }
        // if(z>0)st.insert(0);
        if(pos>=3 || neg>=3)cout<<"NO"<<endl;
        else 
        {
            for(int i=0;i<n;i++)
            {
                if(vec[i]!=0)
                st.insert(vec[i]);

            }
            if(z>0)st.insert(0);
            // assert(st.size()<=5);
            z=min(z,3LL);
            for(int i=0;i<z;i++)cvec.push_back(0);
            int sz=cvec.size();
            assert(sz<=7);
            bool ok=1;
            for(int i=0;i<sz;i++)
            {
                for(int j=i+1;j<sz;j++)
                {
                    for(int k=j+1;k<sz;k++)
                    {
                        int cur=cvec[i]+cvec[j]+cvec[k];
                         assert(st.size()<=5);
                        if(st.find(cur)==st.end())
                        {
                            ok=0;
                        }
                    }
                }
            }
            if(ok)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
      
    }
    return 0;
}

