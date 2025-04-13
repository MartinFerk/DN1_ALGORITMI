#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<unsigned char> &vec, const char s[]) {
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

void Izpis_Stevil(unsigned char* polje, unsigned int velikost) {
    ofstream output("out.txt");

    for (int i = 0; i<velikost; i++)
        output << polje[i] << ' ';
}

void countSortBinary(vector<unsigned char>& A, const vector<int>& D) {
    vector<unsigned char> B(A.size());
    int count[2] = {0};
    int startIndex[2];

    for (int bit : D) {
        count[bit]++;
    }

    startIndex[0] = 0;
    startIndex[1] = count[0];

    for (int i = 0; i < A.size(); i++) {
        int bit = D[i];
        B[startIndex[bit]++] = A[i];
    }

    A = B;
}

void binaryRadixSort(vector<unsigned char>& A) {
    for (int k = 0; k < 8; k++) {

        vector<int> D(A.size());
        for (int i = 0; i < A.size(); i++) {
            D[i] = (A[i] >> k) & 1;
        }
        countSortBinary(A, D);
        
    }
}

int main(int argc, const char* argv[]) {

std::cout << "Test" << std::endl;

    vector<unsigned char> A;

    if (argc < 3) return 0;
    if (!Branje_Stevil(A, argv[2])) return 0;

    if (argv[1][0] == '0') {

        binaryRadixSort(A);
    }

    Izpis_Stevil(&A[0],A.size());

    return 0;
}
