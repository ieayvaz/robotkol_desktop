//Robotkol Desktop Application

#include <iostream>
#include <sstream>
#include <utility>
#include <chrono>
#include <thread>

#include "extern/SerialPort.hpp"

namespace rk
{
class robot_interface
{
public:
  robot_interface() : _port_adress(nullptr), _serial_port(nullptr)
  {}
  
  template<typename T>
  void send_data(T&& data)
  {
    _buffer.str(std::string());
    _buffer << std::forward<T>(data);
    std::cout <<_buffer.str();
    bool has_written = _serial_port->writeSerialPort(_buffer.str().c_str(), 255);
    if(!has_written)
      {
	std::cout << "Veri Gönderilemiyor. Port Adresi : !" + _port_adress << std::endl;
	return;
      }
  }

  void send_record(const std::string& record)
  {
    std::stringstream record_stream(record);
    std::string buf;
    while(record_stream)
      {
	std::getline(record_stream, buf);
	std::cout << buf << std::endl;
	bool has_written = _serial_port->writeSerialPort(buf.c_str(), 255);
	if(!has_written)
	  {
	    std::cout << "Veri Gönderilemiyor. Port Adresi : !" + _port_adress << std::endl;
	    return;
	  }
	std::this_thread::sleep_for(std::chrono::seconds(2));
      }
  }
 
  bool connect(const char* adress)
  {
    _port_adress = adress;
    _serial_port = new SerialPort(_port_adress);

    return _serial_port->isConnected();
  }
  
private:
  std::stringstream _buffer;
  const char * _port_adress;
  SerialPort *_serial_port;
  
};
}
