#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;

    cout << "Введите размер вектора (N): ";
    cin >> N;

    vector<int> numbers(N);

    cout << "Введите " << N << " чисел:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    cout << "Числа в обратном порядке: ";
    for (int i = N - 1; i >= 0; i--) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}