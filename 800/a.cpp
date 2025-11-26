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
        int a,b;
        cin>>a>>b;
        string s;

            bool f=0;
            for(int i=0;i<2*min(a,b);i++)
            {
                if(f)
                {
                    s+='0';
                    f=1-f;
                }
                else 
                {
                    s+='1';
                    f=1-f;
                }
            }
            int temp=min(a,b);
            a-=temp;
            b-=temp;
            while(a>0)
            {
                s+='0';
                a--;
            }
            while(b>0)
            {
                s+='1';
                b--;
            }


        cout<<s<<endl;
    }
    return 0;
}

