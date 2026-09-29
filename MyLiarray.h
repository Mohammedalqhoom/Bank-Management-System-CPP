#pragma once
#include<iostream>
#include"MyLibMath.h";
#include<iomanip>
#include<string>
using namespace std;

namespace MyLiarray {

	void appendArrayFromRandomNumber(int arry[3][3], int row, int col) {
		for (int i = 0;i < row;i++) {

			for (int j = 0;j < col;j++) {
				arry[i][j] = MathNumber::RandomNumber(1, 50);

			}
		}


	}

	void printMatrix(int arry[100], int len) {

		for (int j = 0;j < len;j++) {
			//printf("  %0*d" ,2, arry[i][j]);
			cout << setw(3) << arry[j] << " ";


		}
	}

	void printArray(int arry[3][3], int row, int col) {
		for (int i = 0;i < row;i++) {

			for (int j = 0;j < col;j++) {
				//printf("  %0*d" ,2, arry[i][j]);
				cout << setw(3) << arry[i][j] << " ";

			}
			cout << endl;
		}
	}


	void TranposMatrix(int arry[3][3], int arryTranspos[3][3], short row, short col) {
		for (int i = 0;i < col;i++) {

			for (int j = 0;j < row;j++) {
				arryTranspos[i][j] = arry[j][i];

			}
			cout << endl;
		}
	}
	int SumRow(int arry[3][3], int rowNumber, int cols) {

		int sum = 0;
		for (short i = 0;i < cols;i++) {
			sum += arry[rowNumber][i];
		}

		return sum;
	}

	int SumColums(int arry[3][3], int rows, int colNumber) {

		int sum = 0;
		for (short j = 0;j < rows;j++) {
			sum += arry[j][colNumber];
		}

		return sum;
	}


	void printEachRowsum(int arry[3][3], int row, int col) {
		cout << "\nThe the following are the sum of each row in the matrix:\n";
		for (int i = 0;i < row;i++) {

			cout << "Row " << i + 1 << " Sum =" << SumRow(arry, i, col) << endl;

		}



	}

	void SumMatrixRawInarray(int arry[3][3], int arry1[3], int row, int col) {

		for (int i = 0;i < row;i++) {

			arry1[i] = SumRow(arry, i, col);

		}
	}

	void SumMatrixColumInarray(int arry[3][3], int arry1[3], int row, int col) {

		for (short j = 0;j < col;j++) {

			arry1[j] = SumColums(arry, row, j);

		}
	}

	void FillMatrixWithOrderedNumbers(int arr[3][3], int row, int col) {
		short count = 0;
		for (short i = 0;i < row;i++) {

			for (short j = 0;j < col;j++) {
				count++;
				arr[i][j] = count;

			}
			cout << endl;
		}

	}

	void PrintSumArray(int arry[3], int row) {
		cout << "\nThe the following are the sum of each row in the matrix:\n";
		for (int i = 0;i < row;i++) {
			cout << "Colum " << i + 1 << " Sum =" << arry[i] << endl;


		}



	}

	int MulToNumber(int num1, int num2) {

		return num1 * num2;
	}

	void MultiResultmatrix(int arry1[3][3], int arry2[3][3], int resultarry[3][3], int row, int col) {

		for (short i = 0;i < row;i++) {

			for (short j = 0;j < col;j++) {
				resultarry[i][j] = MulToNumber(arry1[i][j], arry2[i][j]);
			}

			cout << endl;
		}

	}


	void printMedalRow(int arry[3][3], short row, short col) {
		cout << "\n The Medel Row Matrex:\n";
		short MedalRow = row / 2;
		for (int j = 0;j < col;j++) {


			printf(" %0*d", 2, arry[MedalRow][j]);


		}
	}

	void printMedalCol(int arry[3][3], int row, int col) {
		cout << "\n The Medel Col Matrex:\n";
		short MedalCol = col / 2;
		for (short i = 0;i < row;i++) {


			printf(" %0*d", 2, arry[i][MedalCol]);


		}
	}

