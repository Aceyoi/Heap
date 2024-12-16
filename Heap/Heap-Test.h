//Сапожников Юрий ИВТ-22

#pragma once

#include <iostream>
#include <cassert>
#include "Heap-Class.h"
#include "Heap-Modul.h"

using namespace std;

/// проверка данных
void testcheck() {

    MaxHeap<int> testheap;

    testheap.insert(30);
    testheap.insert(10);
    testheap.insert(5);
    testheap.insert(20);
    testheap.insert(50);
    testheap.insert(15);
    testheap.insert(25);
    testheap.insert(45);
    testheap.insert(35);
    testheap.insert(40);


    assert(testheap.isEmpty() == false);
    assert(testheap.size() == 10);

    assert(testheap.getMax() == 50);
    assert(testheap.extractMax() == 50);
    assert(testheap.getMax() == 45);
    assert(testheap.extractMax() == 45);
    assert(testheap.getMax() == 40);
    assert(testheap.extractMax() == 40);
    assert(testheap.getMax() == 35);
    assert(testheap.extractMax() == 35);
    assert(testheap.getMax() == 30);
    assert(testheap.extractMax() == 30);
    assert(testheap.getMax() == 25);
    assert(testheap.extractMax() == 25);
    assert(testheap.getMax() == 20);
    assert(testheap.extractMax() == 20);
    assert(testheap.getMax() == 15);
    assert(testheap.extractMax() == 15);
    assert(testheap.getMax() == 10);
    assert(testheap.extractMax() == 10);
    assert(testheap.getMax() == 5);
    assert(testheap.extractMax() == 5);

    try { // Проверка извлечение максимального элемента если куча пуская
        testheap.extractMax(); // Вызов метода, который вызовет исключение
        assert(0); // Если исключение не вызванно
    }
    catch (...) { // Обработчик исключения
        cout << "" << endl;
    }

    try { // Проверка Получение максимального элемента если куча пуская
        testheap.getMax(); // Вызов метода, который вызовет исключение
        assert(0); // Если исключение не вызванно
    }
    catch (...) { // Обработчик исключения
        cout << "" << endl;
    }

    assert(testheap.isEmpty() == true);
    assert(testheap.size() == 0);

    testheap.insert(10);
    testheap.insert(20);
    testheap.insert(30);
    testheap.insert(40);

    assert(testheap.isEmpty() == false);
    assert(testheap.size() == 4);
    assert(testheap.getMax() == 40);
    assert(testheap.extractMax() == 40);

    // Проверка сортировки массива

    vector<int> testheapmass = { 30,10,5,20,50,25,45,35,40 };
    vector<int> testheapmassbad = { 50,45,40,35,30,25,20,15,10,5 };
    vector<int> testheapmassgood = { 5,10,15,20,25,30,35,40,45,50 };

    assert(sort_check(testheapmassgood) == true);
    assert(sort_check(testheapmassbad) == false);
    assert(sort_check(testheapmass) == false);

    heapsort(testheapmassgood);
    heapsort(testheapmassbad);
    heapsort(testheapmass);

    assert(sort_check(testheapmassgood) == true);
    assert(sort_check(testheapmassbad) == true);
    assert(sort_check(testheapmass) == true);
}