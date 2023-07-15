//
// Created by serpentspirale on 17/06/23.
//

#include <cstring>
#include "c_wrapper.h"
#include "GlslConvert.h"

#ifdef __cplusplus
extern "C" {
#endif

GlslConvert::OptimizationStruct optimizationStruct {}; // Default struct with everything enabled

char *optimize_shader(char *source, int *sourceLength, int isVertex, int vGLSLVersion, int vTargetGLSLVersion) {



    /*optimizationStruct.optimizationFlags = (GlslConvert::OptimizationFlags)~(GlslConvert::OptimizationFlags::OPT_dead_code
            | GlslConvert::OptimizationFlags::OPT_dead_code_local
            | GlslConvert::OptimizationFlags::OPT_dead_code_unlinked
            | GlslConvert::OptimizationFlags::OPT_dead_functions);*/
    //optimizationStruct.optimizationFlags = (GlslConvert::OptimizationFlags)0;
    //optimizationStruct.optimizationFlags_Bis = (GlslConvert::OptimizationFlags_Bis)0;
    //optimizationStruct.instructionToLowerFlags = (GlslConvert::InstructionToLowerFlags)0;
    //std::string shader_source = std::string(source);
    char * optimized_shader = GlslConvert::Instance().Optimize(
            source,
            isVertex ? GlslConvert::MESA_SHADER_VERTEX : GlslConvert::MESA_SHADER_FRAGMENT,
            GlslConvert::API_OPENGL_COMPAT,
            GlslConvert::LANGUAGE_TARGET_GLSL,
            vGLSLVersion,
            vTargetGLSLVersion,
            true,
            optimizationStruct
            );

    return optimized_shader;
}

#ifdef __cplusplus
}
#endif