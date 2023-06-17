LOCAL_PATH := $(call my-dir)

###########################
#
# GL static library
#
###########################

include $(CLEAR_VARS)

LOCAL_MODULE := gl4es_114

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES) -DBCMHOST

LOCAL_SRC_FILES := \
	src/glsl_optimizer/src/code/c_wrapper.cpp \
	src/glsl_optimizer/src/code/ir_print_glsl_visitor.cpp \
	src/glsl_optimizer/src/code/optimizer.cpp \
	src/glsl_optimizer/src/code/GlslConvert.cpp \
	src/glsl_optimizer/src/code/ir_print_ir_visitor.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_redundant_jumps.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_validate.cpp \
	src/glsl_optimizer/src/compiler/glsl/link_uniform_initializers.cpp \
	src/glsl_optimizer/src/compiler/glsl/hir_field_selection.cpp \
	src/glsl_optimizer/src/compiler/glsl/builtin_variables.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_copy_propagation_elements.cpp \
	src/glsl_optimizer/src/compiler/glsl/glsl_parser.cpp \
	src/glsl_optimizer/src/compiler/glsl/generate_ir.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_array_refcount.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_instructions.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_array_splitting.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_vec_index_to_swizzle.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_discard_flow.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_dead_builtin_variables.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_offset_array.cpp \
	src/glsl_optimizer/src/compiler/glsl/link_varyings.cpp \
	src/glsl_optimizer/src/compiler/glsl/glsl_parser_extras.cpp \
	src/glsl_optimizer/src/compiler/glsl/builtin_types.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_constant_propagation.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_algebraic.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_named_interface_blocks.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_cs_derived.cpp \
	src/glsl_optimizer/src/compiler/glsl/link_uniforms.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_structure_splitting.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_tree_grafting.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_constant_expression.cpp \
	src/glsl_optimizer/src/compiler/glsl/ast_type.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_jumps.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_if_simplification.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_const_arrays_to_uniforms.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_vector_insert.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_conditional_discard.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_hierarchical_visitor.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_builder.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_if_to_cond_assign.cpp \
	src/glsl_optimizer/src/compiler/glsl/ast_array_index.cpp \
	src/glsl_optimizer/src/compiler/glsl/propagate_invariance.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_hv_accept.cpp \
	src/glsl_optimizer/src/compiler/glsl/link_interface_blocks.cpp \
	src/glsl_optimizer/src/compiler/glsl/ast_to_hir.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_function_detect_recursion.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_packing_builtins.cpp \
	src/glsl_optimizer/src/compiler/glsl/loop_analysis.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_rvalue_visitor.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_clone.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_vertex_id.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_flip_matrices.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_dead_code.cpp \
	src/glsl_optimizer/src/compiler/glsl/link_uniform_block_active_visitor.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_shared_reference.cpp \
	src/glsl_optimizer/src/compiler/glsl/s_expression.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_constant_variable.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_reader.cpp \
	src/glsl_optimizer/src/compiler/glsl/loop_unroll.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_noise.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_ubo_reference.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_equals.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_vector.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_function_can_inline.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_texture_projection.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_vec_index_to_cond_assign.cpp \
	src/glsl_optimizer/src/compiler/glsl/standalone_scaffolding.cpp \
	src/glsl_optimizer/src/compiler/glsl/link_uniform_blocks.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_function_inlining.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_constant_folding.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_mat_op_to_vec.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_blend_equation_advanced.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_expression_flattening.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_vectorize.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_dead_code_local.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_flatten_nested_if_blocks.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_set_program_inouts.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_function.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_buffer_access.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_variable_refcount.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_vector_derefs.cpp \
	src/glsl_optimizer/src/compiler/glsl/builtin_functions.cpp \
	src/glsl_optimizer/src/compiler/glsl/linker_util.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_distance.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_rebalance_tree.cpp \
	src/glsl_optimizer/src/compiler/glsl/linker.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_dead_functions.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_variable_index_to_cond_assign.cpp \
	src/glsl_optimizer/src/compiler/glsl/glsl_symbol_table.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_dead_builtin_varyings.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_subroutine.cpp \
	src/glsl_optimizer/src/compiler/glsl/link_atomics.cpp \
	src/glsl_optimizer/src/compiler/glsl/glsl_lexer.cpp \
	src/glsl_optimizer/src/compiler/glsl/link_functions.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_tess_level.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_int64.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_discard.cpp \
	src/glsl_optimizer/src/compiler/glsl/string_to_uint_map.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_swizzle.cpp \
	src/glsl_optimizer/src/compiler/glsl/ast_function.cpp \
	src/glsl_optimizer/src/compiler/glsl/ast_expr.cpp \
	src/glsl_optimizer/src/compiler/glsl/standalone.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_print_visitor.cpp \
	src/glsl_optimizer/src/compiler/glsl/opt_minmax.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_basic_block.cpp \
	src/glsl_optimizer/src/compiler/glsl/ir_builder_print_visitor.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_output_reads.cpp \
	src/glsl_optimizer/src/compiler/glsl/lower_packed_varyings.cpp \
	src/glsl_optimizer/src/compiler/glsl_types.cpp \
	src/glsl_optimizer/src/util/compat_layer.cpp \
	src/glsl_optimizer/src/util/sha1/sha1.c \
	src/glsl_optimizer/src/util/half_float.c \
	src/glsl_optimizer/src/util/blob.c \
	src/glsl_optimizer/src/util/strtod.c \
	src/glsl_optimizer/src/util/hash_table.c \
	src/glsl_optimizer/src/util/softfloat.c \
	src/glsl_optimizer/src/util/set.c \
	src/glsl_optimizer/src/util/mesa-sha1.c \
	src/glsl_optimizer/src/util/string_buffer.c \
	src/glsl_optimizer/src/util/ralloc.c \
	src/glsl_optimizer/src/mesa/main/extensions_table.c \
	src/glsl_optimizer/src/mesa/main/imports.c \
	src/glsl_optimizer/src/mesa/program/symbol_table.c \
	src/glsl_optimizer/src/mesa/program/prog_parameter.c \
	src/glsl_optimizer/src/compiler/glsl/glcpp/glcpp.c \
	src/glsl_optimizer/src/compiler/glsl/glcpp/glcpp-parse.c \
	src/glsl_optimizer/src/compiler/glsl/glcpp/pp.c \
	src/glsl_optimizer/src/compiler/glsl/glcpp/pp_standalone_scaffolding.c \
	src/glsl_optimizer/src/compiler/glsl/glcpp/glcpp-lex.c \
	src/glsl_optimizer/src/compiler/shader_enums.c \
	src/gl/arbconverter.c \
	src/gl/arbgenerator.c \
	src/gl/arbhelper.c \
	src/gl/arbparser.c \
	src/gl/array.c \
	src/gl/blend.c \
	src/gl/blit.c \
	src/gl/buffers.c \
	src/gl/build_info.c \
	src/gl/debug.c \
	src/gl/decompress.c \
	src/gl/depth.c \
	src/gl/directstate.c \
	src/gl/drawing.c \
	src/gl/enable.c \
	src/gl/envvars.c \
	src/gl/eval.c \
	src/gl/face.c \
	src/gl/fog.c \
	src/gl/fpe.c \
	src/gl/fpe_cache.c \
	src/gl/fpe_shader.c \
	src/gl/framebuffers.c \
	src/gl/gl_lookup.c \
	src/gl/getter.c \
	src/gl/gl4es.c \
	src/gl/glstate.c \
	src/gl/hint.c \
	src/gl/init.c \
	src/gl/light.c \
	src/gl/line.c \
	src/gl/list.c \
	src/gl/listdraw.c \
	src/gl/listrl.c \
	src/gl/loader.c \
	src/gl/logs.c \
	src/gl/matrix.c \
	src/gl/matvec.c \
	src/gl/oldprogram.c \
	src/gl/pixel.c \
	src/gl/planes.c \
	src/gl/pointsprite.c \
	src/gl/preproc.c \
	src/gl/program.c \
	src/gl/queries.c \
	src/gl/raster.c \
	src/gl/render.c \
	src/gl/samplers.c \
	src/gl/shader.c \
	src/gl/shaderconv.c \
	src/gl/shader_hacks.c \
	src/gl/stack.c \
	src/gl/stencil.c \
	src/gl/string_utils.c \
	src/gl/stubs.c \
	src/gl/texenv.c \
	src/gl/texgen.c \
	src/gl/texture.c \
	src/gl/texture_compressed.c \
	src/gl/texture_params.c \
	src/gl/texture_read.c \
	src/gl/texture_3d.c \
	src/gl/uniform.c \
	src/gl/vertexattrib.c \
	src/gl/wrap/gl4eswraps.c \
	src/gl/wrap/gles.c \
	src/gl/wrap/glstub.c \
	src/gl/math/matheval.c \
	src/glx/hardext.c \
	src/glx/glx.c \
	src/glx/lookup.c \
	src/glx/gbm.c \
	src/glx/streaming.c \
	src/gl/vgpu/shaderconv.c \
    src/gl/iProtecc/iprotecc_string.c \




