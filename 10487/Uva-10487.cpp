#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main(int argc , char* argv[] ){

	int n,kase=0;
	while(cin >> n && n ){
		int array[n];
		for(int i=0;i<n;i++){
			cin >> array[i];
		}
		// compute all possible sum store in dp[n][n]
		// compute half matrix because the matrix is symmetric
		int dp[n][n];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				dp[i][j]=array[i]+array[j];
			}
		}

		int m;
		cin >> m;
		int closest[m];
		for(int i=0;i<m;i++){
			cin >> closest[i];
		}
		cout << "Case " << ++kase << ":" << endl;
		for(int k=0;k<m;k++){
			int diff = INT_MAX;
			// compare closest sum in dp[n][n];
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if( abs(dp[i][j]-closest[k]) < abs(diff) ){
						diff = dp[i][j]-closest[k];
					}
				}
			}
			cout << "Closest sum to " << closest[k] << " is " << diff+closest[k] << "." << endl;
		}
	}	

	return 0;
}