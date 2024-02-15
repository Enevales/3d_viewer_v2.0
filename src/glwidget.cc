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
                                        "uniform mat4 model;"
                                        "uniform mat4 view;"
                                        "uniform mat4 projection;"
                                        "void main()\n"
                                        "{\n"
                                        "   gl_Position = view * projection * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
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
    
    
    glEnable(GL_DEPTH_TEST);
    shader_program_.bind();

    CreateBuffers();

    QMatrix4x4 view;
    view.setToIdentity();
    QMatrix4x4 projection;
    projection.setToIdentity();

    // projection.perspective(45.0f, 800/600, 0.1f, 100.0f);
    view.translate(0.0f, 0.0f, 0.0f);
    shader_program_.setUniformValue("projection", projection);
    shader_program_.setUniformValue("view", view);

    QMatrix4x4 model;
    model.setToIdentity();
    // model.ortho(0.0f, 1131, 0.0f, 1051, 0.1f, 100.0f);
    shader_program_.setUniformValue("model", model);


    DrawVertices();
    DrawEdges();
    ReleaseBuffers();

}

void GLWidget::CreateBuffers(){
    vertex_buffer_.create();
  vertex_buffer_.bind();
  vertex_buffer_.setUsagePattern(QOpenGLBuffer::StaticDraw);
  vertex_buffer_.allocate(vertices_, sizeof(float) * 1521);


  index_buffer_.create();
  index_buffer_.bind();
  index_buffer_.allocate(indices_, sizeof(unsigned int) * 2898); // 2898


  VAO_.create();
  VAO_.bind();

  index_buffer_.bind();
  vertex_buffer_.bind();
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

}

void GLWidget::DrawVertices(){
    glColor3d(0, 0, 1);
    glPointSize(5);
    glDrawArrays(GL_POINTS, 0, 507);

}

void GLWidget::DrawEdges(){
  index_buffer_.bind();
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glDrawElements(GL_TRIANGLES, 2898, GL_UNSIGNED_INT, nullptr);

}


void GLWidget::ReleaseBuffers(){
    vertex_buffer_.release();
    index_buffer_.release();
    VAO_.release();
}

void GLWidget::set_vertices(float *vertices){
    vertices_ = vertices;
}

void GLWidget::set_vertices_num(int num){
    num_of_vertices_ = num;
}

void GLWidget::set_indices(unsigned int *indices){
    indices_ = indices;
}
void GLWidget::set_indices_num(int num){
    num_of_edges_ = num;
}

GLWidget::~GLWidget()
{
    makeCurrent();
    VAO_.destroy();
    vertex_buffer_.destroy();
    
    delete ui;
}
