#include <iostream>
using namespace std;

class Trie{
	long long numOfSubarray;
	Trie* bits[2];

public:
	Trie(): numOfSubarray{0}, bits{NULL} {}
	
	void insert(int num) {
		Trie* node = this;
		for(int i=17; i>=0; i--) {
			int currBit = ((num>>i) & 1);
			if (node->bits[currBit] == NULL) {
				node->bits[currBit] = new Trie();
			}
			node = node->bits[currBit];
			node->numOfSubarray++;
		}
	}

	long long findSubarray(int currXor, int k) {
		Trie *node = this;
		long long res = 0;
		for (int i=17; i>=0; i--) {
			int currXorBit = ((currXor>>i) & 1);
			int currKBit = ((k>>i) & 1);
			if (currKBit) {
				if (node->bits[!currXorBit] != NULL) {
					res += (node->bits[currXorBit])?node->bits[currXorBit]->numOfSubarray:0;

					node = node->bits[!currXorBit];
				}
				else if (node->bits[currXorBit]) {
					res += node->bits[currXorBit]->numOfSubarray;
					return res;
				}
				else 
					return res;
			}
			else {
				if (node->bits[currXorBit])
					node = node->bits[currXorBit];
				else 
					return res;
			}
		}

		return res;
	}
};

long long subarraysXor(int nums[], int n, int k) {
	Trie *node = new Trie();
	long long currXor = 0;
	long long res = 0;
	node->insert(currXor);
	for (int i=0; i<n; i++) {
		currXor ^= (long long)nums[i];
		res += node->findSubarray(currXor, k);
		node->insert(currXor);
	}

	return res;
}

int main() {
	int t;
	cin >> t;   

	while (t--) {
		int n,k;
		cin >> n >> k;

		int nums[n];
		for (int i=0; i<n; i++) 
			cin >> nums[i];

		cout << subarraysXor(nums, n, k) << endl;
	}
}