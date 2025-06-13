#include <bits/stdc++.h>
using namespace std;
class comperator_A
{
    public:
        bool operator()(int a,int b)
        {
            return a<b;
        }
};
class comperator_D
{
    public:
        bool operator()(int a,int b)
        {
            return a>b;
        }
};
void mergersort()
{
    //merge sort algo

}
class MAtrix
{   
    private:
        vector<vector<int>> matrix;
    public:
        MAtrix(vector<vector<int>> mat):matrix(mat){}
        //default constructor
        MAtrix(){}
        //copy constructor
        MAtrix(MAtrix m,MAtrix p){
            m.matrix=p.matrix;
        }
        void sort_A()
        {
            int n=matrix.size();
            for(int i=0;i<n;i++)
            {

            }
        }
        void sort_D()
        {
            int n=matrix.size();
            for(int i=0;i<n;i++)
            {

            }
        }
        int countInversions()
        {
            int ans=0;
            int n=matrix.size();
            // algorithm to find no of inversions
            vector<long long> bigv(n*n);
            int p=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    for(int j=0;j<n;j++)
                    {
                        bigv[p]=matrix[i][j];
                        p++;
                    }
                }
            }

            return ans;
        }
        void display()
        {
            int n=matrix.size();
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<matrix[i][j]<<" ";
                }
                cout<<'\n';
            }
        }
};
pair<int,int> closest_pair(vector<pair<int,int>>& a)
{
    pair<int,int> ans={0,0};
    //algo for finding closest pair
    
    return ans;
}
int main()
{
    string s;cin>>s;
    MAtrix m();
    while(s!="END")
    {
        if(s=="CREATE_2D")
        {
            int n;cin>>n;
            vector<vector<int>> a(n,vector<int> (n,0));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cin>>a[i][j];
                }
            }
            MAtrix p(a);
            MAtrix(m,p);
        }
        else if(s=="INVERSION_2D")
        {
            cout<<m.countinversions()<<'\n';
        }
        else if(s=="SORT_2D")
        {
            string k;cin>>k;
            if(k=="ascending")
            {
                //sort in increasing order
            }
            else
            {
                //sort in decreasing order
            }
        }
        else if(s=="DISPLAY_2D")
        {
            m.display();
        }
        else if(s=="CLOSEST_2D")
        {
            int n;cin>>n;
            vector<pair<int,int>> pairs;
            pair<int,int> ans=closest_pair(pairs);
            cout<<ans.first<<" "<<ans.second<<'\n';
        }
    }
}