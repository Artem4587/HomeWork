#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;

    cout << "������� ������ ������� (N): ";
    cin >> N;

    vector<int> numbers(N);

    cout << "������� " << N << " �����:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    cout << "����� � �������� �������: ";
    for (int i = N - 1; i >= 0; i--) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}