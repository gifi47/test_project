//
// Created by gifi on 05.12.2021.
//

#include "Batch.h"

Batch::Batch(Mesh& mesh) {
    _vertex_count = mesh.GetIndexesSize();

    glGenVertexArrays(1, &_vertex_array_object);
    glGenBuffers(1, &_vertex_buffer_object);
    glGenBuffers(1, &_element_buffer_object);

    glBindVertexArray(_vertex_array_object);

    glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer_object);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mesh.GetVertexesSize(), mesh.GetVertexes(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _element_buffer_object);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(u_int32_t) * mesh.GetIndexesSize(), mesh.GetIndexes(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)nullptr);
    glEnableVertexAttribArray(0);

    /*glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texture_coord));
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texture_id));
    glEnableVertexAttribArray(3);

    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(4);*/

    glBindVertexArray(0);
}

void Batch::Render() const {
    glBindVertexArray(_vertex_array_object);
    glDrawElements(GL_TRIANGLES, _vertex_count, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}

Batch::~Batch() {
    if (_vertex_array_object != 0) {
        glDeleteBuffers(1, &_vertex_array_object);
    }
    if (_vertex_buffer_object != 0) {
        glDeleteBuffers(1, &_vertex_buffer_object);
    }
    if (_element_buffer_object != 0) {
        glDeleteBuffers(1, &_element_buffer_object);
    }
}

Batch::Batch() {
    /*std::cout << "hd\n";
    GLfloat verts[] = {
            0.0f, 0.5f, -2.0f,
            0.4f, -0.3f, -2.0f,
            -0.4f, -0.3f, -2.0f
    };
    std::cout << "g";
    GLuint inds[] = {0, 1, 2};
    _vertex_count = 3;
    std::cout << "f";

    glGenVertexArrays(1, &_vertex_array_object);
    glGenBuffers(1, &_vertex_buffer_object);
    glGenBuffers(1, &_element_buffer_object);

    glBindVertexArray(_vertex_array_object);

    glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer_object);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _element_buffer_object);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(inds), inds, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    std::cout << "hdend\n";*/
}
