#include "Geometrical_Figure.h"
#include <cmath>
#include <iostream>
using namespace std;

Point::Point() {
	x = y = z = 0;
}
Point::Point(double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
}
Geometrical_Figure::Geometrical_Figure() {
}
Circle::Circle() {
    radius = 0;
}
Circle::Circle(int rad) {
    radius = rad;
}
int Circle::get_radius() {
    return radius;
}
shared_ptr<Point> Circle::get_point(double t) {
	return make_shared<Point>(radius * cos(t), radius * sin(t), 0);
}
shared_ptr<Point> Circle::get_derivative(double t) {
	return make_shared<Point>(-radius * sin(t), radius * cos(t), 0);
}
void Circle::print(double t) {
	shared_ptr<Point> point = get_point(t);
	shared_ptr<Point> derivative = get_derivative(t);
	cout << "           " << "Point(" << point->x << "," << point->y << "," << point->z << ")" << endl;
	cout << "           " << "Derivative(" << derivative->x << "," << derivative->y << "," << derivative->z << ")" << endl;
}
Ellipse::Ellipse() {
    radius_x = 0;
    radius_y = 0;
}
Ellipse::Ellipse(int rad_x,int rad_y) {
    radius_x = rad_x;
    radius_y = rad_y;
}
int Ellipse::get_radius() {
	return 0;
}
shared_ptr<Point> Ellipse::get_point(double t) {
	return make_shared<Point>(radius_x * cos(t), radius_y * sin(t), 0);
}
shared_ptr<Point> Ellipse::get_derivative(double t) {
	return make_shared<Point>(-radius_x * sin(t), radius_y * cos(t), 0);
}
void Ellipse::print(double t) {
	shared_ptr<Point> point = get_point(t);
	shared_ptr<Point> derivative = get_derivative(t);
	cout << "           " << "Point(" << point->x << "," << point->y << "," << point->z << ")" << endl;
	cout << "           " << "Derivative(" << derivative->x << "," << derivative->y << "," << derivative->z << ")" << endl;
}
Spiral::Spiral() {
    radius = 0;
    step = 0;
}
Spiral::Spiral(int rad,int st) {
    radius = rad;
    step = st;
}
int Spiral::get_radius() {
	return 0;
}
shared_ptr<Point> Spiral::get_point(double t) {
	return make_shared<Point>(radius * cos(t), radius * sin(t), step * 2 * PI * t);
}
shared_ptr<Point> Spiral::get_derivative(double t) {
	return make_shared<Point>(-radius * sin(t), radius * cos(t), step * 2 * PI);
}
void Spiral::print(double t) {
	shared_ptr<Point> point = get_point(t);
	shared_ptr<Point> derivative = get_derivative(t);
	cout << "           " << "Point(" << point->x << "," << point->y << "," << point->z << ")" << endl;
	cout << "           " << "Derivative(" << derivative->x << "," << derivative->y << "," << derivative->z << ")" << endl;
}
bool comp(shared_ptr<Geometrical_Figure> &a, shared_ptr<Geometrical_Figure> &b) {
    return (a->get_radius() < b->get_radius());
}
