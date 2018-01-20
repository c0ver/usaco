#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int comp(string first, string second)
{
    return first<second;
}

struct structs
{
    string string1;
    string string2;
    string string3;
};

int comp1(structs first, structs second)
{
    if(first.string1>second.string1){
        return 0;
    }
    else{
        return 1;
    }
}

int prob, total[1001];

int main()
{
    ifstream fin ("records.in");
    ofstream fout ("records.out");

    int numb;
    fin >> numb;
    structs name[1001];
    string names[1001][3], place;
    for(int counter=0; counter<numb; counter++){
        for(int counter1=0; counter1<3; counter1++){
            fin >> names[counter][counter1];
        }
    }
    for(int counter=0; counter<numb; counter++){
        sort(names[counter], names[counter]+3, comp);
    }
    for(int counter=0; counter<numb; counter++){
        name[counter].string1=names[counter][0];
        name[counter].string2=names[counter][1];
        name[counter].string3=names[counter][2];
    }
    for(int counter=0; counter<numb; counter++){
        prob=0;
        for(int counter1=counter; counter1<numb; counter1++){
            if(name[counter].string1==name[counter1+1].string1 && name[counter].string2==name[counter1+1].string2 && name[counter].string3==name[counter1+1].string3){
                total[counter]++;
            }
        }
    }
    sort(total, total+numb);
    fout << total[numb-1]+1 << endl;
}
