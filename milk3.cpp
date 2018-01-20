/*
ID: LGD84711
LANG: C++
TASK: milk3
*/
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("milk3.in");
ofstream fout ("milk3.out");

int maxa[3], fil[3], dif, swi;

int pour(int f, int s)
{
    if(fil[f]>=maxa[s]-fil[s] && maxa[s]-fil[s]>0){
        dif=maxa[s]-fil[s];
        fil[f]-=dif;
        fil[s]+=dif;
    }
    else if(fil[f]<maxa[s]-fil[s]){
        dif=fil[f];
        fil[f]-=dif;
        fil[s]+=dif;
    }
    return 0;
}

int rec()
{
    int x;
    for(x=0; x<=2; x++){
        if(fil[x]!=0){
            break;
        }
    }
    for(int y=0; y<=2; y++){
        if(y!=x && fil[y]!=maxa[y] && y!=swi){
            fout << x << " " << y << endl;
            pour(x, y);
            fout << fil[2] << " " << fil[1] << " " << fil[0] << endl;
            rec();
        }
    }
    return 0;
}

int main()
{
    fin >> maxa[2] >> maxa[1] >> maxa[0];
    fil[0]=maxa[0];
    rec();
}
