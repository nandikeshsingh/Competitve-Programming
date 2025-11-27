#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int count(int c)
{
    int cnt=0;
    for(int bit=59;bit>=0;bit--)
    {
        if(((1LL<<bit)&c))cnt++;
    }
    return cnt;
}
signed main()
{
    speed;
    int a,b,c;
    cin>>a>>b>>c;
    int aa=a;
    int bb=b;
    int cnt=count(c);
    // cout<<"a="<<a<<" b="<<b<<" cnt="<<cnt<<endl;
    if(a+b<cnt)cout<<-1<<endl;
    else 
    {
        int rim=cnt-abs(a-b);
        if(rim<0 || rim%2)cout<<-1<<endl;
        else 
        {
            int x=0,y=0;
            if(a<b)swap(a,b);
            int last=60;
            for(int bit=59;bit>=0;bit--)
            {
                if(a==b)break;
                else 
                {
                    if(((1LL<<bit)&c))
                    {
                        x^=(1LL<<bit);
                        a--;
                        cnt--;
                        last=bit;
                    }
                }
            }
            // cout<<"cnt="<<cnt<<" last="<<last<<endl;
            // assert(a==b);
            bool f=1;
            for(int bit=last-1;bit>=0;bit--)
            {
                if(((1LL<<bit)&c))
                {
                    cnt--;
                    if(f)
                    {
                        x^=(1LL<<bit);
                        a--;
                        f^=1;
                    }
                    else 
                    {
                        y^=(1LL<<bit);
                        b--;
                        f^=1;
                    }
                }
            }
            // cout<<"cnt="<<cnt<<" last="<<last<<endl;
            // assert(a==b);
            // assert(cnt==0);
            if(a>0)
            {
                for(int bit=0;bit<=59;bit++)
                {
                    if(a==0 && b==0)break;
                    if(((1LL<<bit)&c)==0)
                    {
                        x^=(1LL<<bit);
                        y^=(1LL<<bit);
                        a--;b--;
                    }
                }
            }
            if(a>0 || b>0)
            {
                cout<<-1<<endl;
            }
            else 
            {
                assert(a==0 && b==0);
                int xc=count(x);
                int yc=count(y);
                if(xc==bb && yc==aa)swap(x,y);
                cout<<x<<" "<<y<<endl;
            }

        }
    }
    return 0;
}


