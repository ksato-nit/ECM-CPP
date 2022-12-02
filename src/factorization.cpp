#include "factorization.hpp"
#include "elliptic_curve.hpp"
#include "point.hpp"
#include "util.hpp"

Integer k;

Factorization::Factorization(){
    this->gen.seed(time(NULL));
    k = Util::klcm(5);
    std::cout << k << std::endl;
}

Integer Factorization::factorize(Integer N){
    Integer b = this->gen() % N;
    Integer x1 = this->gen() % N;
    Integer y1 = this->gen() % N;

    Integer c = (y1 * y1 - (x1 * x1 * x1) - (b * x1)) % N;

    EllipticCurve curve(N, b, c);
    Point p(x1, y1, curve);

    std::cout << "Curve select." << std::endl;
    std::cout << "Coeff. : " << b << " " << c << std::endl;
    std::cout << "Starting Point : " << x1 << " " << y1 << std::endl;

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

    Integer u = k / TWO;

    for(int i = 1; i <= bitLength; ++i){
        if(u % TWO == ONE){
            points.push_back(p);
        }
        u = u / TWO;

        g = boost::integer::gcd(N, p.getY());

        if(g == ONE){
            p = p.doubling();
            std::cout << p.getX() << " " << p.getY() << std::endl;
        }else if(g > ONE && g < N){
            std::cout << p.getY() << std::endl;
            return g;
        }else if(g == N){
            return MINUS_ONE;
        }
    }

    Integer dx;
    Point p0 = points[0];
    for(int i = 1; i < points.size(); ++i){
        dx = points[i].getX() - p0.getX();
        if(dx < ZERO){
            dx *= MINUS_ONE;
        }

        g = boost::integer::gcd(N, dx);

        if(g == ONE){
            p0 = p0 + points[i];
            std::cout << p0.getX() << " " << p0.getY() << std::endl;
        }else if(g > ONE && g < N){
            std::cout << dx << std::endl;
            return g;
        }else if(g == N){
            return MINUS_ONE;
        }
    }

    return MINUS_ONE;
}
