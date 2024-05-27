// assuming that the condition for i, j and k is i<=j<=k because it is not correctly mentioned 
// in the question.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int x, y, z;
    cin >> x >> y >> z;

    int prefix[n+1];
    int postfix[n+1];

    prefix[0] = INT_MIN;
    postfix[n] = INT_MIN;
    for (int i=0; i<n; i++) {
        prefix[i+1] = max(prefix[i], x*nums[i]);
        postfix[n-i-1] = max(postfix[n-i], z*nums[n-i-1]); 
    }

    for (int i=0; i<=n; i++) {
        cout << prefix[i] << " ";
        cout << postfix[n-i] << endl;;
    }
    int maxVal = INT_MIN;
    for (int i=1; i<=n; i++) {
        maxVal = max(maxVal, prefix[i]+(nums[i-1]*y)+postfix[n-i]);
    }

    cout << maxVal << endl;
}

