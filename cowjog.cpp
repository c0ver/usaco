#include <fstream>
using namespace std;

int numb, groups, place;
bool c;

struct structs
{
    int position;
    int speed;
};

structs cows[100000];


int main()
{
    ifstream fin ("cowjog.in");
    ofstream fout ("cowjog.out");

    fin >> numb;

    for(int x=0; x<numb; x++){
        fin >> cows[x].position >> cows[x].speed;
    }

    for(int x=numb-1; x>=0; x--){
        c=0;
        place=x;
        do{
            //fout << cows[place].speed << " " << cows[x-1].speed << endl;
            if(cows[place].speed<cows[x-1].speed){
                c=1;
                if(x>=0){
                    x--;
                }
                else{
                    c=0;
                }
            }
            else{
                c=0;
            }
        }
        while(c==1);
        //fout << endl;
        groups++;
    }
    fout << groups << endl;

}
