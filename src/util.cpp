#include "util.hpp"

Integer Util::gcd(Integer a, Integer b){
    if(b >= a){
        return Util::gcd(b, a);
    }

    if(a == ZERO || b == ZERO){
        throw std::overflow_error("GCD の計算に 0 が渡されました．");
    }

    Integer r = a % b;
    while(r != ZERO) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

Integer Util::lcm(Integer a, Integer b){
    return a * b / boost::integer::gcd(a, b);
}

Integer Util::klcm(Integer k){
    Integer N = ONE;
    while(k != ZERO){
        N = boost::integer::lcm(N, k);
        k -= ONE;
    }
    return N;
}

Integer Util::modInv(Integer a, Integer N){
    if(a < 0){
        return MINUS_ONE * Util::modInv(MINUS_ONE * a, N);
    }
    Integer s = a, t = N;
    Integer x = ONE, u = ZERO;
    Integer k;
    while(t > ZERO) {
    	k = s / t;
    	s = s - (k * t);
        std::swap(s, t);
        x = x - (k * u);
        std::swap(x, u);
    }
    x = x % N;
    if(x < ZERO){
        x = x + N;
    }
    return x;
}

Integer Util::pow(Integer a, Integer b, Integer q){
    /*
    TODO: 多倍長整数の累乗を実装する．
    多倍長整数の多倍長整数乗は，一般には精度の確保が難しいため，boost でもサポートされていない．
    そこで，a^b % q を実装する必要がある．
    */
    return ZERO;
}

std::queue<Integer> Util::getPrimes(Integer max, int min){
    std::vector<std::pair<Integer, bool>> numbers;
    std::queue<Integer> primes;
    numbers.push_back(std::make_pair(0, false));
    numbers.push_back(std::make_pair(1, false));
    for(Integer i = 2; i < max; ++i){
        numbers.push_back(std::make_pair(i, true));
    }

    Integer front = TWO;
    while(front < sqrt(max)){
        primes.push(front);
        Integer f = ZERO;
        for(Integer i = 3; i < max; ++i){
            if(i % front == ZERO){
                numbers[(int) i].second = false;
            }else if(numbers[(int) i].second && !f){
                f = i;
            }
        }
        front = f;
    }

    for(Integer i = front; i < max; ++i){
        if(numbers[(int) i].second){
            primes.push(numbers[(int) i].first);
        }
    }

    return primes;
}
