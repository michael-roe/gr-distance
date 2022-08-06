INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_DISTANCE distance)

FIND_PATH(
    DISTANCE_INCLUDE_DIRS
    NAMES distance/api.h
    HINTS $ENV{DISTANCE_DIR}/include
        ${PC_DISTANCE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    DISTANCE_LIBRARIES
    NAMES gnuradio-distance
    HINTS $ENV{DISTANCE_DIR}/lib
        ${PC_DISTANCE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/distanceTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(DISTANCE DEFAULT_MSG DISTANCE_LIBRARIES DISTANCE_INCLUDE_DIRS)
MARK_AS_ADVANCED(DISTANCE_LIBRARIES DISTANCE_INCLUDE_DIRS)
