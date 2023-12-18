#pragma once
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <random>
#include <vector>


using namespace std;

struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
};

stats insertion_sort(std::vector<int>& arr) {
    stats s;
    int size = arr.size();
    if (size < 2)
        return s;
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0; --j) {
            ++s.comparison_count;
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);;
                ++s.copy_count;
            }
            else break;
        }
    }
    return s;
}

stats coctail_sort(std::vector<int>& arr) {
    int size = arr.size();
    stats s;
    if (size < 2)
        return s;
    int low = 0;
    int up = size - 1;
    int last=-1;
    while (low < up) {
        last = -1;
        for (int i = low; i < up; ++i) {
            ++s.comparison_count;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                last = i;
                ++s.copy_count;
            }
        }
        up = last;
        if (last == -1)
            break;
        for (int i = up - 1; i >= low; --i) {
            ++s.comparison_count;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                last = i;
                ++s.copy_count;
            }
        }
        low = last;
    }
    return s;
}

stats comb_sort(std::vector<int>& arr) {
    stats s;
    int size = arr.size();
    if (size < 2)
        return s;
    int step = size-1;
    bool swaps = true;
    while (step >= 1 || swaps ==true) {
        swaps = false;
        for (int i = 0; i < size-step; ++i) {
            ++s.comparison_count;
            if (arr[i] > arr[i + step]) {
                swap(arr[i], arr[i + step]);
                ++s.copy_count;
                swaps=true;
            }
        }
        step = step-1;
        if (step < 1 && swaps == true) {
            step = 1;
        }

    }return s;
}

vector<int> random_vector(int size, int min, int max) {
    vector<int> arr;
    for (int i = 0; i < size; ++i) {
        arr.push_back(rand() % (max - min + 1) + min);
    }
    return arr;
}

vector<int> normal_vector(int size) {
    vector<int> arr;
    for (int i = 0; i < size; ++i) {
        arr.push_back(i);
    }
    return arr;
}

vector<int> reverse_vector(int size) {
    vector<int> arr;
    for (int i =size-1 ; i >=0; --i) {
        arr.push_back(i);
    }
    return arr;
}

