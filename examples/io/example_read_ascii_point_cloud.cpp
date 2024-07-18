#include <pcl/io/ascii_io.h>


#include <pcl/visualization/pcl_visualizer.h>


int main(int argc, char** argv){
  if (argc != 2) return -1;
  pcl::console::setVerbosityLevel(pcl::console::VERBOSITY_LEVEL::L_VERBOSE);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_raw(new pcl::PointCloud<pcl::PointXYZ>);

  pcl::ASCIIReader reader;
  reader.setInputFields<pcl::PointXYZ> ();
  if(reader.read(argv[1], *cloud_raw) == -1){
    PCL_ERROR("Couldn't read file \n");
  }
  std::cout << cloud_raw->size() << std::endl;
  for (int l = 0; l < 100; ++l) {
    std::cout << cloud_raw->points[l].x << " ";
    std::cout << cloud_raw->points[l].y << " ";
    std::cout << cloud_raw->points[l].z << " \n";
  }

  pcl::visualization::PCLVisualizer viewer("Point Cloud Viewer");
  viewer.addPointCloud<pcl::PointXYZ>(cloud_raw, "cloud");
  //    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud");

  // 显示点云
  while (!viewer.wasStopped())
  {
    viewer.spinOnce(100);
  }
}

