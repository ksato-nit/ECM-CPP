#pragma once
#include "common.hpp"
#include "elliptic_curve.hpp"
#include "point.hpp"

class Util{
public:
    static Integer gcd(Integer, Integer);
    static Integer lcm(Integer, Integer);
    static Integer klcm(Integer);
    static Integer modInv(Integer, Integer);
    static Integer getOrder(EllipticCurve, Point);
    static Integer pow(Integer, Integer, Integer);
    static std::queue<Integer> getPrimes(Integer, int);
private:
    Util();
};
