#include "primality_test.hpp"

bool PrimalityTest::isPrime(Integer N){
    for(int i = 2; i < N; ++i){
        if(N % i == ZERO){
            return false;
        }
    }
    return true;
}
