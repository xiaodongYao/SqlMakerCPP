#include <iostream>
#include <fstream>
#include "CLoader.h"
#include <string>
#include <cstdio>
#include <direct.h>

using namespace std;

bool exists_test(const string &);

int main() {
    auto *loader = new CLoader();
    string filePath = loader->GetPath() + "data";
    char *file = (char *) filePath.data();
    if (exists_test(filePath)) {
        remove(file);
    }
    mkdir(file);
    try {
        if (!loader->LoadFromExcel()) {
            return 0;
        }
    } catch (const char *s) {
        cout << s << endl;
        cin.get();
    }
    std::cout << "success!~" << std::endl;
    cin.get();
}


inline bool exists_test(const string &name) {
    ifstream f(name.c_str());
    return f.good();
}
