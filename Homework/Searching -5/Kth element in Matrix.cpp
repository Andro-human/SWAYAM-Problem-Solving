//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends

int numElemsBeforeMid(int num, int matrix[MAX][MAX], int n) {
        int cnt = 0;
        for (int i=0; i<n; i++) {
            int s = 0, e = n-1;
            while (s <= e) {
                int mid = s + (e-s)/2;

                if (matrix[i][mid] <= num) {
                    s = mid+1;
                }
                else {
                    e = mid-1;
                }
            }
            cnt += s;
        }
        return cnt;
    }

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int s = mat[0][0], e = mat[n-1][n-1];

    while (s<e) {
        int mid = s + (e-s)/2;
        int numElems = numElemsBeforeMid(mid, mat, n);

        if (numElems >= k) {
            e = mid;
        }
        else {
            s = mid+1;
        }
    }

    return e;

}
