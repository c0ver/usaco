/*
ID: LGD84711
LANG: C++
TASK: barn1
*/
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int boards, total, cows, stall[200], most[200];

bool s(const int &a, const int &b)
{
    return a>b;
}

int main()
{
    ifstream fin ("barn1.in");
    ofstream fout ("barn1.out");

    fin >> boards >> total >> cows;
    for(int x=0; x<cows; x++){
        fin >> stall[x];
    }

    if(cows<boards){
        fout << cows << endl;
        return 0;
    }

    sort(stall, stall+cows);

    for(int x=0; x<cows-1; x++){
        most[x]=stall[x+1]-stall[x];
    }

    sort(most, most+cows, s);
    for(int x=0; x<cows; x++){
       //    fout << most[x] << endl;
    }

    total=stall[cows-1];

    for(int x=0; x<boards-1; x++){
        total=total-most[x]+1;
    }
    total=total-stall[0]+1;
    fout << total << endl;
}
