#include<bits/stdc++.h>
using namespace std;

// my approach
int hammingDistance(int x, int y) {
    int ham_dist {} ;
    while( x || y){
        if((x&1) != (y&1) )
            ham_dist++ ;
        x >>= 1 ;
        y >>= 1 ;
    }
    return ham_dist ;
}

int hammingDistance(int x, int y) {
    int XOR {x^y} , ham_dist {};
    while(XOR)
    {
        XOR=XOR&(XOR-1);
        ham_dist++;
    }
    return ham_dist;
}