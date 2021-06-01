//Robotkol Desktop Application

#include "robot_interface.h"
#include <string>
#include <array>

namespace rk
{
enum class axis_type
  {
   axis_1 = 1,
   axis_2 = 2,
   axis_3 = 3,
   axis_4 = 4,
  };

class axis_handler
{
public:
  void set_axis_angle(axis_type axis_t, double angle);
  void set_active();
  void set_deactive();
  
private:
  std::array<double, 4> axis_angles;
  
  std::string data;
  robot_interface _robot_inf;
};
}
