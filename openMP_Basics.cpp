#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

using namespace std;

// Function to print the matrix
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (const auto &element : row)
            cout << element << " ";
        cout << endl;
    }
}

int main()
{
    // Define the size of the matrices
    const int size = 10000;

    // Initialize matrices A and B with constant values, and C with zeros
    vector<vector<int>> A(size, vector<int>(size, 1));
    vector<vector<int>> B(size, vector<int>(size, 2));
    vector<vector<int>> C(size, vector<int>(size, 0));

    // Start timing the matrix addition
    auto start = chrono::high_resolution_clock::now();

    // Perform parallel matrix addition using OpenMP
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Stop timing
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Output the time taken for the matrix addition
    cout << "OpenMP Matrix Addition Time: " << duration.count() << " seconds\n" << endl;

    return 0;
}
