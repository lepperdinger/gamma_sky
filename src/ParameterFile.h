// Author: Stefan Lepperdinger
#ifndef GAMMA_SKY_SRC_PARAMETERFILE_H
#define GAMMA_SKY_SRC_PARAMETERFILE_H

#include <array>
#include <fstream>
#include <string>

class ParameterFile {
public:
  struct Parameters {
    // {x, y, z} observer location in kpc
    std::array<double, 3> xyz_observer_location;
    // size of the radial bins in kpc
    double radial_step_size;
    // longitude of the direction in which the observer looks in radian
    double line_of_sight_longitude;
    // latitude of the direction in which the observer looks in radian
    double line_of_sight_latitude;
    // determines the number of pixels of the gamma sky
    int healpix_order;
  };
  explicit ParameterFile(const std::string &file_path);
  Parameters get_parameters();

private:
  std::string get_string(const std::string &parameter_name);
  int get_int(const std::string &parameter_name);
  double get_double(const std::string &parameter_name);
  const std::string &file_path;
};

#endif // GAMMA_SKY_SRC_PARAMETERFILE_H
