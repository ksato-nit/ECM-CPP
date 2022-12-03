#pragma once
#include "common.hpp"
#include "elliptic_curve.hpp"

class Complex {
private:
public:
    EllipticCurve curve; // 属する楕円曲線
    Integer re, im;
    Integer tau;
    Complex(Integer re, Integer im, EllipticCurve curve);
    Complex operator + (Complex obj);
    Complex operator - (Complex obj);
    Complex operator * (Complex obj);
    Complex operator * (Integer i);
    Complex operator / (Complex obj);
    Complex minus();
};
