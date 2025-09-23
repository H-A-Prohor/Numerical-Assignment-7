#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printVector(const vector<double>& x) {
    for (double val : x) cout << val << "\t";
    cout << endl;
}

vector<double> gaussSeidelDetailed(const vector<vector<double>>& A, const vector<double>& b, double tol, int& iter) {
    int n = A.size();
    vector<double> x(n, 0.0);
    iter = 0;
cout << "\nGauss-Seidel Iterations:\n";
    while (true) {
        vector<double> x_old = x;
        cout << "Iteration " << iter + 1 << ": ";
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) sum += A[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }
        printVector(x);
        iter++;
        double maxErr = 0.0;
        for (int i = 0; i < n; i++)
            maxErr = max(maxErr, fabs(x[i] - x_old[i]));
        if (maxErr < tol) break;
    }
    return x;
}

// SOR with detailed iteration
vector<double> SORDetailed(const vector<vector<double>>& A, const vector<double>& b, double tol, double w, int& iter) {
    int n = A.size();
    vector<double> x(n, 0.0);
    iter = 0;
    cout << "\nSOR Iterations (w=" << w << "):\n";
    while (true) {
        vector<double> x_old = x;
        cout << "Iteration " << iter + 1 << ": ";
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++)
                if (j != i) sum += A[i][j] * x[j];
            x[i] = (1 - w) * x[i] + w * (b[i] - sum) / A[i][i];
        }
        
printVector(x);
        iter++;
        double maxErr = 0.0;
        for (int i = 0; i < n; i++)
            maxErr = max(maxErr, fabs(x[i] - x_old[i]));
        if (maxErr < tol) break;
    }
    return x;
}

int main() {
    int n;
    cout << "Enter number of equations: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Enter coefficients of matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter constants vector b:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    double tol;
    cout << "Enter tolerance (e.g., 0.001): ";
    cin >> tol;

    double w;
    cout << "Enter relaxation factor for SOR (e.g., 1.25): ";
    cin >> w;
