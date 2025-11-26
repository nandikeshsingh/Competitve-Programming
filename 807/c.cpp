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
        int n,c,q;
        cin>>n>>c>>q;
        string s;
        cin>>s;
        vector<int>l(c),r(c),cl(c+1),cr(c+1);
        cl[0]=1;cr[0]=n;
        for(int i=0;i<c;i++)
        {
            cin>>l[i]>>r[i];
            int len=r[i]-l[i]+1;
            // if(i==0)cl[i+1]=l[i]+len,cr[i+1]=cl[i+1]+len-1;
            // else
            {
                cl[i+1]=cr[i]+1;
                cr[i+1]=cl[i+1]+len-1;
            }
        }
        // cout<<"Printing cl and cr"<<endl;
        // for(int i=0;i<=c;i++)
        // cout<<cl[i]<<" "<<cr[i]<<endl;
        while(q--)
        {
            int x;
            cin>>x;
            int cur=n;
            if(x<=cur)
            {
                cout<<s[x-1]<<endl;
                continue;
            }
            int pos=0;
            for(int i=0;i<=c;i++)
            {
                if(x>=cl[i] && x<=cr[i])
                {
                    pos=i;
                    break;
                }
            }
            // cout<<"x="<<x<<" cur="<<cur<<endl;
            // cout<<"pos="<<pos<<endl;
            // int idx=(x-cur+l[pos]-1);
            // idx+=cur;
            // cout<<"idx="<<idx<<endl;
            while(x>n)
            {
                x-=(cr[pos-1]-l[pos-1]+1);
                // cout<<"x in loop="<<x<<endl;
                pos=lower_bound(cr.begin(),cr.end(),x)-cr.begin();
                if(pos==0)break;
            }
            cout<<s[x-1]<<endl;
        }
    }
    return 0;
}

