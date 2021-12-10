//
// Created by gifi on 05.12.2021.
//

#ifndef TEST_PROJECT_MESH_H
#define TEST_PROJECT_MESH_H


#include <iostream>
#include <cstring>

class Mesh {
public:
    Mesh();
    Mesh(const Mesh& mesh);
    Mesh(float* vertexes, int32_t vertexes_size, u_int32_t* indexes, int32_t indexes_size);

    float* GetVertexes();
    u_int32_t* GetIndexes();
    int32_t GetVertexesSize() const;
    int32_t GetIndexesSize() const;

    ~Mesh();
private:
    float* _vertexes{};
    int32_t _vertexes_size{};
    u_int32_t* _indexes{};
    int32_t _indexes_size{};

};


#endif //TEST_PROJECT_MESH_H
