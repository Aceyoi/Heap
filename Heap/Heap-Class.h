//���������� ���� ���-22
#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


// ��������� ����� ����
template <typename T>
class MaxHeap {
private:
    vector<T> heap;

    // ����� ��� ����������� �������� �����
    void siftUp(int index, int size) {
        while (index > 0 && index < size) {
            int parent = (index - 1) / 2;
            if (heap[index] <= heap[parent]) break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    // ����� ��� ����������� �������� ����
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
    // ���������� �������� � ����
    void insert(T value) {
        heap.push_back(value);
        siftUp(heap.size() - 1, heap.size());
    }

    // ���������� ������������� ��������
    T extractMax() {
        if (heap.empty()) throw out_of_range("���� �����!");

        T max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0, heap.size());  // �������� ������� ������ ����
        return max;
    }

    // ���������� ������������ ��������
    T extractMin() {
        if (heap.empty()) throw out_of_range("���� �����!");

        T min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0, heap.size());  // �������� ������� ������ ����
        return min;
    }

    // ��������� ������������� ��������
    T getMax() const {
        if (heap.empty()) throw out_of_range("���� �����!");
        return heap[0];
    }

    // ��������� ������������ ��������
    T getMin() const {
        if (heap.empty()) throw out_of_range("���� �����!");
        int size = heap.size();
        return heap[size-1];
    }

    // ��������, ����� �� ����
    bool isEmpty() const {
        return heap.empty();
    }

    // ��������� ������� ����
    int size() const {
        return heap.size();
    }

    // ��������������� ������� ��� ����������� ����
    void printHeap(int index = 0, int level = 0) const {
        if (index >= heap.size()) return;

        // ����������� ����� ������� ���������
        int rightChild = 2 * index + 2;
        if (rightChild < heap.size()) {
            printHeap(rightChild, level + 1);
        }

        // ������ ��� �������� ������
        for (int i = 0; i < level; ++i) {
            cout << "    ";
        }
        cout << " -> " << heap[index] << endl;  // ����� �������� ����

        // ����������� ����� ������ ���������
        int leftChild = 2 * index + 1;
        if (leftChild < heap.size()) {
            printHeap(leftChild, level + 1);
        }
    }

    // ������� ��� ���������� � ����������� ���� ���������
    void printHeapmass() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }



};
