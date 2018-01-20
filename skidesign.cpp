/*
ID: LGD84711
LANG: C++
TASK: skidesign
*/
#include <fstream>
#include <algorithm>
using namespace std;

int hills[1000], numb, money, dif, total, maximum;

int main()
{
    ifstream fin ("skidesign.in");
    ofstream fout ("skidesign.out");

    fin >> numb;
    for(int x=0; x<numb; x++){
        fin >> hills[x];
    }

    for(int x=0; x<100; x++){
        maximum=x+17;
        money=0;
        for(int y=0; y<numb; y++){
            if(hills[y]<x){
                dif=x-hills[y];
                money=dif*dif+money;
               // fout << "min: " << dif << endl;
            }
            else if(hills[y]>maximum){
                dif=hills[y]-maximum;
                money=dif*dif+money;
               // fout << "max: " << dif << endl;
            }
        }
       // fout << x << " " << maximum << endl;
       // fout << money << endl << endl;
        if(x==0){
            total=money;
        }
        if(total>money){
            total=money;
        }
    }
    fout << total << endl;
}
