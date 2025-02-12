#include "Methods.h"
#include <iostream>
#include <algorithm>


		ArrayMethods::ArrayMethods(int n) { //тут ошибка не числа
			mas = new int[n];
			size = n;
			for (int i = 0; i < size; i++) mas[i] = i;
		};
		void ArrayMethods::Add(int a) { //тут ошибка не числа
			mas[size++] = a;
		}
		int ArrayMethods::at(int i) { //тут ошибка не числа и выхода за границы
			return mas[i];
		}
		void ArrayMethods::Remove(int i) { //тут ошибка не числа и выхода за границы
			for (int j = i; j < size - 1; ++j) {
				mas[j] = mas[j + 1];
			}
			size--;
		}
		int ArrayMethods::Length() {
			return size;
		}
		/////////////////////////////
		int ArrayMethods::Max() { 
			int m=mas[0];
			for (int i = 1; i < size; i++) {
				if (mas[i] > m) m = mas[i];
			}
			return m;
		}
		int ArrayMethods::Min() {
			int m = mas[0];
			for (int i = 1; i < size; i++) {
				if (mas[i] < m) m = mas[i];
			}
			return m;
		}
		double ArrayMethods::Sr() {
			int sum = 0;
			int count = 0;
			for (int i = 0; i < size; i++) {
				sum += mas[i];
				count++;
			}
			if (sum == 0) { throw ArrayException("Сумма элементов равна 0"); sum = 1; }
			if (count == 0) { throw ArrayException("Количество элементов равно 0, заменим на 1"); count = 1; }
			return (double)sum / count;
		}
		void ArrayMethods::SortUp() {
			std::sort(mas, mas + size);
		}
		void ArrayMethods::SortDown() {
			std::sort(mas, mas+size, std::greater<int>());
		}
		/////////////
		void ArrayMethods::print() {
			for (int i = 0; i < size; i++) {
				std::cout << mas[i] << "  ";
			}
			std::cout << std::endl;
		}
		ArrayMethods::~ArrayMethods() {
			delete[]mas;
		}

		