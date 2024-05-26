#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(const string& s, const string& p, int sI, int pI, vector<vector<int>>& res) {
    if (pI == p.length())
        return sI == s.length();

    // Если мы достигли конца строки s, но остались символы в p, проверяем, являются ли они всеми '*'
    if (sI == s.length())
        return p[pI] == '*' && isMatch(s, p, sI, pI + 1, res);

    // Если мы ранее проверяли эту комбинацию индексов, возвращаем результат из памяти
    if (res[sI][pI] != -1)
        return res[sI][pI];

    bool match;
    // Обрабатываем случай с *
    if (p[pI] == '*') {
        // '*' соответствует пустой последовательности или последовательности из одного или нескольких символов
        match = isMatch(s, p, sI + 1, pI, res) || isMatch(s, p, sI, pI + 1, res);
    }
    else {
        // Обычное сравнение символов или сопоставление с подстановочным знаком '?'
        match = (s[sI] == p[pI] || p[pI] == '?') && isMatch(s, p, sI + 1, pI + 1, res);
    }

    // Запоминаем результат для данной комбинации индексов
    return res[sI][pI] = match;
}


bool isPatternMatch(const string& s, const string& p) {
    vector<vector<int>> res(s.length() + 1, vector<int>(p.length() + 1, -1)); // Матрица для хранения значений
    return isMatch(s, p, 0, 0, res);
}

int main() {
    system("chcp 65001");
    string s;
    string p;
    cout << "Введите s: ";
    cin  >> s;
    cout << endl;
    cout << "Введите p: ";
    cin >> p;
    cout << endl;
    if (isPatternMatch(s, p))
        cout << "true";
    else
        cout << "false";

    return 0;
}