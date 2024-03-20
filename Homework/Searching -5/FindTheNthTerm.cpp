#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }

    return gcd(b%a, a);
}

int lcm(int a, int b) {
    return a*b/gcd(a,b);
}

int findPos(int num, int a, int b, int c) {;
    return num/a + num/b + num/c - num/lcm(a,b) - num/lcm(b,c) - num/lcm(c,a) + num/lcm(a, lcm(b,c));
}

int findNthTerm(int a, int b, int c, int N) {
    int l = min(a, min(b,c));
    int h = INT_MAX;

    while (l<=h) {
        int mid = l + (h-l)/2;
        int pos = findPos(mid, a, b, c);
        if (pos == N) {
            h = mid-1;
        }
        if (pos < N)
            l = mid+1;
        else    
            h = mid-1;
    }

    return l;
}

int main() {    
    int a,b,c;
    cin >> a >> b >> c;

    int N;
    cin >> N;

    cout << findNthTerm(a,b,c,N);
}