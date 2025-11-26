#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
signed main()
{
    // speed;
    int n;
    cin>>n;
    vector<int>vec(n+1,0);
    for(int j=n;j>=1;j--)
    {
        cout<<"? "<<2<<" "<<1<<" "<<j<<endl;
        int val;
        cin>>val;
        if(val==0)exit(0);
        else vec[j]=val;
    }
    string s;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
        cout<<"? "<<1<<" "<<1<<endl;
        char ch;
        cin>>ch;
        if(ch==48)
        exit(0);
        s+=ch;
        }
        else if(vec[i]==vec[i-1])
        {
            char x=s.back();
            s+=x;
        }
        else 
        {
        cout<<"? "<<1<<" "<<i<<endl;
        char ch;
        cin>>ch;
        if(ch==48)
        exit(0);
        s+=ch;
        }

    }
    cout<<"! "<<s<<endl;
    return 0;
}
