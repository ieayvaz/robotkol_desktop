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
    std::cout <<_buffer.str();
  }

  void send_record(const std::string& record)
  {
    std::cout << record;
  }
  
private:
  std::stringstream _buffer;
};
}
