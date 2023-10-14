/**********
 * VECTOR.HPP
 * AUTHOR: VITOR RODRIGUES
 * DATE: 10/12/2023, 08h31
 * DESC: Vector namespace and class signatures
**********/

#pragma once

namespace Vectorial {
	const double PI = 3.14159;
	
	class Vector {
		
	private:
		double x, y, z;
		double magnitude;
		
	public:
		Vector(double x = 0, double y = 0, double z = 0);
		~Vector();
		
		// Inverse operator overloading
		Vector operator-(void);
		
		// Vector operations overloading
		Vector operator+(Vector v);
		Vector operator-(Vector v);
		Vector operator*(Vector v);
		
		// Gets and Sets
		double getx() const;
		void setx(double x);
		double gety() const;
		void sety(double y);
		double getz() const;
		void setz(double z);
		double mag() const;
		
		// Vector operations
		static Vector add(Vector a, Vector b);
		static Vector numberProduct(Vector a, double s);
		static double dotProduct(Vector a, Vector b);
		static Vector crossProduct(Vector a, Vector b);
		
		// Vector rotations
		void rotatex(double a);
		void rotatey(double a);
		void rotatez(double a);
		
		// Vector translation
		void translateOver(Vector v);
		
		// Vector normalize
		void normalize();
		
	  // Other utils
		static double angleBetween(Vector a, Vector b);
		static void normalize(Vector a);
		
	private:
		double calculateMag();
		
	};
}