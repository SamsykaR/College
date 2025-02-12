#ifndef Methods_H
#define Methods_H
#include <string>
#include <exception>

class ArrayMethods {
	private:
		int* mas;
		int size;
	public:
		ArrayMethods(int);
		void Add(int);
		int at(int);
		void Remove(int);
		int Length();
		int Max();
		int Min();
		double Sr();
		void SortUp();
		void SortDown();
		void print();
		~ArrayMethods();
};

class ArrayException:public std::exception{
private:
	std::string message;
public:
	ArrayException(std::string);
	const char* what() const noexcept;
};

class SizeNotrange:public ArrayException {
public:
	SizeNotrange(std::string, int);
	const char* what() const noexcept;
};


#endif // !Methods_H
