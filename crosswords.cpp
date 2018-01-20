#include <fstream>
using namespace std;

long long  h, v, clue;
char crossword[51][51];

struct structs
{
    long long right;
    long long down;
};

structs place[250];

int main()
{
    ifstream fin ("crosswords.in");
    ofstream fout ("crosswords.out");

    fin >> v >> h;
    for(int x=0; x<v; x++){
        for(int y=0; y<h; y++){
            fin >> crossword[x][y];
        }
    }

    clue=0;

    for(int x=0; x<v; x++){
        for(int y=0; y<h; y++){
            if(crossword[x][y]=='.'){
                if((y==0 || crossword[x][y-1]=='#') && crossword[x][y+1]=='.' && crossword[x][y+2]=='.'){
                    place[clue].right=y+1;
                    place[clue].down=x+1;
                    clue++;
                }
                else if((x==0 || crossword[x-1][y]=='#') && crossword[x+1][y]=='.' && crossword[x+2][y]=='.'){
                    place[clue].right=y+1;
                    place[clue].down=x+1;
                    clue++;
                }
            }
        }
    }
    fout << clue << endl;
    for(int x=0; x<clue; x++){
        fout << place[x].down << " " << place[x].right << endl;
    }
}
