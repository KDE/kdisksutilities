set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
set(KDE_MIN_VERSION 4.2.0)
find_package(KDE4 REQUIRED)

include (KDE4Defaults)
include_directories( ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} ${KDE4_INCLUDES} )


set(disksdaemon_SRCS disksdaemon.cpp)

kde4_add_plugin( kded_disksdaemon
    ${disksdaemon_SRCS} 
)

target_link_libraries(kded_disksdaemon kdiskmanager ${KDE4_KDEUI_LIBS} ${KDE4_SOLID_LIBS})

install( TARGETS kded_disksdaemon DESTINATION ${PLUGIN_INSTALL_DIR} )

install( FILES disksdaemon.desktop DESTINATION ${SERVICES_INSTALL_DIR}/kded )
