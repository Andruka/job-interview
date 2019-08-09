#include <iostream>

using namespace std;

#ifndef GEOMETRICAL_FIGURE_H
#define GEOMETRICAL_FIGURE_H
#define PI 3.1415926535
#define PI_4 0.78539816339

class Point {
public:
	double x, y, z;
	Point();
	Point(double xx, double yy, double zz);
};

class Geometrical_Figure {
protected:
	virtual shared_ptr<Point> get_point(double t) = 0;
	virtual shared_ptr<Point> get_derivative(double t) = 0;
public:
    Geometrical_Figure();
    virtual int get_radius() = 0;
	virtual void print(double t) = 0;
};

class Circle: public Geometrical_Figure {
private:
    int radius;
	virtual shared_ptr<Point> get_point(double t) override;
	virtual shared_ptr<Point> get_derivative(double t) override;
public:
    Circle();
    Circle(int rad);
    virtual int get_radius() override;
	virtual void print(double t) override;
};

class Ellipse: public Geometrical_Figure {
private:
    int radius_x;
    int radius_y;
	virtual shared_ptr<Point> get_point(double t) override;
	virtual shared_ptr<Point> get_derivative(double t) override;
public:
    Ellipse();
    Ellipse(int rad_x,int rad_y);
    virtual int get_radius() override;
	virtual void print(double t) override;
};

class Spiral: public Geometrical_Figure {
private:
    int radius;
    int step;
	virtual shared_ptr<Point> get_point(double t) override;
	virtual shared_ptr<Point> get_derivative(double t) override;
public:
    Spiral();
    Spiral(int rad,int step);
    virtual int get_radius() override;
	virtual void print(double t) override;
};



bool comp(shared_ptr<Geometrical_Figure> &a,shared_ptr<Geometrical_Figure> &b);

#endif // GEOMETRICAL_FIGURE_H
