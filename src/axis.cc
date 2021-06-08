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
  
void axis_handler::set_axis_angle(axis_type axis_t, double angle, bool is_recording)
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

  if(!is_recording)
  _robot_inf.send_data<std::string>(ss.str());
  else
    _last_record << ss.str();
}

void axis_handler::set_gripper_status(bool status, bool is_recording)
{
  if(!is_recording)
    {
      _robot_inf.send_data<std::string>("G:");
      _robot_inf.send_data<bool>(std::move(status));
      _robot_inf.send_data<char>('\n');
    }
  else
    {
      _last_record << "G:";
      _last_record << status << std::endl;
    }
}

void axis_handler::clear_last_record()
{
  _last_record.str(std::string());
}

void axis_handler::play_last_record()
{
  _robot_inf.send_record(_last_record.str());
}

std::string axis_handler::get_last_record()
{
  return _last_record.str();
}

bool axis_handler::check_last_record()
{
  return _last_record.tellp() == std::streampos(0) ? false : true; 
}

bool axis_handler::init(const std::string& port_adress)
{
  return _robot_inf.connect(port_adress.c_str());
}

}
