cmake_minimum_required(VERSION 3.14)

project(QtGram LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(QtGram
  main.cpp
  Game.h
  Game.cpp
  Entity.h
  Manager.h
  Sprite.h
  Sprite.cpp
  Resource.qrc
  Map.h
  Map.cpp
  PlayerPlane.h
  PlayerPlane.cpp
  Bullet.h
  Bullet.cpp
  EnemyPlane.h
  EnemyPlane.cpp


)
target_link_libraries(QtGram Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS QtGram
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
