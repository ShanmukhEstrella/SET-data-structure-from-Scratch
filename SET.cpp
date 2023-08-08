#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;
class SET
{
    public:
    vector<ll> v,v1,v2,v3,v4;
    ll n,n1;
    ll Insert(ll x)
    {
        if(find(v.begin(),v.end(),x)==v.end())
        {
            v.push_back(x);
        }
        n=v.size();
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n-i-1;j++)
            {
                if(v[j]>v[j+1]) swap(v[j],v[j+1]);
            }
        }
        return v.size();
    }
    ll Delete(ll x)
    {
        for(ll i=0;i<n;i++)
        {
            if(v[i]==x)
            {
                v.erase(v.begin()+i,v.begin()+i+1);
                break;
            }
        }
        return v.size();
    }
    bool Belongs_to(ll x)
    {
        return binary_search(v.begin(),v.end(),x);
    }
    ll Union(SET s2)
    {
        v1=v;
        for(auto i : s2.v)
        {
            if(find(v1.begin(),v1.end(),i)==v1.end()) v1.push_back(i);
        }
        n1=v1.size();
        for(ll i=0;i<n1;i++)
        {
            for(ll j=0;j<n1-i-1;j++)
            {
                if(v1[j]>v1[j+1]) swap(v1[j],v1[j+1]);
            }
        }
        v=v1;
        return v1.size();
    }
    ll Intersection(SET s2)
    {
        for(auto i : v)
        {
            if(find((s2.v).begin(),(s2.v).end(),i)!=(s2.v).end())
            {
                v3.push_back(i);
            }
        }
        n1=v3.size();
        for(ll i=0;i<n1;i++)
        {
            for(ll j=0;j<n1-i-1;j++)
            {
                if(v3[j]>v3[j+1]) swap(v3[j],v3[j+1]);
            }
        }
        v=v3;
        return v3.size();
    }
    ll Size()
    {
        return v.size();
    }
    ll Difference(SET s2)
    {
        for(auto i : v)
        {
            if(find(s2.v.begin(),s2.v.end(),i)==s2.v.end())
            {
                v2.push_back(i);
            }
        }
        v=v2;
        return v.size();
    }
    ll Symmetric_Difference(SET s2)
    {
        for(auto i : v)
        {
            if(find(s2.v.begin(),s2.v.end(),i)==s2.v.end())
            {
                v4.push_back(i);
            }
        }
        for(auto i : s2.v)
        {
            if(find(v.begin(),v.end(),i)==v.end()&&find(v4.begin(),v4.end(),i)==v4.end())
            {
                v4.push_back(i);
            }
        }
        n1=v4.size();
        for(ll i=0;i<n1;i++)
        {
            for(ll j=0;j<n1-i-1;j++)
            {
                if(v4[j]>v4[j+1]) swap(v4[j],v4[j+1]);
            }
        }
        v=v4;
        return v.size();
    }
    void Print()
    {
        for(auto i : v)
        {
            cout<<i<<",";
        }
        cout<<endl;
    }
};
int main()
{
   int a,b,c,m,x;
   SET s1,s2;
   m=0;x=0;
   while(true){
   cin>>a>>b>>c;
   if(b==1)
   {
     if(a==1)
     {
        cout<<s1.Insert(c)<<endl;
        m++;
     }
     else if(a==2)
     {
        if(m!=0) cout<<s1.Delete(c)<<endl;
        else cout<<-1<<endl;
     }
     else if(a==3)
     {
        if(m!=0) cout<<s1.Belongs_to(c)<<endl;
        else cout<<-1<<endl;
     }
     else if(a==4)
     {
        cout<<s1.Union(s2)<<endl;
        m++;
     }
     else if(a==5)
     {
        cout<<s1.Intersection(s2)<<endl;
        m++;
     }
     else if(a==6)
     {
        cout<<s1.Size()<<endl;
        m++;
     }
     else if(a==7)
     {
        cout<<s1.Difference(s2)<<endl;
        m++;
     }
     else if(a==8)
     {
        cout<<s1.Symmetric_Difference(s2)<<endl;
        m++;
     }
     else if(a==9)
     {
        if(m!=0) s1.Print();
        else cout<<endl;
     }
   }
   else if(b==2)
   {
     if(a==1)
     {
        cout<<s2.Insert(c)<<endl;
        x++;
     }
     else if(a==2)
     {
       if(x!=0) cout<<s2.Delete(c)<<endl;
       else cout<<-1<<endl;
     }
     else if(a==3)
     {
        if(x!=0) cout<<s2.Belongs_to(c)<<endl;
        else cout<<-1<<endl;
     }
     else if(a==4)
     {
        cout<<s2.Union(s1)<<endl;
        x++;
     }
     else if(a==5)
     {
        cout<<s2.Intersection(s1)<<endl;
        x++;
     }
     else if(a==6)
     {
        cout<<s2.Size()<<endl;
        x++;
     }
     else if(a==7)
     {
        cout<<s2.Difference(s1)<<endl;
        x++;
     }
     else if(a==8)
     {
        cout<<s2.Symmetric_Difference(s1)<<endl;
        x++;
     }
     else if(a==9)
     {
        if(x!=0) s2.Print();
        else cout<<endl;
     }
   }
  }
}
