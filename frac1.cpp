/*
ID: LGD84711
LANG: C++
TASK: frac1
*/
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

ifstream fin ("frac1.in");
ofstream fout ("frac1.out");

int N, counter;

int gcd(int num, int den)
{
    int common_factor = den % num;
    if(num == 1) return num;
    if(common_factor == 0) return den;
    if(common_factor == 1) return num;
    for(int x=2; x<common_factor; x++){
        if(common_factor % x == 0 && num % x == 0){
            return den;
        }
    }
    if(num % common_factor == 0) return den;
    else return num;
}

struct fractions
{
    double value;
    int num, den;
};

fractions frac_array[100000];

bool sort_fractions(const fractions &f1, const fractions &f2)
{
    return f1.value < f2.value;
}

int main()
{
    fin >> N;

    frac_array[0].value = 0;
    frac_array[0].num = 0;
    frac_array[0].den = 1;
    counter = 1;

    for(int x=1; x<=N; x++){
        for(int y=1; y<x; y++){
            //cout << y << " " << x << " " << gcd(y, x) << endl;
            if(gcd(y, x) == y){
                frac_array[counter].value = (double) y / x;
                frac_array[counter].den = x;
                frac_array[counter].num = y;
                cout << frac_array[counter].value << " " << frac_array[counter].num << "/" << frac_array[counter].den << endl;
                counter++;
            }
        }
    }

    sort(frac_array, frac_array+counter, sort_fractions);
    frac_array[counter].value = 1;
    frac_array[counter].num = 1;
    frac_array[counter].den = 1;
    counter++;

    for(int x=0; x<counter; x++){
        fout << frac_array[x].num << "/" << frac_array[x].den << endl;
    }
}