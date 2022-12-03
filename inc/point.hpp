#pragma once
#include "common.hpp"
#include "complex.hpp"
#include "elliptic_curve.hpp"

class Point {
private:
    Complex x, y; // 座標
    EllipticCurve curve; // 属する楕円曲線
public:
    Point(Complex x, Complex y, EllipticCurve curve);
    Complex getX();
    Complex getY();
    Point operator + (Point obj);
    Point operator * (Integer k);
    Point doubling();
    Point minus();
};
