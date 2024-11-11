//Сапожников Юрий ИВТ-22
#include <iostream>
#include <cassert>
#include "Heap-Class.h"
#include "Heap-Test.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");

    testcheck();

    MaxHeap<int> heap;

    heap.insert(30);
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(50);
    heap.insert(25);
    heap.insert(45);
    heap.insert(35);
    heap.insert(40);

    heap.printHeapmass();
    //heap.printHeap();
    heap.heapsort();
    heap.printHeapmass();

    cout << endl << "Размер кучи: " << heap.size() << endl << endl;

   // cout  << "Минимального элемент: " << heap.getMin() << endl;
    cout  << "Максимальный элемент: " << heap.getMax() << endl << endl;

    cout << "Извлекает максимальный элемент: " << heap.extractMax() << endl;
   // cout << "Извлекает минимальный элемент: " << heap.extractMin() << endl << endl;

    cout << "Максимальный элемент после извлечения: " << heap.getMax() << endl;
   // cout << "Минимальный элемент после извлечения: " << heap.getMin() << endl << endl;

    cout << "Размер кучи: " << heap.size() << endl << endl;

    heap.printHeapmass();
    heap.printHeap();


    return 0;
}

