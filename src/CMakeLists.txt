add_executable(robotkol
  main.cc)

target_link_libraries(robotkol ${GTKMM_LIBRARIES})
target_include_directories(robotkol PRIVATE ${GTKMM_INCLUDE_DIRS})
