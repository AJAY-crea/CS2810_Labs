#include <bits/stdc++.h>
using namespace std;
class RollNumber
{
    public:
        string roll;
        RollNumber(string roll):roll(roll){}
};
class Faculty
{
    public:
        string fac;
        bool per;
        Faculty(string fac,bool per):fac(fac),per(per){}
        Faculty() : fac("Unknown"), per(false) {}
};
class BTech{
    public:
        RollNumber r;
        string hostel;
        Faculty facad;
        Faculty BTPguide;
        float cgpa;
        BTech(RollNumber r, string hostel, Faculty facad, float cgpa):r(r),hostel(hostel),facad(facad),cgpa(cgpa){}
        string getHostel() const
        {
            return hostel;
        }
        Faculty getFacad() const
        {
            return facad;
        }
        void changeHostel(string a) 
        {
            hostel=a;
        }
        Faculty getBTPGuide() const
        {
            return BTPguide;
        }
        void setBTPGuide(Faculty b)
        {
            BTPguide=b;
        }
};
class DualDegree
{
    public:
        RollNumber r;
        string hostel;
        Faculty facad;
        Faculty DDPguide;
        Faculty tasup;
        float cgpa;
        DualDegree(RollNumber r, string hostel, Faculty facad, float cgpa):r(r),hostel(hostel),facad(facad),cgpa(cgpa){}
        string getHostel() const
        {
            return hostel;
        }
        Faculty getFacad() const
        {
            return facad;
        }
        void changeHostel(string a)
        {
            hostel=a;
        }
        Faculty getDDPGuide() const
        {
            return DDPguide;
        }
        void setDDPGuide(Faculty b)
        {
            DDPguide=b;
        }
        void setTASupervisor(Faculty b)
        {
            tasup=b;
        }
        Faculty getTASupervisor() const
        {
            return tasup;
        }
};
std::string generate_random_string(size_t length) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::string random_string;
    for (size_t i = 0; i < length; ++i) {
        // Use std::rand() to pick a random index
        int random_index = std::rand() % characters.size();
        random_string += characters[random_index];
    }

    return random_string;
}

bool comp(const BTech &a ,const BTech & b)
{
    return a.cgpa>b.cgpa;
};
bool comp1(const DualDegree &a,const DualDegree& b)
{
    return a.cgpa>b.cgpa;
};
int main()
{   
    int n=100;int m=60;
    vector<BTech> btech;
    vector<DualDegree> dualdegree;
    vector<Faculty> faculty;
    std::srand(static_cast<unsigned int>(std::time(0)));
    for(int i=0;i<m;i++)
    {
        bool b=true;
        string name;
        name=generate_random_string(10);
        faculty.emplace_back(name,true);
    }
    for(int i=0;i<n;i++)
    {
        std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<> distribution(0, faculty.size() - 1);
        int p = distribution(generator);
        string roll=generate_random_string(8);
        string hname=generate_random_string(5);
        float cg = static_cast<float>(rand()) / RAND_MAX * 5.0;
        RollNumber rol(roll);
        Faculty& f=faculty[p];
        BTech a(rol,hname,f,cg);
        btech.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<> distribution(0, faculty.size() - 1);
        int p = distribution(generator);
        string roll=generate_random_string(8);
        string hname=generate_random_string(5);
        float cg = static_cast<float>(rand()) / RAND_MAX * 5.0;
        Faculty& f=faculty[p];
        RollNumber r(roll);
        DualDegree d(r,hname,f,cg);
        dualdegree.push_back(d);
    }
    sort(btech.begin(),btech.end(),comp);
    int k=0;int p=0;
    for(int i=0;i<m;i++)
    {   
        auto& f=faculty[i];
        if(f.per==true){
            if(p>=m)break;
            auto& now=btech[p];
            now.setBTPGuide(f);
            p++;
            if(p>=m)break;
            auto& now1=btech[p];
            now1.setBTPGuide(f);
            p++;
        }
    }
    sort(dualdegree.begin(),dualdegree.end(),comp1);
    p=0;
    for(int i=0;i<m;i++)
    {   
        auto& f=faculty[i];
        if(f.per==true){
            if(p>=m)break;
            auto& now=dualdegree[p];
            now.setDDPGuide(f);
            p++;
            if(p>=m)break;
            auto& now1=dualdegree[p];
            now1.setDDPGuide(f);
            p++;
        }
    }
    p=0;
    for(int i=0;i<m;i++)
    {   
        auto& f=faculty[i];
        int k=1;
        while(k<6 and p<m)
        {
            auto& now=dualdegree[p];
            now.setTASupervisor(f);
            k++;p++;
        }
    }

    cout << "Faculty Details:" << endl;
    for (const auto &f : faculty) {
        cout << "Faculty Name: " << f.fac << ", Permanent: " << (f.per ? "Yes" : "No") << endl;
    }

    // Print    
    cout << "\nBTech Students:" << endl;
    for (const auto &bt : btech) {
        cout << "Roll: " << bt.r.roll << ", Hostel: " << bt.getHostel() << ", CGPA: " << bt.cgpa
             << ", Facad: " << bt.getFacad().fac << ", BTP Guide: " << bt.getBTPGuide().fac << endl;
    }

    // Print all DualDegree student details
    cout << "\nDualDegree Students:" << endl;
    for (const auto &dd : dualdegree) {
        cout << "Roll: " << dd.r.roll << ", Hostel: " << dd.getHostel() << ", CGPA: " << dd.cgpa
             << ", Facad: " << dd.getFacad().fac << ", DDP Guide: " << dd.getDDPGuide().fac
             << ", TA Supervisor: " << dd.getTASupervisor().fac << endl;
    }

    return 0;
}