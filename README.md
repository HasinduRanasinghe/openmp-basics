# OpenMP Matrix Addition

This repository contains a C++ program that performs element-wise addition of two 10,000 × 10,000 matrices using OpenMP for parallelization. The program uses 2D vectors to represent matrices and measures execution time with `std::chrono`.

## Overview

The program adds two matrices (`A` and `B`) to produce a result matrix (`C`), where each element `C[i][j] = A[i][j] + B[i][j]`. It uses OpenMP to parallelize the nested loops, distributing the computation across multiple threads for improved performance.

## Prerequisites

- A C++ compiler with OpenMP support.
- Standard libraries: `<iostream>`, `<vector>`, `<chrono>`, `<omp.h>`.
- Compile with the `-fopenmp` flag (e.g., `g++ -fopenmp openMP_Basics.cpp -o openMP_Basics`).

## File

- `openMP_Basics.cpp`: The implementation of matrix addition using 2D vectors and OpenMP.

## Compilation and Execution

1. **Compile**:
   ```bash
   g++ -fopenmp openMP_Basics.cpp -o openMP_Basics
   ```

2. **Run**:
   ```bash
   ./openMP_Basics
   ```

3. **Output**:
   - The program prints the execution time in seconds for the matrix addition.
   - To print the result matrix, use the `printMatrix(const vector<vector<int>> &matrix)` function (Note: Printing is not recommended for large sizes because its tend to be slow).

## Notes

- The matrix size is set to 10,000 × 10,000 (`size = 10000`). Adjust the `size` constant to test with smaller or larger matrices.
- Experiment with OpenMP scheduling options (`#pragma omp parallel for collapse(2) schedule(static, chunk_size)`) to optimize thread workload distribution.
