/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>


int *spiral_wrapper(int rows, int columns, int** input_array, int * resArray, int *index, int *stx, int *sty, int *enx, int *eny){

	int w, x, y, z;
	w = *stx;
	x = *sty;
	y = *enx;
	z = *eny;

	int i;
	int ind = *index;

	if (ind >= rows*columns-1)
		return resArray;

	for (i = x; i <= z; i++){

		resArray[ind++] = input_array[w][i];
		}
	w++;

	for (i = w; i <= y; i++){
		resArray[ind++] = input_array[i][z];
		}
	z--;
	if (w < y){
		for (i = z; i >= x; i--){
			resArray[ind++] = input_array[y][i];
			}
		y--;
		}

	if (x < z){
		for (i = y; i >= w; i--){
			resArray[ind++] = input_array[i][x];
			}
		x++;
		}

	*stx = w;
	*sty = x;
	*enx = y;
	*eny = z;
	*index = ind;

	if (ind == rows*columns - 1){
		if (w == y && x == z)
			resArray[ind] = input_array[w][z];
		return resArray;

		}

	return spiral_wrapper(rows, columns, input_array, resArray, index, stx, sty, enx, eny);

	}

int *spiral(int rows, int columns, int **input_array)
	{

	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;

	int *resArray = (int*)calloc(rows*columns, sizeof(int));

	int stx, sty, enx, eny;

	stx = 0;
	sty = 0;
	enx = rows - 1;
	eny = columns - 1;
	int index = 0;

	resArray = spiral_wrapper(rows, columns, input_array, resArray, &index, &stx, &sty, &enx, &eny);

	return resArray;
	}
