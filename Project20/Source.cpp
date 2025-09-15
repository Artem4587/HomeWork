#include <iostream>
using namespace std;

void customSwap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partitionAroundMiddle(int arr[], int low, int high) {
    int pivot_index = low + (high - low) / 2;
    int pivot_value = arr[pivot_index];
    customSwap(arr, pivot_index, high);

    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot_value) {
            i++; 
            customSwap(arr, i, j); 
        }
    }
    customSwap(arr, i + 1, high);
    return (i + 1);
}

int main() {
    setlocale(LC_ALL, "ru");
    int arr[] = { 3, 8, 1, 9, 4, 7, 2, 10, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << std::endl;
    cout << "\nВыполняем один шаг разделения вокруг среднего элемента..." << endl;

    int pivot_final_index = partitionAroundMiddle(arr, 0, n - 1);

    cout << "\nМассив после разделения вокруг среднего элемента (опорный элемент на позиции "
        << pivot_final_index << "):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << std::endl;
}