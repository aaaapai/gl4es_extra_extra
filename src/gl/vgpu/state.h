//
// Created by serpentspirale on 09/09/23.
//

#include "../gles.h"

#ifndef GL4ES_STATE_H
#define GL4ES_STATE_H

extern int MaxDrawBuffers;
extern int MaxColorAttachs;

extern GLfloat ClearColorValue[4];
extern GLfloat ClearDepthValue[4];
extern GLint ClearStencilValue[4];

extern GLenum Attachs[8];
extern int DrawBufs_Num;
extern GLenum DrawBufs[8];


#endif //GL4ES_STATE_H
