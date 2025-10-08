

# ============================================================================
# =========================  PROJECT SETUP  ==================================
# ============================================================================

cmake_minimum_required(VERSION 3.23)

# set the project name and languages
project(image_builder)
project(image_builder VERSION 3.0.4)
project(image_builder LANGUAGES C)

# Determine target name based on OS
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(TARGET_NAME "image_builder_windows")
else()
    set(TARGET_NAME "image_builder_linux")
endif()

# Create a common target for compile definitions
add_library(common INTERFACE)

# enable debug/release configs
set(CMAKE_DEBUG_POSTFIX d)

# enable debug/release configs
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_BUILD_TYPE EQUAL "RELEASE")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s")
endif ()

# Include cargs, a library for command-line parsing
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/cargs) 

# Include CycloneCRYPTO, our Crypto library
if(CMAKE_SYSTEM_NAME STREQUAL Linux)
    set(CYCLONE_CRYPTO_PORT_SRC
            ${PROJECT_SOURCE_DIR}/lib/common/os_port_posix.c
    )
endif()
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    set(CYCLONE_CRYPTO_PORT_SRC
            ${PROJECT_SOURCE_DIR}/lib/common/os_port_windows.c
    )
endif()

set(CYCLONE_CRYPTO_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/common/cpu_endian.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/common/date_time.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/hash/sha512.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/hash/sha256.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/hash/sha224.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/hash/sha384.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/hash/sha1.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/hash/sha1.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/hash/md5.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/rng/yarrow.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/cipher/aes.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/cipher_modes/cbc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/mac/hmac.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/pkc/rsa.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/pkc/rsa_misc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/pkc/dsa.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/encoding/oid.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/encoding/asn1.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/encoding/base64.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/mpi/mpi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/pkix/pem_common.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/pkix/pem_decrypt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/pkix/x509_common.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/pkix/x509_key_parse.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/pkix/pem_import.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/pkix/pkcs8_key_parse.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/ecc/ec_curves.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/ecc/ecdsa.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/ecc/ec.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/CycloneCRYPTO/ecc/ec_misc.c
    ${CYCLONE_CRYPTO_PORT_SRC}
)


# add the executable
add_executable(${TARGET_NAME}
        main.c
        src/cli.c
        src/header.c
        src/body.c
        src/footer.c
        src/utils.c
        src/crc32.c
        ${CYCLONE_CRYPTO_SRC}
)
set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
# =============================================================================



# =============================================================================
# =========================  PROJECT CONFIG  ==================================
# =============================================================================

# let the preprocessor know about the system name
if(CMAKE_SYSTEM_NAME STREQUAL Linux)
target_compile_definitions(common INTERFACE IS_LINUX) 
endif()
if(CMAKE_SYSTEM_NAME STREQUAL Darwin)
target_compile_definitions(common INTERFACE IS_MACOS) # No Macros for MacOS as of yet.
endif()
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
target_compile_definitions(common INTERFACE IS_WINDOWS) 
endif()

set(CMAKE_CXX_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
set(APP_VERSION_MAJOR 2)
set(APP_VERSION_MINOR 5)
set(APP_VERSION_PATCH 0)

# set header version info
set(HEADER_VERSION_MAJOR 1)
set(HEADER_VERSION_MINOR 1)
set(HEADER_VERSION_PATCH 0)

# built time
string( TIMESTAMP currentTime "%Y%m%dT%H%M" )
set(TIMESTAMP ${currentTime})

include_directories(${PROJECT_BINARY_DIR}/config)
configure_file(${PROJECT_SOURCE_DIR}/config/ImageBuilderConfig.h.in ${PROJECT_BINARY_DIR}/config/ImageBuilderConfig.h @ONLY)

# =============================================================================


# =============================================================================
# =========================  PROJECT LINKING  =================================
# =============================================================================

# add the binary tree to the search path for include files
# so that we will find AppImageBuilderConfig.h
target_include_directories(${TARGET_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_BINARY_DIR}/inc
    ${PROJECT_SOURCE_DIR}/lib/CycloneCRYPTO
    ${PROJECT_SOURCE_DIR}/lib/common
    ${PROJECT_SOURCE_DIR}/config
    ${PROJECT_BINARY_DIR}/config
)

target_link_libraries(${TARGET_NAME} PRIVATE common)
target_link_libraries(${TARGET_NAME} PUBLIC cargs)
if(CMAKE_SYSTEM_NAME STREQUAL Linux)
  target_link_libraries(${TARGET_NAME} PUBLIC pthread) # Needed on Linux to compile crypto
endif()

# =============================================================================


