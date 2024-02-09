#include "glwidget.h"
#include "ui_glwidget.h"

#include <iostream>


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

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

void GLWidget::initializeGL(){
}

void GLWidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
}
void GLWidget::paintGL(){

//     Shaders* shaders
//         = Shaders::GetInstance(vertexShaderSource, fragmentShaderSource);
   
//    float vertices[] = {
//        0, 0, 0.5f,
//        0.5f, -0.5f, -0.5f,
//        -0.5f, -0.5f, -0.5f,
//        -0.5f, 0.5f, -0.5f,

//    };
//     unsigned int VBO, VAO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);

//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);


//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);


//     glClearColor(0, 0.2f, 0.4f, 0);
//     glClear(GL_COLOR_BUFFER_BIT);

//     glUseProgram(shaders->get_shader_program());
//     glBindVertexArray(VAO);

//     glDrawArrays(GL_POINTS, 0, 4);

//     glDeleteVertexArrays(1, &VAO);
//     glDeleteBuffers(1, &VBO);
}

void GLWidget::set_vertices(float *vertices){
    vertices_ = vertices;
}

Shaders *Shaders::shaders_;

Shaders *Shaders::GetInstance(const char *vertex_shader_source, const char *fragment_shader_source){
    if(shaders_ == nullptr){
        shaders_ = new Shaders(vertex_shader_source, fragment_shader_source);
    }
    return shaders_;
}

unsigned int Shaders::get_shader_program(){
    return shader_program_;
}

GLWidget::~GLWidget()
{
    delete ui;
}
