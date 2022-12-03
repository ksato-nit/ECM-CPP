#include "point.hpp"
#include "util.hpp"

Point::Point(Complex x, Complex y, EllipticCurve curve) : x(x), y(y){
    this->curve = curve;
}

Complex Point::getX(){
    return this->x;
}

Complex Point::getY(){
    return this->y;
}

Point Point::operator + (Point obj){
    // TOO WET!
    Integer N = this->curve.getCharacteristic();
    Integer tau = this->curve.getTau();

    /*
    Integer x1 = this->x.first;
    Integer x2 = this->x.second;
    Integer y1 = this->y.first;
    Integer y2 = this->y.second;
    Integer dx1 = obj.getX().first - x1;
    Integer dx2 = obj.getX().second - x2;
    Integer dy1 = obj.getY().first - y1;
    Integer dy2 = obj.getY().second - y2;
    Integer lambda1 = (dy1 * dx1 - dx2 * dy2 * tau) * (Util::modInv(dx1 * dx1 - tau * dx2 * dx2, N)) % N;
    Integer lambda2 = (- dy1 * dx2 + dx1 * dy2) * (Util::modInv(dx1 * dx1 - tau * dx2 * dx2, N)) % N;
    Integer nu1 = y1 - lambda1 * x1 - lambda2 * x2 * tau;
    Integer nu2 = y2 - lambda1 * x2 - lambda2 * x1;
    */

    Complex dx = obj.getX() - this->x;
    Complex dy = obj.getY() - this->y;
    Complex lambda = dy / dx;
    Complex nu = this->y - lambda * this->x;

    Complex nx = lambda * lambda - this->x - obj.x;
    Complex ny = lambda * (this->x - nx) - this->y;

    /*
    Integer nx1 = ((lambda1 * lambda1 + tau * lambda2 * lambda2) % N) - x1 - obj.getX().first;
    Integer nx2 = (TWO * lambda1 * lambda2 % N) - x2 - obj.getX().second;
    Integer ny1 = -(lambda1 * nx1 + tau * lambda2 * nx2 % N) - nu1;
    Integer ny2 = -(lambda1 * nx2 + lambda2 * nx1 % N) - nu2;
    nx1 = nx1 % N; nx2 = nx2 % N; ny1 = ny1 % N; ny2 = ny2 % N;
    if(nx1 < ZERO) nx1 = nx1 + N;
    if(nx2 < ZERO) nx2 = nx2 + N;
    if(ny1 < ZERO) ny1 = ny1 + N;
    if(ny2 < ZERO) ny2 = ny2 + N;
    */
    Point p(nx, ny, this->curve);
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
    Integer tau = this->curve.getTau();
    /*
    Integer lambda1 = (this->y.first * ((3 * this->x.first * this->x.first + 3 * this->x.second * this->x.second * tau) + b) - 6 * this->x.first * this->x.second * this->y.second * tau) * (Util::modInv(TWO * (this->y.first * this->y.first - tau * this->y.second * this->y.second), N));
    Integer lambda2 = (6 * this->x.first * this->x.second * this->y.first - this->y.second * ((3 * this->x.first * this->x.first + 3 * this->x.second * this->x.second * tau) + b)) * (Util::modInv(TWO * (this->y.first * this->y.first - tau * this->y.second * this->y.second), N));
    lambda1 = lambda1 % N;
    lambda2 = lambda2 % N;
    //std::cout << this->y.first * ((3 * this->x.first * this->x.first + 3 * this->x.second * this->x.second * tau) + b) - 6 * this->x.first * this->x.second * this->y.second * tau << " " << lambda2 << std::endl;
    Integer nu1 = this->y.first - lambda1 * this->x.first - lambda2 * this->x.second * tau;
    Integer nu2 = this->y.second - lambda1 * this->x.second - lambda2 * this->x.first;
    Integer x1 = ((lambda1 * lambda1 + tau * lambda2 * lambda2) % N) - (2 * this->x.first);
    Integer x2 = (TWO * lambda1 * lambda2 % N) - (2 * this->x.second);
    Integer y1 = -(lambda1 * x1 + tau * lambda2 * x2 % N) - nu1;
    Integer y2 = -(lambda1 * x2 + lambda2 * x1 % N) - nu2;
    x1 = x1 % N; x2 = x2 % N; y1 = y1 % N; y2 = y2 % N;
    if(x1 < ZERO) x1 = x1 + N;
    if(x2 < ZERO) x2 = x2 + N;
    if(y1 < ZERO) y1 = y1 + N;
    if(y2 < ZERO) y2 = y2 + N;

    Complex ch = this->x * this->x * 3 + Complex(b, 0, this->curve);
    Complex m = this->y * 2;
    Complex lambda = ch / m;
    Complex nu = this->y - lambda * this->x;

    Complex nx = lambda * lambda - this->x * 2;
    Complex ny = lambda.minus() * nx - nu;
    */

    Complex lambda = (this->x * this->x * 3 + Complex(b, 0, this->curve)) / (this->y * 2);

    Complex nx = lambda * lambda - this->x - this->x;
    Complex ny = lambda * (this->x - nx) - this->y;

    Point p(nx, ny, this->curve);
    return p;
}


Point Point::minus(){
    Point p(this->x, this->y, this->curve);
    return p;
}
