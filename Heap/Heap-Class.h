//Сапожников Юрий ИВТ-22
#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


// Шаблонный класс кучи
template <typename T>
class MaxHeap {
private:
    vector<T> heap;

    // Метод для перемещения элемента вверх
    void siftUp(int index, int size) {
        while (index > 0 && index < size) {
            int parent = (index - 1) / 2;
            if (heap[index] <= heap[parent]) break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    // Метод для перемещения элемента вниз
    void siftDown(int index, int size) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            siftDown(largest, size);
        }
    }

public:
    // Добавление элемента в кучу
    void insert(T value) {
        heap.push_back(value);
        siftUp(heap.size() - 1, heap.size());
    }

    // Извлечение максимального элемента
    T extractMax() {
        if (heap.empty()) throw out_of_range("КУЧА ПУСТА!");

        T max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0, heap.size());  // Передаем текущий размер кучи
        return max;
    }

    // Извлечение минимального элемента
    T extractMin() {
        if (heap.empty()) throw out_of_range("КУЧА ПУСТА!");

        T min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0, heap.size());  // Передаем текущий размер кучи
        return min;
    }

    // Получение максимального элемента
    T getMax() const {
        if (heap.empty()) throw out_of_range("КУЧА ПУСТА!");
        return heap[0];
    }

    // Получение минимального элемента
    T getMin() const {
        if (heap.empty()) throw out_of_range("КУЧА ПУСТА!");
        int size = heap.size();
        return heap[size-1];
    }

    // Проверка, пуста ли куча
    bool isEmpty() const {
        return heap.empty();
    }

    // Получение размера кучи
    int size() const {
        return heap.size();
    }

    // Вспомогательная функция для отображения кучи
    void printHeap(int index = 0, int level = 0) const {
        if (index >= heap.size()) return;

        // Рекурсивный вывод правого поддерева
        int rightChild = 2 * index + 2;
        if (rightChild < heap.size()) {
            printHeap(rightChild, level + 1);
        }

        // Отступ для текущего уровня
        for (int i = 0; i < level; ++i) {
            cout << "    ";
        }
        cout << " -> " << heap[index] << endl;  // Вывод значения узла

        // Рекурсивный вывод левого поддерева
        int leftChild = 2 * index + 1;
        if (leftChild < heap.size()) {
            printHeap(leftChild, level + 1);
        }
    }

    // Функция для добавления и отображения всех элементов
    void printHeapmass() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }



};
