//
// Created by maks on 03.01.2024.
//

#include "buffer_copier.h"
static bool buffer_copier_is_init = false;
static GLuint tempfb;
static GLuint temp_texture;
static GLuint destfb;

void buffer_copier_init() {
    if(buffer_copier_is_init) return;
    LOAD_GLES(glBindTexture)
    LOAD_GLES(glTexParameteri)
    LOAD_GLES(glGenTextures)
    LOAD_GLES2_OR_OES(glGenFramebuffers)
    gles_glGenTextures(1, &temp_texture);
    gles_glGenFramebuffers(1, &tempfb);
    gles_glGenFramebuffers(1, &destfb);
    gles_glBindTexture(GL_TEXTURE_2D, temp_texture);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    buffer_copier_is_init = true;
}
void buffer_copier_store(GLint x, GLint y, GLsizei w, GLsizei h) {
    LOAD_GLES(glGetIntegerv)
    int current_texbind;
    gles_glGetIntegerv(GL_TEXTURE_BINDING_2D, &current_texbind);
    buffer_copier_init();
    LOAD_GLES(glBindTexture)
    LOAD_GLES(glTexImage2D)
    gles_glBindTexture(GL_TEXTURE_2D, temp_texture);
    gles_glTexImage2D(GL_TEXTURE_2D, 0,
                      GL_DEPTH_COMPONENT,
                      w, h, 0, GL_DEPTH_COMPONENT,
                      hardext.depth24 ? GL_UNSIGNED_INT : GL_UNSIGNED_SHORT,
                      NULL);
    gles_glBindTexture(GL_TEXTURE_2D, current_texbind);
    LOAD_GLES2_OR_OES(glBindFramebuffer)
    LOAD_GLES2_OR_OES(glFramebufferTexture2D)
    LOAD_GLES2(glBlitFramebuffer)
    gles_glBindFramebuffer(GL_DRAW_FRAMEBUFFER, tempfb);
    gles_glBindFramebuffer(GL_READ_FRAMEBUFFER, glstate->fbo.fbo_read->id);
    gles_glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, temp_texture, 0);
    gles_glBlitFramebuffer(x, y, x+w, y+h, 0, 0, w, h, GL_DEPTH_BUFFER_BIT, GL_NEAREST);
    gles_glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
    gles_glBindFramebuffer(GL_DRAW_FRAMEBUFFER, glstate->fbo.current_fb->id);
    return;
}
void buffer_copier_release(GLenum target, GLuint what_target, GLint x, GLint y, GLint w, GLint h) {
    if(!buffer_copier_is_init) return;
    gltexture_t* texture = glstate->texture.bound[glstate->texture.active][what_target];
    LOAD_GLES2_OR_OES(glBindFramebuffer)
    LOAD_GLES2_OR_OES(glFramebufferTexture2D)
    LOAD_GLES2(glBlitFramebuffer)
    gles_glBindFramebuffer(GL_DRAW_FRAMEBUFFER, destfb);
    gles_glBindFramebuffer(GL_READ_FRAMEBUFFER, tempfb);
    gles_glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, target, texture->glname, 0);
    gles_glBlitFramebuffer(0, 0, w, h, x, y, x+w, y+h, GL_DEPTH_BUFFER_BIT, GL_NEAREST);
    gles_glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, 0, 0);
    gles_glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
    gles_glBindFramebuffer(GL_DRAW_FRAMEBUFFER, glstate->fbo.current_fb->id);
    return;
}
