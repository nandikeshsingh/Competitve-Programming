#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<bool>vec(4,0);
        for(auto& u : s)
        {
            int ac=u;
            if(ac<=57 && ac>=48)vec[2]=1;
            if(ac<=122 && ac>=97)vec[1]=1;
            if(ac<=90 && ac>=65)vec[0]=1;
            if(u=='#' || u=='@' || u=='*' || u=='&')vec[3]=1;

        }
        if(vec[0]==0)s+='A';
        if(vec[1]==0)s+='a';
        if(vec[2]==0)s+='1';
        if(vec[3]==0)s+='#';
        while(s.length()<7)s+='a';
        cout<<"Case #"<<t<<": "<<s<<endl;
    }
    return 0;
}