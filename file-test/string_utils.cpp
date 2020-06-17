#include "string_utils.h"

void string_utils::toChar(const string &str, const string &delimeter, vector<string> &res) {
    size_t pos = 0;
    size_t offset = str.find_first_of( delimeter, pos);
    while ( offset != string::npos ) {
        res.push_back(str.substr( pos, offset - pos));
        pos = offset + 1;
        offset = str.find_first_of( delimeter, pos);
    }
    if ( offset > pos ) {
        res.push_back(str.substr(pos, offset - pos));
    }
}

void string_utils::toChar(const string &str, const string &delimeter, vector<string> &res, size_t pos) {
    size_t offset = str.find_first_of( delimeter, pos);
    if ( offset != string::npos ) {
        res.push_back( str.substr( pos, offset - pos));
        toChar( str, delimeter, res, ++offset);
    }
}
