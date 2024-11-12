//Сапожников Юрий ИВТ-22

#pragma once

#include <iostream>
#include <cassert>
#include "Heap-Class.h"
#include "Heap-Modul.h"

using namespace std;

/// проверка данных
void testcheck(){

    MaxHeap<int> testheap;
    vector<int> testheapmass = { 30,10,5,20,50,25,45,35,40 };

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

    assert(sort_check(testheapmass) == false);
    heapsort(testheapmass);
    assert(sort_check(testheapmass) == true);

}