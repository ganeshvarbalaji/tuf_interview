#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void sieveOfEratosthenes(int n) {
    // Create a boolean array to mark prime numbers
    vector<bool> isPrime(n + 1, true);
    // Mark 0 and 1 as non-prime
    isPrime[0] = false;
    isPrime[1] = false;

    // Loop from 2 to the square root of n
    for (int p = 2; p <= sqrt(n); p++) {
        // If p is still marked as prime
        if (isPrime[p]) {
            // Mark all multiples of p as non-prime
            for (int multiple = 2*p; multiple <= n; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    // Print all prime numbers up to n
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;

    // Take input from the user
    cout << "Enter the value of n: ";
    cin >> n;

    // Call the sieve function
    sieveOfEratosthenes(n);
}
