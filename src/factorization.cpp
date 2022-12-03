#include "factorization.hpp"
#include "elliptic_curve.hpp"
#include "point.hpp"
#include "util.hpp"

Integer k;

Factorization::Factorization(){
    this->gen.seed(time(NULL));
}

Integer Factorization::factorize(Integer N){
    Integer cizero = 0;
    Integer cione = 1;
    k = N;
    Integer j("-884736");
 
    Integer R = this->gen() % N;
    Integer b = (3 * j * R * R * Util::modInv(1728 - j, N)) % N;
    Integer c = (2 * j * R * R * R * Util::modInv(1728 - j, N)) % N;
    Integer rx1 = this->gen() % N;
    Integer tau = rx1*rx1*rx1 + b*rx1 + c;
 
    EllipticCurve curve(N, b, c, tau);
    Complex x1(rx1, cizero, curve);
    Complex y1(cizero, cione, curve);
    Point p(x1, y1, curve);
 
    std::cout << "Curve select." << std::endl;
    std::cout << "Coeff. : " << b << " " << c << std::endl;
    std::cout << "Starting Point : " << rx1 << " " << 1 << std::endl;

    Integer d = boost::integer::gcd(curve.getDiscriminant(), N);

    if(d == N){
        return MINUS_ONE;
    }
    if(d > ONE && d < N){
        return d;
    }

    /* 繰り返し 2 乗法により k 倍の計算を行う */

    int bitLength = boost::multiprecision::msb(k);
    std::vector<Point> points;

    Integer g;

    Integer u = k;

    for(int i = 0; i <= bitLength + 1; ++i){
        Complex ty = p.getY();
        g = boost::integer::gcd(N, ty.re * ty.re - tau * ty.im * ty.im);

        if(g == ONE){
            p = p.doubling();
        }else if(g > ONE && g < N){
            return g;
        }else if(g == N){
            return MINUS_ONE;
        }

        if(u % TWO == ONE){
            points.push_back(p);
        }
        u = u / TWO;
    }

    Integer dx;
    Point p0 = points[0];
    for(int i = 1; i < points.size(); ++i){
        Integer dx1 = points[i].getX().re - p0.getX().re;
        Integer dx2 = points[i].getX().im - p0.getX().im;
        dx = dx1 * dx1 - tau * dx2 * dx2;
        if(dx < ZERO){
            dx *= MINUS_ONE;
        }

        g = boost::integer::gcd(N, dx);

        if(g == ONE){
            p0 = p0 + points[i];
        }else if(g > ONE && g < N){
            return g;
        }else if(g == N){
            return MINUS_ONE;
        }
    }

    return MINUS_ONE;
}
