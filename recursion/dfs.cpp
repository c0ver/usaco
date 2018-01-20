#include <fstream>
using namespace std;

ifstream fin ("dfs.in");
ofstream fout ("dfs.out");

int n, p[10000], c[10000], parent, child, deep, m;
bool tree;

int rec(int check)
{
    tree=false;
    for(int x=0; x<n; x++){
        parent=p[x];
        if(parent==check){
            m++;
            rec(c[x]);
            tree=true;
        }
    }
    if(tree==false){
        if(m>deep){
            deep=m;
        }
        m=0;
    }
    return 0;
}

int main()
{
    fin >> n;
    for(int x=0; x<n; x++){
        fin >> p[x] >> c[x];
    }
    for(int x=0; x<n; x++){
        m=0;
        rec(c[x]);
        if(m>deep){
            deep=m;
        }
    }
    fout << deep+1 << endl;
}
