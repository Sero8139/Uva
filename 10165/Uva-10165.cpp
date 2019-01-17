#include <iostream>

using namespace std;

int main(int argc , char* argv[]){

	int N;
	while(cin>>N && N){

		int stones[N];
		for(int i=0;i<N;i++){
			cin >> stones[i];
		}
		int XOR = 0;
		for(int i=0;i<N;i++){
			XOR = XOR^stones[i];
		}
		if( XOR ){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}

	return 0;
}