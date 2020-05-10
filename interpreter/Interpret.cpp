//
// Created by adeel on 5/9/2020.
//

#include "Interpret.h"
#include "Parse.h"
#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include "exptree.hpp"

using namespace std;

map<string,int> variables;

void run() {
    read_next_token();
    while (next_token_type != END && !kill) {
        if (next_token_type == NAME || next_token_type == SYMBOL) {
            if (strcmp(next_token(), "text") == 0) {
                text();
            } else if (strcmp(next_token(), "output") == 0) {
                output();
            } else if (strcmp(next_token(), "//") == 0) {
                skip_line();
            } else if (strcmp(next_token(), "var") == 0) {
                var(variables);
            } else if (strcmp(next_token(), "set") == 0) {
                set(variables);
            }
        }
        read_next_token();
    }
}

void text() {
    read_next_token();
    string topPrint = next_token();
    cout << topPrint;
}

void output() {
    int toPrint = parseInt();
    cout << toPrint;
}

int parseInt() {
    vector<string> expr;
    while( (isExpressionMember(peek_next_token()) || strcmp(peek_next_token(), "//") == 0) && next_token_type != END) {
        read_next_token();
        if (strcmp(next_token(), "//") == 0)
            skip_line();
        else if (next_token_type == NAME) //check if variable name
            expr.emplace_back(to_string(variables[next_token()]));
        else if (strcmp(next_token(), "") != 0)
            expr.emplace_back(next_token());
    }
    ExpTree parser(expr);
    return parser.eval();
}

string getName() {
    while(strcmp(peek_next_token(), "//") == 0) {
        skip_line();
    }
    read_next_token();
    return next_token();
}

void var(map<string,int> &varList) {
    string name = getName();
    int val = parseInt();
    bool exists = ( varList.count(name) );
    if (exists) {
        cerr << "[WARNING] variable " << name << " incorrectly re-initialized" << endl;
        varList[name] = val;
    } else {
        varList.emplace(name, val);
    }

}

void set(map<string,int> &varList) {
    string name = getName();
    int val = parseInt();
    bool exists = ( varList.count(name) );
    if (exists) {
        varList[name] = val;
    } else {
        cerr << "[WARNING] variable " << name << " not declared" << endl;
        varList.emplace(name, val);
    }
}

bool isExpressionMember(const char* token) {
    if (strcmp(token, "*") == 0 || strcmp(token, "/") == 0 || strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "%") == 0) {
        return true;
    }
    if (strcmp(token, "&&") == 0 || strcmp(token, "||") == 0 || strcmp(token, "<") == 0 || strcmp(token, ">") == 0 || strcmp(token, "==") == 0 || strcmp(token, "!=") == 0) {
        return true;
    }
    if (strcmp(token, "<=") == 0 || strcmp(token, ">=") == 0 || strcmp(token, "!") == 0 || strcmp(token, "~") == 0) {
        return true;
    }
    if (variables.count(token))
        return true;
    for (int i=0; token[i]; i++) {
        if (!(token[i] >= '0' && token[i] <= '9'))
            return false;
    }
    return true;
}

int main() {
    set_input("test_grader.blip");
    run();
}
