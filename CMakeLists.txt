# CMakeList.txt : Top-level CMake project file, do global configuration and include sub-projects here
cmake_minimum_required(VERSION 3.12.0)

if (NOT DEFINED CMAKE_MAKE_PROGRAM)
    message(FATAL_ERROR "CMAKE_MAKE_PROGRAM is not set, aborting")
endif()

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    message(FATAL_ERROR "CMAKE_TOOLCHAIN_FILE is not set, aborting")
endif()

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("grpc_mock_server_common")

include(GNUInstallDirs)

# Include sub-projects.
add_subdirectory("grpc_mock_server_common")
add_subdirectory("grpc_mock_server_common_test")
