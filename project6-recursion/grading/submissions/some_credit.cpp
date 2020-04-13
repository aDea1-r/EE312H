#include <stdio.h>
#include <stdint.h>
#include "MazeParams.h"
#include "Recursion.h"

int minIt(int x[], int n) {
	return 0;
}

int minRec1(int x[], int n) {
    static bool first = true;
    if(first) {
        first = false;
        return 1;
    }
	return -1;
}

int minRec2(int x[], int n) {
	return 0;
}

double sqrtIt(double x, double low_guess, double high_guess) {
	return 0;
}

double sqrtRec(double x, double low_guess, double high_guess) {
	return 0;
}

int strCompare(char* str1, char* str2) {
	return 0;
}
int strCompare2(char* str1, char* str2) {
	return 0;
}
int solveMazeRec(int row, int col) {
	return 0;
}
void solveMazeIt(int row, int col) {
	int dir = 2;
	maze[row][col] = 2;
}
Martian change(int cents) {
	return Martian{};
}
Martian change(int cents, int nick_val, int dodek_val) {
	return Martian{};
}
Martian changeIt(int cents) {
	return Martian{};
}
Martian changeIt(int cents, int nick_value, int dodek_value) {
	return Martian{};
}
