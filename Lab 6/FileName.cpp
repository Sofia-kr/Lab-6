#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
int binarySearch(const vector<T>& array, T key) {
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == key) {
            return mid;  
        }
        if (array[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;  
}

template <typename T>
class ArrayTransformer {
public:
    ArrayTransformer(const vector<T>& array) : data(array) {}

    void applyExp() {
        for (int i = 0; i < data.size(); ++i) {
            data[i] = exp(data[i]);
        }
    }

    void print() const {
        for (int i = 0; i < data.size(); ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

private:
    vector<T> data;
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    vector<int> arr = { 1, 3, 5, 7, 9, 11 };
    int key = 7;

    // Завдання 1: Використання шаблонної функції для пошуку елемента
    int index = binarySearch(arr, key);
    if (index != -1) {
        cout << "Елемент знайдено на індексі: " << index << endl;
    }
    else {
        cout << "Елемент не знайдено." << endl;
    }

    // Завдання 2: Використання шаблонного класу для перетворення масиву
    vector<float> arrFloat = { 1.0, 2.0, 3.0, 4.0 };
    ArrayTransformer<float> transformer(arrFloat);
    transformer.applyExp();
    cout << "Масив після застосування exp типу float: ";
    transformer.print();
    vector<int> arrInt = { 1, 2, 3, 4 };
    ArrayTransformer<int> transformeri(arrInt);
    cout << "" << endl;
    transformeri.applyExp();

    cout << "Масив після застосування exp типу int: ";
    transformeri.print();

    return 0;
}
