#pragma once
#include "common.hpp"

class Factorization{
public:
    Factorization();
    Integer factorize(Integer);
private:
    boost::random::independent_bits_engine<boost::mt19937, 64, Integer> gen;
};
