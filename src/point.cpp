#include "point.hpp"
#include "util.hpp"

Point::Point(Integer x, Integer y, EllipticCurve curve){
    this->x = x;
    this->y = y;
    this->curve = curve;
}

Integer Point::getX(){
    return this->x;
}

Integer Point::getY(){
    return this->y;
}

Point Point::operator + (Point obj){
    //std::cout << "加法開始：(" << this->x << ", " << this->y << ") + (" << obj.getX() << ", " << obj.getY() << ")" << std::endl;
    Integer N = this->curve.getCharacteristic();
    Integer dx = obj.getX() - this->x;
    Integer dy = obj.getY() - this->y;
    Integer lambda = dy * (Util::modInv(dx, N));
    lambda = lambda % N;

    Integer x = (lambda * lambda % N) - this->x - obj.getX();
    Integer y = (lambda * (this->x - x) % N) - this->y;
    x = x % N; y = y % N;
    if(x < ZERO) x = x + N;
    if(y < ZERO) y = y + N;
    Point p(x, y, this->curve);
    //std::cout << "加法終了" << std::endl;
    return p;
}

Point Point::operator * (Integer k){
    // TODO: 定数倍を実装する．
    return *this;
}

Point Point::doubling(){
    Integer N = this->curve.getCharacteristic();
    Integer b = this->curve.getParameterB();
    Integer c = this->curve.getParameterC();

    Integer lambda = ((3 * this->x * this->x % N) + b) * (Util::modInv(TWO * this->y, N));
    lambda = lambda % N;
    Integer x = (lambda * lambda % N) - (2 * this->x);
    Integer y = (lambda * (this->x - x) % N) - this->y;
    x = x % N; y = y % N;
    if(x < ZERO) x = x + N;
    if(y < ZERO) y = y + N;

    Point p(x, y, this->curve);
    return p;
}


Point Point::minus(){
    Point p(this->x, MINUS_ONE * this->y, this->curve);
    return p;
}
