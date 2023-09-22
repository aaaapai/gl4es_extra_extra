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

    if (!globals4es.vgpu_optimization) {
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_algebraic;
        //optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_constant_folding;
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_constant_propagation;
        //optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_constant_variable;
        //optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_constant_variable_unlinked;
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_copy_propagation_elements;
//        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_dead_code;
//        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_dead_code_local;
//        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_dead_code_unlinked;
//        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_dead_functions;
//        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_function_inlining;
//        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_if_simplification;
//        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_mat_op_to_vec;
//        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_optimize_swizzles;
//        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_optimize_redundant_jumps;
        //      optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_structure_splitting;
        optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_tree_grafting;
        //optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_vec_index_to_cond_assign;
        //optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_vec_index_to_swizzle;
        //optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_flatten_nested_if_blocks;
        //optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_conditional_discard;
        //optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_flip_matrices;
        //optimizationStruct.optimizationFlags &= ~GlslConvert::OptimizationFlags::OPT_vectorize;

        //optimizationStruct.optimizationFlags_Bis &= ~GlslConvert::OptimizationFlags_Bis::OPT_minmax_prune;
        optimizationStruct.optimizationFlags_Bis &= ~GlslConvert::OptimizationFlags_Bis::OPT_rebalance_tree;
        //optimizationStruct.optimizationFlags_Bis &= ~GlslConvert::OptimizationFlags_Bis::OPT_optimize_split_arrays;
        //optimizationStruct.optimizationFlags_Bis &= ~GlslConvert::OptimizationFlags_Bis::OPT_set_unroll_Loops;
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