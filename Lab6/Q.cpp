#include <bits/stdc++.h>
using namespace std;
class CurrencySorter
{    
    public:   
        CurrencySorter(){}
        vector<long long> operator()(vector<long long>& arr)
        {
            vector<long long> p =arr;
            //quicksort

            return p;
        }
};
class FibonacciGenerator
{  public:
    long long operator()(long long n)
    {   int ans=0;
        //fibonaci 
        return ans;
    }
};
class PrimeCalculator{
    public:
        void printPrimes(long long  l,long long r)
        {
            vector<long long> primes=primeRange(l,r);
            for(auto& t:primes)
            {
                cout<<t<<" ";
            }
            cout<<'\n';
        }
        long long printPrimeSum(long long  l,long long r)
        {
            vector<long long> primes;
            vector<long long> primes=primeRange(l,r);
            long long sum=0;
            for(auto & t:primes)
            {
                sum+=t;
            }
            return sum;
        }
};
class NumberAnalyzer
{
    public:
        bool isSquareFree(long long n)
        {
            if(n%2==0)
            n=n/2;
            if(n%2==0)
            return false;
            for(int i=3;i<=sqrt(n);i=i+2)
            {
                if(n%i==0)
                {
                    n=n/i;
                    if(n%i==0)
                    return false;
                }
            }
            return true;
        }
        long long countDivisors(long long x)
        {
            long long ans=0;
            for(long long i=1;i*i<=x;i++)
            {
                if(x%i==0)ans+=2;
            }
            return ans;
        }
        long long sumOfDivisors(long long x)
        {
            long long ans=0;
            for(long long i=1;i*i<=x;i++)
            {
                if(x%i==0)
                {
                    ans=ans+i+(x/i);
                }
                if((i*i)==x and x%i==0){ans-=i;}
            }
            return ans;
        }
};
int main()
{
    int n;cin>>n;
    if(n==1)
    {
        int t;cin>>t;
        while(t--)
        {
            int p;cin>> p;
            vector<long long> arr;
            for(int i=0;i<n;i++)
            {cin>>arr[i];}
            CurrencySorter c;
            arr=c(arr);
            for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<'\n';
        }
    }
    else if(n==2)
    {
        int t;cin>> t;
        while(t--)
        {
            long long x;cin>>x;
            FibonacciGenerator f;
            long long y=f(x);
            cout<<y<<'\n';
        }
    }
    else if(n==3)
    {
        int t;cin>>t;
        while(t--)
        {
            string s;cin>>s;
            long long l;long long r;cin>>l>>r;
            if(s=="printPrimes")
            {
                PrimeCalculator p;
                p.printPrimes(l,r);
            }
            else 
            {
                PrimeCalculator p;
                long long g=p.printPrimeSum(l,r);
                cout<<g<<'\n';
            }
        }
    }
    else{
        int t;cin>>t;
        while(t--)
        {
            string s;cin>>s;
            long long n;cin>>n;
            if(s=="isSquareFree")
            {
                NumberAnalyzer num;
                bool p=num.countDivisors(n);
                if(p==1){cout<<"yes"<<'\n';}
                else{cout<<"no"<<'\n';}
            }
            else if(s=="countDivisors")
            {
                NumberAnalyzer num;
                long long ans=num.countDivisors(n);
                cout<<ans<<'\n';
            }
            else
            {
                NumberAnalyzer num;
                cout<<num.sumOfDivisors(n)<<'\n';
            }
        }
    }
}