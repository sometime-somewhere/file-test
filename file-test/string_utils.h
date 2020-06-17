#pragma once
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class string_utils {
public:
    static void toChar(const string &str, const string &delimeter, vector<string> &res);
    static void toChar(const string &str, const string &delimeter, vector<string> &res, size_t pos);
};

