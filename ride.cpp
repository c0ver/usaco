/*
ID: LGD84711
LANG: C++
TASK: ride
*/
//my first program
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("ride.in");
    ofstream fout ("ride.out");

    int a, z, b, c, d, e, f, g;
    string x, y;
    fin >> x >> y;
    a = x.length();
    z = y.length();
    d=1;
    f=1;
    c=0;
    do{
        b=x[c];
        b=b-64;
        d=d*b;
        c++;
    } while(c<a);
    c=0;
    do{
        e=y[c];
        e=e-64;
        f=f*e;
        c++;
    } while(c<z);
    if(d%47==f%47){
        fout << "GO" << endl;
    }
    else{
        fout << "STAY" << endl;
    }
}
