#include <fstream>
#include <algorithm>
using namespace std;

int a, b, numb, found, o;

struct structs
{
    int price;
    int cities;
    int path[500];
};

structs choices[500];

int sortp(structs first, structs second)
{
    if(first.price>second.price){
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
    ifstream fin ("cowroute.in");
    ofstream fout ("cowroute.out");

    fin >> a >> b >> numb;
    for(int x=0; x<numb; x++){
        fin >> choices[x].price >> choices[x].cities;
        //fout << choices[x].price << " " << choices[x].cities << " ";
        for(int x1=0; x1<choices[x].cities; x1++){
            fin >> choices[x].path[x1];
            //fout << choices[x].path[x1] << " ";
        }
        //fout << endl;
    }
    sort(choices, choices+numb, sortp);
    for(int x=0; x<numb; x++){
        //fout << choices[x].price << endl;
    }
    for(int x=0; x<numb; x++){
        for(int x1=0; x1<choices[x].cities; x1++){
            if(choices[x].path[x1]==a){
                found=1;
            }
            if(found==1 && choices[x].path[x1]==b){
                fout << choices[x].price << endl;
                return 0;
            }
        }
        found=0;
    }
    if(o==0){
        fout << -1 << endl;
    }
}
