#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> st;
        vec.push_back(st);
        while (isspace(input.peek())) input.get();
    }
    input.close();
    return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
    ofstream output("out.txt");
    for (unsigned int i = 0; i < velikost; i++)
        output << polje[i] << ' ';
}

void countSort(vector<int>& A, int bit) {
    vector<int> B(A.size());
    int count[2] = {0};

    for (int num : A) {
        count[(num >> bit) & 1]++;
    }
    count[1] += count[0];

    for (int i = A.size() - 1; i >= 0; i--) {
        int bitVal = (A[i] >> bit) & 1;
        B[--count[bitVal]] = A[i];
    }
    A = B;
}

void BinaryradixSort(vector<int>& A) {
    for (int bit = 0; bit < 8; bit++) {
        countSort(A, bit);
    }
}

int main(int argc, const char* argv[]) {
    vector<int> A;

    if (argc < 3) return 0;
    if (!Branje_Stevil(A, argv[2])) return 0;

    if (argv[1][0] == '0') {
        BinaryradixSort(A);
    } else {
        return 0;
    }
    Izpis_Stevil(&A[0], A.size());

    return 0;
}
