#include "../include/stdafx.h"
using namespace std;

Bicalc::Bicalc(int range_x, int range_y, int n, double p){
    this->range_x = range_x;
    this->n = n;
    this->p = p;
    this->q = 1-p;
    this->range_y = range_y;
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

// DON'T CALL printres()
void Bicalc::compute(){
    long double resvec_buffer, sum = 0.0;
    cout << "Cumulative Distribution: " << '\n';
    for (int i = range_x; i <= range_y; i++){
        resvec_buffer = comb(n,i) * pow(p,i) * pow(q,(n-i));
        resvec.push_back(resvec_buffer);
        sum += resvec_buffer;

        cout << "P(X = " << i << ") = "
             << fixed << setprecision(numeric_limits<long double>::digits10 + 1) 
             << resvec_buffer << '\n';
    }
    cout << "With the sum of: " << sum << '\n';
    // printres();
}

// void Bicalc::printres(){
//     cout << "Cumulative Distribution: " << '\n';
//     long double sum = 0;
//     for (int i = range_x; i <= range_y; i++){
//         cout << fixed << setprecision(numeric_limits<long double>::digits10 + 1) << "P(X = " << i << ") = " 
//              << resvec[i] << '\n';
//         sum += resvec[i];
//     }
//     cout << "Sum of CD: " << sum << '\n';
// }