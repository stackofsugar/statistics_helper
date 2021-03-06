#include "../include/stdafx.h"
using namespace std;

int main(){
    cout << ">>> Welcome to Statistics Helper <<<\n"
         << "Please choose your solver:" << '\n';
    
    while(1){
        cout << "1. Cumulative Binomial Distribution \n"
             << "> ";
        int choice = input<int>(0,1);

        if(choice == eBinomial){
            int binom_n, binom_a, binom_b;
            double binom_p;
            cout << "Enter your n (number of tries): ";
            binom_n = input<int>();
            cout << "Enter p (singular probability): ";
            binom_p = input<double>();
            cout << "Enter x sum range (a < x < b || a <space> b): ";
            binom_a = input<int>();
            binom_b = input<int>(binom_a + 1);
            Bicalc binomial(binom_a, binom_b, binom_n, binom_p);
            binomial.compute();
        }
    }
}