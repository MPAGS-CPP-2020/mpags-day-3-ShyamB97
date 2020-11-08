# - Configure tests for building

# most basic test
add_executable(testCatch testCatch.cpp)
add_test(NAME test-catch COMMAND testCatch)

# - Library interface for MPAGSCipher tests
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(Catch INTERFACE cxx_noexcept)

# - test transformChar function
add_executable(testTransformChar testTransformChar.cpp)
add_test(NAME test-transformChar COMMAND testTransformChar)
target_link_libraries(testTransformChar MPAGSCipher)

# - test ProcessCommandLine function
#add_executable(testProcessCommandLine testProcessCommandLine.cpp)
#add_test(NAME test-ProcessCommandLine COMMAND testProcessCommandLine)
#target_link_libraries(testProcessCommandLine MPAGSCipher)

# - test CaesarCipher function
add_executable(testCaesarCipher testCaesarCipher.cpp)
add_test(NAME test-CaesarCipher COMMAND testCaesarCipher)
target_link_libraries(testCaesarCipher MPAGSCipher)