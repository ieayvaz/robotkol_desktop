//Robotkol Desktop Application

#include <iostream>
#include <sstream>
#include <utility>

namespace rk
{
class robot_interface
{
public:
  template<typename T>
  void send_data(T&& data)
  {
    _buffer.str(std::string());
    _buffer << data;
    out_console(_buffer.str());
  }
private:
  void out_console(std::string content)
  {
    std::cout << content;
  }
  std::stringstream _buffer;
};
}
