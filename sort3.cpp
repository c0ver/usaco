/*
ID: LGD84711
LANG: C++
TASK: sort3
*/
#include <iostream>
#include <fstream>
using namespace std;

int N, N_integers[3], sequence[1000][2];
int changes;

int main()
{
    ifstream fin ("sort3.in");
    ofstream fout ("sort3.out");

    fin >> N;
    for(int x=0; x<N; x++){
        fin >> sequence[x][0];
        if(sequence[x][0] == 1) N_integers[0]++;
        else if(sequence[x][0] == 2) N_integers[1]++;
        else if(sequence[x][0] == 3) N_integers[2]++;
    }

    N_integers[1] += N_integers[0];
    N_integers[2] += N_integers[1];

    for(int x=0; x<N; x++){ // assign the right place for each integer in the array
        if(x < N_integers[0]) sequence[x][1] = 1;
        else if(x < N_integers[1]) sequence[x][1] = 2;
        else sequence[x][1] = 3;

        //cout << sequence[x][0] << " " << sequence[x][1] << endl;
    }

    for(int x=1; x<=3; x++){
        for(int y=N-1; y>=0; y--){
            bool check_switch = false;
            if(sequence[y][0] == x && sequence[y][1] != x){
                int placement = sequence[y][1];
                for(int z=N-1; z>=0; z--){
                    if(sequence[z][1] == x && sequence[z][0] == placement){
                        check_switch = true;
                        swap(sequence[z][0], sequence[y][0]);
                        /*cout << y << endl;
                        cout << "Good switch" << endl;
                        for(int x1=0; x1<N; x1++){
                            cout << sequence[x1][0] << " ";
                            if(x1 == z) cout << "Switched To Here";
                            if(x1 == y) cout << "Switched From Here";
                            cout << endl;
                        }
                        cout << endl;*/
                        changes++;
                        break;
                    }
                }
                if(check_switch == false){
                    for(int z=N-1; z>=0; z--){
                        if(sequence[z][1] == x && sequence[z][0] != x){
                            swap(sequence[z][0], sequence[y][0]);
                            /*cout << y << endl;
                            cout << "Bad switch" << endl;
                            for(int x1=0; x1<N; x1++){
                                cout << sequence[x1][0] << " ";
                                if(x1 == z) cout << "Switched To Here";
                                if(x1 == y) cout << "Switched From Here";
                                cout << endl;
                            }
                            cout << endl;*/
                            changes++;
                            break;
                        }
                    }
                }
            }
        }
        //cout << "finished " << x << endl;
    }
    fout << changes << endl;
}