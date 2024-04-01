#include "yaml.hpp"

yaml_dict& yaml_dict::operator=(const yaml_dict& other)
{
    dict = other.dict;
    num = nullopt;
    str = nullopt;

    return *this;
}
yaml_dict& yaml_dict::operator=(const int& other)
{
    num = other;
    str = nullopt;
    dict = map<string, yaml_dict>();

    return *this;
}
yaml_dict& yaml_dict::operator=(const string& other)
{
    str = other;
    num = nullopt;
    dict = map<string, yaml_dict>();

    return *this;
}

yaml_dict& yaml_dict::operator[](string key)
{
    return dict[key];
};

string yaml_dict::get_string() const {
    if (num.has_value())
        return to_string(num.value());
    if (str.has_value())
        return "\"" + str.value() + "\"";

    string str;
    str += "{\n";

    for (const auto& [key, value] : dict)
        str += "  \"" + key + "\": " + regex_replace(value.get_string(), regex("\n"), "\n  ") + ",\n";

    str += "}";
    return str;
};
any yaml_dict::get_value() const {
    if (num.has_value())
        return num.value();
    if (str.has_value())
        return str.value();

    return dict;
}

void yaml_dict::write(string filepath) {
    ofstream ofs(filepath);
    ofs << get_string() << endl;
    ofs.close();
};