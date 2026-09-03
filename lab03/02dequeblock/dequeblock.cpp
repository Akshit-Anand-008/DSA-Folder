#pragma once
#include "dequeblock.h"

#include "deque.h"

template <typename T>
dequeBlock<T>::dequeBlock(int capacity) {
    data = new T[capacity];
    this->cap = capacity;
    this->count = 0;
    this->startIdx = 0;
}

template <typename T>
dequeBlock<T>::~dequeBlock() {
    delete[] this->data;
}

// I am using one less space for consistency
template <typename T>
bool dequeBlock<T>::pushBack(const T& val) {
    if (this->count >= (this->cap) - 1) { return false; }
    int lastIdx = (startIdx + count) % cap;
    data[lastIdx] = val;
    count++;
    return true;
}

template <typename T>
bool dequeBlock<T>::pushFront(const T& val) {
    if (this->count >= (this->cap) - 1) { return false; }
    startIdx = (startIdx - 1) % cap;
    data[startIdx] = val;
    count++;
    return true;
}

template <typename T>
bool dequeBlock<T>::popBack(T& outVal) {
    if (this->count == 0) { return false; }
    int lastIdx = (startIdx + count) % cap;
    outVal = data[lastIdx - 1];
    count--;
    return true;
}

template <typename T>
bool dequeBlock<T>::popFront(T& outVal) {
    if (this->count == 0) { return false; }
    outVal = data[startIdx];
    startIdx = (startIdx + 1) % cap;
    count--;
    return true;
}

template <typename T>
T& dequeBlock<T>::front() {
    return data[startIdx];
}

template <typename T>
T& dequeBlock<T>::back() {
    int lastIdx = (startIdx + count) % cap;
    return data[lastIdx - 1];
}

template <typename T>
T& dequeBlock<T>::operator[](int i) {
    return data[i];
}

template <typename T>
int dequeBlock<T>::size() const {
    return this->count;
}

template <typename T>
int dequeBlock<T>::capacity() const {
    return this->cap;
}

template <typename T>
bool dequeBlock<T>::isFull() const {
    return (this->count >= ((this->cap) - 1));
}

template <typename T>
bool dequeBlock<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
dequeBlock<T>* Deque<T>::makeBlock() {
    // creating a dequeBlock and returns it's pointer
    dequeBlock<T>* d = new dequeBlock<T>(blockCapacity);
    return d;
}

template <typename T>
void Deque<T>::growDirectoryIfNeeded() {
    // I need to reallocate in here
}

template <typename T>
Deque<T>::Deque(int blockCapacity) {
    this->blockCapacity = blockCapacity;
    this->totalCount = 1;
    this->directory = this->makeBlock(this->totalCount);
}

template <typename T>
Deque<T>::~Deque() {
    delete[] this->directory;
}

template <typename T>
void Deque<T>::pushBack(const T& val) {
    // Deque is a dequeBlock also and therefore it must have the variables a dequeblock has as well
}

template <typename T>
void Deque<T>::pushFront(const T& val) {}

template <typename T>
bool Deque<T>::popBack(T& outVal) {}

template <typename T>
bool Deque<T>::popFront(T& outVal) {}

template <typename T>
T& Deque<T>::front() {}

template <typename T>
T& Deque<T>::back() {}

template <typename T>
T& Deque<T>::operator[](int i) {}

template <typename T>
int Deque<T>::size() const {}

template <typename T>
bool Deque<T>::isEmpty() const {}
