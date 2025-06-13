#include <bits/stdc++.h>
using namespace std;
class Island{
    private:
    public:
        virtual string getid()
        {
            return " ";
        }
        virtual string getid()
        {
            return 0;
        }
        virtual int getd()
        {
            return 0;
        }
        virtual pair<int,int> getcenter()
        {
            return {0,0};
        }

};
class Rectangle : public Island
{
    private:
        string islandid;
        vector<int> x;
        vector<int> y;
        pair<int,int> center={0,0};
        float disBtwcenterandvertex=0;
    public:
        Rectangle()
        {
            //
            x.resize(4);
            y.resize(4);
            cin>>islandid>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];
            center.first=(x[0]+x[1]+x[2]+x[3])/4;
            center.second=(y[0]+y[1]+y[2]+y[3])/4;
            float l=abs(x[1]-x[0]);
            int b=abs(y[2]-y[1]);
            disBtwcenterandvertex=sqrtl((l*l+b*b)/2);
        }
        string getid()
        {
            return islandid;
        }
        int getd()
        {
            return disBtwcenterandvertex;
        }
        pair<int,int> getcenter()
        {
            return center;
        }
};

// Function to calculate distance
float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

class Triangle: public Island
{
    private:
        string islandid;
        vector<int> x;
        vector<int> y;
        pair<int,int> center;
        float disBtwcenterandvertex=0;
    public:
        Triangle()
        {
            //
            x.resize(3);
            y.resize(3);
            cin>>islandid>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];
            center.first=(x[0]+x[1]+x[2])/3;
            center.second=(y[0]+y[1]+y[2])/3;
            float p=0;
            for(int i=0;i<3;i++)
            {
                p=max(p,distance(center.first,center.second,x[i],y[i]));
            }
            disBtwcenterandvertex=p;
        }
        string getid()
        {
            return islandid;
        }
        int getd()
        {
            return disBtwcenterandvertex;
        }
        pair<int,int> getcenter()
        {
            return center;
        }
};

class Circle: public Island
{
    private:
        string islandid;
        int radius;
        pair<int,int> center={0,0};
        float disBtwcenterandvertex=0;
    public:
        Circle()
        {
            cin>>islandid>>center.first>>center.second>>radius;
            disBtwcenterandvertex=radius;
        }
        string getid()
        {
            return islandid;
        }
        int getradius()
        {
            return radius;
        }
        int getd()
        {
            return disBtwcenterandvertex;
        }
        pair<int,int> getcenter()
        {
            return center;
        }
};

int main()
{
    int n;cin>>n;
    map<Island*,set<Island*>> gp;
    vector<Island*> nodes;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        if(s=="RECTANGLE")
        {
            Rectangle* island=new Rectangle;
            nodes.push_back(island);
        }
        else if(s=="TRIANGLE")
        {
            Triangle* island=new Triangle;
            nodes.push_back(island);
        }
        else
        {
            Circle* island=new Circle;
            nodes.push_back(island);
        }
    }
    //add edges btw two islands if they can have common points when rotated
    for(auto& t:nodes)
    {
        for(auto& q:nodes)
        {
            if(t->getid()!=q->getid())
            {
                pair c1=t->getcenter();
                pair c2=q->getcenter();
                float disbtw_centers=distance(c1.first,c1.second,c2.first,c2.second);
                if(disbtw_centers<=(t->getd()+q->getd()))
                {
                    gp[t].insert(q);
                    gp[q].insert(t);
                }
            }
        }
    }
    //run hamiltonian algo to find the possible path in the gp
    
}