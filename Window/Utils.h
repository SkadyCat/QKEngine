
#pragma once
#include <string>
#include <vector>
using namespace std;

std::string ltrim(const std::string &s);
std::string rtrim(const std::string &s);
std::string trim(const std::string &s);
string&  replace_all_distinct(string&  str, const string& old_value, const  string&  new_value);
vector<string> split(const string& str, const string& delim);
string getResourcesFolder();