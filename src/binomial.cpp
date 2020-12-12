#include "../include/stdafx.h"
using namespace std;

Bicalc::Bicalc(int x, int y, int n, double p){
    this->x = x;
    this->n = n;
    this->p = p;
    this->q = 1-p;
    this->y = y;
}

long double Bicalc::fact(int x){
    long double res = 1;
    for (int i = x; i > 1; i--){
        res *= i;
    }
    return res;
}

long double Bicalc::comb(int n,int r){
    long double res;
    res = fact(n) / (fact(n - r) * fact(r));
    return res;
}

long double Bicalc::pow(double p, int x){
    long double res = 1;
    if (x == 0){
        res = 1;
    }
    else if (x == 1){
        res = p;
    }
    else if (x < 0){
        res = -1;
    }
    else {
        for (int i = 1; i <= x; i++){
            res *= p;
        }
    }
    return res;
}

void Bicalc::compute(){
    long double resvec_buffer;
    for (int i = 0; i <= x; i++){
        resvec_buffer = comb(n,i) * pow(p,i) * pow(q,(n-i));
        resvec.push_back(resvec_buffer);
    }
}

void Bicalc::printres(){
    cout << "Cumulative: " << endl;
    long double sum = 0;
    for (int i = 0; i <= x; i++){
        cout << fixed << setprecision(numeric_limits<long double>::digits10 + 1) << "P(X = " << i << ") = " 
             << resvec[i] << endl;
        sum += resvec[i];
    }
    if (sum == 1){
        cout << "The result succeded test." << endl;
    }
    else {
        cout << "The result failed. Continue with caution." << endl;
    }
}