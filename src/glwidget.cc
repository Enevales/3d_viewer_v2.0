#include "glwidget.h"
#include "ui_glwidget.h"

#include <iostream>


GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::GLWidget)
{
    ui->setupUi(this);
}

void GLWidget::initShaders() {
  shader_program_.addShaderFromSourceCode(QOpenGLShader::Vertex,
                                        "#version 330 core\n"
                                        "layout (location = 0) in vec3 aPos;\n"
                                        "void main()\n"
                                        "{\n"
                                        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                        "}\0");

 shader_program_.addShaderFromSourceCode(QOpenGLShader::Fragment,
                                        "#version 330 core\n"
                                        "out vec4 FragColor;\n"
                                        "void main()\n"
                                        "{\n"
                                        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                        "}\n\0");
    if (!shader_program_.link())
        close();

    if (!shader_program_.bind())
        close();
    // shader_program_.log();

}


void GLWidget::initializeGL(){
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);
    
    initShaders();

}

void GLWidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);

    // qreal aspect = qreal(w) / qreal(h ? h : 1);
    // const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;

    // projection_.setToIdentity();

    // projection_.perspective(fov, aspect, zNear, zFar);

}
void GLWidget::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0.2f, 0.4f, 0);
    
    //  temporary 
    // if(vertices_ != nullptr) return;
    
    glEnable(GL_DEPTH_TEST);
    shader_program_.bind();

    //QMatrix4x4 matrix;
    // matrix.translate(0.0, 0.0, 0);

    //shader_program_.setUniformValue("mvp_matrix", projection_ * matrix);

//     VAO_.bind();


//     vertex_buffer_.create();
//   vertex_buffer_.bind();
//   vertex_buffer_.setUsagePattern(QOpenGLBuffer::StaticDraw);
//   vertex_buffer_.allocate(vertices_, sizeof(float) * 1521);
//   vertex_buffer_.release();

//   VAO_.create();
//   VAO_.bind();

//   vertex_buffer_.bind();
//   glEnableVertexAttribArray(0);
//   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

//       glColor3d(0, 0, 1);
//   glPointSize(5);
//    glDrawArrays(GL_POINTS, 0, 507);
   
//   vertex_buffer_.release();

//   VAO_.release();

    CreateBuffers();
    DrawVertices();
    ReleaseBuffers();

}

void GLWidget::CreateBuffers(){
    vertex_buffer_.create();
  vertex_buffer_.bind();
  vertex_buffer_.setUsagePattern(QOpenGLBuffer::StaticDraw);
  vertex_buffer_.allocate(vertices_, sizeof(float) * 1521);
  vertex_buffer_.release();

  VAO_.create();
  VAO_.bind();

  vertex_buffer_.bind();
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

}

void GLWidget::DrawVertices(){
    glColor3d(0, 0, 1);
    glPointSize(5);
    glDrawArrays(GL_POINTS, 0, 507);

}

void GLWidget::ReleaseBuffers(){
    vertex_buffer_.release();
    VAO_.release();
}

void GLWidget::set_vertices(float *vertices){
    vertices_ = vertices;
}

void GLWidget::set_vertices_num(int num){
    num_of_vertices_ = num;
}


GLWidget::~GLWidget()
{
    makeCurrent();
    VAO_.destroy();
    vertex_buffer_.destroy();
    
    delete ui;
}
