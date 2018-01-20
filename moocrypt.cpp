#include <fstream>
#include <algorithm>
using namespace std;

struct structs
{
    char let;
    int numb;
};
structs freq[26];
char puzzle[50][50], the, crypt[50][50];
int w, h, place;

int main()
{
    ifstream fin ("moocrypt.in");
    ofstream fout ("moocrypt.out");

    fin >> h >> w;
    for(int x=0; x<h; x++){
        for(int y=0; y<w; y++){
            fin >> puzzle[x][y];
        }
    }

    for(int x=0; x<h; x++){
        for(int y=0; y<w; y++){
            place=(int) puzzle[x][y];
            place=place-65;
            freq[place].let=puzzle[x][y];
            freq[place].numb++;
            //fout << place << " " << freq[place].let << " " << freq[place].numb << endl;
        }
    }

    place=0;
    for(int x=0; x<26; x++){
        if(freq[x].numb>place){
            place=freq[x].numb;
            the=freq[x].let;
        }
    }

    for(int x=0; x<h; x++){
        for(int y=0; y<w; y++){
            if(puzzle[x][y]==the){
                puzzle[x][y]='O';
            }
        }
    }

    for(int x=0; x<h; x++){
        for(int y=0; y<w; y++){
            crypt[x][y]=puzzle[x][y];
        }
    }

    for(int x=0; x<26; x++){
        the=(char) 65+x;
        for(int x=0; x<h; x++){
            for(int y=0; y<w; y++){
                if(crypt[x][y]==the){
                    crypt[x][y]='M';
                }
            }
        }
    }

    /*for(int x=0; x<h; x++){
        for(int y=0; y<w; y++){
            fout << crypt[x][y];
        }
        fout << endl;
    }*/
}
