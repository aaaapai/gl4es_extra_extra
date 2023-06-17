//
// Created by serpentspirale on 17/06/23.
//

#include <cstring>
#include "c_wrapper.h"
#include "GlslConvert.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Version separated from C land */
char* resize_if_needed(char* pBuffer, int *size, int addsize) {
    char* p = pBuffer;
    int newsize = strlen(pBuffer)+addsize+1;
    if (newsize>*size) {
        //newsize += 100;
        p = (char*)realloc(pBuffer, newsize);
        *size=newsize;
    }
    return p;
}

char *optimize_shader(char *source, int *sourceLength, int isVertex, int vGLSLVersion) {
    std::string shader_source = std::string(source);

    std::string optimized_shader = GlslConvert::Instance().Optimize(
            shader_source,
            isVertex ? GlslConvert::MESA_SHADER_VERTEX : GlslConvert::MESA_SHADER_FRAGMENT,
            GlslConvert::API_OPENGL_COMPAT,
            GlslConvert::LANGUAGE_TARGET_GLSL,
            vGLSLVersion,
            GlslConvert::OptimizationStruct {}  // Default struct with everything enabled
            );

    source = resize_if_needed(source, sourceLength, (*sourceLength) - strlen(source) + 1 );
    strcpy(source, optimized_shader.c_str());

    return source;
}

#ifdef __cplusplus
}
#endif