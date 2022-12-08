//
// Created by yxd on 2022/12/8.
//

#ifndef SQLMAKERCPP_CLOADER_H
#define SQLMAKERCPP_CLOADER_H

#include <string>
using namespace std;
class CLoader {
public:
    bool LoadFromExcel();

    string GetPath() { return cfgRootPath; }
private:
    string cfgRootPath = "../";
};


#endif //SQLMAKERCPP_CLOADER_H
