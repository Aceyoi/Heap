//Сапожников Юрий ИВТ-22
#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Heap-Class.h"

using namespace std;

// Сложность O(logn)
// Метод для перемещения элемента вниз
template <typename T>
void siftDown(vector<T>& heap, size_t index, size_t size) {
    size_t largest = index;
    size_t leftChild = 2 * index + 1;
    size_t rightChild = 2 * index + 2;

    if (leftChild < size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }
    if (rightChild < size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        siftDown(heap, largest, size);
    }
}

// Сложность O(nlogn)
// Сортировка кучей
template <typename T>
void heapsort(vector<T>& heap) {
    // Построение кучи
    size_t n = heap.size();
    size_t size = heap.size() - 1;
    // Построение максимальной кучи
    for (int i = n / 2 - 1; i >= 0; --i) {
        siftDown(heap, i, n);
    }
    // Из-за свойства кучи, максимальный  элемент всегда будет первым
    // После перестроения кучи цикл повторяется 
    // Извлечение максимальных элементов один за другим и перемещение их в конец массива
    for (size_t i = n - 1; i > 0; --i) {
        swap(heap[0], heap[i]);  // Меняем местами корень и последний элемент
        siftDown(heap, 0, i);  // Восстанавливаем кучу на оставшихся элементах
    }
}




// Функция для добавления и отображения всех элементов
template <typename T>
void printmass(vector<T>& heap) {
    for (size_t i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

//Функция на проверку сортировки
template <typename T>
bool sort_check(vector<T>& heap) {
    for (size_t i = 0; i < heap.size() - 1; i++) {
        if (heap[i] > heap[i + 1]) {
            return false;
        }
    };
    return true;
}