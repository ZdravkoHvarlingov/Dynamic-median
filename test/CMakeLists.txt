project(DynamicMedianTests)

set(Sources
    TestDynamicMedian.cpp
    TestMinMaxHeap.cpp
    TestsStartUp.cpp
)

add_executable(Tests ${Sources})
target_link_libraries(Tests PRIVATE DataStructures Catch2)