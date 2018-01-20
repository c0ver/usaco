#include <fstream>
#include <algorithm>
using namespace std;

int a, b, numb, found, pay, fina;

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
        for(int x1=0; x1<choices[x].cities; x1++){
            fin >> choices[x].path[x1];
        }
    }
    sort(choices, choices+numb, sortp);
    for(int x=0; x<numb; x++){
        //fout << choices[x].price << endl;
    }
    fina=choices[numb-1].price*2;
    for(int x=0; x<numb; x++){
        for(int x1=0; x1<choices[x].cities; x1++){
            if(choices[x].path[x1]==a){
                found=1;
            }
            if(found==1 && choices[x].path[x1]==b){
                pay=choices[x].price;
            }
        }
        if(fina>pay && pay!=0){
            fina=pay;
        }
        found=0;
    }
    found=0;
    //fout << fina << endl;
    for(int x=0; x<numb; x++){
        for(int x1=0; x1<choices[x].cities; x1++){
            if(choices[x].path[x1]==a && found==0){
                pay=0;
                pay=choices[x].price;
                found=1;
            }
            if(found==1 && choices[x].path[x1]==b){
                pay=pay+choices[x].price;
                //fout << pay << endl;
                if(fina>pay && pay!=0){
                    fina=pay;
                }
                found=0;
                pay=0;
                break;
            }
        }
    }
    found=0;
    for(int x=numb-1; x>=0; x--){
        for(int x1=0; x1<choices[x].cities; x1++){
            if(choices[x].path[x1]==a && found==0){
                pay=0;
                pay=choices[x].price;
                //fout << pay << endl;
                found=1;
            }
            if(found==1 && choices[x].path[x1]==b){
                pay=pay+choices[x].price;
                //fout << pay << endl;
                if(fina>pay && pay!=0){
                    fina=pay;
                }
                found=0;
                pay=0;
                break;
            }
        }
    }
    if(fina==choices[numb-1].price*2){
        fout << -1 << endl;
        return 0;
    }
    fout << fina << endl;
}
