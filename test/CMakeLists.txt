project(DynamicMedianTests)

set(Headers
    DoubleEquality.hpp
)

set(Sources
    TestDynamicMedian.cpp
    TestMinMaxHeap.cpp
    TestsStartUp.cpp
    DoubleEquality.cpp
)

add_executable(Tests ${Sources} ${Headers})
target_link_libraries(Tests PRIVATE DataStructures Catch2)