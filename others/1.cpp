// Given a 32-bit signed integer, reverse digits of an integer.
#include <bits/stdc++.h>
using namespace std;
int reverse(int x) {
    long long res = 0;
    while(x) {
        res = res*10 + x%10;
        x /= 10;
    }
    return (res<INT_MIN || res>INT_MAX) ? 0 : res; // NOTE: must realize that after reversing the number whether it will be overflow (>2^31)
}
int main(){
    int x = 1534236469;
    cout<<reverse(x);
}