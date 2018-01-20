#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("angry.in");
ofstream fout ("angry.out");

int n, k, dif[50000], difn, bigdif, bigdifa[10], place, biggest, start, stop;
int cows[50000];
bool split[50000];

int main()
{
    fin >> n >> k;
    for(int x=0; x<n; x++){
        fin >> cows[x];
    }
    sort(cows, cows + n);
    for(int x=0; x<n; x++){
        fout << cows[x] << endl;
    }
    fout << endl;
        
    difn = n-1;
    for(int x=0; x<difn; x++){
        dif[x] = cows[x+1] - cows[x];
        fout << dif[x] << endl;
    }
    fout << endl;

    for(int x=0; x<k-1; x++){
        for(int y=0; y<difn; y++){
            if(split[y] == false && dif[y] > bigdif){
                bigdif = dif[y];
                place = y;
            }
        }
        fout << place << endl;
        bigdifa[x] = place;
        split[place] = true;
        bigdif = 0;
        sort(bigdifa, bigdifa+x+1);
    }
    //fout << endl;

    stop = bigdifa[0];
    for(int x=0; x<k; x++){
        fout << cows[start] << " " << cows[stop] << endl;
        if(cows[stop] - cows[start] > biggest){
            biggest = cows[stop] - cows[start];
        }
        start = stop + 1;
        if(x == k-2){
            stop = n - 1;
        }
        else{
            stop = bigdifa[x+1];
        }
        //fout << biggest << endl;
    }

    if(biggest % 2 == 1){
        biggest++;
    }
    fout << biggest/2 << endl;
}
