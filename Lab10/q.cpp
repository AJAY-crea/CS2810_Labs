#include <bits/stdc++.h>
using namespace std;
template <typename temp>
class multiplication{
    public:
        vector<pair<temp,temp>> poly;
        multiplication(vector<pair<temp,temp>> p):poly(p){}
        void operator*(multiplication& poly2)
        {
            multiply(this->poly,poly2);
        }
};
template <typename temp>
void multiply(vector<pair<temp,temp>>& p1,vector<pair<temp,temp>>& p2)
{
    // pad 0's to polynomial with less degree to make it degree same as higher one and write a recurive fun to calculate required one
}
template <typename temp>
class evaluation{
    public:
        vector<temp> poly;
        evaluation(vector<temp> p):poly(p){};
        //for int and floats
        void evaluate1(int x)
        {
            int n=poly.size();
            int p=1;
            long long sum=0;
            sum+=poly[0];
            for(int i=1;i<n;i++)
            {
                p*=x;
                sum+=(p*poly[i]);
            }
            cout<<sum<<'\n';
        }
        // for strings
        void evaluate2(int x)
        {
            int n=poly.size();
            int p=1;
            string s;
            for(int i=1;i<n;i++)
            {
                p*=x;
            }
            for(int i=n-1;i>=0;i--)
            {
                for(int i=1;i<=p;i++)
                {
                    s+=poly[i];
                }
                p=p/x;
            }
            cout<<s<<'\n';
        }
};
template <typename temp>
class Differentiation
{
    public:
        Differentation(){};
        void diff(vector<temp> poly)
        {
            int n=poly.size();
            for(int i=1;i<n;i++)
            {
                cout<<poly[i]*i<<" "
            }
            cout<<'\n';
        }
};
int main()
{
    int q;cin>>q;
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            string s;cin>>s;
            vector<pair<float,float>> poly1;
            vector<pair<float ,float>> poly2;
            if(s=="integer" or s=="float")
            {
                int deg1;cin>>deg1;
                for(int i=0;i<deg1;i++)
                {
                    float a;cin>>a;
                    poly1.push_back({a,0});
                }
                int deg2;cin>>deg2;
                for(int i=0;i<deg2;i++)
                {
                    float a;cin>>a;
                    poly2.push_back({a,0});
                }
            }
            else{
                int deg1;cin>>deg1;
                for(int i=0;i<deg1;i++)
                {
                    float a;cin>>a;
                    float b;cin>>b;
                    poly1.push_back({a,b});
                }
                int deg2;cin>>deg2;
                for(int i=0;i<deg2;i++)
                {
                    float a;cin>>a;
                    float b;cin>>b;
                    poly2.push_back({a,b});
                }
            }
        }
        else if(op==2)
        {
            string s;cin>>s;
            if(s=="integer" or s=="float")
            {
                vector<float> poly;
                int deg;cin>>deg;
                for(int i=0;i<deg;i++)
                {
                    float p;
                    poly.push_back(p);
                }
                int x;cin>>x;
                evaluation e=evaluation(poly);
                e.evaluate1(x); 
            }
            else
            {
                vector<string> poly;
                int deg;cin>>deg;
                for(int i=0;i<deg;i++)
                {
                    string p;
                    poly.push_back(p);
                }
                int x;cin>>x;
                evaluation e=evaluation(poly);
                e.evaluate2(x);
            }   
        }
        else
        {
            string s;cin>>s;
            vector<float> poly;
            int deg;cin>>deg;
            for(int i=0;i<deg;i++)
            {
                float p;
                poly.push_back(p);
            }
            Differentiation<float> d;
            d.diff(poly);
        }

    }
}
