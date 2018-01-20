#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

long long a, b, total;
int numb, place, first, second, dif, counter;
bool skip;

struct structs
{
    string spot;
    int weight;
};

structs cows[50000];

bool sortw(const structs &w, const structs &w1)
{
    return w.weight<w1.weight;
}

int main()
{
    ifstream fin ("learning.in");
    ofstream fout ("learning.out");

    fin >> numb >> a >> b;
    for(int x=0; x<numb; x++){
        fin >> cows[x].spot >> cows[x].weight;
    }

    sort(cows, cows+numb, sortw);

    /*for(int x=0; x<numb; x++){
        skip=0;
        if(cows[x+1].spot=="S" && cows[x+1].weight>a){
                skip=1;
                counter++;
        }
        if(a>cows[x].weight && cows[x].spot=="S" && skip==0){
            total=total-cows[x].weight;
            break;
        }
        else if(skip==0){
            break;
        }
    }
    skip=0;*/

    for(int x=0; x<numb-1; x++){
        fout << x << endl;
        if(cows[x].weight>=a && cows[x+1].weight<=b){
            for(int y=x; y<numb-1;){
                if(cows[x].spot=="S" && cows[y+1].spot=="S"){
                    y++;
                }
                else{
                    total=total+cows[y].weight-a;
                }
            }
        }
    }
    fout << total << endl;
}
