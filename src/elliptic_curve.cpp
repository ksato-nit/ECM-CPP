#include "elliptic_curve.hpp"

EllipticCurve::EllipticCurve(){
}

EllipticCurve::EllipticCurve(Integer N, Integer b, Integer c){
    this->N = N;
    this->b = b;
    this->c = c;
    this->discriminant = (4 * b * b * b) + (27 * c * c);
}

Integer EllipticCurve::getCharacteristic(){
    return this->N;
}

Integer EllipticCurve::getParameterB(){
    return this->b;
}

Integer EllipticCurve::getParameterC(){
    return this->c;
}

Integer EllipticCurve::getDiscriminant(){
    return this->discriminant;
}
