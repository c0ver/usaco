#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct structs
{
    char event;
    int number;
};

int numb, t, the, counterd, countert, fraction;
float speed;
structs probt[10000], probd[10000], prob[10000];
char character;

int comp(structs first, structs second)
{
    if(first.number>second.number){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    ifstream fin ("slowdown.in");
    ofstream fout ("slowdown.out");

    fin >> numb;
    speed=1;
    for(int counter=0; counter<numb; counter++){
        fin >> prob[counter].event >> prob[counter].number;
    }
    for(int counter=0; counter<numb; counter++){
        if(prob[counter].event=='T'){
            probt[the].event='T';
            probt[the].number=prob[counter].number;
            the++;
        }
    }
    the=0;
    for(int counter=0; counter<numb; counter++){
        if(prob[counter].event=='D'){
            probd[the].event='D';
            probd[the].number=prob[counter].number;
        }
    }
    sort(probt, probt+numb, comp);
    sort(probd, probd+numb, comp);
    fraction=1;
    for(double counter=0; counter<1000; counter=counter+speed){
        if(probd[counterd].number==counter){
            counterd++;
            fraction++;
            speed=1/(double)fraction;
        }
        if(probt[countert].number==t){
            countert++;
            fraction++;
            speed=1/(double)fraction;
        }
        t++;
    }
    fout << t << endl;
}
