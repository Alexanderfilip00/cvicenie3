#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

class Point {
private:
	double x, y, z;
public:
	Point();
	Point(double u, double v, double w) : x(u), y(v), z(w) {};
	void Set(double u, double v, double w);
	void Print();
	double X() { return x; };
	double Y() { return y; };
	double Z() { return z; };
};

Point::Point()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

void Point::Set(double u, double v, double w)
{
	x = u;
	y = v;
	z = w;
}

void Point::Print()
{
	std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
}



class Triangle {
private:
	Point Body[3];
	double area;
	double peri;
	double Lengths[3];
	double N[3];
	double Ang[3];
	double Centr[3];

	void CalcLengths();			//procedury na vypocet udajov
	void CalcNormal();
	void CalcAngles();
	void CalcCentroid();
	void CalcPerim();
	void CalcArea();

	void CalcAll();		//vypocita vsetky udaje

public:
	Triangle();
	Triangle(Point Pole[]);
	Triangle(Point A, Point B, Point C);
	void SetTri(Point Pole[]);
	void SetTri(Point A, Point B, Point C);
	void PrintPoints();

	void PrintLengths();		//procedury na vypis udajov
	void PrintNormal();
	void PrintAngles();
	void PrintCentroid();
	void PrintPerim();
	void PrintArea();
	void PrintAll();

	double* GetLengths() { return Lengths; };		//funkcie na vratenie udajov
	double* GetNormal() { return N; };
	double* GetAngles() { return Ang; };
	double* GetCentroid() { return Centr; };
	double GetPerim() { return peri; };
	double GetArea() { return area; };

};

Triangle::Triangle()
{
	Body[0] = Point(0, 0, 0);
	Body[1] = Point(0, 0, 0);
	Body[2] = Point(0, 0, 0);
	CalcAll();
}

Triangle::Triangle(Point Pole[])
{
	Body[0] = Pole[0];
	Body[1] = Pole[1];
	Body[2] = Pole[2];
	CalcAll();
}

Triangle::Triangle(Point A, Point B, Point C)
{
	Body[0] = A;
	Body[1] = B;
	Body[2] = C;
	CalcAll();
}

void Triangle::SetTri(Point Pole[])
{
	Body[0] = Pole[0];
	Body[1] = Pole[1];
	Body[2] = Pole[2];
	CalcAll();
}

void Triangle::SetTri(Point A, Point B, Point C)
{
	Body[0] = A;
	Body[1] = B;
	Body[2] = C;
	CalcAll();
}

void Triangle::CalcAll()
{
	CalcLengths();	
	CalcNormal();
	CalcAngles();
	CalcCentroid();
	CalcPerim();
	CalcArea();
}

void Triangle::CalcLengths()
{
	Lengths[0] = sqrt(pow((Body[0].X() - Body[1].X()), 2) + pow((Body[0].Y() - Body[1].Y()), 2) + pow((Body[0].Z() - Body[1].Z()), 2));
	Lengths[1] = sqrt(pow((Body[0].X() - Body[2].X()), 2) + pow((Body[0].Y() - Body[2].Y()), 2) + pow((Body[0].Z() - Body[2].Z()), 2));
	Lengths[2] = sqrt(pow((Body[2].X() - Body[1].X()), 2) + pow((Body[2].Y() - Body[1].Y()), 2) + pow((Body[2].Z() - Body[1].Z()), 2));
}

void Triangle::PrintPoints()
{
	std::cout << "Trojuholnik: \n";
	Body[0].Print();
	Body[1].Print();
	Body[2].Print();
	std::cout << std::endl;
}

void Triangle::CalcPerim()
{
	peri = Lengths[0] + Lengths[1] + Lengths[2];
}

void Triangle::CalcArea()
{
	double s = (Lengths[0] + Lengths[1] + Lengths[2] ) / 2;
	area = sqrt(s * (s - Lengths[0]) * (s - Lengths[1]) * (s - Lengths[2]));
}

