#include <iostream>
#include <omp.h>
using namespace std;

const int n = 10;
const int t = 1;
const int group_size = 80;
const int age = 50;
double matrix[n][group_size][2];
int main() {
    setlocale(LC_ALL, "RUS");

    // Ініціалізація
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < group_size; j++) {
            matrix[i][j][0] = 0;
            matrix[i][j][1] = rand() % 100;
            // cout << matrix[i][j][1] << " ";
        }
        // cout << endl;
    }

    omp_set_num_threads(t);
    double timein = omp_get_wtime();

    // Основний процес
    for (int i = 0; i < age; i++) {
#pragma omp parallel for
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < group_size; k++) {
                matrix[j][k][0] += matrix[j][k][1];
            }
        }
    }

    double timeout = omp_get_wtime();
    double dt = timeout - timein;

    // cout << endl << "Результати" << endl;

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < group_size; j++) {
            cout << matrix[i][j][0] << " ";
        }
        cout << endl;
    }*/

    std::cout << endl << "Время вычислений : " << dt * 1000 << " милисекунд" << std::endl;
}