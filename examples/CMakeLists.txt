add_executable(Example gates.cpp)
target_link_libraries(Example PRIVATE Scions::Scions)
target_link_libraries(Example PRIVATE Scions::CPU)