cmake_minimum_required(VERSION 3.0.0)

set(PROJECTNAME lab04)

set(SOURCES main.cpp visuals.cpp)

project(${PROJECTNAME})

add_executable(${PROJECTNAME} ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(${PROJECTNAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
