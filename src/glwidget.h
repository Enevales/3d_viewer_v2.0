#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glew.h>
#include <GL/glut.h>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class GLWidget;
}
QT_END_NAMESPACE

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

        void initializeGL() override;
        void resizeGL(int w, int h) override;
        void paintGL() override;
private:
    Ui::GLWidget *ui;
};

// const char *vertexShaderSource = "#version 330 core\n"
//     "layout (location = 0) in vec3 aPos;\n"
//     "void main()\n"
//     "{\n"
//     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//     "}\0";
// const char *fragmentShaderSource = "#version 330 core\n"
//     "out vec4 FragColor;\n"
//     "void main()\n"
//     "{\n"
//     "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//     "}\n\0";

class Shaders{
    protected:
        Shaders(const char *vertex_shader_source, const char *fragment_shader_source){
            std::cout << "vertex shaders compiled!" << std::endl;
            std::cout << "fragment shaders compiled!" << std::endl;
            // vertex_shader_ = glCreateShader(GL_VERTEX_SHADER);
            // glShaderSource(vertex_shader_, 1, &vertex_shader_source, NULL);
            // glCompileShader(vertex_shader_);

            // fragment_shader_ = glCreateShader(GL_FRAGMENT_SHADER);
            // glShaderSource(fragment_shader_, 1, &fragment_shader_source, NULL);
            // glCompileShader(fragment_shader_);
            
            // shader_program_ = glCreateProgram();

            // glAttachShader(shader_program_, vertex_shader_);
            // glAttachShader(shader_program_, fragment_shader_);
            // glLinkProgram(shader_program_);
        }
        ~Shaders(){
            std::cout << "shaders are destroyed!" << std::endl;
            // glDeleteShader(vertex_shader_);
            // glDeleteShader(fragment_shader_);
            // glDeleteProgram(shader_program_);
        }
        
    public:
        Shaders(Shaders &other) = delete;
        void operator=(const Shaders &) = delete;
        static Shaders* shaders_;
        static Shaders *GetInstance(const char *vertex_shader_source, const char *fragment_shader_source);

    private:
        unsigned int vertex_shader_;
        unsigned int fragment_shader_;
        unsigned int shader_program_;
};

#endif // GLWIDGET_H
