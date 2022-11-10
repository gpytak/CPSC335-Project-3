#include <iostream>
#include <cmath>
using namespace std;

unsigned long long int fibonacci_number(unsigned long long int n){
    return round((pow((1+sqrt(5)), n) - pow((1-sqrt(5)), n)) / (pow(2,n)*sqrt(5)));
}

unsigned long long int previous_term(unsigned long long int Fib_P, unsigned long long int N, unsigned long long int P){
    return round(Fib_P*(pow(1.618033989, (N-P))));
}

unsigned long long int next_term(unsigned long long int Fib_N){
    return round(Fib_N*1.618033989);
}

int main(){
    unsigned long long int P, N, Fib_P, Fib_N, previous_Fib_P, next_Fib_N;
    double input;

    cout << "Enter a positive and non-floating point for 'p': ";
    cin >> input;
    P = (int)input;

    while(input < 1 || (input-floor(input))){
        cout << "Incorrect input, enter a positive and non-floating point for 'p': ";
        cin >> input;
        P = (int)input;
    }

    cout << "Enter a positive and non-floating point for 'n': ";
    cin >> N;

    Fib_P = fibonacci_number(P);
    Fib_N = previous_term(Fib_P, N, P);
    next_Fib_N = next_term(Fib_N);

    cout << "P: f(" << P << ") -> " << Fib_P << endl;
    cout << "N: f(" << N << ") -> " <<  Fib_N << endl;
    cout << "N+1: f(" << N+1 << ") -> " <<  next_Fib_N << endl;

    return 0;
}