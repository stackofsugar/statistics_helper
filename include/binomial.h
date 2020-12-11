#pragma once
#include <vector>
class Bicalc {
    private:
        int n,x,y;
        double p,q;
        std::vector<long double> resvec;
    public:
        Bicalc(int, int, int, double);
        long double fact(int);
        long double comb(int, int);
        long double pow(double, int);
        void compute();
        void printres();
};