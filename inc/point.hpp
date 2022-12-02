#pragma once
#include "common.hpp"
#include "elliptic_curve.hpp"

class Point {
private:
    Integer x, y; // 座標
    EllipticCurve curve; // 属する楕円曲線
public:
    Point(Integer x, Integer y, EllipticCurve curve);
    Integer getX();
    Integer getY();
    Point operator + (Point obj);
    Point operator * (Integer k);
    Point doubling();
    Point minus();
};
