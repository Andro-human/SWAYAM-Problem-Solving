#include <iostream>
#include <vector>
using namespace std;

int maxSubarrayMid(int x, int s, vector<int> &vec) {
    int curr = 0;
    for (int i=0; i<x; i++) {
        curr += vec[i];
    }

    if (curr > s)
        return false;
    int st = 0, e = x;
    while (e < vec.size()) {
        curr -= vec[st];
        curr += vec[e];
        st++, e++;

        if (curr > s)
            return false;
    }
    return true;
}

int maxSubarrayLessThanS(vector<int> &vec, int s) {
    int l = 0;
    int h = vec.size();

    while (l<=h) {
        int mid = l + (h-l)/2;
        if (maxSubarrayMid(mid, s, vec)) {
            l = mid+1;
        }
        else    
            h = mid-1;
    }

    return h;
}

int main() {
    vector<int> vec {1,3,4,2};
    int s;
    cin >> s;

    cout << maxSubarrayLessThanS(vec, s);
}