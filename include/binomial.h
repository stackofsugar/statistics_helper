#pragma once
#include <vector>
class Bicalc {
    private:
        int n, range_x, range_y;
        double p,q;
        std::vector<long double> resvec;
    public:
        Bicalc(int, int, int, double);
        long double fact(int);
        long double comb(int, int);
        long double pow(double, int);
        void compute();
        // void printres();
};