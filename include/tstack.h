// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T, int size>
class TStack {
  private:
    static constexpr int kSize = size;
    T arr[kSize];
    int top;

  public:
    TStack() : top(-1) {}
    bool isEmpty() const {
        return top == -1;
    }
    void push(const T& item) {
        if (top < kSize - 1)
            arr[++top] = item;
        else
            throw std::string("Full");
    }
    T get() const {
        if (top < 0)
            throw std::string("Empty!");
        else
            return arr[top];
    }
    void pop() {
        if (top < 0)
            throw std::string("Empty!");
        else
            --top;
    }
};

#endif  // INCLUDE_TSTACK_H_
