//
// Created by adeel on 5/9/2020.
//

#ifndef INTERPRETER_INTERPRET_H
#define INTERPRETER_INTERPRET_H

#include <string>
#include <map>

using namespace std;

void text();
void output();
int parseInt();
bool isExpressionMember(const char* token);
void var(map<string,int> &varList);
void set(map<string,int> &varList);

#endif //INTERPRETER_INTERPRET_H
