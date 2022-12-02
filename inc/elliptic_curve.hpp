#pragma once
#include "common.hpp"

class EllipticCurve {
private:
    Integer N; // 定義体の位数
    Integer b, c; // Weierstrass 方程式 y^2 = x^3 + bx + c の係数
    Integer discriminant; // 判別式
public:
    EllipticCurve();
    EllipticCurve(Integer, Integer, Integer);
    Integer getCharacteristic();
    Integer getParameterB();
    Integer getParameterC();
    Integer getDiscriminant();
};
