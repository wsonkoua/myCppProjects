cmake_minimum_required (VERSION 3.25.2)

project(thread_synchroniser
	VERSION 1.0
	DESCRIPTION "A small program introducing a thread synchroniser class.")
	
set (CMAKE_CXX_STANDARD 20)

list (APPEND thread_synchroniser_DEFINITIONS "thread_synchroniser_DEBUG_BUILD")

message(STATUS ${PROJECT_NAME})

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  googlebenchmark
  GIT_REPOSITORY https://github.com/google/benchmark
  GIT_TAG        v1.9.0
)

FetchContent_MakeAvailable(googletest googlebenchmark)


if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
	add_subdirectory(src/tests)
endif()

#Determine sources and headers

set (thread_synchroniser_SOURCE src/thread_synchroniser/thread_synchroniser.cpp				
						)			
						
set (thread_synchroniser_SOURCE_HEADERS
  src/thread_synchroniser/thread_synchroniser.h		
)
	 

source_group ("Source Files" FILES ${thread_synchroniser_SOURCE})
source_group ("Header Files" FILES ${thread_synchroniser_SOURCE_HEADERS})

add_library (thread_synchroniser_lib STATIC
  ${thread_synchroniser_SOURCE}
  ${thread_synchroniser_SOURCE_HEADERS}
  )
  
target_include_directories (thread_synchroniser_lib PUBLIC
  src
  src/ext
)
  

target_compile_definitions (thread_synchroniser_lib PRIVATE ${thread_synchroniser_DEFINITIONS})

add_executable (thread_synchroniser_exe src/thread_synchroniser/bin/main.cpp)

target_include_directories (thread_synchroniser_exe PUBLIC
  src
  src/ext
)

#option(thread_synchroniser_TEST_SOURCE "Enable tests" OFF)



