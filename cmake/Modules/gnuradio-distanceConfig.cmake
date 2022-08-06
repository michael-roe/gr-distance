find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_DISTANCE gnuradio-distance)

FIND_PATH(
    GR_DISTANCE_INCLUDE_DIRS
    NAMES gnuradio/distance/api.h
    HINTS $ENV{DISTANCE_DIR}/include
        ${PC_DISTANCE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_DISTANCE_LIBRARIES
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

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-distanceTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_DISTANCE DEFAULT_MSG GR_DISTANCE_LIBRARIES GR_DISTANCE_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_DISTANCE_LIBRARIES GR_DISTANCE_INCLUDE_DIRS)
