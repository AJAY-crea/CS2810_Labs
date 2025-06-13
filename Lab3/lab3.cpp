#include <bits/stdc++.h>
using namespace std;
class graph{
    private:
        set<int> v;
        map<int,set<int>> gp;
    public:
        graph(set<int> sv,map<int,set<int>> gp)
        {
            v=sv;
           this->gp=gp;
        }
        graph(){
            ;
        }
        void addvertex(int a)
        {
            v.insert(a);
        }
        void addedge(int a,int b)
        {   if(max(a,b)>=gp.size())return;
            gp[a].insert(b);
            gp[b].insert(a);
        }
        void operator+(graph g2)
        {
            // graph ng=*this;
            for(auto& t:g2.v)
            {
                
                v.insert(t);
            }
            for(auto& t:g2.gp)
            {
                for(auto &p:t.second)
                {
                    if(gp[t.first].find(p)==gp[t.first].end())
                    {
                        gp[t.first].insert(p);
                        gp[p].insert(t.first);
                    }
                }
            }
             
            // return *this;
        }
        void operator-(graph& gp2)
        {
            set<int> sv;
            map<int,set<int>> ngp;
            for(auto &t: gp2.v)
            {
                if(v.find(t)!=v.end())
                {
                    sv.insert(t);
                }
            }
            for(auto & t:sv)
            {
                for(auto& p:sv)
                {
                    if(p!=t)
                    {
                        if(gp.find(p)!=gp.end() and gp[p].find(t)!=gp[p].end() and gp2.gp.find(p)!=gp2.gp.end() and gp2.gp[p].find(t)!=gp2.gp[p].end()){
                            ngp[t].insert(p);
                            ngp[p].insert(t);
                        }
                    }
                }
            }
            v=sv; gp=ngp;
            // *this=graph(sv,ngp);
            // return *this;
        }
        void operator!()
        {
            map<int,set<int>> ngp;
            for(auto& t:v)
            {   
                for(auto &p :v)
                {
                    if(p!=t)
                    {
                        if(gp[p].find(t)==gp[p].end())
                        {
                            
                            ngp[p].insert(t);
                            ngp[t].insert(p);
                        }
                    }
                }
            }
            gp=ngp;
        }
        friend ostream& operator<<(ostream& os,graph& g)
        {   
            for(auto& t:g.gp)
            {
                os<<"Vertex "<<t.first<<":"<<" ";
                for(auto& p:g.gp[t.first])
                {
                    os<<p<<" ";
                }
                os<<'\n';
            }
            return os;
        }
        friend istream& operator>>(istream& im,graph& g)
        {   
            int n,m;im>>n>>m;
            for(int i=0;i<n;i++)
            {
                auto it=g.gp[i].find(0);
            }
            while(m--){
                int a;int b;
                im>>a>>b;
                g.gp[a].insert(b);
                g.gp[b].insert(a);
                g.v.insert(a);
                g.v.insert(b);
            }
            return im;
        }
        void removeedge(int a,int b){
            if(max(a,b)>=gp.size())return;
            if(gp[a].find(b)!=gp[a].end())
            {
                gp[a].erase(b);
                gp[b].erase(a);
            }
        }
        void isreachable(int a,int b){
            if(max(a,b)>=gp.size()){
                cout<<"No"<<'\n';
                return;
            }
            map<int,int> mp;
            for(auto& t: gp)
            {
                mp[t.first]=0;
            }
            bool p=dfs(mp,b,a);
            if(p==true){cout<<"Yes"<<'\n';}
            else{cout<<"No"<<'\n';}
        }
        bool dfs(map<int,int>& mp,int b,int node)
        {   
            if(node==b){return true;}
            mp[node]=true;
            for(auto& t:gp[node])
            {
                if(mp[t]==0)
                {
                    if(dfs(mp,b,t)){return true;}
                }
            }
            return false;
        }
};
int main() {
    string s;cin>>s;
    graph g;
    while(s!="end")
    {   
        if(s=="Graph")
        {
            cin>>g;
        }
        else if(s=="union")
        {
            string p;cin>>p;
            graph g2;
            cin>>g2;
            g+g2;
        }
        else if(s=="printGraph")
        {
            cout<<g;
        }
        else if(s=="isReachable")
        {
            int a,b;cin>>a>>b;
            g.isreachable(a,b);
        }
        else if(s=="remove_edge")
        {
            int a,b;cin>>a>>b;
            g.removeedge(a,b);
        }
        else if(s=="complement")
        {
            !g;
        }
        else if(s=="add_edge")
        {
            int a,b;cin>>a>>b;
            g.addedge(a,b);
        }
        else if(s=="intersection")
        {
            string p;cin>>p;
            graph g2;
            cin>>g2;
            g-g2;
        }
        cin>>s;
    }
}