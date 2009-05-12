set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
set(KDE_MIN_VERSION 4.2.0)
find_package(KDE4 REQUIRED)

include (KDE4Defaults)

set(kformat_SRCS main.cpp format.cpp)

kde4_add_ui_files(kformat_SRCS format.ui )

kde4_add_executable(kformat ${kformat_SRCS})

target_link_libraries(kformat  ${KDE4_KDEUI_LIBS} )

install(TARGETS kformat  ${INSTALL_TARGETS_DEFAULT_ARGS} )
