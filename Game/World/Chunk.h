//
// Created by gifi on 06.12.2021.
//

#ifndef GAME_CHUNK_H
#define GAME_CHUNK_H


#include "../../Engine/Graphics/Mesh.h"
#include <iostream>
#include <cstring>

class Chunk {
public:
    Chunk();
    Chunk(const Chunk& chunk);
    Chunk(u_int8_t size_x, u_int8_t size_y, u_int8_t size_z);
    ~Chunk();
    Mesh GenerateMesh();
    void GenerateData();
private:
    u_int32_t _data_size{};
    u_int8_t _size_x{};
    u_int8_t _size_y{};
    u_int8_t _size_z{};
    u_int8_t* _data;

    u_int8_t GetTileType(u_int8_t x, u_int8_t y, u_int8_t z);
    void SetTileType(u_int8_t x, u_int8_t y, u_int8_t z, u_int8_t tile_type);
};


#endif //GAME_CHUNK_H
