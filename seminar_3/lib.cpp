#include "lib.hpp"

// В исходную строку добавили некоторое количество 
// символов. Необходимо выявить, была ли строка a 
// исходной для строки b.

bool is_Subsequence(std::string a, std::string b){
    bool result = false; // 0
    size_t counter = 0;
    for(size_t i = 0; i < b.size(); ++i){
        if(b[i] == a[counter]){
            counter++;
        }
        if(counter == a.size()){
            result = true; // 1
            break;
        }
    }
    return result;
}


// Напишите функцию, которая принимает на вход строку и 
// возвращает true, если она является палиндромом*. В 
// противном случае верните false.
// *слово или текст, одинаково читающиеся в обоих 
// направлениях.

bool is_Palindrome_1(std::string str){ // реализация методом двух указателей
    bool result = true; // 1
    size_t left = 0;
    size_t right = str.size() - 1;

    while(right > left){
        if(str[left] == str[right]){
            ++left;
            --right;
        } else {
            result = false; // 0
            break;
        }
    }
    return result;
}

bool is_Palindrome_2(std::string str){ // реализация с помощью стека
    bool result = true; // 1
    std::vector<char> array(str.size());
    for(size_t i = 0; i < array.size(); ++i){
        array[i] = str[i];
    }
    for(size_t i = 0; i < array.size(); ++i){
        if(array.back() != str[i]){
            result = false; // 0
            break;
        }
        array.pop_back();
    }
    return result;
}

bool is_Palindrome_3(std::string str){ // реализация с помощью дека
    bool result = true; // 1
    std::deque<char> array(str.size());
    for(size_t i = 0; i < array.size(); ++i){
        array[i] = str[i];
    }
    while(!array.empty()){
        if(array.front() != array.back()){
            result = false; // 0
            break;
        }
        array.pop_back();
        if(array.empty()){
            break;
        }
        array.pop_front();
    }
    return result;
}


// Написать функцию, которая находит корень числа или ближайшее, 
// подходящее, наименьшее целое число

int binary_search_sqrt(int number){
    int left = 0;
    int right = (number / 2) + 1;
    int mid;

    while (right - left > 1){
        mid = (right + left) / 2;
        if(mid * mid >= number){
            right = mid;
        } else if(mid * mid < number){
            left = mid;
        }
    }

    if(right * right != number){
        --right;
    }

    return right;
}




// Сегодня утром жюри решило добавить в вариант олимпиады еще одну “Очень 
// Легкую Задачу”. Ответственный секретарь Оргкомитета напечатал ее условие в 
// одном экземпляре, и теперь ему нужно до начала олимпиады успеть сделать 
// еще N копий. В его распоряжении имеются два ксерокса, один из которых 
// копирует лист за х секунд, а другой – за y. (Разрешается использовать как один 
// ксерокс, так и оба одновременно. Можно копировать не только с оригинала, но 
// и с копии.) Помогите ему выяснить, какое минимальное время для этого 
// потребуется.

int copy_time(int N, int x, int y) {
    if (N <= 0) return 0;
    if (N == 1) return std::min(x, y);

    int min_time = std::min(x, y);
    int left = min_time;
    int right = min_time + (N - 1) * std::max(x, y);

    while (left < right) {
        int mid = (left + right) / 2;
        int copies = 1 + (mid - min_time) / x + (mid - min_time) / y;

        if (copies >= N) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}


// Дана строка s. Строка состоит из английских букв в нижнем регистре. Необходимо из 
// строки удалить все рядом стоящие повторяющиеся буквы. Например, в строке xyyx 
// мы должны удалить yy, а после и оставшиеся xx и того, после должна получиться 
// пустая строка. Или же в строке fqffqzzsd после удаления остануться только fsd. 
// Первыми удаляться ff, являющимися третьими и четвертыми символами, затем qq и 
// после уже zz.

void delete_dublicat(std::string& array){
    std::vector<char> stek;
    std::string result = "";
    size_t counter = 0;
    for(size_t i = 0; i < array.size(); ++i){
        if(stek.empty()){
            stek.push_back(array[i]);
            continue;
        }
        if(stek.back() == array[i]){
            if(counter == 0){
                counter = 1;
            }
            continue;
        }

        if(stek.back() != array[i]){
            if(counter == 1){
                stek.pop_back();
                counter = 0;
            }
            if(stek.back() == array[i]){
                counter = 1;
            } else {
                stek.push_back(array[i]);
            }
        }
    }

    if(counter == 1){
        stek.pop_back();
    }

    if(!stek.empty()){
        for(size_t i = 0; i < stek.size(); ++i){
            result += stek[i]; 
        }
    }
    array = result;
}
