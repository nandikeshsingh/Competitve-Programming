#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
void compute(int S,int X)
{
    int A = (S-X)/2;
    int a = 0, b = 0;
    for (int i=0; i<8*sizeof(S); i++)
    {
        int Xi = (X & (1 << i));
         int Ai = (A & (1 << i));
        if (Xi == 0 && Ai == 0)
        {

        }
        else if (Xi == 0 && Ai > 0)
        {
            a = ((1 << i) | a);
            b = ((1 << i) | b);
        }
        else if (Xi > 0 && Ai == 0)
        {
            a = ((1 << i) | a);
        }
        else 
        {
            cout <<-1<<endl;
            return;
        }
    }
    cout<<a<<" "<<b<<endl;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        if(x%2)cout<<-1<<endl;
        else 
        {
            compute(x+x,x);
        }
    }
    return 0;
}


