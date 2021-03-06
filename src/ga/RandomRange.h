#ifndef __LIBRARY__RandomRange__
#define __LIBRARY__RandomRange__

#include <random>

namespace RandomRange {
namespace {
    std::random_device rd;
    std::mt19937 rng(rd());

    template <class T>
    struct TypeIsInt {
        static const bool value = false;
    };

    template <>
    struct TypeIsInt<int> {
        static const bool value = true;
    };

    template <class T>
    inline const bool isInt(const T num) {
        if (TypeIsInt<T>::value) {
            return true;
        }
        else {
            return false;
        }
    }

    template <class T>
    inline const T random(const T min, const T max) {
        if (TypeIsInt<T>::value) {
            std::uniform_int_distribution<int> uniform_int(min, max);
            return uniform_int(rng);
        }
        else {
            std::uniform_real_distribution<double> uniform_real(min, max);
            return uniform_real(rng);
        }
    }
    
    template <class T>
    inline const T normal(const T mean, const T std) {
        std::normal_distribution<> normal(mean, std);
        if (TypeIsInt<T>::value) {
            return (int)normal(rng);
        }
        else {
            return (T)normal(rng);
        }
    }
}
}

#endif
