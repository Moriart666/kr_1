#include "lib.hpp"


// Сортировка шелла
// Shell sort
// Усовершенствованный алгоритм сортировки 
// вставками (?)
// ● Сравниваем не рядом стоящие элементы, а 
// элементы, которые располагаются на 
// определенном удалении (шаге) друг от 
// друга.
// ● На каждой итерации шаг уменьшается в два 
// раза, пока не станет равным единицы
// ● На последнем проходе, когда gap = 1 
// сортировка вырождается в сортировку 
// вставками.


void shell_sort(std::vector<int>& array) {
    int n = array.size();
    // Начинаем с большого шага и уменьшаем его
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Выполняем сортировку вставками с заданным шагом
        for (int i = gap; i < n; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}



// Накормить животных
// В небольшом зоопарке есть некоторое количество животных.
// Каждое животное потребляет какой-то объем еды, выраженный в целочисленном 
// значении. Например, еноту нужна 1-порция еды, зебре 2, пантере 3, льву 4, 
// жирафу 8 и т.д.
// Каждый день, смотритель зоопарка привозит еду такими же порциями. То есть за 
// раз он привозит 8, 3, 9, 1, 7. Порция на 8 может накормить одно животное один 
// раз. То есть такая порция может накормить либо енота, либо льва, либо жирафа, 
// но не может накормить, например зебру и енота. Только кого-то одного.
// Надо написать функцию, которая определит, сколько из переданных животных 
// может накормить заданное количество еды.


void feed_animals(const std::vector<int>& animals, const std::vector<int>& food, int& result) {
    // Сортируем потребности животных и доступную еду
    std::vector<int> sorted_animals = animals;
    std::vector<int> sorted_food = food;
    std::sort(sorted_animals.begin(), sorted_animals.end());
    std::sort(sorted_food.begin(), sorted_food.end());

    int animal_idx = 0;
    int food_idx = 0;
    int count = 0;

    while (animal_idx < sorted_animals.size() && food_idx < sorted_food.size()) {
        if (sorted_food[food_idx] >= sorted_animals[animal_idx]) {
            // Кормим животное
            count++;
            animal_idx++;
            food_idx++;
        } else {
            // Порция слишком маленькая, переходим к следующей порции
            food_idx++;
        }
    }

    result = count;
}

// Найти разницу между двух строк
// На вход функции подается две строки: a и b. Строка b образована из строки a 
// путем перемешивания и добавления одной буквы. Необходимо вернуть эту 
// букву

char extraLetter(const std::string& a, const std::string& b) {
    std::unordered_map<char, int> count;
    for (char c : b) {
        count[c]++;
    }
    for (char c : a) {
        count[c]--;
        if (count[c] == 0) {
            count.erase(c);
        }
    }
    // Оставшаяся буква — это дополнительная буква
    return count.begin()->first;
}


// Сумма двух элементов массива
// Дан не отсортированный массив целых чисел и 
// некоторое число target. Необходимо написать 
// функцию, которая найдет два таких элемента в 
// массиве, сумма которых будет равна target
// Один элемент можно использовать лишь один 
// раз. В случае если два таких элемента не 
// нашлось, возвращаем пустой массив

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> cache; // значение -> индекс
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (cache.find(complement) != cache.end()) {
            return {cache[complement], i};
        }
        cache[nums[i]] = i;
    }
    return {};
}

// Массив анаграмм
// Дан массив строк strs. Сгруппируйте анаграммы вместе. Вы можете вернуть ответ в 
// любом порядке.
// Анаграмма - это слово или фраза, полученная путем перестановки букв другого 
// слова или фразы, обычно с использованием всех исходных букв ровно один раз.
// Входные данные: ["eat","tea","tan","ate","nat","bat"]
// Выходные: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Входные данные: ["won","now","aaa","ooo","ooo"]
// Выходные: [["aaa"],["ooo", "ooo"],["won","now"]]

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (const auto& s : strs) {
        std::string key = s;
        std::sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    std::vector<std::vector<std::string>> result;
    for (auto& pair : groups) {
        result.push_back(pair.second);
    }
    return result;
}