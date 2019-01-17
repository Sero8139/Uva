#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc , char* argv[]){

    int N;
    while(cin >> N){

    	// computer the number of corners
        int length = 1 << N;
        // get input weights
        int weights[length]={0};
        for(int i=0;i<length;i++){
			cin >> weights[i];        
        }
        // computer potency of every corner
        int potency[length]={0};
        for(int i=0;i<length;i++){
        	int sum = 0;
        	int mask = 1;
            for(int j=0;j<N;j++){
                sum += weights[i ^ mask];
                mask = mask << 1;
        	}
        	potency[i] = sum;
        }
        
        // find maximun protency of two neighbouring corners
        int MAX = INT_MIN;
        for(int i=0;i<length;i++){
            int mask = 1;
            for(int j=0;j<N;j++){
                MAX = max(MAX , potency[i]+potency[i ^ mask]);
                mask = mask << 1;
            }
        }
        cout << MAX << endl;

    }
    return 0;
}
