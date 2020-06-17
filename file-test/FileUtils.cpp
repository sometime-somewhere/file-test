#include "FileUtils.h"

string FileUtils::getLine(string filename, string param) {
    ifstream input(filename);
    if ( !input.is_open() ) { return string("");}
    string line = "";
    while ( getline(input, line) ) {
        if ( line.find(param) != string::npos ) {
            return line;
        }
    }
    input.close();
    return string("");
}

void FileUtils::writeLine(string filename, string line) {
    ofstream output(filename);
    if ( !output.is_open() ) {
        cout << "Error opening file"; exit (1);
        return ;
    }
    output << line;
    output.close();
}

void FileUtils::deleteLine(string filename, string target) {
    ifstream input(filename);
    
    if ( !input.is_open() ) { return ; }
    string line = "";
    string data = "";
    while ( getline(input, line) ) {
        if ( line.find(target, 0) != string::npos ) {
            continue;
        }
        data += line;
        data += "\n";
    }

    input.close();

    ofstream output(filename);
    output.flush();
    output << data;
    output.close();
}

void FileUtils::modifyLine(string filename, string targetLine, string newLine) {
    ifstream input(filename);
    if ( !input.is_open() ) {
        cout << "Fail to open file " << filename << endl;
        exit(-1);
    }
    string data = "";
    string line = "";
    while ( getline(input, line) ) {
        if ( line.find(targetLine) != string::npos ) {
            data += newLine;
            data += "\n";
        } else {
            data += line;
            data += "\n";
        }
    }
    input.close();

    ofstream output(filename);
    if ( !output.is_open() ) {
        cout << "Fail to open file " << filename << endl;
        exit(-1);
    }
    output.flush();
    output << data;
    output.close();
    
}
