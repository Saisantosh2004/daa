#include <bits/stdc++.h>
using namespace std;

string lcs(string X, string Y, int m, int n) {
    if (m == X.length() || n == Y.length())
        return "";

    if (X[m] == Y[n])
        return lcs(X, Y, m +1, n + 1) + X[m];
    else {
        string lcs1 = lcs(X, Y, m + 1, n);
        string lcs2 = lcs(X, Y, m, n + 1);
        return (lcs1.size() > lcs2.size()) ? lcs1 : lcs2;
    }
}

int main() {
    string S1 = "stone";
    string S2 = "longest";
    int m = S1.size();
    int n = S2.size();

    string longestCommonSubsequence = lcs(S1, S2, 0, 0);
    reverse(longestCommonSubsequence.begin(),longestCommonSubsequence.end()) ;
    cout << "Longest Common Subsequence: " << longestCommonSubsequence<< endl;
    cout << "Length of LCS is: " << longestCommonSubsequence.size() << endl;

    return 0;
}
