/*
ID: LGD84711
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int cows, work, idle, worktime, y;

struct structs
{
    int s;
    int e;
};

structs t[5000];

int main()
{
    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");

    fin >> cows;
    for(int x=0; x<cows; x++){
        fin >> t[x].s >> t[x].e;
    }
    for(int x=0; x<cows-1; x++){
        for(int x1=0; x1<cows-1; x1++){
            if(t[x1].s>t[x1+1].s){
                y=t[x1].s;
                t[x1].s=t[x1+1].s;
                t[x1+1].s=y;

                y=t[x1].e;
                t[x1].e=t[x1+1].e;
                t[x1+1].e=y;
            }
        }
    }
    worktime=t[0].e-t[0].s;
    for(int x=1; x<cows; x++){
        if(t[0].e>=t[x].s && t[0].e<=t[x].e){
            t[0].e=t[x].e;
            if(worktime<t[0].e-t[0].s){
                worktime=t[0].e-t[0].s;
            }
        }
        if(t[x].s>t[0].e){
           if (t[0].e - t[0].s > worktime)
               worktime = t[0].e - t[0].s;

           if (t[x].s - t[0].e > idle)
               idle = t[x].s - t[0].e;

           t[0].s = t[x].s;
           t[0].e = t[x].e;
       }
    }
    fout << worktime << " " << idle << endl;
}
