#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <memory>
#include <optional>
#include <any>

using namespace std;

class yaml_dict {
private:
    optional<int> num;
    optional<string> str;
    map<string, yaml_dict> dict;

public:
    yaml_dict() {};

    yaml_dict& operator=(const yaml_dict& other);
    yaml_dict& operator=(const int& other);
    yaml_dict& operator=(const string& other);

    yaml_dict& operator[](string key);

    string get_string() const;
    any get_value() const;
    

    void write(string filepath);
};