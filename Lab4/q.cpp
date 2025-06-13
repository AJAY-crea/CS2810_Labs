#include <bits/stdc++.h>
using namespace std;
typedef 
class QNS
{
    private:
        int powerLevel = 1000;
        int durability = 500;
        int energyStorage = 300;
        int heatLevel = 0;
    public:
        QNS(int p, int d, int e, int h)
        {
            powerLevel = p;
            durability = d;
            energyStorage = e;
            heatLevel = h;
        }
        QNS()
        {
        }
        QNS(QNS& q)
        {
            powerLevel = q.powerLevel;
            durability = q.durability;
            energyStorage = q.energyStorage;
            heatLevel = q.heatLevel;
        }
        QNS& operator+(QNS& q)
        {
            powerLevel += q.energyStorage;
            durability += q.durability;
            energyStorage += q.powerLevel;
            return *this;
        }
        QNS& operator-(int x)
        {
            if(durability <= x)
            {
                durability = 0;
                energyStorage += x;
                heatLevel += x;
                return *this;
            }
            else
            {
                durability -= x;
                energyStorage += x;
                heatLevel += x;
                return *this;
            }
        }
        QNS& operator*(int x)
        {
            powerLevel += (powerLevel)* (x/100);
            energyStorage += 5 * x;
            heatLevel +=x;
        }
        QNS& operator/(int x)
        {
            durability += x;
            heatLevel -= x;
            if(heatLevel <= 0){heatLevel = 0;}
            return *this;
        }
        void boostPower(int fac){
            *this = (*this)*fac;
            return ;
        }
        void boostPower(QNS otherSuit)
        {
            *this = (*this) + otherSuit;
        }
        bool operator==(QNS& q)
        {
            if(powerLevel == q.powerLevel and durability == q.durability)
            {
                return true;
            }
            return false;
        }
        bool operator<(QNS& q)
        {
            if((powerLevel + durability) < (q.powerLevel + q.durability))
            {
                return true;
            }
            return false;
        }
        int getpower()
        {
            return powerLevel;
        }
        int getdurability()
        {
            return durability;
        }
        int getenergy()
        {
            return energyStorage;
        }
        int getheat()
        {
            return heatLevel;
        }
        void setpower(int x)
        {
            powerLevel = x;
        }
        void setdurability(int x)
        {
            durability = x;
        }
        void setenergy(int x)
        {
            energyStorage = x;
        }
        void setheat(int x)
        {
            heatLevel = x;
        }
};
class Avenger
{
    private:
        string name;
        QNS suit;
        int attackStrength;
    public:
        Avenger(string avName, QNS avSuit, int strength)
        {
            name = avName;
            suit = avSuit;
            attackStrength = strength;
        }
        void attack(Avenger& enemy)
        {
            enemy.suit = enemy.suit - attackStrength;
        }
        void upgradeSuit()
        {
            
        }
        void repair(int x)
        {

        }
        void printStatus()
        {
            cout<< name << " " << suit.getpower() << " " << suit.getdurability() << " " << suit.getenergy() << " " << suit.getheat() <<'\n';
        }
        QNS getsuit()
        {
            return suit;
        }
};
class Battle
{
    private:
        vector<Avenger> heroes;
        vector<Avenger> enemies;
        vector<QNS> suits;
        vector<string> battleLog;
    public:
        void startBattle()
        {
            string s;
            cin>> s;
            while(s != "End")
            {
                if(s=="attack")
                {

                }
            }
        }
        void printBattleLog()
        {
            int n=battleLog.size();
            for(int i = 0; i < n; i++)
            {
                cout << battleLog[i] << '\n';
            }
        }
        int Result()
        {
            int heroespower = 0;
            int enemiespower = 0;
            int n = heroes.size();
            for(int i = 0 ;  i< n ;i++)
            {   
                QNS q = heroes[i].getsuit();
                heroespower += q.getpower();
                heroespower += q.getdurability();
            }
            n = enemies.size();
            for(int i =0 ;i < n  ;i++)
            {
                QNS q = heroes[i].getsuit();
                heroespower += q.getpower();
                heroespower += q.getdurability();
            }
            if(heroespower > enemiespower)return 1;
            else if(heroespower == enemiespower)return 0;
            return -1;
        }
};
int main()
{

}