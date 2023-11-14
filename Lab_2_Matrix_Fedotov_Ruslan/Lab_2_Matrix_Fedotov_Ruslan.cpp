#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int n, m;
    cout << "Кол-во строк и столбцов: ";
    cin >> n >> m;

    while (cin.fail() || (n <= 0 || m <= 0)) {
        cin.clear();
        cout << "Введите числа верно! Повторите попытку: " << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> n >> m;
    }

    int** arr = new int* [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            cout << "Введите элемент [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    int* columnID = new int[m];
    iota(columnID, columnID + m, 0);
    sort(columnID, columnID + m,
        [arr, n](int i, int j) {
            int minEl_I = numeric_limits<int>::max();
            int minEl_J = numeric_limits<int>::max();
            for (int k = 0; k < n; ++k) {
                minEl_I = min(minEl_I, arr[k][i]);
                minEl_J = min(minEl_J, arr[k][j]);
            }
            return minEl_I < minEl_J;
        });

    cout << "Столбцы по возрастанию мин. элементов: ";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][columnID[j]] << " ";
        }
        cout << '\n';
    }
    return 0;
}