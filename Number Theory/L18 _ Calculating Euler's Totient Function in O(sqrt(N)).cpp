// L18 _ Calculating Euler's Totient Function in O(sqrt(N))

/* Final Expression of ETF :
    Phi(N) = N * ((P1-1)/P1) * ((P2-1)/P2) * ((P3-1)/P3) *...* ((Pk-1)/Pk)     */

#include<iostream>
using namespace std;

int phi(int n){
    int res = n;

    for (int i = 2; i * i <= n;i++){
        if(n%i==0){
            res *= (i - 1);
            res /= i;

            while (n%i==0)
                n /= i;
        }
    }
    if(n>1){    
        res *= (n - 1);
        res /= n;
    }
    return res;
}

int main(){
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << "ETF(" << n<< ") = " << phi(n) << endl;
    }

    return 0;
}