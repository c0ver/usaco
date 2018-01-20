/*
ID: LGD84711
LANG: C++
TASK: milk
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int total, farmers, bought, paid;

struct structs
{
    int price;
    int amount;
};

structs choice[5000];

bool sortp(const structs &p, const structs &p1)
{
    return p.price<p1.price;
}

int main()
{
    ifstream fin ("milk.in");
    ofstream fout ("milk.out");

    fin >> total >> farmers;
    for(int x=0; x<farmers; x++){
        fin >> choice[x].price >> choice[x].amount;
    }

    sort(choice, choice+farmers, sortp);
    for(int x=0; x<farmers; x++){
        if(choice[x].amount<total-bought){
            bought=choice[x].amount+bought;
            paid=choice[x].amount*choice[x].price+paid;
        }
        else{
            paid=paid+(total-bought)*choice[x].price;
            break;
        }
    }
    fout << paid << endl;
}
