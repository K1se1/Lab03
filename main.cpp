#include<iostream>
#include<vector>
#include<string>
#include<random>


// Задача 1.1 

// Проверка является ли набор слов акронимом строки
bool is_acronym(const std::vector<std::string> &words, const std::string& acr)
{
    if(words.size() != acr.size()) return false; // если размеры не равны сразу возвращаем ложь

    for(size_t i =0; i < words.size(); ++i)
    {
        if(words[i][0] != acr[i])  return false; // Проверяем каждый символ акронима и каждого слова,
                                                 // если не равны возвращаем ложь 
    }
    return true;
}


// Задача 2.1


// Проверка является ли строка палиндромом
bool is_palindrome(const std::string &word)
{
    size_t size = word.size();
    size_t chunk = size/2; 
    for(size_t i =0; i <= chunk; ++i)
    {
        if(word[i] != word[size-i-1]) return false;
    }
    return true;
}



/// Задача 3
/// работает только на входных данных с строчными буквами
/// Не баг, а фича!!!

/// Счет для слова
long best_word_score(const std::vector<std::string> &words, const std::vector<int> &score, const std::string &letters)
{
    long max_score = 0, temp_score =0; // long - перестраховка от возможного переполнения

    // здесь заполняем новый вектор счета, в нем счет всех букв, не принадлежащих к letters == 0 
    std::vector<int> new_score(26, 0);
    for(char letter: letters) new_score[letter-'a'] = score[letter-'a'];

    for(std::string word: words)
    {
        for(char letter: word) 
            temp_score+=new_score[letter-'a']; // прибавляем к счету слова счет буквы из вектора нового счета
        max_score = std::max(temp_score, max_score); 
        temp_score = 0;
    }
    return max_score;




}

int main(int, char**){
    setlocale(LC_ALL, "Russian");
    ///// Задача 1.1
    int size;
    std::string str;
    std::cout << "Введите количество слов: ";
    std::cin >> size;
    std::vector<std::string> words(size);
    std::cout << "Введите слова:\n";
    for(size_t i =0; i < size; ++i) std::cin >> words[i];
    std::cout << "Введите акроним: ";
    std::cin >> str;
    std::cout << is_acronym(words, str) << "\n\n";
    ///Задача 2.1
    std::cout << "Введите слово: ";
    std::cin >> str;
    std::cout << is_palindrome(str) << "\n\n";
    ///Задача 3
    /// счет составим рандомно 
    std::vector<int> score(26, 0);
    for(size_t i =0; i < 26; ++i) score[i] = rand() % 100;
    std::cout << "Введите количество слов: ";
    std::cin >> size;
    words.resize(size);
    std::cout << "Введите слова:\n";
    for(size_t i =0; i < size; ++i) std::cin >> words[i];
    std::cout << "Введите символы: ";
    std::cin >> str;
    std::cout << best_word_score(words, score, str);

}
