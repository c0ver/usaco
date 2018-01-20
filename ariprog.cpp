/*
ID: LGD84711
LANG: C++
TASK: ariprog
*/
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("ariprog.in");
ofstream fout ("ariprog.out");

int n, m, sq[125001], solvec;
bool pass, over;

struct structs
{
    int start;
    int dif;
};

bool comp1(const structs &w, const structs &w1)
{
    return w.dif<w1.dif;
}
structs solve[10000];

int main()
{
    fin >> n >> m;
    for(int x=0; x<125001; x++){
        sq[x]=3; // random number
    }
    
    for(int x1=0; x1<=m; x1++){
        for(int x2=0; x2<=m; x2++){
            sq[x1*x1+x2*x2]=x1*x1+x2*x2;
        }
    }
    for(int x=0; x<m*m+m*m-n; x++){ // go through all beginning numbers a
        for(int x1=1; x1<=(m*m+m*m)/(n-1); x1++){ // go through all differences b
            if(sq[x]+x1*(n-1)>m*m+m*m){
                break;
            }
            pass=true;
            for(int x2=0; x2<n; x2++){ // go through all calculated sequence
                if(sq[sq[x]+x1*x2]==3 || sq[x]+x1*x2>125000){
                    pass=false;
                    break;
                }
            }
            if(pass==true){
                solve[solvec].start=sq[x];
                solve[solvec].dif=x1;
                solvec++;
            }
        }
    }
    sort(solve, solve+solvec, comp1);
    for(int x=0; x<solvec; x++){
        fout << solve[x].start << " " << solve[x].dif << endl;
    }
    if(solve[0].dif==0){
        fout << "NONE" << endl;
    }
}