LOCAL_CPP_FEATURES := exceptions

LOCAL_CPPFLAGS = -std=gnu++20

LOCAL_CFLAGS += -g -funwind-tables -Ofast -ffast-math -mllvm -polly -flto -fvisibility=hidden -include include/android_debug.h
LOCAL_CFLAGS += -DNOX11
LOCAL_CFLAGS += -DNO_GBM
#LOCAL_CFLAGS += -DNO_INIT_CONSTRUCTOR
LOCAL_CFLAGS += -DDEFAULT_ES=2

LOCAL_CFLAGS += -std=gnu2x
LOCAL_CFLAGS += -D_LIB
LOCAL_CFLAGS += -DNOMINMAX
LOCAL_CFLAGS += -D_USE_MATH_DEFINES
LOCAL_CFLAGS += -D__STDC_NO_THREADS__
LOCAL_CFLAGS += -D__STDC_LIMIT_MACROS
LOCAL_CFLAGS += -D__STDC_FORMAT_MACROS
LOCAL_CFLAGS += -D__STDC_CONSTANT_MACROS
LOCAL_CFLAGS += -DUTIL_ARCH_LITTLE_ENDIAN
LOCAL_CFLAGS += -DUNIX

//TODO: maybe temporary?
LOCAL_CFLAGS += -Wno-typedef-redefinition -Wno-dangling-else

LOCAL_LDLIBS := -llog
#building as a static lib

include $(BUILD_SHARED_LIBRARY)
