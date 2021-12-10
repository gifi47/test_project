//
// Created by gifi on 06.12.2021.
//

#include "Chunk.h"

Chunk::Chunk(u_int8_t size_x, u_int8_t size_y, u_int8_t size_z):_size_x(size_x), _size_y(size_y), _size_z(size_z) {
    _data_size = size_x * size_y * size_z;
    _data = new u_int8_t[_data_size];
}

Chunk::Chunk() {
    _data = new u_int8_t[_data_size];
}

Mesh Chunk::GenerateMesh() {
    std::cout << "enter";
    float* vertexes{ new float[6 * 4 * 3 / 2 * _data_size]};
    u_int32_t* indexes{ new u_int32_t[6 * 6 / 2 * _data_size]};

    float* vertexes_ptr = vertexes;
    int32_t vertexes_count{0};

    u_int32_t* indexes_ptr = indexes;
    int32_t index{0};

    u_int8_t size_xy = _size_x * _size_y;
    for (u_int8_t x{0}; x < _size_x; ++x) {
        for (u_int8_t y{0}; y < _size_y; ++y) {
            for (u_int8_t z{0}; z < _size_z; ++z) {
                if (GetTileType(x, y, z) == 0){
                    if (x > 0 && GetTileType(x - 1, y, z) != 0){
                        //up left
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z;

                        //up right
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z + 1;

                        //down right
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z + 1;

                        //down left
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z;
                        vertexes_count+=4;

                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 1;
                        (*(indexes_ptr++)) = index + 2;

                        (*(indexes_ptr++)) = index + 3;
                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 2;
                        index += 6;
                    }
                    if (x < _size_x - 1 && GetTileType(x + 1, y, z) != 0){
                        //up left
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z + 1;

                        //up right
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z;

                        //down right
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z;

                        //down left
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z + 1;
                        vertexes_count+=4;

                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 1;
                        (*(indexes_ptr++)) = index + 2;

                        (*(indexes_ptr++)) = index + 3;
                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 2;
                        index += 6;
                    }
                    if (y > 0 && GetTileType(x, y - 1, z) != 0){
                        //up left
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z + 1;

                        //up right
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z + 1;

                        //down right
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z;

                        //down left
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z;
                        vertexes_count+=4;

                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 1;
                        (*(indexes_ptr++)) = index + 2;

                        (*(indexes_ptr++)) = index + 3;
                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 2;
                        index += 6;
                    }
                    if (y < _size_y - 1 && GetTileType(x, y + 1, z) != 0){
                        //up left
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z;

                        //up right
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z;

                        //down right
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z + 1;

                        //down left
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z + 1;
                        vertexes_count+=4;

                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 1;
                        (*(indexes_ptr++)) = index + 2;

                        (*(indexes_ptr++)) = index + 3;
                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 2;
                        index += 6;
                    }
                    if (z > 0 && GetTileType(x, y, z - 1) != 0){
                        //up left
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z;

                        //up right
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z;

                        //down right
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z;

                        //down left
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z;
                        vertexes_count+=4;

                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 1;
                        (*(indexes_ptr++)) = index + 2;

                        (*(indexes_ptr++)) = index + 3;
                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 2;
                        index += 6;
                    }
                    if (z < _size_z - 1 && GetTileType(x, y, z + 1) != 0){
                        //up left
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z + 1;

                        //up right
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y + 1;
                        (*(vertexes_ptr++)) = (float)z + 1;

                        //down right
                        (*(vertexes_ptr++)) = (float)x + 1;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z + 1;

                        //down left
                        (*(vertexes_ptr++)) = (float)x;
                        (*(vertexes_ptr++)) = (float)y;
                        (*(vertexes_ptr++)) = (float)z + 1;
                        vertexes_count+=4;

                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 1;
                        (*(indexes_ptr++)) = index + 2;

                        (*(indexes_ptr++)) = index + 3;
                        (*(indexes_ptr++)) = index;
                        (*(indexes_ptr++)) = index + 2;
                        index += 6;
                    }
                }
            }
        }
    }
    auto vertexes_cut = (float*)std::memcpy(new float[vertexes_count * 3], vertexes, vertexes_count * 3 * sizeof(float));

    delete[] vertexes;

    auto indexes_cut = (u_int32_t*)std::memcpy(new u_int32_t[index], indexes, index * sizeof(u_int32_t));
    for (int i = 0; i < vertexes_count * 3; i++){
        vertexes_cut[i] = (vertexes_cut[i] - 8.0f) * 0.1f;
    }

    delete[] indexes;

    std::cout << "success";

    return {vertexes_cut, vertexes_count * 3, indexes_cut, index};
}

u_int8_t Chunk::GetTileType(u_int8_t x, u_int8_t y, u_int8_t z) {
    return *(_data + x * _size_x * _size_y + y * _size_y + z);
}

void Chunk::SetTileType(u_int8_t x, u_int8_t y, u_int8_t z, u_int8_t tile_type) {
    *(_data + x * _size_x * _size_y + y * _size_y + z) = tile_type;
}

Chunk::~Chunk() {
    delete[] _data;
}

void Chunk::GenerateData() {
    for (u_int8_t x{0}; x < _size_x; ++x) {
        for (u_int8_t y{0}; y < _size_y; ++y) {
            for (u_int8_t z{0}; z < _size_z; ++z) {
                if (x > 4 && x < 12 && z > 4 && z < 12 && y != 8) {
                    SetTileType(x, y, z, 1);
                } else {
                    SetTileType(x, y, z, 0);
                }
            }
        }
    }
}

Chunk::Chunk(const Chunk &chunk){
    delete[] _data;
    _size_x = chunk._size_x;
    _size_y = chunk._size_y;
    _size_z = chunk._size_z;
    _data_size = _size_x * _size_y * _size_z;
    _data = (u_int8_t*)memcpy(new u_int8_t[_data_size], chunk._data, _data_size * sizeof(u_int8_t));
}
