template<int N> struct fib {
    static const int value =
        fib<N - 2>::value +
        fib<N - 1>::value;
};
template<> struct fib<1> { static const int value = 1; };
template<> struct fib<0> { static const int value = 0; };
template<int N> struct int_ {};
