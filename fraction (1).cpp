#include "fraction.h"
#include <iostream>
#include <numeric>
using namespace std;

Fraction& Fraction::shorten() {
	int g = gcd(ch, zn);
	ch /= g;
	zn /= g;
};

Fraction::Fraction() {
	this -> ch = 1;
	this -> zn = 1;
}
Fraction::Fraction(int cel, int ch, int zn) {
	this->ch += ch + cel*zn;
	this->zn = zn;
	shorten();
}
int Fraction::get_cel() { return ch / zn;  };
int Fraction::get_ch() { return ch; };
int Fraction::get_zn() { return zn; };
Fraction& Fraction::set_cel(int i) { 
	this->ch = zn * i + (ch % zn);
	shorten();
	return *this; 
};
Fraction& Fraction::set_chisl(int i) {
	this->ch = i;
	shorten();
	return *this;
};
Fraction& Fraction::set_zn(int i) {
	this->zn = i;
	shorten();
	return *this;
};
Fraction Fraction::sum(const Fraction& F) const {
	Fraction result;
	result.ch = ch * F.zn + F.ch * zn;
	result.zn = zn * F.zn;
	return result.shorten();
}; // �����
Fraction Fraction::dif(const Fraction& F) const {
	Fraction result;
	result.ch = ch * F.zn - F.ch * zn;
	result.zn = zn * F.zn;
	return result.shorten();
}; // ��������
Fraction Fraction::mul(const Fraction& F) const {
	Fraction result;
	result.ch = ch * F.ch;
	result.zn = zn * F.zn;
	return result.shorten();
}; // ���������
Fraction Fraction::div(const Fraction& F) const {
	Fraction result;
	result.ch = ch * F.zn;
	result.zn = zn * F.ch;
	return result.shorten();
}; // �������
Fraction Fraction::operator-() {
	Fraction result;
	result.ch = -ch;
	result.zn = zn;
	return result.shorten();
};



Fraction Fraction::operator+(const Fraction& F) const {
	Fraction result;
	result.ch = ch * F.zn + F.ch * zn;
	result.zn = zn * F.zn;
	return result.shorten();
};
Fraction Fraction::operator-(const Fraction& F) const {
	Fraction result;
	result.ch = ch * F.zn - F.ch * zn;
	result.zn = zn * F.zn;
	return result.shorten();
};
Fraction Fraction::operator*(const Fraction& F) const {
	Fraction result;
	result.ch = ch * F.ch;
	result.zn = zn * F.zn;
	return result.shorten();
};
Fraction Fraction::operator/(const Fraction& F) const {
	Fraction result;
	result.ch = ch * F.zn;
	result.zn = zn * F.ch;
	return result.shorten();
};
Fraction Fraction::operator+(int i) {
	this->ch = zn * ((ch % zn)+i) + (ch % zn);
	shorten();
	return *this;
};
Fraction Fraction::operator-(int i) {
	this->ch = zn * ((ch % zn) - i) + (ch % zn);
	shorten();
	return *this;
};
Fraction Fraction::operator*(int i) {
	this->ch = zn * ((ch % zn) * i) + (ch % zn);
	shorten();
	return *this;
};
Fraction Fraction::operator/(int i) {
	this->ch = zn * ((ch % zn) / i) + (ch % zn);
	shorten();
	return *this;
};
Fraction Fraction::operator%(int i) {
	this->ch = ch%zn;
	return *this;
};
Fraction& Fraction::operator++() {
	ch += zn;
    return shorten();
};
Fraction Fraction::operator++(int i) {
	ch += zn*i;
    return shorten();
};
Fraction& Fraction::operator--() {
	ch -= zn; 
    return shorten();
};
Fraction Fraction::operator--(int i) {
	ch -= zn*i; 
    return shorten();
};
int Fraction::operator>(const Fraction& F) {
	return (ch * f.zn > f.ch * zn);
};
int Fraction::operator<(const Fraction& F) {
	return (ch * f.zn < f.ch * zn);
};
int Fraction::operator>=(const Fraction& F) {
	return (ch * f.zn >= f.ch * zn);
};
int Fraction::operator<=(const Fraction& F) {
	return (ch * f.zn <= f.ch * zn);
};
int Fraction::operator==(const Fraction& F) {
	return (ch * f.zn == f.ch * zn);
};
Fraction::operator double() const {
	return static_cast<double>(ch) / zn;
}; // ���������� ����
int Fraction::operator[](int i) {

};
/*friend Fraction Fraction::operator+(int i, const Fraction& F) {

};
friend Fraction Fraction::operator-(int i, const Fraction& F) {

};
friend Fraction Fraction::operator*(int i, const Fraction& F) {

};
friend Fraction Fraction::operator/(int i, const Fraction& F) {

};
friend istream& Fraction::operator>>(istream&, Fraction& F) {

};
friend ostream& Fraction::operator<<(ostream&, const Fraction& F) {

};*/