#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QWidget>
#include <QOpenGLWidget>

#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QMatrix4x4>


#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class GLWidget;
}
QT_END_NAMESPACE


class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    using QOpenGLWidget::QOpenGLWidget;
    explicit GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

    void set_vertices(float *vertices);
    void set_vertices_num(int num);
    void CreateBuffers();
    void DrawVertices();
    void ReleaseBuffers();
    
    protected:
        void initializeGL() override;
        void resizeGL(int w, int h) override;
        void paintGL() override;

        

        void initShaders();

private:
    Ui::GLWidget *ui;
    float *vertices_ = nullptr;
    int num_of_vertices_;
    QOpenGLShaderProgram shader_program_;
    QMatrix4x4 projection_;

    QOpenGLVertexArrayObject VAO_;
    QOpenGLBuffer vertex_buffer_ = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
};



#endif // GLWIDGET_H
