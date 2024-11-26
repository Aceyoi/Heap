//���������� ���� ���-22
#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Heap-Class.h"

using namespace std;

// ��������� O(logn)
// ����� ��� ����������� �������� ����
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

// ��������� O(nlogn)
// ���������� �����
template <typename T>
void heapsort(vector<T>& heap) {
    // ���������� ����
    size_t n = heap.size();
    size_t size = heap.size() - 1;
    // ���������� ������������ ����
    for (int i = n / 2 - 1; i >= 0; --i) {
        siftDown(heap, i, n);
    }
    // ��-�� �������� ����, ������������  ������� ������ ����� ������
    // ����� ������������ ���� ���� ����������� 
    // ���������� ������������ ��������� ���� �� ������ � ����������� �� � ����� �������
    for (size_t i = n - 1; i > 0; --i) {
        swap(heap[0], heap[i]);  // ������ ������� ������ � ��������� �������
        siftDown(heap, 0, i);  // ��������������� ���� �� ���������� ���������
    }
}




// ������� ��� ���������� � ����������� ���� ���������
template <typename T>
void printmass(vector<T>& heap) {
    for (size_t i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

//������� �� �������� ����������
template <typename T>
bool sort_check(vector<T>& heap) {
    for (size_t i = 0; i < heap.size() - 1; i++) {
        if (heap[i] > heap[i + 1]) {
            return false;
        }
    };
    return true;
}