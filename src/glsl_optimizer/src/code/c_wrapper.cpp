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

    GlslConvert::OptimizationStruct optimizationStruct {}; // Default struct with everything enabled
    /*optimizationStruct.optimizationFlags = (GlslConvert::OptimizationFlags)~(GlslConvert::OptimizationFlags::OPT_dead_code
            | GlslConvert::OptimizationFlags::OPT_dead_code_local
            | GlslConvert::OptimizationFlags::OPT_dead_code_unlinked
            | GlslConvert::OptimizationFlags::OPT_dead_functions);*/
    //optimizationStruct.optimizationFlags = (GlslConvert::OptimizationFlags)0;
    //optimizationStruct.optimizationFlags_Bis = (GlslConvert::OptimizationFlags_Bis)0;
    //optimizationStruct.instructionToLowerFlags = (GlslConvert::InstructionToLowerFlags)0;

    std::string optimized_shader = GlslConvert::Instance().Optimize(
            shader_source,
            isVertex ? GlslConvert::MESA_SHADER_VERTEX : GlslConvert::MESA_SHADER_FRAGMENT,
            GlslConvert::API_OPENGL_COMPAT,
            GlslConvert::LANGUAGE_TARGET_GLSL,
            vGLSLVersion,
            optimizationStruct
            );

    char* copy_dest = (char*)malloc(optimized_shader.size()+1);
    strcpy(copy_dest, optimized_shader.c_str());

    return copy_dest;
}

#ifdef __cplusplus
}
#endif