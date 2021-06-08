add_executable(robotkol
  main.cc
  rk_application.cc
  main_window.cc
  axis.cc
  extern/SerialPort.cpp
  )

target_link_libraries(robotkol ${GTKMM_LIBRARIES})
target_include_directories(robotkol PRIVATE ${GTKMM_INCLUDE_DIRS})
