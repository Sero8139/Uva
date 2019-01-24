#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>

using namespace std;

int compute_max( bool *solution, int *weights , int n){

	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(solution[i*n+j]){
				sum+=weights[i*n+j];
			}
		}
	}
	return sum;
}

void backtrack(vector<bool*> &map , int*weights , int x, int y , int c ,int n,int &MAX)
{

	bool *solution=map[0];
	bool *mx=map[1];
	bool *my=map[2];
	bool *md1=map[3];
	bool *md2=map[4];

    if (y == n){  
    	x++; 
    	y=0;
    }
 
    if (x == n){
        if(c == n){
        	MAX = max( MAX,compute_max(solution,weights,n) );
        }
        return;
    }
 
    int d1 = (x+y) % (2*n-1), d2 = (x-y+(2*n-1)) % (2*n-1);
 
    if (!mx[x] && !my[y] && !md1[d1] && !md2[d2])
    {
        mx[x] = my[y] = md1[d1] = md2[d2] = true;
        solution[x*n+y] = true;
        backtrack(map,weights,x, y+1, c+1 , n , MAX);
        mx[x] = my[y] = md1[d1] = md2[d2] = false;
    }
    solution[x*n+y] = false;
    backtrack(map,weights,x, y+1 , c , n , MAX);

}

int main(int argc , char* argv[] ){

	int kase;
	cin >> kase;
	for(int k=0;k<kase;k++){

		int n = 8;
		int weights[n*n]={0};
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> weights[i*n+j]; 
			}
		}

		bool solution[n*n]={false};
		bool mx[n]={false},my[n]={false},md1[2*n-1]={false},md2[2*n-1]={false};
		vector<bool*> map;
		map.push_back(solution);
		map.push_back(mx);
		map.push_back(my);
		map.push_back(md1);
		map.push_back(md2);

		int MAX=INT_MIN;
		backtrack(map,weights,0,0,0,n,MAX);

		cout << setfill(' ') << setw(5) << MAX << endl;
	}

	return 0;
}