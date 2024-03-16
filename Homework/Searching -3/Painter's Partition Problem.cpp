int allocate(int mid, vector<int> &boards) {
    int board = 1, pages = 0;

    for (int i=0; i<boards.size(); i++) {
        if (pages + boards[i] > mid) {
            pages = boards[i];
            board++;
        }
        else    
            pages += boards[i];
    }

    return board;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
     if (k > boards.size())
        return -1;
    int s  = *max_element(boards.begin(), boards.end());
    int e = accumulate(boards.begin(), boards.end(), 0);
    while (s<=e) {
        int mid = s + (e-s)/2;
        int numBoards = allocate(mid, boards);
        if (numBoards > k) 
            s = mid+1;
        else 
            e = mid-1; 
    }

    return s;
}