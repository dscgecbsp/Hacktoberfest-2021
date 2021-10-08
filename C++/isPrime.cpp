/*
Problem Statement:
Given a integer n, write a function to return TRUE if n is prime, otherwise return false
*/

/// Returns 'true' if [n] is prime, otherwise returns 'false'
bool isPrime(const int& n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}