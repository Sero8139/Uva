#include <iostream>

using namespace std;

int main(int argc , char* argv[] ){

	int kase;
	cin >> kase ;
	while(kase--){
		int n;
		cin >> n;
		int A[n];
		int B[n]={0};
		for(int i=0;i<n;i++){
			cin >> A[i];
			int count =0;
			for(int j=0;j<i;j++){
				if( A[j] <= A[i]){
					count++;
				}
			}
			B[i]=count;
		}

		int sum=0;
		for(int i=0;i<n;i++){
			sum+=B[i];
		}
		cout << sum << endl;
	}	

	return 0;
}