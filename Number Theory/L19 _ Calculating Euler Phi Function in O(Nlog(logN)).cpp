// L19 _ Calculating Euler Phi Function in O(Nlog(logN))

/* Problem to be Discussed :
    Find efficient way to find phi(n) from 1 to n, where n<=10^6
*/
/*  Approach : using Sieve
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
phi[] = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18    // Initialization 

phi[] = 1 1 3 2 5 3 7 4 9  5 11  6 13  7 15  8 17  9    // start with 2 i.e. multiply res by (P-1)=(2-1) and divide res by P = 2 
phi[] = 1 1 2 2 5 2 7 4 6  5 11  4 13  7 10  8 17  6    // start with 3
This processs is continuous and so on...
*/

// Time Complexity = O(Nlog(logN)) , Space Complexity = O(N)

#include<iostream>
using namespace std;
int phi[1000001];

void init(int maxN)
{   
    // Initialization
    for (int i = 1; i <= maxN;i++)
        phi[i] = i;
    
    // Calculating phi[n]
    for (int i = 2; i <= maxN;i++){
        // If the number is prime i.e. phi[n] = n
        if(phi[i]==i){
            for (int j = i; j <= maxN;j+=i){
                phi[j] *= (i - 1);
                phi[j] /= i;
            }
        }
    }
}

int main(){
    init(1000000);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << "ETF(" << n<< ") = " << phi[n] << endl;
    }

    return 0;
}