#include <iostream>
using namespace std;

class Distance
{
    public:
    int thou, inch, feet, yard, chain, furlong, mile, league;
    //constructor
    Distance(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
    {
        thou = a1;
        inch = a2;
        feet = a3;
        yard = a4;
        chain = a5;
        furlong = a6;
        mile = a7;
        league = a8;
    }
    private:
    void convert()
    {
        //converting to imperial diatance
        inch+=(thou/1000);
        thou=(thou%1000);
        feet+=(inch/12);
        inch=(inch%12);
        yard+=(feet/3);
        feet=(feet%3);
        chain+=(yard/22);
        yard=(yard%22);
        furlong+=(chain/10);
        chain=(chain%10);
        mile+=(furlong/8);
        furlong=(furlong%8);
        league+=(mile/3);
        mile=(mile%3);

    }
    public:
    void imperialDist()
    {
        convert();
        cout<<league<<" leagues "<<endl;
        cout<<mile<<" miles, "<<endl;
        cout<<furlong<<" furlongs, "<<endl;        
        cout<<chain<<" chains, "<<endl;
        cout<<yard<<" yards, "<<endl;
        cout<<feet<<" feet, "<<endl;
        cout<<inch<<" inches, "<<endl;
        cout<<thou<<" thous, "<<endl;
    }

};

int main()
{
    cout<<"Enter imperial distance from leagues to thous"<<endl;
    int a[8];
    for(int i=0;i<8;i++)
    {
        cin>>a[i];
    }
    Distance dist(a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
    cout<<"Distance: "<<endl;
    dist.imperialDist();

    return 0;
}
