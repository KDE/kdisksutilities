cmake_minimum_required(VERSION 2.8)
set(KDE_MIN_VERSION 4.2.0)
find_package(KDE4 REQUIRED)

add_subdirectory(libkdiskmanager)
add_subdirectory(disksdaemon)
#add_subdirectory(kdiskmanager)
add_subdirectory(kformat)
