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
