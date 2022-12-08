//
// Created by yxd on 2022/12/8.
//

#include "CLoader.h"
#include "LoadFlag.h"
#include <iostream>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <vector>
#include <io.h>

using namespace std;
using namespace chrono;

void getFiles(string path, string exd, vector<string> &files) {
    long hFile = 0;
    struct _finddata_t file_info;
    string temp;
    if ((hFile = _findfirst(temp.assign(path).append("/*" + exd).c_str(), &file_info)) != -1) {
        do {
            files.push_back(temp.assign(path).append("/").append(file_info.name));
        } while (_findnext(hFile, &file_info) == 0);
        _findclose(hFile);
    }
}

bool LoadExcel(string strPath, bool excesql, LoadFlag *lf) {
    //fopen()
}


bool CLoader::LoadFromExcel() {
    cout << "LoadFromExcel start!" << endl;
    auto start = system_clock::now();
    vector<string> strFiles;
    string exd = ".xlsx";
    getFiles(GetPath() + "/excel/", exd, strFiles);

    LoadFlag lf[strFiles.size()];
    int c = 0;
    for (auto &strPath : strFiles) {
        LoadFlag *i = new LoadFlag();
        lf[c++] = *i;
        string::size_type iStart = strPath.find_last_of('/');
        string::size_type iEnd = strPath.find_last_of('.');
        string strTmp = strPath;
        string name = strTmp.substr(iStart + 1, iEnd - iStart - 1);

        if (name == "UILanguage" || name == "Language") {
            i->SetState(2);
        } else if (!LoadExcel(strPath, false, i)) {
            cout << "import xml : " << strPath << " failed" << endl;
            return false;
        }
    }


    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "LoadFromExcel end! " << double(duration.count()) * microseconds::period::num / microseconds::period::den
         << "s" << endl;
    return true;
}
