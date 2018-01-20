/*
ID: LGD84711
LANG: C++
TASK: castle
*/
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

ifstream fin ("castle.in");
ofstream fout ("castle.out");

int floorplan[50][50][4];
int checkfp[50][50];
int col, row;
int room_size[2500], counter;
int rem_wall[5000][4], rem_counter;

int searchr(int r, int c, int prev, int s, int roomt)
{
    //fout << r << " " << c << " " << s << " " << roomt << endl;
    if(checkfp[r][c] != 0){
        fout << "ERROR" << endl;
        return 0;
    }
    checkfp[r][c] = roomt;
    if(floorplan[r][c][0] == 0 && prev != 2 && checkfp[r][c-1] == 0) s = searchr(r, c-1, 0, s+1, roomt); //West
    if(floorplan[r][c][1] == 0 && prev != 3 && checkfp[r-1][c] == 0) s = searchr(r-1, c, 1, s+1, roomt); //North
    if(floorplan[r][c][2] == 0 && prev != 0 && checkfp[r][c+1] == 0) s = searchr(r, c+1, 2, s+1, roomt); //East
    if(floorplan[r][c][3] == 0 && prev != 1 && checkfp[r+1][c] == 0) s = searchr(r+1, c, 3, s+1, roomt); //South
    return s;
}

int main()
{
    // find the walls
    fin >> col >> row;
    for(int x=0; x<row; x++){
        for(int y=0; y<col; y++){
            int walls;
            fin >> walls;
            //fout << x << " " << y << " " << walls << endl;
            while(walls != 0){
                if(walls >= 8){
                    floorplan[x][y][3] = 1;
                    walls -= 8;
                    //fout << "s";
                }
                if(walls >= 4){
                    floorplan[x][y][2] = 1;
                    walls -= 4;
                    //fout << "e";
                }
                if(walls >= 2){
                    floorplan[x][y][1] = 1;
                    walls -= 2;
                    //fout << "n";
                }
                if(walls >= 1){
                    floorplan[x][y][0] = 1;
                    walls -= 1;
                    //fout << "w";
                }             
            }
            //fout << x << " " << y << " ";
            //for(int z=0; z<4; z++) fout << floorplan[x][y][z] << " ";
            //fout << endl;
            //fout << " ";
        }
    }
    
    // use recursion to find the room sizes
    for(int x=0; x<row; x++){
        for(int y=0; y<col; y++){
            if(checkfp[x][y] != 0) continue;
            room_size[counter] = searchr(x, y, 5, 1, counter+1);
            counter++;
        }
    }

    //go through every room and find when they are adjacent
    for(int x=0; x<row; x++){
        for(int y=0; y<col; y++){
            bool checkabove = 1;
            bool checkright = 1;
            if(x == 0) checkabove = 0;
            if(y == col - 1) checkright = 0;

            if(checkfp[x][y] != checkfp[x][y+1] && checkright == 1){
                rem_wall[rem_counter][0] = room_size[checkfp[x][y] - 1] + room_size[checkfp[x][y+1] - 1];
                rem_wall[rem_counter][1] = x;
                rem_wall[rem_counter][2] = y;
                rem_wall[rem_counter][3] = 1; // keep track of whether the wall is to the right or above
                //cout << "right: " << x+1 << " " << y+1 << " " << rem_wall[rem_counter][0] << endl;
                rem_counter++;
            }
            if(checkfp[x][y] != checkfp[x-1][y] && checkabove == 1){
                rem_wall[rem_counter][0] = room_size[checkfp[x-1][y] - 1] + room_size[checkfp[x][y] - 1];
                rem_wall[rem_counter][1] = x;
                rem_wall[rem_counter][2] = y;
                rem_wall[rem_counter][3] = 0;
                //cout << "above: " << x+1 << " " << y+1 << " " << rem_wall[rem_counter][0] << endl;
                rem_counter++;
            }
            //cout << rem_wall[rem_counter-1][0] << " " << rem_wall[rem_counter-1][1] << " " << rem_wall[rem_counter-1][2] << endl;
        }
    }

    //for(int x=0; x<rem_counter; x++) fout << rem_wall[x][0] << " " << rem_wall[x][1] << " " << rem_wall[x][2] << endl;

    //find west -> south -> north -> east

    // find largest room
    int largest = 0;
    int L_array[rem_counter][3];
    int L_counter = 0;
    for(int x=0; x<rem_counter; x++) if(rem_wall[x][0] > largest) largest = rem_wall[x][0];
    for(int x=0; x<rem_counter; x++){
        //fout << x << " " << rem_wall[x][1] << " " << rem_wall[x][2] << endl;
        if(rem_wall[x][0] == largest){
            L_array[L_counter][0] = rem_wall[x][1];
            L_array[L_counter][1] = rem_wall[x][2];
            L_array[L_counter][2] = rem_wall[x][3];
            L_counter++;
        }
        //fout << x << " " << L_array[x][0] << " " << L_array[x][1] << " " << L_array[x][2] << endl;
    }

    //answer
    //fout << endl;
    fout << counter << endl;
    sort(room_size, room_size+counter);
    fout << room_size[counter-1] << endl;
    fout << largest << endl;

    if(L_counter == 1){
        fout << L_array[0][0] + 1 << " " <<  L_array[0][1] + 1 << " ";
        if(L_array[0][2] == 1) fout << "E" << endl;
        else fout << "N" << endl;
        return 0;
    }
    

    int west = 50; // a random number far to the east
    int W_counter = 0;
    int W_array[L_counter][3];
    for(int x=0; x<L_counter; x++) if(L_array[x][1] < west) west = L_array[x][1];
    for(int x=0; x<L_counter; x++){
        //if(L_array[x][1] == 0) cout << L_array[x][0] << " " << L_array[x][1] << " " << x << endl;
        if(L_array[x][1] == west){
            W_array[W_counter][0] = L_array[x][0];
            W_array[W_counter][1] = L_array[x][1];
            W_array[W_counter][2] = L_array[x][2];
            //cout << W_array[W_counter][0] << " " << W_array[W_counter][1] << " " << W_array[W_counter][2] << endl;
            W_counter++;
        }
    }
    if(W_counter == 1){
        fout << W_array[0][0] + 1 << " " <<  W_array[0][1] + 1 << " ";
        if(W_array[0][2] == 1) fout << "E" << endl;
        else fout << "N" << endl;
        return 0;
    }
    //cout << endl;

    int south = 0; // a random number far to the north
    int S_counter = 0;
    int S_array[2][3];
    for(int x=0; x<W_counter; x++) if(W_array[x][0] > south) south = W_array[x][0];
    for(int x=0; x<W_counter; x++){
        if(W_array[x][0] == south){
            S_array[S_counter][0] = W_array[x][0];
            S_array[S_counter][1] = W_array[x][1];
            S_array[S_counter][2] = W_array[x][2];
            //cout << S_array[S_counter][0] << " " << S_array[S_counter][1] << " " << S_array[S_counter][2] << endl;
            S_counter++;
        }
    }
    
    if(S_counter == 2){
        for(int x=0; x<2; x++){
            if(S_array[x][2] == 0){
                fout << S_array[x][0] + 1 << " " <<  S_array[x][1] + 1 << " " << "N" << endl;
                return 0;
            }
        }
    }
    else{
        fout << S_array[0][0] + 1 << " " <<  S_array[0][1] + 1 << " ";
        if(S_array[0][2] == 1) fout << "E" << endl;
        else fout << "N" << endl;
    }
}