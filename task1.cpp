#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canInstallPrograms(const vector<int>& freeSpace, const vector<int>& programSizes, int N) {
    // Сортируем свободное пространство в порядке убывания
    vector<int> sortedFreeSpace = freeSpace;
    sort(sortedFreeSpace.begin(), sortedFreeSpace.end(), greater<int>());

    // Проверяем, можно ли установить все программы
    int currentN = 0;
    for (int i = 0; i < sortedFreeSpace.size(); i++) {
        bool canInstall = true;
        for (int j = 0; j < programSizes.size(); j++) {
            if (sortedFreeSpace[i] < programSizes[j]) {
                canInstall = false;
                break;
            }
        }
        if (canInstall) {
            currentN++;
            if (currentN == N) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int M, N;
    cout << "Введите количество компьютеров (M) и программных систем (N): ";
    cin >> M >> N;

    vector<int> freeSpace(M);
    vector<int> programSizes(N);

    cout << "Введите объемы свободного пространства на компьютерах: ";
    for (int& space : freeSpace) {
        cin >> space;
    }

    cout << "Введите объемы памяти, необходимые для установки программных систем: ";
    for (int& size : programSizes) {
        cin >> size;
    }

    if (canInstallPrograms(freeSpace, programSizes, N)) {
        cout << "Можно установить все программные системы" << endl;
    } else {
        cout << "Невозможно установить все программные системы" << endl;
    }

    return 0;
}
