#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc , char* argv[] ){

	int N;
	cin >> N;
	for(int i=0;i<N;i++){

		string str;
		cin >> str;
		int n = str.length();
		int matrix[n+1][n+1];
		std::memset(matrix, 0, sizeof matrix);
		for(int j=1;j<=n;j++){
			matrix[1][j]=str[j-1]-'0';
		}
		for(int i=2;i<=n;i++){
			cin >> str;
			for(int j=1;j<=n;j++){
				matrix[i][j]=str[j-1]-'0';
			}
		}

		int matrix_sum[n+1][n+1];
		std::memset(matrix_sum, 0, sizeof matrix_sum);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				matrix_sum[i][j] =   matrix_sum[i-1][j]
								   + matrix_sum[i][j-1]
								   - matrix_sum[i-1][j-1]
								   + matrix[i][j];
			}
		}
		int MAX = INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int si=0;si<i;si++){
					for(int sj=0;sj<j;sj++){
						MAX = max(MAX ,  matrix_sum[i][j]
									   - matrix_sum[i][sj]
									   - matrix_sum[si][j]
									   + matrix_sum[si][sj]);
					}
				}

			}
		}
		cout << MAX << endl;

	}

	return 0;
}