/*
ID: LGD84711
LANG: C++
TASK: gift1
*/
#include <iostream>
#include <fstream>
using namespace std;

struct structs
{
    string person;
    int bank;
};

int main()
{
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");

    int people, money, counter, split, counters, counter1;
    string chosen;
    structs friends[11];
    fin >> people;
    for(int counter=0; counter<people; counter++){
        fin >> friends[counter].person;
        friends[counter].bank=0;
    }
    counter=0;
    do{
        chosen="0";
        fin >> chosen;
        cout << chosen << endl;
        money=1;
        do{
            if(chosen==friends[counter].person){
                fin >> money >> split;
                if(split==0){
                    break;
                }
                cout << money << " " << split << endl;
                money=money/split;
                friends[counter].bank=friends[counter].bank-(money*split);
                cout << money << endl;
                for(int counters=0; counters<split; counters++){
                    fin >> chosen;
                    cout << chosen << endl;
                    counter1=0;
                    do{
                        if(chosen==friends[counter1].person){
                            friends[counter1].bank=friends[counter1].bank+money;
                            break;
                        }
                        counter1++;
                    }
                    while(counter1<people);
                }
                for(int counter=0; counter<people; counter++){
                    cout << friends[counter].person << " " << friends[counter].bank << endl;
                }
                break;
            }
            counter++;
        }
        while(counter<people);
        counter=0;
    }
    while(chosen!="0");
    for(int counter=0; counter<people; counter++){
        fout << friends[counter].person << " " << friends[counter].bank << endl;
    }
}
