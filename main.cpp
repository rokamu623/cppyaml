#include "yaml.cpp"
#include <any>

int main(void) {
    yaml_dict y;
    y["a"] = "a";
    y["b"] = 2;
    y["c"] = 3;
    y["d"]["da"] = 1;
    y["d"]["db"] = "db";
    y["d"] = 1;
    y["b"]["ba"] = 1;
    y["b"]["ba"]["baa"] = "a";
    y.write("./output.yaml");
    cout <<  any_cast<string>(y["a"].get_value()) << endl;
    return 0;
}