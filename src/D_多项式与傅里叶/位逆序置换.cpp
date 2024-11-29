vector<int> bitReverse(vector<int>& arr) {
    int n = arr.size();
    int logN = log2(n);
    ector<int> result(n);
    for (int i = 0; i < n; ++i) {
        int reversedIndex = 0;
        for (int j = 0; j < logN; ++j) {
            if (i & (1 << j)) {
                reversedIndex |= (1 << (logN - 1 - j));
            }
        }
        result[reversedIndex] = arr[i];
    }
    return result;
}