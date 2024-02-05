#include "glwidget.h"
#include "ui_glwidget.h"

#include <iostream>
#define GL_SILENCE_DEPRECATION

GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::GLWidget)
{
    ui->setupUi(this);
    QSurfaceFormat format;
format.setDepthBufferSize(24);
format.setStencilBufferSize(8);
setFormat(format);
}


void GLWidget::initializeGL(){
}

void GLWidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
}
void GLWidget::paintGL(){
    const char *ty = "something";
    const char *tx = "something";
    //Shaders *shaders = Shaders::GetInstance(vertexShaderSource, fragmentShaderSource);
    //Shaders *shaders = Shaders::GetInstance(ty, tx);

}

Shaders *Shaders::shaders_;

Shaders *Shaders::GetInstance(const char *vertex_shader_source, const char *fragment_shader_source){
    if(shaders_ == nullptr){
        shaders_ = new Shaders(vertex_shader_source, fragment_shader_source);
    }
    return shaders_;
}

GLWidget::~GLWidget()
{
    delete ui;
}