	int SumMatrix(int arry1[3][3], short row, short col) {
		int sum = 0;
		for (short i = 0;i < row;i++) {

			for (short j = 0;j < col;j++) {
				sum += arry1[i][j];
			}

		}
		return sum;

	}

	bool AreEqualMatrices(int arry1[3][3], int arry2[3][3], int row, int col) {

		return (SumMatrix(arry1, row, col) == SumMatrix(arry2, row, col));

	}


	bool AreTipecalMatrices(int arry[3][3], int arr2[3][3], short row, short col) {
		for (int i = 0;i < row;i++) {

			for (int j = 0;j < col;j++) {
				if (arry[i][j] != arr2[i][j])return false;

			}

		}

		return true;
	}
	bool IsIdentityMatrix(int arry[3][3], short row, short col) {
		for (int i = 0;i < row;i++) {

			for (int j = 0;j < col;j++) {
				if (j == i && arry[i][j] != 1) {

					return false;

				}
				else if (i != j && arry[i][j] != 0) {

					return false;
				}

			}

		}

		return true;
	}

	bool IsScalarMatrix(int arry[3][3], short row, short col) {
		short scalar = arry[0][0];
		for (int i = 0;i < row;i++) {

			for (int j = 0;j < col;j++) {
				if (j == i && arry[i][j] != scalar) {

					return false;

				}
				else if (i != j && arry[i][j] != 0) {

					return false;
				}

			}

		}

		return true;
	}

	short CountNumberInMatrix(int arry[3][3], short number, short row, short col) {
		short countNumber = 0;
		for (short i = 0;i < row;i++) {

			for (short j = 0;j < col;j++) {
				if (arry[i][j] == number)countNumber++;
			}

		}
		return countNumber;

	}


	bool IsSparesMatrix(int arry[3][3], short row, short col) {

		short Sizematrix = row * col;
		return (CountNumberInMatrix(arry, 0, row, col) >= Sizematrix / 2);
	}



	bool IsNumberInMatrix(int arry[3][3], int number, short row, short col) {

		for (short i = 0;i < row;i++) {

			for (short j = 0;j < col;j++) {
				if (arry[i][j] == number)return true;
			}


			return false;
		}


	}

	void PrintInsectedNumbers(int arry1[3][3], int arry2[3][3], short row, short col) {
		int Number;
		for (short i = 0;i < row;i++) {

			for (short j = 0;j < col;j++) {

				Number = arry1[i][j];
				if (IsNumberInMatrix(arry2, Number, row, col)) {
					cout << setw(2) << Number << " ";

				}
			}



		}


	}



	int MinNumberInMatrix(int arry1[3][3], short row, short col) {
		short min = arry1[0][0];
		for (short i = 0;i < row;i++) {

			for (short j = 0;j < col;j++) {
				if (arry1[i][j] < min) {
					min = arry1[i][j];
				}

			}



		}
		return min;

	}



	int MaxNumberInMatrix(int arry1[3][3], short row, short col) {
		short max = arry1[0][0];
		for (short i = 0;i < row;i++) {

			for (short j = 0;j < col;j++) {
				if (arry1[i][j] > max) {
					max = arry1[i][j];
				}
			}



		}
		return max;

	}




	bool IsPalindRomMatrix(int arry1[3][3], short row, short col) {

		for (short i = 0;i < row;i++) {

			for (short j = 0;j < col / 2;j++) {
				if (arry1[i][j] != arry1[i][col - 1 - j]) {
					return false;
				}
			}



		}
		return true;

	}


	void	PrintFibonacciUsingLoops(short num) {

		int FibonacNum = 0;
		short prev1 = 1, prev2 = 0;
		cout << "1 ";
		for (short i = 1;i < num; i++) {

			FibonacNum = prev1 + prev2;
			cout << FibonacNum << " ";
			prev2 = prev1;
			prev1 = FibonacNum;



		}


	}


	void	PrintFibonacciUsingRecrgin(int num, int prev1, int prev2) {


		int Fibonacc = prev1 + prev2;
		cout << Fibonacc << " ";
		if (num > 1) {

			PrintFibonacciUsingRecrgin(num - 1, Fibonacc, prev1);
		}
	}





}
