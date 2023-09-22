//
// Created by serpentspirale on 17/06/23.
//

#include <cstring>
#include "c_wrapper.h"
#include "GlslConvert.h"
#include "../../../gl/init.h"

#ifdef __cplusplus
extern "C" {
#endif

GlslConvert::OptimizationStruct optimizationStruct {}; // Default struct with everything enabled

void apply_struct_settings(){
    static bool first;
    if (first) return;
    first = true;

    if (!globals4es.vgpu_lower_instructions) {
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_lower_discard;
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_lower_if_to_cond_assign;
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_lower_instructions;
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_lower_jumps;
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_lower_noise;
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_lower_quadop_vector;
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_lower_texture_projection;
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_lower_variable_index_to_cond_assign;

        optimizationStruct.optimizationFlags_Bis &= ~GlslConvert::OptimizationFlags_Bis::OPT_lower_vector_insert;
    }
}

char *optimize_shader(char *source, int isVertex, int vGLSLVersion, int vTargetGLSLVersion) {
    apply_struct_settings();
    GlslConvert& converter = GlslConvert::Instance();

    char * optimized_shader = converter.Optimize(
            source,
            isVertex ? GlslConvert::MESA_SHADER_VERTEX : GlslConvert::MESA_SHADER_FRAGMENT,
            GlslConvert::API_OPENGL_COMPAT,
            GlslConvert::LANGUAGE_TARGET_GLSL,
            vGLSLVersion,
            vTargetGLSLVersion,
            true,
            optimizationStruct
            );
    if(converter.Failed()) {
        printf("Shader conversion failed!\n%s\n", converter.GetLog().c_str());
        return nullptr;
    }
    return optimized_shader;
}

#ifdef __cplusplus
}
#endif