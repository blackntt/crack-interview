#include <assert.h>
#include <iostream>
using namespace std;
int** zeroMatrix(int **m, int N, int M){
	bool rows[N];
	bool cols[M];
	memset(rows,0,sizeof(rows));
	memset(cols,0,sizeof(cols));
	int** result;
	result = new int*[N];
	for(int i=0;i<N;i++){
		result[i] = new int[M];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			result[i][j] = m[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j = 0 ;j< M;j++){
			if(m[i][j]== 0){
				rows[i]=true;
				cols[j]=true;
			}
		}
	}
	for(int i=0;i<N;i++){
		if(rows[i]){
			for(int j=0;j<M;j++){
				result[i][j]=0;
			}
		}
	}
	for(int i=0;i<M;i++){
		if(cols[i]){
			for(int j=0;j<N;j++){
				result[j][i]=0;
			}
		}
	}
	return result;
}
int main(int argc, char ** argv){
	int n,m;
	cin >>n>>m;
	int **matrix = new int*[n];
	for(int i=0;i<n;i++){
		matrix[i] = new int[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> matrix[i][j];
		}
	}

	int **result1= new int*[n];
	for(int i=0;i<n;i++){
		result1[i] = new int[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> result1[i][j];
		}
	}
	int ** result = zeroMatrix(matrix, n,m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			assert(result1[i][j] == result[i][j]); 
		}
	}
	
}
