//
// Created by gifi on 06.12.2021.
//

#ifndef GAME_H
#define GAME_H


#include "World/Chunk.h"
#include "../Engine/Graphics/Batch.h"
#include "../Engine/Graphics/Shader.h"
#include "../Engine/Application/Application.h"

class Game: public Application {
public:
    explicit Game(const char* name);
    int8_t Loop() override;
    void Init();

private:
    Shader shader{};
    Chunk chunk{};
    Mesh mesh{};
    Batch batch{};
};

#endif //GAME_H
