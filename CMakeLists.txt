cmake_minimum_required(VERSION 3.0.2)
project(dataset_collect)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        cv_bridge
        )

find_package(OpenCV REQUIRED)


catkin_package(
        INCLUDE_DIRS include
        CATKIN_DEPENDS roscpp cv_bridge
        LIBRARIES ${PROJECT_NAME}
)

include_directories(
        include ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/main.cpp)


target_link_libraries(${PROJECT_NAME}
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS}
        )