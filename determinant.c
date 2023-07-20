#include <stdio.h>
#include <math.h>


int main(int argc, char const *argv[]) {
	int N;
	double z;

	//Get matrix dimensions
	scanf("%d", &N);
	double matrix[N][N];

	//Get entries for matrix
	for(int r = 0; r < N; r++) {
		for(int c = 0; c < N; c++) {
			scanf("%lf", &matrix[r][c]);
		}
	}

    /* 
     * Convert to upper triangular matrix
     * Using Gaussian Elimination w/Partial Pivoting
     */
    int swap = 0;
    for(int r = 0; r < N-1; r++){
        for(int c = r+1; c < N; c++){

            // If absolute |diagonal #| is < any value below it
            if(fabs(matrix[r][r]) < fabs(matrix[c][r])){
                for(int s = 0; s < N; s++){ //Switch rows (pivot)               
                    double temp;
                    temp = matrix[r][s];
                    matrix[r][s] = matrix[c][s];
                    matrix[c][s] = temp;
                    if(s == N-1) { swap++;} //Increment swap for each row swap
                }
            }
            // Gaussian Elimination here
            if(c > r) {
                double z = matrix[c][r] / matrix[r][r];
            }
            for(int s = 0; s < N+1; s++){
                matrix[c][s] = matrix[c][s] - z*matrix[r][s];
            }
        }
    }

    //Find determinant: multiply diagonal elements
    double det = 1;
    for(int h = 0; h < N; h++) {
        det = det * matrix[h][h];
    }
    //If # of row swaps is odd, then determinant is negative
    if(swap % 2 != 0) { det = -det; }
    printf("%f", det);

	return 0;
}