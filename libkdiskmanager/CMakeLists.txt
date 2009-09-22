set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
set(KDE_MIN_VERSION 4.2.0)
find_package(KDE4 REQUIRED)

include (KDE4Defaults)
include_directories( ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} ${KDE4_INCLUDES} )


set(libkdiskmanager_SRCS
	blockdevice.cpp
	blockdevicemanager.cpp
	OrgFreedesktopDeviceKitDisks.cpp 
	OrgFreedesktopDeviceKitDisksDevice.cpp
)

kde4_add_library( kdiskmanager SHARED
    ${libkdiskmanager_SRCS} 
)

target_link_libraries(kdiskmanager ${KDE4_SOLID_LIBS} ${KDE4_KDECORE_LIBS})

install(TARGETS kdiskmanager EXPORT kdelibsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS})

install(FILES
    blockdevice.h
    blockdevicemanager.h
    DESTINATION ${INCLUDE_INSTALL_DIR}/kdiskmanager COMPONENT Devel)

