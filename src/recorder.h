//Robotkol Desktop Application

#include <string>
#include <sstream>

namespace rk
{
class record
{
public:
  record();
  ~record();

  std::string read();
  void write(std::string content);

private:
  std::stringstream buffer;
};
}
