//
// Created by serpentspirale on 17/06/23.
//



#ifndef GL4ES_C_WRAPPER_H
#define GL4ES_C_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

char *optimize_shader(char *source, int *sourceLength, int isVertex, int vGLSLVersion);

#ifdef __cplusplus
} /* extern C */
#endif


#endif //GL4ES_C_WRAPPER_H
