#include <iostream>
using namespace std;

unsigned long long int fibonacci(unsigned long long int n_val){
    if(n_val == 0){
        return 0;
    }else if(n_val == 1){
        return 1;
    }else{
        return fibonacci(n_val-1) + fibonacci(n_val-2);
    }
}

int main(){
    unsigned long long int input = 14;
    unsigned long long int output;

    output = fibonacci(input);

    cout << "\nThe 15th element of fibonacci is " << output << endl;
    return 0;
}
