#include "common.hpp"
#include "factorization.hpp"
#include "primality_test.hpp"
#include "util.hpp"
#include <time.h>
Integer N("2924077739655891297001");

int main(){
    Factorization f;

    int i = 1;
    while(i){
        Integer r = f.factorize(N);
        if (r > ZERO){
            std::cout << "Prime factor:" << std::endl;
            std::cout << r << std::endl;
            --i;
        }
    }

    return 0;
}
