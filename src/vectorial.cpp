/**********
 * VECTOR.CPP
 * AUTHOR: VITOR RODRIGUES
 * DATE: 10/12/2023, 10h25
 * DESC: Vector class implementation
**********/

#include <cmath>
#include "../include/vectorial.hpp"

using namespace Vectorial;

Vector::Vector(double x, double y, double z): x(x), y(y), z(z) {
	magnitude = calculateMag();
}

Vector::~Vector() {
	x = 0;
	y = 0;
	z = 0;
	magnitude = 0;
}

// Inverse operator overloading
Vector Vector::operator-(void) {
	double _x = -x;
	double _y = -y;
	double _z = -z;
	
	return Vector(_x, _y, _z);
}

// Vector operations overloading
Vector Vector::operator+(Vector v) {
	return Vector::add(*this, v);
}

Vector Vector::operator-(Vector v) {
	return Vector::add(*this, -v);
}

Vector Vector::operator*(Vector v) {
	return Vector::crossProduct(*this, v);
}

// Gets and Sets
double Vector::getx() const {
	return x;
}

void Vector::setx(double x) {
	this->x = x;
}

double Vector::gety() const {
	return y;
}

void Vector::sety(double y) {
	this->y = y;
}

double Vector::getz() const {
	return z;
}

void Vector::setz(double z) {
	this->z = z;
}

double Vector::mag() const {
	return magnitude;
}

// Vector operations
Vector Vector::add(Vector a, Vector b) {
	double x = a.getx() + b.getx();
	double y = a.gety() + b.gety();
	double z = a.getz() + b.getz();
	
	return Vector(x, y, z);
}

Vector Vector::numberProduct(Vector a, double s) {
	double x = s * a.getx();
	double y = s * a.gety();
	double z = s * a.getz();
	
	return Vector(x, y, z);
}

double Vector::dotProduct(Vector a, Vector b) {
	double x = a.getx() * b.getx();
	double y = a.gety() * b.gety();
	double z = a.getz() * b.getz();
	
	return x + y + z;
}

Vector Vector::crossProduct(Vector a, Vector b) {
	double x = a.gety() * b.getz() - a.getz() * b.gety();
	double y = a.getz() * b.getx() - a.getx() * b.getz();
	double z = a.getx() * b.gety() - a.gety() * b.getx();
	
	return Vector(x, y, z);
}

// Vector rotations
void Vector::rotatex(double a) {
	a *= PI / 180; // Conversion from degrees to rads
	
	// X-axis rotation matrix
	double _y = y * cos(a) + z * -sin(a);
	double _z = y * sin(a) + z *  cos(a);
	
	y = _y;
	z = _z;
}

void Vector::rotatey(double a) {
	a *= PI / 180;
	
	// Y-axis rotation matrix
	double _x = x *  cos(a) + z * sin(a);
	double _z = x * -sin(a) + z * cos(a);
	
	x = _x;
	z = _z;
}

void Vector::rotatez(double a) {
	a *= PI / 180;
	
	// Z-axis rotation matrix
	double _x = x * cos(a) + y * -sin(a);
	double _y = x * sin(a) + y *  cos(a);
	
	x = _x;
	y = _y;
}

// Vector translation
void Vector::translateOver(Vector v) {
	*this = Vector::add(*this, v);
}

// Vector normalize
void Vector::normalize() {
	x = x / magnitude;
	y = y / magnitude;
	z = z / magnitude;
	
	magnitude = calculateMag();
}

// Other utils
double Vector::angleBetween(Vector a, Vector b) {
	double dp = Vector::dotProduct(a, b);
	double ma = a.mag();
	double mb = b.mag();
	double rad;
	
	if(ma && mb) // Divide by zero is not a good idea
		rad = acos(dp / (ma * mb));
	else
		rad = 0;
	
	return rad * 180 / PI; // Conservion from rads to degrees
}

// Private methods
double Vector::calculateMag() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}