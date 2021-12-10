//
// Created by gifi on 05.12.2021.
//

#include "Utils.h"

char* ReadFile(const std::string& name){
    std::ifstream fin(name, std::ios::in | std::ios::binary);
    if (fin) {
        fin.seekg(0, std::ios::end);
        int64_t length{fin.tellg()};
        fin.seekg(0, std::ios::beg);
        char *data{new char[length + 1]};
        fin.read(data, length);
        data[length] = '\0';
        fin.close();
        return data;
    }
    throw(errno);
}