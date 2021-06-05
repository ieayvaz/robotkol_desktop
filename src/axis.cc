//Robotkol Desktop Application

#include "axis.h"
#include <iostream>
#include <sstream>
#include <utility>

namespace rk
{

void axis_handler::set_deactive()
{
  _robot_inf.send_data<char>('<');
  _robot_inf.send_data<char>('\n');
}
  
void axis_handler::set_active()
{
  _robot_inf.send_data<char>('>');
  _robot_inf.send_data<char>('\n');
}
  
void axis_handler::set_axis_angle(axis_type axis_t, double angle)
{
  int int_angle = static_cast<int>(angle);
  std::stringstream ss;
  
  switch(axis_t)
    {
    case axis_type::axis_1:
      ss << "1:" << int_angle << std::endl;
      break;
    case axis_type::axis_2:
      ss << "2:" << int_angle << std::endl;
      break;
    case axis_type::axis_3:
      ss << "3:" << int_angle << std::endl;
      break;
    case axis_type::axis_4:
      ss << "4:" << int_angle << std::endl;
      break;
    }
  
  _robot_inf.send_data<std::string>(ss.str());
}

void axis_handler::set_gripper_status(bool status)
{
  _robot_inf.send_data<std::string>("G:");
  if(status)
    _robot_inf.send_data<bool>(std::move(status));
  _robot_inf.send_data<char>('\n');
}
  
}
