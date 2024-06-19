cmake_minimum_required(VERSION 3.5.0)
project(SHA-Intrinsics VERSION 0.1.0 LANGUAGES C CXX)

if (CMAKE_SYSTEM_PROCESSOR MATCHES "(arm)|(arm64)|(ARM64)")
	set(HEADER_FILES sha-intrinsics.h sha1-arm.h sha256-arm.h sha256.h sha512.h)
	set(SRC_FILES sha1-arm.c sha256-arm.c sha256.c sha512.c)
	add_library(SHA-Intrinsics STATIC ${SRC_FILES})
	set_target_properties(SHA-Intrinsics PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")
elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86_64)(X86)|(AMD64)")
	set(HEADER_FILES sha-intrinsics.h sha1-x86.h sha256-x86.h sha256.h sha512.h)
	set(SRC_FILES sha1-x86.c sha256-x86.c sha256.c sha512.c)
	add_library(SHA-Intrinsics STATIC ${SRC_FILES})
	set_target_properties(SHA-Intrinsics PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")
	if(CMAKE_C_COMPILER_ID MATCHES "Clang")
		target_compile_options(SHA-Intrinsics PUBLIC -mssse3 -msse4 -msha)
	endif()
else()
	set(HEADER_FILES sha-intrinsics.h sha256.h sha512.h)
	set(SRC_FILES sha256.c sha512.c)
	add_library(SHA-Intrinsics STATIC ${SRC_FILES})
	set_target_properties(SHA-Intrinsics PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")
endif ()

install(
	TARGETS SHA-Intrinsics
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
