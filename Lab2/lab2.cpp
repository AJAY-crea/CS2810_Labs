#include <bits/stdc++.h>
using namespace std;
class Member;
class Library;
class Book
{
    private:
        string isbn;
        int copiesAvailable;
        int totalCopies;
    public:
        string author;
        string title;
    Book() : title("UnknownTitle"), author("UnknownAuthor"), isbn("ISBN"), copiesAvailable(0), totalCopies(5) {}
    Book(string title, string author, string isbn, int copiesAvailable, int totalCopies)
        : title(title), author(author), isbn(isbn), copiesAvailable(copiesAvailable), totalCopies(totalCopies) {}
    Book(const Book& b, string nisbn)
        : title(b.title), author(b.author), isbn(nisbn), copiesAvailable(b.copiesAvailable), totalCopies(b.totalCopies) {}
        string getisbn()
        {
            return isbn;
        }
        void setisbn(string nisbn)
        {
            isbn=nisbn;
        }
        int getcopiesAvailable()
        {
            return copiesAvailable;
        }
        void setcopiesAvailable(int n)
        {
            copiesAvailable=n;
        }
        int gettotalCopies()
        {
            return totalCopies;
        }
        void settotalCopies(int n)
        {
            totalCopies=n;
        }
        void updateCopies(int n)
        {
            if(copiesAvailable+n<0 or totalCopies+n<0){cout<<"Invalid request! Count becomes negative"<<'\n';}
            else{
                copiesAvailable+=n;
                totalCopies+=n;
            }
        }
        bool borrowBook()
        {
            if(copiesAvailable==0)
            {
                cout<<"Invalid request! Copy of book not available"<<'\n';
                return false;
            }
            else
            {
                copiesAvailable--;
                return true;
            }
        }
        bool returnBook()
        {
            if(copiesAvailable==totalCopies)
            {
                cout<<"Invalid request! Copy of book exceeds total copies"<<'\n';
                return false;
            }
            else{
                copiesAvailable++;
                return true;
            }
        }
        void printDetails()
        {
            cout<<title<<" "<<author<<'\n';
        }
    friend class Member;
    friend class Library;
};
class Member
{
    private:
        string memberID;
        map<string,int> borrowedBooks;
        int borrowLimit;
    public:
        string name;
        Member(string name, string memberID, int borrowLimit = 3) : name(name), memberID(memberID), borrowLimit(borrowLimit){}
        bool borrowBook(string is)
        {   
            int sum=0;
            for(auto &t:borrowedBooks)
            {
                sum+=t.second;
            }
            if(sum<borrowLimit)
            {   
                borrowedBooks[is]++;
               // cout<<borrowedBooks[is]<<'\n';
                return true;
            }
            cout<<"Invalid request! Borrow limit exceeded"<<'\n';
            return false;
        }
        bool returnBook(string isbn)
        {
            if(borrowedBooks[isbn]>=1){
                borrowedBooks[isbn]--;
                return true;
            }
            cout<<"Invalid request! Book not borrowed"<<'\n';return false;
        }
        void printDetails()
        { //cout<<borrowedBooks.size()<<'\n';
            for(auto& t:borrowedBooks)
            {  //cout<<1<<'\n';
                if(t.second>0){
                   // cout<<2<<'\n';
                    cout<<memberID<<" "<<name<<" ";
                    cout<<t.first<<" "<<t.second<<'\n';
                }
            }
        }
        string getID() 
        {
            return  memberID;
        }
         friend class Library;
};
class Library
{
    private:
        vector<Book> books;
        vector<Member> members;
    public:
        bool addBook(Book & b)
        {
            for(auto& t:books)
            {
                if(t.isbn==b.isbn)
                {
                    cout<<"Invalid request! Book with same isbn already exists"<<'\n';
                    return false;
                }
            }
            books.push_back(b);return true;
        }
        bool registerMember(Member& m)
        {
            for(auto& t:members)
            {
                if(t.getID()==m.getID())
                {
                    cout<<"Invalid request! Member with same id already exists"<<'\n';return false;
                }
            }
            members.push_back(m);return true;
        }
        bool borrowBook(string mid,string is)
        {   
            Book* b=nullptr;
            Member* m=nullptr;
            for(auto &t:books)
            {
                if(t.getisbn()==is)
                {
                    b=&t;break;
                }
            }
            if(b==nullptr or b->getcopiesAvailable()==0){
                cout<<"Invalid request! Copy of book not available"<<'\n';
                return false;
            }
            for(auto& p:members)
            {
                if(p.memberID==mid)
                {
                    m=&p;break;
                }
            }
            if(m==nullptr)
            {
                cout<<"Invalid request! Member not found"<<'\n';return false;
            }
            int sum=0;
            for(auto &t:m->borrowedBooks)
            {
                sum+=t.second;
            }
            if(sum>=m->borrowLimit)
            {
                cout<<"Invalid request! Borrow limit exceeded"<<'\n';return false;
            }
            m->borrowedBooks[is]++;
            b->setcopiesAvailable(b->getcopiesAvailable()-1);
            return true;
        }
        bool returnBook(string mid,string is)
        {
            Book* b=nullptr;
            Member* m=nullptr;
            for(auto& t:books)
            {
                if(t.getisbn()==is)
                {  // cout<<t.getcopiesAvailable()<<' '<<t.gettotalCopies()<<'\n';
                    b=&t;break;
                }
            }
            if(b==nullptr or b->getcopiesAvailable()+1>b->gettotalCopies())
            {   
                cout<<"Invalid request! Copy of book exceeds total copies"<<'\n';return false;
            }
            for(auto &t:members)
            {
                if(t.getID()==mid)
                {
                    m=&t;break;
                }
            }
            if(m==nullptr or m->borrowedBooks[is]==0)
            {
                cout<<"Invalid request! Book not borrowed"<<'\n';return false;
            }
            m->borrowedBooks[is]--;
            b->updateCopies(1);
            return true;
        }
        void printDetails()
        {
            for(auto& t:books)
            {
                cout<<t.title<<" "<<t.author<<" "<<t.getcopiesAvailable()<<'\n';
            }
            for(auto &t:members)
            {
                cout<<t.getID()<<" "<<t.name<<'\n';
            }
        }
        void updateCopiesLib(string is,int count)
        {
            for(auto &t:books)
            {
                if(t.getisbn()==is)
                {
                    t.updateCopies(count);
                }
            }
        }
        void printmem(string id){
            for(auto & c: members){
                if(c.getID()== id){
                    c.printDetails();
                }
            }
            return;
        }
};
int main() {
    Library lib;
    string s="";
    vector<Book> booksinp;
    vector<Member> membersinp;
    while(true)
    {
        cin>>s;
        if(s=="Done"){break;}
        else if(s=="Book")
        {
            string name;
            cin>>name;
            if(name=="None")
            {
                Book b;
                bool ok = lib.addBook(b);
               if(ok==true){
                booksinp.push_back(b);
               }
            }
            else if(name=="ExistingBook")
            {
                string oisb,nisb;
                cin>>oisb>>nisb;
                Book b;
                for(auto& c:booksinp)
                {
                    if(c.getisbn()==oisb)
                    {
                        b=Book(c,nisb);
                        break;
                    }
                }
                if(b.getisbn()!="ISBN")
                { 
                    bool ok=lib.addBook(b);
                    if(ok==true){
                        booksinp.push_back(b);
                    }
                }
            }
            else
            {
                string aut, isb;
                int cpie,tot;
                cin>>aut>>isb>>cpie>>tot;
                Book b(name,aut,isb,cpie,tot);
                bool ok=lib.addBook(b);
                if(ok==true)
                {
                    booksinp.push_back(b);
                }
            }
        } 
        else if(s=="Member")
        {
            string b;
            cin>>b;
            if(b=="NoBorrowLimit") 
            {
                string id, name;
                cin>>id>>name;
                Member m(name,id);
                bool ok=lib.registerMember(m);
                if(ok==true)
                {
                    membersinp.push_back(m);
                }
            }
            else
            {
                string name;
                int limit;
                cin>>name>>limit;
                Member m(name,b,limit);
                bool ok=lib.registerMember(m);
                if(ok==true)
                {
                    membersinp.push_back(m);
                }
            }
        }
        else if(s=="Borrow")
        {
            string id,isbn;
            cin>>id>>isbn;
            lib.borrowBook(id,isbn);
        }
        else if(s=="PrintBook")
        {
            string isbn;
            cin>>isbn;
            for(auto& c:booksinp)
            {
                if(c.getisbn()==isbn) 
                {   
                    c.printDetails();
                }
            }
        }
        else if(s=="PrintMember")
        {
            string id;
            cin>>id;
            lib.printmem(id);

        }
        else if(s=="PrintLibrary")
        {
            lib.printDetails();
        }
        else if(s=="Return")
        {
            string id,isbn;
            cin>>id>>isbn;
            lib.returnBook(id,isbn);
        }
        else if(s=="UpdateCopiesCount")
        {
            string isbn;
            int count;
            cin>>isbn>>count;
            lib.updateCopiesLib(isbn,count);
        }
    }
}
