// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prioritet(char oper) {
    if (oper == '+' || oper == '-') return 1;
    if (oper == '*' || oper == '/') return 2;
    return 0;
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> stack;
    std::string rez = "";
    for (int i = 0; i < inf.size(); i++) {
        char c = inf[i];
        if (c == ' ') continue;
        if (c >= '0' && c <= '9') {
            while (i < inf.size() && inf[i] >= '0' && inf[i] <= '9') {
                rez += inf[i];
                i++;
            }
            rez += ' ';
            i--;
        }
        else if (c == '(') {
            stack.push(c);
        }
        else if (c == ')') {
            while (stack.get() != '(') {
                rez += stack.get();
                rez += ' ';
                stack.pop();
            }
            stack.pop();  
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {

            while (!stack.isEmpty() && stack.get() != '(' && prioritet(stack.get()) >= prioritet(c)) {
                rez += stack.get();
                rez += ' ';
                stack.pop();
            }
            stack.push(c);  
        }
    }
    while (!stack.isEmpty()) {
        rez += stack.get();
        rez += ' ';
        stack.pop();
    }
    if (rez.size() > 0 && rez[rez.size() - 1] == ' ') {
        rez.pop_back();
    }
    return rez;
}

int eval(const std::string& pref) {
    TStack<int, 100> stack;

    for (int i = 0; i < pref.size(); i++) {
        char c = pref[i];
        if (c == ' ') continue;

        if (c >= '0' && c <= '9') {
            int num = 0;
            while (i < pref.size() && pref[i] >= '0' && pref[i] <= '9') {
                num = num * 10 + (pref[i] - '0');
                i++;
            }
            stack.push(num);
            i--;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = stack.get(); stack.pop();
            int a = stack.get(); stack.pop();
            if (c == '+') stack.push(a + b);
            if (c == '-') stack.push(a - b);
            if (c == '*') stack.push(a * b);
            if (c == '/') stack.push(a / b);
        }
    }
    return stack.get();
}
