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
}

int ViewerController::get_vertices_num(){
    return model->get_vertices_num();
}

int ViewerController::get_edges_num(){
    return model->get_edges_num();
}

float *ViewerController::get_vertices(){
//    std::vector<Vertex> vertices = model->set_vertices();
//    float axis_values[vertices.size() * DIM];

//    for (size_t i = 0; i < vertices.size(); ++i) {
//        axis_values[i * DIM] = vertices[i].x_axis;
//        axis_values[i * DIM + 1] = vertices[i].y_axis;
//        axis_values[i * DIM + 2] = vertices[i].z_axis;
//    }
//     for (size_t i = 0; i < vertices.size() * DIM; ++i) {
//         std::cout << axis_values[i] << std::endl;
//    }
return 0;
}


ViewerController::~ViewerController()
{
    delete model;
}
