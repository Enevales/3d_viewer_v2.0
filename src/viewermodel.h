#ifndef VIEWERMODEL_H
#define VIEWERMODEL_H

#include <vector>
#include <fstream>
#include <sstream>

#define DIM 3

struct Vertex{
    float x_axis;
    float y_axis;
    float z_axis;
};

class ViewerModel
{
public:
    ViewerModel();
   //  ~ViewerModel();
    int ParseObjectFile(std::string file_path);
    void ClearModel();
    int get_vertices_num();
    int get_edges_num();
   std::vector<Vertex> &get_vertices();
   
private:
    std::vector<Vertex> vertices_;
    std::vector<unsigned int> indices_;
};



#endif // VIEWERMODEL_H
