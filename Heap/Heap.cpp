//Сапожников Юрий ИВТ-22
#include <iostream>
#include <cassert>
#include "Heap-Class.h"
#include "Heap-Test.h"
#include "Heap-Modul.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    testcheck();

    MaxHeap<int> heap;
    vector<int> heapmass = { 30,10,5,20,50,25,45,35,40 };

    heap.insert(30);
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(50);
    heap.insert(25);
    heap.insert(45);
    heap.insert(35);
    heap.insert(40);

    cout << "Массив heapmass: " << endl; printmass(heapmass);
    heapsort(heapmass);
    cout << "Массив heapmass после сортировки кучей: " << endl; printmass(heapmass);

    cout << endl << "Массив класса heap: " << endl;
    heap.printHeapmass();

    cout << endl << "=============== Куча в виде дерева ======================" << endl;
    heap.printHeap();
    cout << "=========================================================" << endl;

    cout << endl << "Размер кучи: " << heap.size() << endl << endl;

    cout << "Максимальный элемент: " << heap.getMax() << endl << endl;

    cout << "Извлекает максимальный элемент: " << heap.extractMax() << endl << endl;

    cout << "Максимальный элемент после извлечения: " << heap.getMax() << endl << endl;

    return 0;
}

