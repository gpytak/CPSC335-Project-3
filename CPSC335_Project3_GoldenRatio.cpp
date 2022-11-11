#include <iostream>
#include <cmath>
using namespace std;

unsigned long long int fibonacci_number(unsigned long long int n){
    return round((pow((1+sqrt(5)), n) - pow((1-sqrt(5)), n)) / (pow(2,n)*sqrt(5)));
}

unsigned long long int previous_term(unsigned long long int Fib_N, unsigned long long int N, unsigned long long int P, bool N_greater_than_P){
    if(N_greater_than_P){
        return round(Fib_N*(pow(1.618033989, (N-P))));
    }else{
        return round(Fib_N/(pow(1.618033989, (N-P))));
    }
}

unsigned long long int next_term(unsigned long long int Fib_N){
    return round(Fib_N*1.618033989);
}

int main(){
    unsigned long long int P, N, Fib_P, Fib_N, next_Fib;
    double input;

    cout << "Enter a positive and non-floating point integer for 'p': ";
    cin >> input;
    P = (int)input;

    while(input < 1 || (input-floor(input))){
        cout << "Incorrect input, enter a positive and non-floating point integer for 'p': ";
        cin >> input;
        P = (int)input;
    }

    cout << "Enter a positive and non-floating point integer for 'n': ";
    cin >> input;
    N = (int)input;

    while(input < 1 || (input-floor(input))){
        cout << "Incorrect input, enter a positive and non-floating point integer for 'n': ";
        cin >> input;
        N = (int)input;
    }

    // Part A
    Fib_P = fibonacci_number(P); // Equation 3
    if(P < N){
        Fib_N = previous_term(Fib_P, N, P, true); // Equation 4
    }else{
        Fib_N = previous_term(Fib_P, P, N, false); // Equation 4
    }
    cout << "\nP: f(" << P << ") -> " << Fib_P << endl;
    cout << "N: f(" << N << ") -> " <<  Fib_N << endl;
    Fib_N = fibonacci_number(N); // Equation 3
    next_Fib = next_term(Fib_N); // Equation 5
    cout << "N+1: f(" << N+1 << ") -> " <<  next_Fib << endl;       

    // Part B
    cout << "\nThe first 20 terms of the fibonacci sequence:" << endl;
    for(int i = 0; i < 21; i++){
        cout << "f(" << i << ") -> " << fibonacci_number(i) << endl;
    }

    // Part C
    cout << "\nUsing equation 4 on equation 5 results:" << endl;
    Fib_N = previous_term(next_Fib, N+1, N, false); // Equation 4
    cout << "N+1: f(" << N+1 << ") -> " <<  next_Fib << endl;
    cout << "N: f(" << N << ") -> " <<  Fib_N << endl;

    // Part D
    cout << "\nMaxim with F(3) and F(30):" << endl;
    float maxim_prove = (float)fibonacci_number(30)/(float)fibonacci_number(29); // Equation 3
    float maxim_disprove = (float)fibonacci_number(3)/(float)fibonacci_number(2); // Equation 3
    if((maxim_prove - 1.618033989) < (maxim_disprove - 1.618033989)){
        cout << "F(30) proves the maxim." << endl;
    }else if((maxim_prove - 1.618033989) > (maxim_disprove - 1.618033989)){
        cout << "F(3) disproves the maxim." << endl;
    }

    return 0;
}
