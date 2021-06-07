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
  void set_axis_angle(axis_type axis_t, double angle, bool is_recording);
  void set_active();
  void set_deactive();
  void set_gripper_status(bool status, bool is_recording);

  std::string get_last_record();
  void play_last_record();
  void clear_last_record();
  
private:
  std::stringstream _last_record;
  robot_interface _robot_inf;
};
}
