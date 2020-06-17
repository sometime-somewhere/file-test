#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class FileUtils {
public:
    static string getLine(string filename, string param);

    static void writeLine(string filename, string line);

    static void deleteLine(string filename, string line);

    static void modifyLine(string filename, string targetLine, string newLine);
};

