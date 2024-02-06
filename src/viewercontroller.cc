#include "viewercontroller.h"
#include <iostream>  //temp

ViewerController::ViewerController(QWidget *parent)
    : QWidget{parent}
    , model(new ViewerModel)
{

}

void ViewerController::set_file_path(QString file_name){
    this->file_path_ = file_name.toStdString();

}

void ViewerController::ProcessFile(){
    status_ = model->ParseObjectFile(file_path_);
    get_vertices();
    widget_->paintGL();

}

int ViewerController::get_vertices_num(){
    return model->get_vertices_num();
}

int ViewerController::get_edges_num(){
    return model->get_edges_num();
}

void ViewerController::set_widget(GLWidget *widget){
    widget_ = widget;
}

void ViewerController::get_vertices(){
    std::vector<Vertex> vertices = model->get_vertices();

    float *axis_values = new float[vertices.size() * DIM];

    for (size_t i = 0; i < vertices.size(); ++i) {
        axis_values[i * DIM] = vertices[i].x_axis;
        axis_values[i * DIM + 1] = vertices[i].y_axis;
        axis_values[i * DIM + 2] = vertices[i].z_axis;
    }
    widget_->set_vertices(axis_values);

}


ViewerController::~ViewerController()
{
    delete model;
}
