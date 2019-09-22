#pragma once
#include <iostream>

class Matrix {
private:
	int x, y;
	float **matrix;

public:
	Matrix(int x = 1, int y = 1) {
		this->x = x;
		this->y = y;
		if (x > 0 && y > 0) {
			matrix = new float*[x];
			for (int i = 0; i < y; i++) {
				matrix[i] = new float[y];
			}
		}
	}

	float get(int x, int y) {
		return matrix[x][y];
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void set(int x, int y, float value) {
		matrix[x][y] = value;
	}

	void Randomize() {
		int sign;

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				sign = rand() % 2;
				matrix[i][j] = (float)(rand() % 100);
				if (sign == 0) {
					matrix[i][j] *= -1;
				}
			}
		}
	}
};