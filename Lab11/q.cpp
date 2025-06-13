#include <bits/stdc++.h>
using namespace std;
class node {
    private:
        string roomid;
        int distance;
    public:
        node(string s):roomid(s){}
        string getid()
        {
            return roomid;
        }
        void setid(string s)
        {
            roomid=s;
        }
        void setdis(int x)
        {
            distance=x;
        }
        int getdis()
        {
            return distance;
        }
};
template<typename T>
class pq{
    private:
        vector<T> arr;
    public:
        pq(vector<pair<T,int>> arr):arr(arr){}
        const size_t size() const{
            return arr.size();
        }
        void push(const T&,int d)
        {
            //add node to arr and heapify up
            arr.push_back({T,d});
            int i=arr.size()-1;
            while(i>0)  
            {
                int p=(i-1)/2;
                if(arr[i].second<arr[p].second())
                {
                    swap(arr[i],arr[p]);
                    i=p;
                }
                else{break;}
            }
        }
        void popy(int i)
        {
            //remove the first node in array and take the last element to top and heapify down this node
            int n=arr.size();
            while(i<n)
            {
                int p=i;
                if((2*p+1)<n and    arr[2*p+1].second<arr[p].second)
                {
                    i=2*p+1;
                }
                if((2*p+2)<n and arr[2*p+2].second<arr[p].second)
                {
                    i=2*p+2;
                }
                if(p!=i)
                {
                    swap(arr[p],arr[i]);
                    popy(i);
                }
                else
                {
                    break;
                }
            }
        }
        void pop()
        {
            if(arr.size()==0)return;
            arr[0]=arr.back();
            arr.pop_back();
            popy(0);
        }
        pair<T,int> top() const{
            return arr[0];
        }
        const bool empty() const{
            return arr.size()==0;
        }
};
int main()
{
    int n,m;cin>>n>>m;
    map<string,node> mapping;
    map<node,vector<node>> mapy;
    map<pair<node,node>,int> distances;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        mapping[s]=node(s);
    }
    for(int i=0;i<m;i++)
    {
        string x,y;int d;
        cin>>x>>y>>d;
        node smtg1=mapping[x];
        node smtg2=mapping[y];
        mapy[smtg1].push_back(smtg2);
        mapy[smtg2].push_back(smtg1);
        distances[{smtg1,smtg2}]=d;
        distances[{smtg2,smtg1}]=d;
    }
    string sor,des;
    cin>>sor>>des;
    vector<pair<node,int>> arr={};
    pq spq=pq(arr);
    unordered_map<string,int> disfromsor;
    for(auto& t:mapping)
    {
        disfromsor[t.first]=INT_MAX;
    }
    disfromsor[sor]=0;
    spq.push(mapping[sor],0);
    while(!spq.empty())
    {
        pair<node,int> p=spq.top();
        spq.pop();
        int dis=p.second;
        node nody=p.first;
        for(auto& t:mapy[nody])
        {
            if(dis+distances[{nody,t}]<disfromsor[t.getid()])
            {
                spq.push(t,dis+distances[{nody,t}]);
            }

        }
    }
    if(disfromsor[des]==INT_MAX){cout<<-1<<'\n';}
    else{
        cout<<disfromsor[des]<<'\n';
    }
}