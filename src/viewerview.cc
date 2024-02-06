#include "viewerview.h"
#include "./ui_viewerview.h"
#include "glwidget.h"
#include <QFileDialog>
ViewerView::ViewerView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewerView)
    , controller(new ViewerController)
{
    ui->setupUi(this);


    GLWidget *widget = new GLWidget;
    ui->gridLayout->addWidget(widget);

    controller->set_widget(widget);

    QPushButton *file_button = ViewerView::findChild<QPushButton *>("pushButton");
    connect(file_button, SIGNAL(released()), this, SLOT(LoadFile()));
}

ViewerView::~ViewerView()
{

    delete ui;
}


void ViewerView::LoadFile()
{
    QString path = QFileDialog::getOpenFileName(this, "Add file", "C://", tr("3D Model Files (*.obj)"));
    ui->file_line->setText(path);
    controller->set_file_path(path);

    QFileInfo file_path(path);
    QString file_name = file_path.fileName();
    ui->filename_label->setText(file_name);



    controller->ProcessFile();
    ui->vertices_num->setText(QString::number(controller->get_vertices_num()));
    ui->edges_num->setText(QString::number(controller->get_edges_num()));
    // TEMPORARY

//    GLWidget *widget = new GLWidget;
//    ui->gridLayout->addWidget(widget);
}

