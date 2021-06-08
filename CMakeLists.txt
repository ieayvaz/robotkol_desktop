cmake_minimum_required(VERSION 3.2)

project(robotkol-desktop)
enable_language(CXX)

include(GNUInstallDirs)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

add_subdirectory(src)

