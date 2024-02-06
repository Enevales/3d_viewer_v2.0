#ifndef VIEWERCONTROLLER_H
#define VIEWERCONTROLLER_H

#include <QMainWindow>
#include "viewermodel.h"
#include "glwidget.h"

class ViewerController : public QWidget
{
    Q_OBJECT
public:
    explicit ViewerController(QWidget *parent = nullptr);
    ~ViewerController();
    void ProcessFile();
    void set_file_path(QString file_name);
    int get_vertices_num();
    int get_edges_num();
    void set_widget(GLWidget *widget);
    void get_vertices();

//    friend class GLWidget;
private:
    std::string file_path_;
    ViewerModel *model;
    GLWidget *widget_;
    int status_;
};

#endif // VIEWERCONTROLLER_H
