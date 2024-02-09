#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GL_SILENCE_DEPRECATION
//#include <GL/glew.h>
//#include <GL/glut.h>
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

        void set_vertices(float *vertices);
private:
    Ui::GLWidget *ui;
    float *vertices_ = nullptr;
};

class Shaders{
    protected:
        Shaders(const char *vertex_shader_source, const char *fragment_shader_source){
            //  vertex_shader_ = glCreateShader(GL_VERTEX_SHADER);
            //  glShaderSource(vertex_shader_, 1, &vertex_shader_source, NULL);
            //  glCompileShader(vertex_shader_);

            //  fragment_shader_ = glCreateShader(GL_FRAGMENT_SHADER);
            //  glShaderSource(fragment_shader_, 1, &fragment_shader_source, NULL);
            //  glCompileShader(fragment_shader_);
            
            //  shader_program_ = glCreateProgram();

            //  glAttachShader(shader_program_, vertex_shader_);
            //  glAttachShader(shader_program_, fragment_shader_);
            //  glLinkProgram(shader_program_);
        }
        ~Shaders(){ // WHY WASN'T THE FUNCTION INVOKED??
            std::cout << "shaders are destroyed!" << std::endl;
            //  glDeleteShader(vertex_shader_);
            //  glDeleteShader(fragment_shader_);
            //  glDeleteProgram(shader_program_);
        }
        
    public:
        Shaders(Shaders &other) = delete;
        void operator=(const Shaders &) = delete;
        unsigned int get_shader_program();
        static Shaders* shaders_;
        static Shaders *GetInstance(const char *vertex_shader_source, const char *fragment_shader_source);

    private:
        unsigned int vertex_shader_;
        unsigned int fragment_shader_;
        unsigned int shader_program_;
};

#endif // GLWIDGET_H
