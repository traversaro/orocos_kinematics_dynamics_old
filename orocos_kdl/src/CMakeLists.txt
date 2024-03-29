FILE( GLOB KDL_SRCS [^.]*.cpp )
FILE( GLOB KDL_HPPS [^.]*.hpp [^.]*.inl)

FILE( GLOB UTIL_SRCS utilities/[^.]*.cpp utilities/[^.]*.cxx)
FILE( GLOB UTIL_HPPS utilities/[^.]*.h utilities/[^.]*.hpp)
if(MSVC)
    set(LIB_TYPE STATIC)
else()
    set(LIB_TYPE SHARED)
endif()
ADD_LIBRARY(orocos-kdl ${LIB_TYPE} ${KDL_SRCS} ${UTIL_SRCS})
SET_TARGET_PROPERTIES( orocos-kdl PROPERTIES
  SOVERSION "${KDL_VERSION_MAJOR}.${KDL_VERSION_MINOR}"
  VERSION "${KDL_VERSION}"
  COMPILE_FLAGS "${CMAKE_CXX_FLAGS_ADD} ${KDL_CFLAGS}"
  INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")

#INSTALL_TARGETS( /lib orocos-kdl)
INSTALL(TARGETS orocos-kdl EXPORT orocos-kdl-target DESTINATION lib)
# CMake 2.2:
INSTALL_FILES( /include/kdl FILES ${KDL_HPPS})
INSTALL_FILES( /include/kdl/utilities FILES ${UTIL_HPPS})

# Orocos convention:
CONFIGURE_FILE( kdl.pc.in ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc @ONLY)
CONFIGURE_FILE( kdl.pc.in ${CMAKE_CURRENT_BINARY_DIR}/orocos_kdl.pc @ONLY)

INSTALL_FILES( /lib/pkgconfig FILES ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc)