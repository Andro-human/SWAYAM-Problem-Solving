#include <bits/stdc++.h>
using namespace std;

bool ifSingleChild(vector<int> preOrder) {
    for(int i=0; i<preOrder.size(); i++) {
        if (i == preOrder.size()-1)
            break;
        int curr = preOrder[i];
        int nextSuccessor = preOrder[i+1];
        int lastSuccessor = preOrder[preOrder.size()-1];
        if (curr > nextSuccessor && curr < lastSuccessor)
            return false;
        if (curr < nextSuccessor && curr > lastSuccessor)
            return false;
    }

    return true;
}

int main() {
    vector<int> preOrder {20,10,11,13,12};
    cout << ifSingleChild(preOrder);
}