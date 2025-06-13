#include <bits/stdc++.h>
using namespace std;
int first=0;
int second=0;
int third=0;
class Sentinel
{
    private:
        int id;
        string name;
        int rank;
    public:
        Sentinel(){}
        virtual int countHigherRanked()
        {
            return 0;
        }
        virtual int getid()
        {
            return 0;
        }
        virtual int getrank()
        {
            return 0;
        }
};
class Senapati:public Sentinel
{
    private:
        int id;
        string name;
        int rank=0;
    public:
        Senapati(int id,string name,int r):id(id),name(name),rank(r){}
        int countHigherRanked()
        {
            return 0;
        }
        virtual int getid()
        {
            return id;
        }
        virtual int getrank()
        {
            return rank;
        }
};
class Dandanayaka:public Sentinel
{
    private:
        int id;
        string name;
        int rank;
    public:
        Dandanayaka(int id,string name,int r):id(id),name(name),rank(r){}
        int countHigherRanked()
        {
            return first;
        }
        virtual int getid()
        {
            return id;
        }
        virtual int getrank()
        {
            return rank;
        }
};
class Chaturangini:public Sentinel
{
    private:
        int id;
        string name;
        int rank;
    public:
        Chaturangini(int id,string name,int r):id(id),name(name),rank(r){}
        int countHigherRanked()
        {
            return first+second;
        }
        virtual int getid()
        {
            return id;
        }
        virtual int getrank()
        {
            return rank;
        }
};
template<typename T>
class Kingdom
{   
    private:
        vector<set<T>> tree;
    public:
        void addedge(T a,T b)
        {
            tree[a].insert(b);
            tree[b].insert(a);
        }
        int minVertexCover()
        {   int ans=0;
            //dp algo to find min vertx cover
            return ans;
        }
};
bool comp(Sentinel& a,Sentinel& b)
{
    if(a.getrank()==b.getrank()){
        return a.getid()<b.getid();
    }
    return a.getrank()<b.getrank();
}
vector<Sentinel> sentinals;
int main()
{
    int n;
    cin>>n;
    vector<set<int>> map;
    vector<Sentinel> sentinals;
    Kingdom<int> ashoka;
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        ashoka.addedge(a,b);
    }
    for(int i=0;i<n;i++)
    {
        string name,sentype;
        cin>>name>>sentype; 
        if(sentype=="Senapati")
        {
            first++;
            sentinals.push_back(Senapati(i,name,1));
        }
        else if(sentype=="DANDANAYAKA")
        {
            second++;
            sentinals.push_back(Dandanayaka(i,name,2));
        }
        else
        {
            third++;
            sentinals.push_back(Chaturangini(i,name,3));
        }
    }
    int q;cin>>q;
    int query1answer=ashoka.minVertexCover();
    vector<int> query2ans;
    vector<Sentinel> sens=sentinals;
    sort(sentinals.begin(),sentinals.end(),comp);
    for(int i=0;i<n;i++)
    {
        query2ans.push_back(sentinals[i].getid());
    }
    for(int i=0;i<q;i++)
    {
        int p;cin>>p;
        if(p==1)
        {
            cout<<query1answer<<'\n';
        }
        else if(p==2)
        {
            for(int i=0;i<n;i++)
            {
                cout<<query2ans[i]<<" ";
            }
            cout<<'\n';
        }
        else
        {
            int id;cin>>id;
            cout<<sens[id].countHigherRanked()<<'\n';
        }

    }

}