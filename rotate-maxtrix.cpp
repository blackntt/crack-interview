#include <iostream>
#include <assert.h>
using namespace std;
int** rotateMatrix(int** matrix, int N, int M){
	int** rotatedMatrix;
	rotatedMatrix = new int*[M];
	for(int i=0;i<M;i++){
		rotatedMatrix[i] = new int[N];
	}
	for(int i=0;i< N;i++){
		for(int j=0;j<M;j++){
			rotatedMatrix[j][N-i-1]=matrix[i][j];
		}
	}
	return rotatedMatrix;
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

	int **result1= new int*[m];
	for(int i=0;i<m;i++){
		result1[i] = new int[n];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> result1[i][j];
		}
	}
	int ** result = rotateMatrix(matrix, n,m);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			assert(result1[i][j] == result[i][j]); 
		}
	}
	return 0;
}
