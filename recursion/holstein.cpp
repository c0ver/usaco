/*
ID: LGD84711
LANG: C++
TASK: holstein
*/
#include <iostream>
#include <fstream>
using namespace std;

int N_feed, feed[15][25];
int N_vita, vita_req[25];

int lowest_length = 15;
int lowest_sum = 200;
int best_sequence[15];

int tree(int end, int N_array[], int index, int length)
{
    //when a combination of feed is found
    if(index == length){
        bool req_met = true;
        int vita_consumed[25] = {0};

        // add up all the feed vitamins
        for(int x=0; x<index; x++){
            for(int y=0; y<N_vita; y++){
                vita_consumed[y] += feed[N_array[x]][y];
            }
        }

        //check if requirements are met
        for(int x=0; x<N_vita; x++){
            if(vita_consumed[x] < vita_req[x]){
                req_met = false;
                break;
            }
        }

        /*cout << endl;
        cout << req_met << endl;
        for(int x=0; x<N_vita; x++){
            cout << vita_consumed[x] << " ";
        }
        cout << endl;*/

        if(req_met == true && index <= lowest_length){
            int length_sum = 0;
            lowest_length = index;
            for(int x=0; x<index; x++){
                length_sum += N_array[x] + 1;
            }
            //cout << length_sum << " " << lowest_sum << endl << endl;
            if(length_sum < lowest_sum){
                lowest_sum = length_sum;
                for(int y=0; y<index; y++){
                    best_sequence[y] = N_array[y];
                }
            }
        }

        return 0;
    }
    for(int x=end; x<N_feed; x++){
        N_array[index] = x;
        tree(x+1, N_array, index+1, length);
    }
    return 0;
}

int main()
{
    ifstream fin ("holstein.in");
    ofstream fout ("holstein.out");

    fin >> N_vita;
    for(int x=0; x<N_vita; x++) fin >> vita_req[x];

    fin >> N_feed;
    for(int x=0; x<N_feed; x++){
        for(int y=0; y<N_vita; y++){
            fin >> feed[x][y];
        }
    }

    // in case there is only one feed to chose from
    if(N_feed == 1){
        fout << "1 1" << endl;
        return 0;
    }
    for(int x=0; x<N_feed; x++){
        int N_array[N_feed] = {0};
        tree(0, N_array, 0, x+1);
    }

    fout << lowest_length;
    for(int x=0; x<lowest_length; x++){
        fout << " " << best_sequence[x] + 1;
    }
    fout << endl;
}