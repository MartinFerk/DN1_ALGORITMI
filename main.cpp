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

    for (int i = 0; i<velikost; i++)
        output << polje[i] << ' ';
}

void countSort(vector<int>& A, int bit){

    vector<int> B(A.size());
    int count[2] = {0};
    int startIndex[2];

    for (int num : A) {
        int bitVal = (num >> bit) & 1;
        count[bitVal]++;
    }

    startIndex[0] = 0;
    startIndex[1] = count[0];

    for (int i = 0; i < A.size(); i++) {
        int bitVal = (A[i] >> bit) & 1;
        B[startIndex[bitVal]++] = A[i];
    }

    A = B;
}



int main(int argc, const char* argv[]) {
    vector<int> A;

    if (argc < 3) return 0;
    if (!Branje_Stevil(A, argv[2])) return 0;

    if (argv[1][0] == '0') {

        countSort(A);
    }

    Izpis_Stevil(&A[0],A.size());

    return 0;
}
