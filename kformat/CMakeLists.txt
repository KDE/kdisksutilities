set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
set(KDE_MIN_VERSION 4.2.0)
find_package(KDE4 REQUIRED)
find_package(PolkitQt-1)

include (KDE4Defaults)
include_directories( ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} ${KDE4_INCLUDES})

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../libkdiskmanager)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libkdiskmanager)
endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../libkdiskmanager)

set(kformat_SRCS main.cpp format.cpp)

kde4_add_ui_files(kformat_SRCS format.ui )

kde4_add_executable(kformat ${kformat_SRCS})

target_link_libraries(kformat kdiskmanager ${KDE4_KDEUI_LIBS} ${KDE4_SOLID_LIBS} ${POLKITQT-1_CORE_LIBRARY})

install(TARGETS kformat  ${INSTALL_TARGETS_DEFAULT_ARGS} )
