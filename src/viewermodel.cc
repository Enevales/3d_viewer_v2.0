#include "viewermodel.h"

ViewerModel::ViewerModel()
{

}

int ViewerModel::ParseObjectFile(std::string file_path){
    std::ifstream f(file_path);
    if (!f.is_open())
        return false;


    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);

        std::stringstream s;
        s << line;

        char junk;

        if (line[0] == 'v')
        {
            Vertex v;
            s >> junk >> v.x_axis >> v.y_axis >> v.z_axis;
            vertices_.push_back(v);
        }
        if (line[0] == 'f')
        {
            s >> junk;
            unsigned int index;
            while(s >> index){
                indices_.push_back(index);
            }
        }
    }
    return true;
}


int ViewerModel::get_vertices_num(){
    return vertices_.size();
}

int ViewerModel::get_edges_num(){
    return indices_.size();
}

std::vector<Vertex> &ViewerModel::get_vertices(){
   return vertices_;
}
