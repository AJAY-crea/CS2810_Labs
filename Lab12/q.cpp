#include <bits/stdc++.h>
using namespace std;
class Card
{
    private:

    public:
        Card()
        {
            
        }
        virtual void area()
        {

        }
        virtual int getarea()
        {

        }
        virtual bool operator<(Card* c)
        {

        }
        virtual char getchar()
        {

        }
        virtual int getside(){}
        virtual int getlength(){}
        virtual int getbreadth(){}
        virtual int getbase(){}
        virtual int getheight(){}
};
class Square:public Card{
    private:
        int side;
        int area;
        char c;
    public:
        Square(int s,int a,char c):side(s),area(a),c(c){}
        void area()
        {
            area=side*side;
        }
        int getarea()
        {
            return area;
        }
        virtual bool operator<(Card* c)
        {
            return area<c->getarea();
        }
        char getchar()
        {
            return c;
        }
        int getside()
        {
            return side;
        }

};
class Rectangle:public Card{
    private:
        int length;
        int breadth;
        int area;
        char c;
    public:
        Rectangle(int l,int b,int a,char c):length(l),breadth(b),area(a),c(c){}
        void area()
        {
            area=length*breadth;
        }
        int getarea()
        {
            return area;
        }
        virtual bool operator<(Card* c)
        {
            return area<c->getarea();
        }
        char getchar()
        {
            return c;
        }
        int getlength()
        {
            return length;
        }
        int getbreadth()
        {
            return breadth;
        }
};
class Triangle:public Card{
    private:
        int base;
        int height;
        int area;
        char c;
    public:
        Triangle(int b,int h,int a,char c):base(b),height(h),area(0),c(c){}
        void area()
        {
            area=(base*height)/2;
        }
        int getarea()
        {
            return area;
        }
        char getchar()
        {
            return c;
        }
        virtual bool operator<(Card* c)
        {
            return area<c->getarea();
        }
        int getbase()
        {
            return base;
        }
        int getheight()
        {
            return height;
        }
};
class CardOrganizer{
    private:
        vector<Card*> arr;
        vector<vector<Card*>> piles;
    public:
        CardOrganizer(){}
        void addCard(Card* a)
        {
            arr.push_back(a);
            // greedy algo to sutiably add the new card to right pile
        }
        size_t getPileCount() const {
            return piles.size();
        }
        vector<Card*> getLIS() const 
        {
            vector<Card*> ans;
            // algo for computing LIS
        }
};
int main()
{
    int q;cin>>q;
    CardOrganizer game=CardOrganizer();
    while(q--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            string s;
            if(s=="TRIANGLE")
            {
                int b;int h;cin>>b>>h;
                Card *a= new Triangle(b,h,0,'t');
                a->area();
                game.addCard(a);
            }
            else if(s=="RECTANGLE")
            {
                int l;int b;cin>>l>>b;
                Card* a=new Rectangle(l,b,0,'r');
                a->area();
                game.addCard(a);
            }
            else
            {
                int s;
                Card* a=new Square(s,0,'s');
                a->area();
                game.addCard(a);
            }
        }
        else if(x==2)
        {
            cout<<game.getPileCount()<<'\n';
        }
        else
        {
            vector<Card*> ans=game.getLIS();
            cout<<ans.size()<<'\n';
            for(auto& t:ans)
            {
                if(t->getchar()=='t')
                {
                    cout<<"TRIANGLE"<<" "<<t->getbase()<<" "<<t->getheight()<<'\n';
                }
                else if(t->getchar()=='r')
                {
                    cout<<"RECTANGLE"<<" "<<t->getlength()<<" "<<t->getbreadth()<<'\n';
                }
                else
                {
                    cout<<"SQUARE"<<" "<<t->getside()<<'\n';
                }
            }
        }
    }
}