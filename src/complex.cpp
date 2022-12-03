#include "complex.hpp"
#include "util.hpp"

Complex::Complex(Integer re, Integer im, EllipticCurve curve){
    this->re = re;
    this->im = im;
    this->curve = curve;
    this->tau = curve.getTau();
}

Complex Complex::operator + (Complex obj){
    Integer n = this->curve.getCharacteristic();
    Complex c((this->re + obj.re) % n, (this->im + obj.im) % n, this->curve);
    return c;
}

Complex Complex::operator - (Complex obj){
    Integer n = this->curve.getCharacteristic();
    Complex c((this->re - obj.re) % n, (this->im - obj.im) % n, this->curve);
    return c;
}

Complex Complex::operator * (Complex obj){
    Integer n = this->curve.getCharacteristic();
    Integer re = this->re * obj.re + tau * this->im * obj.im;
    Integer im = this->im * obj.re + this->re * obj.im;
    Complex c(re % n, im % n, this->curve);
    return c;
}

Complex Complex::operator * (Integer i){
    Integer n = this->curve.getCharacteristic();
    Complex c((this->re * i) % n, (this->im * i) % n, this->curve);
    return c;
}

Complex Complex::operator / (Complex obj){
    Integer n = this->curve.getCharacteristic();
    Integer m = obj.re * obj.re - this->tau * obj.im * obj.im;
    if(boost::integer::gcd(m, n) != 1){
        std::cout << "Oops." << std::endl;
        std::cout << obj.re << " " << obj.im << std::endl;
        std::cout << boost::integer::gcd(m, n) << std::endl;
        exit(1);
    }
    Integer invm = Util::modInv(m, n);

    Complex conjObj(obj.re, -obj.im, this->curve);
    Complex ch = (*this) * conjObj;
    Complex c((ch.re * invm) % n, (ch.im * invm) % n, this->curve);
    return c;
}

Complex Complex::minus(){
    Complex c(-this->re, -this->im, this->curve);
    return c;
}