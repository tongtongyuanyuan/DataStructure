#include <iostream>
#include <fstream>
#include <string>
using namespace std;
uint32_t lcs_count(string a,string b) { //Taught by TA is support center
    int m = a.length();
    int n = b.length();
    int leftCount[m  + 1][n + 1];
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if(i == 0 || j == 0) {
                leftCount[i][j] = 0;
                continue;
            }
            if (a[i - 1] == b[j - 1])
                leftCount[i][j] = leftCount[i-1][j-1] + 1;
            else {
                leftCount[i][j] = max(leftCount[i-1][j],leftCount[i][j-1]);
            }
        }
    }
    return leftCount[m][n];
}
//read file into string
string GetFile(const char filename[]) {
    ifstream f(filename);
    string contents;
    f >> contents;
    return contents;
}

int main(int argc, char* argv[]) {
    string a = GetFile(argv[1]);
    string b = GetFile(argv[2]);
    cout << lcs_count(a,b) << endl;
}
