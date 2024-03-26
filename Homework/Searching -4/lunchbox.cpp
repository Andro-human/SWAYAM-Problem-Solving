#include <bits/stdc++.h>
using namespace std;

bool isPossible(int lunchBoxes, vector<int> fooditems, int A) {
    int res = 0;
    for (int i=0; i<fooditems.size(); i++) {
        res += fooditems[i]/lunchBoxes;
    }
    return res >= A;
}

int MaxLunchBox(int A, vector<int> foodItems) {
    unordered_map<int, int> m;
    for (int i=0; i<foodItems.size(); i++) {
        m[foodItems[i]]++;
    }
    vector<int> freq;
    int maxElem = 0;
    for (auto &i: m) {
        freq.push_back(i.second);
        maxElem = max(maxElem, i.second);
    }


    int s = 1, e = maxElem;
    while (s <= e) {
        int mid = s + (e-s)/2;
        if (isPossible(mid, freq, A)) {
            s = mid+1;
        }
        else 
            e = mid-1;
    }

    return e;
}

int main() {
    int A, n;
    cin >> A >> n;

    vector<int> foodItems;
    for (int i=0; i<n; i++) {
        int x; 
        cin >> x;
        foodItems.push_back(x);
    }
    cout << MaxLunchBox(A, foodItems);
}