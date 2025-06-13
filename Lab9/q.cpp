#include <bits/stdc++.h>
using namespace std;
class isCycle{};
class indepComponent{};
class validOrder{};
class maxHype{};
class GraphAlgorithm{
    private:
        int n;
        int m;
        vector<int> hypescore;
        vector<vector<int>> graph;
    public:
        GraphAlgorithm(int a,int b,vector<int> c,vector<vector<int>> d):n(a),m(b),hypescore(c),graph(d){}
        virtual void Query()
        {

        }
        friend class isCycle;
        friend class indepComponent;
        friend class maxHype;
        friend class validOrder;
};
// isCyle class in which we find weather there is a cycle present in the given directed graph or not
class isCycle:public GraphAlgorithm
{
    public:
        isCycle(int a,int b,vector<int> c,vector<vector<int>> d):GraphAlgorithm(a,b,c,d)
        {
            //algo
        }
        virtual void Query()
        {

        }
};
//indepComponent class computes cardinality of strongly connected component in the graph andd number of SCC's
class indepComponent:public GraphAlgorithm
{
    public:
        indepComponent(int a,int b,vector<int> c,vector<vector<int>> d):GraphAlgorithm(a,b,c,d)
        {
            //algo
        }
        virtual void Query()
        {

        }
};
//gives valid topological order of the events
class validOrder:public GraphAlgorithm
{
    public:
        validOrder(int a,int b,vector<int> c,vector<vector<int>> d):GraphAlgorithm(a,b,c,d)
        {
            //algo
        }
        virtual void Query()
        {

        }
};
//Computes the maximum total hype score achievable by attending events in a valid path among all the possible paths. 
class maxHype:public GraphAlgorithm
{
    public:
        maxHype(int a,int b,vector<int> c,vector<vector<int>> d):GraphAlgorithm(a,b,c,d)
        {
            //algo
        }
        virtual void Query()
        {

        }
};
//comparator functor to sort adj lists
class comp{
    public:
       bool operator()(int a,int b)
       {
            return a<b;
       } 
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> hs(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>hs[i];
    }
    vector<vector<int>> gp(n+1);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        gp[a].push_back(b);
    }
    int q;cin>>q;
    while(q--)
    {
        int x;cin>>x;
        if(x==1)
        {
            isCycle a=isCycle(n,m,hs,gp);
            a.Query();
        }
        else if(x==2)
        {
            indepComponent a=indepComponent(n,m,hs,gp);
            a.Query();
        }
        else if(x==3)
        {
            validOrder a=validOrder(n,m,hs,gp);
            a.Query();
        }
        else
        {
            maxHype a=maxHype(n,m,hs,gp);
            a.Query();
        }
    }
}