//
// Created by maks on 03.01.2024.
//

#ifndef GL4ES_WRAPPER_BUFFER_COPIER_H
#define GL4ES_WRAPPER_BUFFER_COPIER_H
#include "../loader.h"
#include "../gl4es.h"
void buffer_copier_store(GLint x, GLint y, GLsizei w, GLsizei h);
void buffer_copier_release(GLenum target, GLuint what_target, GLint x, GLint y, GLint w, GLint h);

#endif //GL4ES_WRAPPER_BUFFER_COPIER_H
