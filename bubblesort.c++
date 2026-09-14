#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
// Estructura para almacenar cada algoritmo
struct Metricas {
    long long comparaciones = 0;
    long long intercambios = 0;
};
//FUNCIONES 
Metricas bubbleSortBase(vector<int> arr);
Metricas bubbleSortMejora1(vector<int> arr);
Metricas bubbleSortMejora2(vector<int> arr);
Metricas bubbleSortOptimizado(vector<int> arr);
Metricas selectionSort(vector<int> arr);
void probarCasos(const string& nombreCaso, const vector<int>& datosOriginales);

int main() {
    probarCasos("Caso 1 [5, 3, 8, 2]", {5, 3, 8, 2});
    probarCasos("Caso 2 [1, 2, 3, 4, 5]", {1, 2, 3, 4, 5});
    probarCasos("Caso 3 [5, 4, 3, 2, 1]", {5, 4, 3, 2, 1});

    return 0;
}

// 1. Bubble Sort Base
Metricas bubbleSortBase(vector<int> arr) {
    Metricas m;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            m.comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                m.intercambios++;
            }
        }
    }
    return m;
}
// 2. Bubble Sort con mejora 1 detección de arreglo ordenado
Metricas bubbleSortMejora1(vector<int> arr) {
    Metricas m;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1; j++) {
            m.comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                m.intercambios++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return m;
}
// 3. Bubble Sort con mejora 2 reducción de comparaciones j < n - i - 1
Metricas bubbleSortMejora2(vector<int> arr) {
    Metricas m;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            m.comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                m.intercambios++;
            }
        }
    }
    return m;
}
// 4. Bubble Sort Optimizado mejora 1 + mejora 2 combinadas
Metricas bubbleSortOptimizado(vector<int> arr) {
    Metricas m;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            m.comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                m.intercambios++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return m;
}
// 5. Selection Sort
Metricas selectionSort(vector<int> arr) {
    Metricas m;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            m.comparaciones++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            m.intercambios++;
        }
    }
    return m;
}
// Función para imprimir métricas
void probarCasos(const string& nombreCaso, const vector<int>& datosOriginales) {
    cout << "  PRUEBA: " << nombreCaso << "\n";
    Metricas mBase = bubbleSortBase(datosOriginales);
    Metricas mM1 = bubbleSortMejora1(datosOriginales);
    Metricas mM2 = bubbleSortMejora2(datosOriginales);
    Metricas mOpt = bubbleSortOptimizado(datosOriginales);
    Metricas mSel = selectionSort(datosOriginales);

    cout << "1. Bubble Base:       Comp: " << mBase.comparaciones << " | Inter: " << mBase.intercambios << "\n";
    cout << "2. Mejora 1:          Comp: " << mM1.comparaciones << " | Inter: " << mM1.intercambios << "\n";
    cout << "3. Mejora 2:          Comp: " << mM2.comparaciones << " | Inter: " << mM2.intercambios << "\n";
    cout << "4. Optimizado:        Comp: " << mOpt.comparaciones << " | Inter: " << mOpt.intercambios << "\n";
    cout << "5. Selection Sort:    Comp: " << mSel.comparaciones << " | Inter: " << mSel.intercambios << "\n\n";
}
