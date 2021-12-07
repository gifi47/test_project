//
// Created by gifi on 05.12.2021.
//

#include "Mesh.h"

Mesh::Mesh(float *vertexes, int32_t vertexes_size, u_int32_t *indexes, int32_t indexes_size): _vertexes(vertexes),
    _vertexes_size(vertexes_size), _indexes(indexes), _indexes_size(indexes_size) {}

Mesh::Mesh() {

}

Mesh::~Mesh() {
    delete[] _vertexes;
    delete[] _indexes;
}

u_int32_t* Mesh::GetIndexes() {
    return _indexes;
}

float* Mesh::GetVertexes() {
    return _vertexes;
}

int32_t Mesh::GetVertexesSize() const {
    return _vertexes_size;
}

int32_t Mesh::GetIndexesSize() const {
    return _indexes_size;
}
