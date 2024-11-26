#include "lib.hpp"
// Дан массив целых чисел.Необходимо развернуть его.
// Сделать это надо за линейное время без дополнительных аллокаций памяти

void array_revers1(std::vector<int>& array) {
  int left = 0;
  int right = array.size() - 1;

  while (left < right) {
    std::swap(array[left], array[right]);
    ++left;
    --right;
  }
}

// Дан массив целых чисел. Необходимо развернуть справа налево часть массива,
// которая указана вторым параметром. Сделать это надо за линейное время без
// дополнительных аллокаций

void temp_revers2(std::vector<int>& array, int left, int right) {
  while (left < right) {
    std::swap(array[left], array[right]);
    ++left;
    --right;
  }
}

void array_revers2(std::vector<int>& array, int k) {
  int k_mod = (k + array.size())% array.size();
  temp_revers2(array, 0, array.size() - 1);
  temp_revers2(array, 0, k_mod - 1);
  temp_revers2(array, k_mod, array.size() - 1);
}

// Дано два отсортированных массива. Необходимо написать функцию которая
// объединит эти два массива в один отсортированный.

std::vector<int> merge_sorted(std::vector<int>& left, std::vector<int>& right) {
  std::vector<int> result(left.size() + right.size());
  int counter = 0;
  int i = 0;
  int j = 0;
  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      result[counter] = left[i];
      ++i;
      ++counter;
    } else {
      result[counter] = right[j];
      ++j;
      ++counter;
    }
  }

  if (i == left.size()) {
    while (j < right.size()) {
      result[counter] = right[j];
      ++j;
      ++counter;
    }
  } else {
    while (i < left.size()) {
      result[counter] = left[i];
      ++i;
      ++counter;
    }
  }
  return result;
}

// Дано два отсортированных массива. Необходимо написать функцию которая
// объединит эти два массива в один отсортированный. Первый массив имеет размер,
// равный результирующиму массиву, значения в конце равны нулям. Мы не должны
// создавать третий массив.

std::vector<int> merge_sorted2(std::vector<int>& left,
                               std::vector<int>& right) {
  int mid = left.size() - 1;
  int j = right.size() - 1;
  int i = left.size() - right.size() - 1;
  while (i >= 0 && j >= 0) {
    if (left[i] > right[j]) {
      left[mid] = left[i];
      --mid;
      --i;
    } else {
      left[mid] = right[j];
      --mid;
      --j;
    }
  }

  if(i == -1){
    while(j >= 0){
      left[mid] = right[j];
      --j;
      --mid; 
    }
  } else {
    while(i >= 0){
      left[mid] = left[i];
      --i;
      --mid;
    }
  }

  return left;
}

// Дан не отсортированный массив целых чисел. Необходимо перенести в начало
// массива все четные числа, сохраняя их очередность. То есть если 8 стояла
// после 6, то после переноса в начало, он по-прежнему должна стоять после 6

void first_even(std::vector<int>& array) {
  int counter = 0;
  for (size_t i = 1; i < array.size(); ++i) {
    if (array[i] % 2 == 0) {
      std::swap(array[counter], array[i]);
      ++counter;
    }
  }
}

// В школе прошел экзамен по математике.
// Несколько человек списали решения и были
// замечены. Этим школьникам поставил 0
// баллов. Задача: есть массив с оценками,
// среди которых есть 0. Необходимо все
// оценки, равные нулю перенести в конец
// массива, чтобы все такие школьники
// оказались в конце списка.

void end_null(std::vector<int>& array) {
  int counter = 0;
  for (size_t i = 1; i < array.size(); ++i) {
    if (array[i] != 0) {
      std::swap(array[counter], array[i]);
      ++counter;
    }
  }
}

//.................................................................//
// int main() {
//   std::vector<int> array1 = {1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0};
//   std::vector<int> array2 = {8, 9, 10, 11};
//   // std::vector<int> result = merge_sorted(array1, array2);
//   // first_even(result);
//   // for(size_t i = 0; i < result.size(); ++i){
//   //     std::cout << result[i] << " ";
//   // }
//   std::vector<int> array3 = {1, 2, 3, 4, 5, 6, 7};
//   // array_revers2(array3, 10);
//   std::vector<int> result = merge_sorted(array3, array2);
//   std::vector<int> test = {0, 0, 0, 18, 16, 0, 0, 77, 99};
//   end_null(test);
//   for (int i = 0; i < test.size(); ++i) {
//     std::cout << test[i] << " ";
//   }
// }
