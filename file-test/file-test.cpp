
#include <iostream>
#include <string>
#include <fstream>
#include "string_utils.h"
#include <windows.h>
#include <iterator>
#include <algorithm> 
#include <fstream>
#include <string>
#include <vector>
#include "FileUtils.h"
using namespace std;


void testRecursiveToChar ( const string str, const string delimeter) {
    vector<string> res;
    string_utils::toChar( str, delimeter, res, 0);
    
    for ( auto &ret : res ) {
        cout << ret << endl;
    }

}

void testIterationToChar ( const string str, const string delimeter) {
    vector<string> res;
    string_utils::toChar( str, delimeter, res);
    for ( auto &ret : res ) {
        cout << ret << endl;
    }
}

void dosomething( int vi) {
   vi++;
}


void forloop(vector<int> v) {
    for ( int i = 0; i < v.size(); i++ ) {
        dosomething(v[i]);
    }
}

void autoForLoop(vector<int> v) {
    for ( int vi : v) {
        dosomething( vi);
    }
}

void foreach(vector<int> v) {
    for_each(v.cbegin(), v.cend(), dosomething);
}

template<typename T>
struct functor {
    void operator()(const T &obj) {
        dosomething(obj);
    }
};

void foreachFunctor(vector<int> v) {
    for_each( v.cbegin(), v.cend(), functor<int>());
}

void foreachLambda( vector<int> v) {
    for_each(v.cbegin(), v.cend(), [](const int &val) -> void {dosomething(val);});
}

void iteratorLoop(vector<int> v) {
    auto end = v.end();
    for ( vector<int>::const_iterator iter = v.begin(); iter != end; iter++) {
        dosomething( *iter);
    }
}  


ULONGLONG testTime( void (*fun)(vector<int>), vector<int> v) {
    ULONGLONG start = GetTickCount64();
    fun(v);
    ULONGLONG end = GetTickCount64();
    cout << "Time cost: " << end - start << endl;
    return end - start;
}

void testVectorTraverse() {

    vector<int> v;

    for ( int i = 0; i < 200000; i++ ) {
        v.push_back(i);
    }

    void (*pfun)(vector<int> v);

    pfun = forloop;
    ULONGLONG fl_time = testTime(pfun, v);

    pfun = autoForLoop;
    ULONGLONG afl_time = testTime(pfun, v);

    pfun = iteratorLoop;
    ULONGLONG i_time = testTime(pfun, v);

    pfun = foreach;
    ULONGLONG fe_time = testTime(pfun, v);

    pfun = foreachFunctor;
    ULONGLONG fef_time = testTime(pfun, v);

    pfun = foreachLambda;
    ULONGLONG fel_time = testTime(pfun, v);

    cout << "for loop cost " << fl_time << endl;
    cout << "auto for loop cost " << afl_time << endl;
    cout << "foreach cost " << i_time << endl;
    cout << "for each  cost " << fe_time << endl;
    cout << "for each functor cost " << fef_time << endl;
    cout << "for each lambda cost " << fel_time << endl;
}

void testDeleteFile() {
    FileUtils::deleteLine("F:\\test.txt", "klm");
}

void testModifyFile() {
    FileUtils::modifyLine("F:\\test.txt", "klm", "123");
}

void testSetFile() {
    string line = FileUtils::getLine("F:\\test.txt", "klm");
    vector<string> res;
    string_utils::toChar(line, ",", res);
    for ( string str : res ) {
        cout << str <<endl;
    }

    string substr = res[1].substr(0, res[1].length());
    string newLine = res[0] + ", " + to_string(stod(substr)) + ");";
    FileUtils::writeLine("F:\\newTest.txt",newLine);
    
}

int main () {
    testSetFile();
}