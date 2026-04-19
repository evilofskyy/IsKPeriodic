#include <string>
bool IsKPeriodic(const std::string& s, int K) {
    // K должно быть положительным по условию задачи
    if (K <= 0) {
        return false;
    }

    size_t n = s.length();

    // Пустая строка считается кратной любому K (0 повторений)
    if (n == 0) {
        return true;
    }

    // Длина строки должна быть кратна K
    if (n % K != 0) {
        return false;
    }

    // Проверка повторяемости: каждый символ должен совпадать с символом на K позиций ранее
    for (size_t i = K; i < n; ++i) {
        if (s[i] != s[i - K]) {
            return false;
        }
    }

    return true;
}

#include <iostream>

int main() {
    std::string s1 = "abcabcabcabc";
    std::cout << IsKPeriodic(s1, 3) << std::endl; // 1 (true)

    std::string s2 = "abcdabcdab";
    std::cout << IsKPeriodic(s2, 4) << std::endl; // 0 (false, длина не кратна 4)

    std::string s3 = "aaaaaa";
    std::cout << IsKPeriodic(s3, 2) << std::endl; // 1 (true, повторяется "aa")

    std::string s4 = "";
    std::cout << IsKPeriodic(s4, 5) << std::endl; // 1 (true, пустая строка)

    return 0;
}