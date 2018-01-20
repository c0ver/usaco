/*
ID: LGD84711
LANG: C++
TASK: pprime
*/
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

ifstream fin ("pprime.in");
ofstream fout ("pprime.out");

bool check_palindrome(int N) {
    int reverse_N = 0, temp = N;
    while(temp > 0) {
        reverse_N = reverse_N * 10 + (temp % 10);
        temp /= 10;
    }
    if(reverse_N != N) return false;
    else return true;
}

bool check_prime(int N) {
    if(N % 2 == 0) return false;

    for(int x=3; x<=sqrt(N); x+=2) {
        if(N % x == 0) return false;
    }
    return true;
}

int main()
{
    int min_N, max_N;
    fin >> min_N >> max_N;

    int counter = -1; // all prime numbers are a form of 6k +- 1
    for(int x=1; x<=max_N/6; x++) {
        for(int y=-1; y<=1; y+=2) {
            if(x * 6 + y < min_N) continue;
            if(x * 6 + y > 10000000) return 0;

            if(check_palindrome(x * 6 + y) && check_prime(x * 6 + y)) {
                fout << x * 6 + y << endl; 
            }
        }
    }
}
