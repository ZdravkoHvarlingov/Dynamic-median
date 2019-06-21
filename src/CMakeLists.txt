project(DynamicMedianSource)

set(Headers 
    data_structures/headers/DynamicMedian.hpp
    data_structures/headers/MinMaxHeap.hpp   
)

set(Sources
    data_structures/implementation/DynamicMedian.cpp
    data_structures/implementation/MinMaxHeap.cpp
)

add_library(DataStructures STATIC ${Headers} ${Sources})
target_include_directories(DataStructures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/data_structures/headers)

add_executable(StartUp StartUp.cpp)
target_link_libraries(StartUp PRIVATE DataStructures)