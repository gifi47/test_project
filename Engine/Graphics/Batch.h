//
// Created by gifi on 05.12.2021.
//

#ifndef TEST_PROJECT_BATCH_H
#define TEST_PROJECT_BATCH_H


#include "GL/glew.h"
#include "Mesh.h"

class Batch {
public:
    Batch();
    explicit Batch(Mesh& mesh);
    ~Batch();
    void Render() const;
private:
    GLuint _vertex_array_object{};
    GLuint _vertex_buffer_object{};
    GLuint _element_buffer_object{};

    int32_t _vertex_count{};
};


#endif //TEST_PROJECT_BATCH_H
