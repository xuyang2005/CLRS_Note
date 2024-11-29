void Matrix_Sum(int n, int** MatrixA, int** MatrixB, int** MatrixSum) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			MatrixSum[i][j] = MatrixA[i][j] + MatrixB[i][j];
}
void Matrix_Sub(int n, int** MatrixA, int** MatrixB, int** MatrixSub) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			MatrixSub[i][j] = MatrixA[i][j] - MatrixB[i][j];
}
void Matrix_Mul(int n, int** MatrixA, int** MatrixB, int** MatrixMul) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			MatrixMul[i][j] = 0;
			for (int k = 0; k < n; k++)
				MatrixMul[i][j] = MatrixMul[i][j] + MatrixA[i][k] * MatrixB[k][j];
		}
}
void Strassen(int N, int** MatrixA, int** MatrixB, int** MatrixC ) {
	int n = N / 2; //分治思想
	//初始化每个小矩阵的大小
	//数组的第二维一定要显示指定
	int** MatrixA11 = new int* [n];
	int** MatrixA12 = new int* [n];
	int** MatrixA21 = new int* [n];
	int** MatrixA22 = new int* [n];
	int** MatrixB11 = new int* [n];
	int** MatrixB12 = new int* [n];
	int** MatrixB21 = new int* [n];
	int** MatrixB22 = new int* [n];
	int** MatrixC11 = new int* [n];
	int** MatrixC12 = new int* [n];
	int** MatrixC21 = new int* [n];
	int** MatrixC22 = new int* [n];

	for (int i = 0; i < n ; i++) {  //分配连续内存
		MatrixA11[i] = new int[n];
		MatrixA12[i] = new int[n];
		MatrixA21[i] = new int[n];
		MatrixA22[i] = new int[n];
		MatrixB11[i] = new int[n];
		MatrixB12[i] = new int[n];
		MatrixB21[i] = new int[n];
		MatrixB22[i] = new int[n];
		MatrixC11[i] = new int[n];
		MatrixC12[i] = new int[n];
		MatrixC21[i] = new int[n];
		MatrixC22[i] = new int[n];
	}
	//为每个小矩阵赋值，将大矩阵分割为4个小矩阵
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			MatrixA11[i][j] = MatrixA[i][j];
			MatrixA12[i][j] = MatrixA[i][j + n];
			MatrixA21[i][j] = MatrixA[i + n][j];
			MatrixA22[i][j] = MatrixA[i + n][j + n];

			MatrixB11[i][j] = MatrixB[i][j];
			MatrixB12[i][j] = MatrixB[i][j + n];
			MatrixB21[i][j] = MatrixB[i + n][j];
			MatrixB22[i][j] = MatrixB[i + n][j + n];
		}		

	//存放加减法结果
	int** S1 = new int* [n];
	int** S2 = new int* [n];
	int** S3 = new int* [n];
	int** S4 = new int* [n];
	int** S5 = new int* [n];
	int** S6 = new int* [n];
	int** S7 = new int* [n];
	int** S8 = new int* [n];
	int** S9 = new int* [n];
	int** S10 = new int* [n];

	for (int i = 0; i < n; i++) {  //分配连续内存
		S1[i] = new int[n];
		S2[i] = new int[n];
		S3[i] = new int[n];
		S4[i] = new int[n];
		S5[i] = new int[n];
		S6[i] = new int[n];
		S7[i] = new int[n];
		S8[i] = new int[n];
		S9[i] = new int[n];
		S10[i] = new int[n];
	}
	//计算
	Matrix_Sub(n, MatrixA12, MatrixA22, S1);
	Matrix_Sum(n, MatrixB21, MatrixB22, S2);
	Matrix_Sum(n, MatrixA11, MatrixA22, S3);
	Matrix_Sum(n, MatrixB11, MatrixB22, S4);
	Matrix_Sub(n, MatrixA11, MatrixA21, S5);
	Matrix_Sum(n, MatrixB11, MatrixB12, S6);
	Matrix_Sum(n, MatrixA11, MatrixA12, S7);
	Matrix_Sub(n, MatrixB12, MatrixB22, S8);
	Matrix_Sub(n, MatrixB21, MatrixB11, S9);
	Matrix_Sum(n, MatrixA21, MatrixA22, S10);

	//存放乘法结果
	int** M1 = new int* [n];
	int** M2 = new int* [n];
	int** M3 = new int* [n];
	int** M4 = new int* [n];
	int** M5 = new int* [n];
	int** M6 = new int* [n];
	int** M7 = new int* [n];

	for (int i = 0; i < n; i++) {  //分配连续内存
		M1[i] = new int[n];
		M2[i] = new int[n];
		M3[i] = new int[n];
		M4[i] = new int[n];
		M5[i] = new int[n];
		M6[i] = new int[n];
		M7[i] = new int[n];
	}
	Matrix_Mul(n, S1, S2, M1);
	Matrix_Mul(n, S3, S4, M2);
	Matrix_Mul(n, S5, S6, M3);
	Matrix_Mul(n, S7, MatrixB22, M4);
	Matrix_Mul(n, MatrixA11, S8, M5);
	Matrix_Mul(n, MatrixA22, S9, M6);
	Matrix_Mul(n, S10, MatrixB11, M7);

	//finally
	//计算C
	Matrix_Sum(n, M1, M2, MatrixC11);
	Matrix_Sub(n, MatrixC11, M4, MatrixC11);
	Matrix_Sum(n, MatrixC11, M6, MatrixC11);

	Matrix_Sum(n, M4, M5, MatrixC12);
	Matrix_Sum(n, M6, M7, MatrixC21);

	Matrix_Sub(n, M2, M3, MatrixC22);
	Matrix_Sum(n, MatrixC22, M5, MatrixC22);
	Matrix_Sub(n, MatrixC22, M7, MatrixC22);

	//将C合并
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			MatrixC[i][j] = MatrixC11[i][j];
			MatrixC[i][j + n] = MatrixC12[i][j];
			MatrixC[i + n][j] = MatrixC21[i][j];
			MatrixC[i + n][j + n] = MatrixC22[i][j];
		}
}