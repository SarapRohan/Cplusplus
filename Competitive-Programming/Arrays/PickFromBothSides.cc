int PickFromBothSides(vector<int> &A, int B) {
    int left = 0, right = 0;
    for (int i = 0; i < B; i++) left += A[i];
    int res = left;
    for (int i = A.size() - 1, j = B - 1; j >= 0; i--, j--) {
        res = max(res, (left -= A[j]) + (right += A[i]));
    }
    return res;
}
