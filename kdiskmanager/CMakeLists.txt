set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
set(KDE_MIN_VERSION 4.2.0)
find_package(KDE4 REQUIRED)

include (KDE4Defaults)
include_directories( ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} ${KDE4_INCLUDES} )


set(kdiskmanager_SRCS main.cpp diskmanager.cpp blockdeviceutility.cpp OrgFreedesktopDeviceKitDisks.cpp OrgFreedesktopDeviceKitDisksDevice.cpp)

kde4_add_ui_files(kdiskmanager_SRCS diskmanager.ui )

kde4_add_executable(kdiskmanager ${kdiskmanager_SRCS})

target_link_libraries(kdiskmanager ${KDE4_KDEUI_LIBS} ${KDE4_SOLID_LIBS})

install(TARGETS kdiskmanager  ${INSTALL_TARGETS_DEFAULT_ARGS} )
