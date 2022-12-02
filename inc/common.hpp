#pragma once
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/integer/common_factor.hpp>
#include <random>
#include <cstring>
#include <iostream>
#include <ios>
#include <iomanip>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stdexcept>
#define BASE 1000 // 10^n であること．
#define LOG_BASE 3 // BASE の 10 による対数．
#define MAX_DIGIT 500
#define ZERO 0
#define ONE 1
#define MINUS_ONE -1
#define TWO 2
typedef boost::multiprecision::cpp_int Integer;