void Triangle::CalcNormal()
{
	double U[3];
	double V[3];
	U[0] = Body[1].X() - Body[0].X();	//vektor u, suradnica x
	U[1] = Body[1].Y() - Body[0].Y();	//vektor u, suradnica y
	U[2] = Body[1].Z() - Body[0].Z();	//vektor u, suradnica z

	V[0] = Body[2].X() - Body[0].X();	//vektor v, suradnica x
	V[1] = Body[2].Y() - Body[0].Y();	//vektor v, suradnica y
	V[2] = Body[2].Z() - Body[0].Z();	//vektor v, suradnica z

	N[0] = (U[1] * V[2]) - (U[2] * V[1]);	//vektor n, suradnica x
	N[1] = (U[2] * V[0]) - (U[0] * V[2]);	//vektor n, suradnica y
	N[2] = (U[0] * V[1]) - (U[1] * V[0]);	//vektor n, suradnica z
}

void Triangle::PrintLengths()
{
	std::cout << "Dlzky stran trojuholnika: \na = " << Lengths[0] << ", b = " << Lengths[1] << ", c = " << Lengths[2] << std::endl << std::endl;
}

void Triangle::PrintNormal()
{
	std::cout << "Normala na plochu trojuholnika: \nx = " << N[0] << ", y = " << N[1] << ", z = " << N[2] << std::endl << std::endl;
}

void Triangle::CalcAngles()
{
	Ang[0] = (acos(((Lengths[1] * Lengths[1]) + (Lengths[2] * Lengths[2]) - (Lengths[0] * Lengths[0])) / (2 * Lengths[1] * Lengths[2])) ) * 180 / M_PI;
	Ang[1] = (acos(((Lengths[0] * Lengths[0]) + (Lengths[2] * Lengths[2]) - (Lengths[1] * Lengths[1])) / (2 * Lengths[0] * Lengths[2])) ) * 180 / M_PI;
	Ang[2] = (acos(((Lengths[0] * Lengths[0]) + (Lengths[1] * Lengths[1]) - (Lengths[2] * Lengths[2])) / (2 * Lengths[0] * Lengths[1])) ) * 180 / M_PI;
}

void Triangle::PrintAngles()
{
	std::cout << "Vnutorne uhly trojuholnika su: \n" << Ang[0] << "  " << Ang[1] << "  " << Ang[2] << std::endl << std::endl;
}

void Triangle::CalcCentroid()
{
	Centr[0] = (Body[0].X() + Body[1].X() + Body[2].X()) / 3;
	Centr[1] = (Body[0].Y() + Body[1].Y() + Body[2].Y()) / 3;
	Centr[2] = (Body[0].Z() + Body[1].Z() + Body[2].Z()) / 3;
}

void Triangle::PrintCentroid()
{
	std::cout << "Suradnice taziska trojuholnika: \nx = " << Centr[0] << ", y = " << Centr[1] << ", z = " << Centr[2] << std::endl << std::endl;
}

void Triangle::PrintPerim()
{
	std::cout << "Obvod trojuholnika: \no = " << peri << std::endl << std::endl;
}

void Triangle::PrintArea()
{
	std::cout << "Plocha trojuholnika: \nS = " << area << std::endl << std::endl;
}

void Triangle::PrintAll()
{
	PrintPoints();
	PrintLengths();
	PrintNormal();
	PrintAngles();
	PrintCentroid();
	PrintPerim();
	PrintArea();
}


int main() {
	
	Point A(2.123, 3.431, 5.341);
	Point B(4.123, 1.43, 6.421);
	Point C(3.541, 12.435, 7.341);
	Point Body1[3] = {A,B,C};

	Triangle Atroj(Body1);
	Atroj.PrintAll();


	Point D(1, 2, 3);
	Point E(3, 4, 5);
	Point F(6, 5, 4);

	Atroj.SetTri(D, E, F);
	Atroj.PrintAll();


	return 0;
}