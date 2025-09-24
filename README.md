# Numerical-Assignment-7

### Solving Linear Systems Using Gauss-Seidel and SOR Methods (C++)

This project implements two iterative methods — **Gauss-Seidel** and **SOR (Successive Over-Relaxation)** — to solve systems of linear equations of the form:


The program takes user input for the coefficient matrix `A`, the constant vector `b`, the convergence tolerance, and the relaxation factor for SOR. It then solves the system using both methods and prints the solution along with iteration details.

---
## 🧠 Methods Implemented

### 🔹 Gauss-Seidel Method
An iterative method for solving a square system of linear equations. It improves the solution at each iteration using the latest available values.

### 🔹 SOR (Successive Over-Relaxation) Method
An improved version of Gauss-Seidel that introduces a relaxation factor `w` to potentially speed up convergence.

---

## 📁 Files

- `Gauss_Seidel_and_SOR.cpp`: Main C++ source code implementing both methods.
- `LICENSE`: License information for the repository.
- `README.md`: Project documentation (this file).

---



## 🔧 How It Works

1. Prompts the user to enter:
   - Number of equations `n`
   - Matrix `A` (n × n)
   - Vector `b` (length n)
   - Tolerance (e.g., `0.001`)
   - Relaxation factor for SOR (e.g., `1.25`)

2. Applies both **Gauss-Seidel** and **SOR** methods.

3. Outputs:
   - Iteration details (for each method)
   - Final solution vectors
   - Number of iterations taken to converge



### Requirements
- C++ compiler (e.g., `g++`)
- C++11 or higher


