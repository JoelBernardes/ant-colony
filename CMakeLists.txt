cmake_minimum_required(VERSION 3.20)
project(PredOrPrey)

set(CMAKE_CXX_STANDARD 17)

# create the executable and use libimgLib created above
add_executable(${CMAKE_PROJECT_NAME}
        main.cpp
        lib/include/Organisms.h
        lib/include/DoodleBug.h
        lib/src/QueenAnts.cpp
        lib/include/QueenAnts.h
        lib/src/MatingAnts.cpp
        lib/include/MatingAnts.h
        lib/src/WorkerAnts.cpp
        lib/include/WorkerAnts.h
        lib/src/Organisms.cpp
        lib/src/DoodleBug.cpp
        lib/src/Grid.cpp
        lib/include/Grid.h
        lib/src/Simulation.cpp
        lib/include/Simulation.h
        lib/src/Cell.cpp
        lib/include/Cell.h
)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/include)
