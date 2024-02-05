#include <gtest/gtest.h>
#include <ostream>
#include "../viewermodel.h"

#define EPS 1.0e-7
class ModelTest : public ::testing::Test {
protected:
  void SetUp() override {model = new ViewerModel();
  }

  void TearDown() override {
    delete model;
  }
  ViewerModel *model;
};

TEST_F(ModelTest, Parser_00) {
    model->ParseObjectFile("samples/monkey_3_points_in_polygon.obj");
    ASSERT_EQ(model->get_vertices_num(), 507);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}