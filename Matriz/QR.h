#pragma once

#pragma once 
#include "Matrix.h"
#include <iostream>
#include <vector>

class Mundo {
	std::vector<std::vector<float>> A;
	std::vector<std::vector<float>> r; //matriz R
	std::vector<std::vector<float>> q; // matriz Q
	Matrix *mr, *mq;
public:
	Mundo(Matrix *A1) {
		A = recibirM(A1);
	}
private:
	std::vector<std::vector<float>> recibirM(Matrix *A1) {
		std::vector<std::vector<float>> aux;
		std::vector<float> aux2;
		for (int i = 0; i < A1->getX(); i++) {
			aux.push_back(aux2);
			for (int j = 0; j < A1->getY(); j++) {
				aux[i].push_back(A1->get(i, j));
			}
		}
		return aux;
	}
	Matrix *recibirV(std::vector<std::vector<float>> vec) {
		Matrix *aux = new Matrix(vec.size(), vec.size());
		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec.size(); j++) {
				if (vec[i][j] < 0.0005 && vec[i][j] > -0.0005) vec[i][j] = 0;
				aux->set(i, j, vec[i][j]);
			}
		}
		return aux;
	}
	std::vector<std::vector<float> > inici(int a) {
		std::vector<std::vector<float>> ra(a);
		std::vector<float> wa(a);
		for (float i = 0; i < a; i++) {
			ra.push_back(wa);
		}
		return ra;
	}
	std::vector<float> getcolumna(std::vector<std::vector<float>> vec, float col) {
		std::vector<float> v;
		for (float i = 0; i < vec.size(); i++) {
			v.push_back(vec[i][col]);
		}
		return v;
	}
	float productopunto(std::vector<std::vector<float>> vec, std::vector<std::vector<float>> vec2) {
		float acu = 0;
		for (float i = 0; i < vec.size(); i++) {
			for (float j = 0; j < vec.size(); j++) {
				acu += (vec[i][j] * vec2[i][j]);
			}
		}
		return acu;
	}
	std::vector<float> resta(std::vector<float> vec, std::vector<float> vec2) {
		std::vector<float> v;
		for (float i = 0; i < vec.size(); i++) {
			v.push_back(vec[i] - vec2[i]);
		}
		return v;
	}
	float prodV(std::vector<float> fa, std::vector<float> fu) {
		float ka = 0;
		for (float i = 0; i < fa.size(); i++) {
			ka += (fa[i] * fu[i]);

		}
		return ka;
	}
	std::vector<float> prodE(float a, std::vector<float> vec) {
		std::vector<float> v;
		for (float i = 0; i < vec.size(); i++) {

			v.push_back(a*vec[i]);

		}
		return v;
	}
	std::vector<std::vector<float>>producto(float a, std::vector<std::vector<float>> vec) {
		std::vector<std::vector<float>> v = inici(vec.size());
		for (float i = 0; i < vec.size(); i++) {
			for (float j = 0; j < vec.size(); j++) {
				v[i][j] = vec[i][j] * a;
			}
		}
		return v;
	}
	std::vector<std::vector<float>>division(float a, std::vector<std::vector<float>> vec) {
		std::vector<std::vector<float>> v = inici(vec.size());
		for (float i = 0; i < vec.size(); i++) {
			for (float j = 0; j < vec.size(); j++) {
				v[i][j] = vec[i][j] / a;
			}
		}
		return v;
	}
	std::vector<std::vector<float>> productoMat(std::vector<std::vector<float>> vec, std::vector<std::vector<float>> vec2) {
		std::vector<std::vector<float>> v(vec.size());
		for (float i = 0; i < vec.size(); i++) {
			for (float j = 0; j < vec.size(); j++) {
				float aux = 0;
				for (float fi = 0; fi < vec.size(); fi++) {
					aux += vec[i][fi] * vec2[fi][j];
				}
				v[i].push_back(aux);
			}

		}
		return v;
	}
	std::vector<std::vector<float>> Transponer(std::vector<std::vector<float> > vec) {
		std::vector<std::vector<float>> va(vec.size());
		for (float i = 0; i < vec.size(); i++) {
			for (float j = 0; j < vec.size(); j++) {
				va[i].push_back(vec[j][i]);
			}
		}
		return va;
	}
	void mostrarM(std::vector<std::vector<float>> q) {
		for (auto ar : q) {
			for (auto far : ar) {
				std::cout << far << " ";
			}
			std::cout << std::endl;
		}
	}
	float num(std::vector<float> vec) {
		float a = 0;
		for (auto fu : vec) {
			a += fu * fu;
		}
		return sqrt(a);
	}
	float nom(std::vector<float> vec) {
		float a = 0;
		for (auto fu : vec) {
			a += fu * fu;
		}
		return  sqrt(a);
	}
	void mostrarC(std::vector<float> ra) {
		for (auto f : ra) {
			std::cout << f << " ";
		}
		std::cout << std::endl;
	}

public:
	void operar() {
		std::vector<float> zz = getcolumna(A, 0);
		q.push_back(prodE(1 / nom(zz), zz));

		for (float j = 1; j < A.size(); j++) {
			std::vector<float> ff = getcolumna(A, j);

			for (float i = 0; i < j; i++) {
				float a = prodV(ff, q[i]);
				std::vector<float> faa = prodE(a, q[i]);
				std::cout << std::endl;
				ff = resta(ff, faa);
			}
			q.push_back(prodE(1 / nom(ff), ff));
		}

		r = productoMat(q, A);
		q = Transponer(q);

		/*std::cout << "Matriz A: " << std::endl;
		mostrarM(A);
		std::cout << "QR" << std::endl;
		mostrarM(q);
		std::cout << std::endl;
		mostrarM(r);
		std::cout << std::endl;
		std::vector<std::vector<float>> res = productoMat(q, r);
		mostrarM(res);
		std::cout << std::endl;*/

		mr = recibirV(r);
		mq = recibirV(q);
	}
	Matrix *getR() {
		return mr;
	}
	Matrix *getQ() {
		return mq;
	}
};