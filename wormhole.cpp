/*
ID: LGD84711
LANG: C++
TASK: wormhole
*/
#include <fstream>
using namespace std;

ifstream fin ("wormhole.in");
ofstream fout ("wormhole.out");

int n, a[13], b[13], pairs[13], total, closeright[13];

bool cycle_exists()
{
  for (int start=1; start<=n; start++) {
    int pos = start;
    for (int counts=0; counts<n; counts++)
      pos = closeright[pairs[pos]];
    if (pos != 0){
        return true;
    }
  }
  return false;
}

int solve()
{
    int x, total=0;
    for(x=1; x<n+1; x++){
        if(pairs[x]==0){
            break;
        }
    }
    fout << "x: " << x << endl << endl;

    if (x > n) {
        if (cycle_exists()==true){
            return 1;
        }
        else{
            return 0;
        }
    }

    for(int y=x+1; y<n+1; y++){
        if(pairs[y]==0){
            pairs[x]=y;
            pairs[y]=x;
            fout << "pair: ";
            for(int t=1; t<n+1; t++){
                fout << pairs[t] << " ";
            }
            fout << endl << endl;
            total+=solve();
            fout << "Total: " << total << endl;
            fout << "y: " << y << endl;
            pairs[x]=0;
            pairs[y]=0;
            for(int t=1; t<n+1; t++){
                fout << pairs[t] << " ";
            }
            fout << endl;
        }
    }
    fout << "end" << endl;
    return total;
}

int main()
{
    fin >> n;
    for(int x=1; x<n+1; x++){
        fin >> a[x] >> b[x];
    }
    for(int x=1; x<n+1; x++){
        for(int y=1; y<n+1; y++){
            if(b[x]==b[y] && a[x]<a[y]){
                if(closeright[x]==0 || a[y]-a[x]<a[closeright[x]]-a[x])
                    closeright[x]=y;
            }
        }
        //fout << closeright[x] << endl;
    }

   fout << "solve: " << solve() << endl;
}
