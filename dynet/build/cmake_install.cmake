# Install script for directory: /Users/rio/Desktop/glgl/dynet

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dynet" TYPE FILE FILES
    "/Users/rio/Desktop/glgl/dynet/aligned-mem-pool.h"
    "/Users/rio/Desktop/glgl/dynet/c2w.h"
    "/Users/rio/Desktop/glgl/dynet/cfsm-builder.h"
    "/Users/rio/Desktop/glgl/dynet/cuda.h"
    "/Users/rio/Desktop/glgl/dynet/cudnn-ops.h"
    "/Users/rio/Desktop/glgl/dynet/deep-lstm.h"
    "/Users/rio/Desktop/glgl/dynet/devices.h"
    "/Users/rio/Desktop/glgl/dynet/device-structs.h"
    "/Users/rio/Desktop/glgl/dynet/dict.h"
    "/Users/rio/Desktop/glgl/dynet/dim.h"
    "/Users/rio/Desktop/glgl/dynet/dynet.h"
    "/Users/rio/Desktop/glgl/dynet/dynet-helper.h"
    "/Users/rio/Desktop/glgl/dynet/except.h"
    "/Users/rio/Desktop/glgl/dynet/exec.h"
    "/Users/rio/Desktop/glgl/dynet/expr.h"
    "/Users/rio/Desktop/glgl/dynet/fast-lstm.h"
    "/Users/rio/Desktop/glgl/dynet/functors.h"
    "/Users/rio/Desktop/glgl/dynet/globals.h"
    "/Users/rio/Desktop/glgl/dynet/gpu-kernels.h"
    "/Users/rio/Desktop/glgl/dynet/gpu-ops.h"
    "/Users/rio/Desktop/glgl/dynet/grad-check.h"
    "/Users/rio/Desktop/glgl/dynet/graph.h"
    "/Users/rio/Desktop/glgl/dynet/gru.h"
    "/Users/rio/Desktop/glgl/dynet/hsm-builder.h"
    "/Users/rio/Desktop/glgl/dynet/index-tensor.h"
    "/Users/rio/Desktop/glgl/dynet/init.h"
    "/Users/rio/Desktop/glgl/dynet/io.h"
    "/Users/rio/Desktop/glgl/dynet/lstm.h"
    "/Users/rio/Desktop/glgl/dynet/matrix-multiply.h"
    "/Users/rio/Desktop/glgl/dynet/mem.h"
    "/Users/rio/Desktop/glgl/dynet/model.h"
    "/Users/rio/Desktop/glgl/dynet/mp.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-activations.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-affinetransform.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-argmax.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-arith-const.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-arith-cwise.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-arith-sum.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-arith-unary.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-concat.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-const.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-contract.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-conv2d.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-conv.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-cumulative.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-def-macros.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-dropout.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-flow.h"
    "/Users/rio/Desktop/glgl/dynet/nodes.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-hinge.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-impl-macros.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-linalg.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-logsumexp.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-losses.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-lstm.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-matrixmultiply.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-maxpooling2d.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-minmax.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-moments.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-normalization.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-norms.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-pickneglogsoftmax.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-random.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-rounding.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-select.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-similarities.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-softmaxes.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-to-device.h"
    "/Users/rio/Desktop/glgl/dynet/nodes-trig.h"
    "/Users/rio/Desktop/glgl/dynet/param-init.h"
    "/Users/rio/Desktop/glgl/dynet/param-nodes.h"
    "/Users/rio/Desktop/glgl/dynet/pretrain.h"
    "/Users/rio/Desktop/glgl/dynet/rnn.h"
    "/Users/rio/Desktop/glgl/dynet/rnn-state-machine.h"
    "/Users/rio/Desktop/glgl/dynet/saxe-init.h"
    "/Users/rio/Desktop/glgl/dynet/shadow-params.h"
    "/Users/rio/Desktop/glgl/dynet/sig.h"
    "/Users/rio/Desktop/glgl/dynet/simd-functors.h"
    "/Users/rio/Desktop/glgl/dynet/str-util.h"
    "/Users/rio/Desktop/glgl/dynet/tensor-eigen.h"
    "/Users/rio/Desktop/glgl/dynet/tensor.h"
    "/Users/rio/Desktop/glgl/dynet/timing.h"
    "/Users/rio/Desktop/glgl/dynet/training.h"
    "/Users/rio/Desktop/glgl/dynet/treelstm.h"
    "/Users/rio/Desktop/glgl/dynet/virtual-cudnn.h"
    "/Users/rio/Desktop/glgl/dynet/weight-decay.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/rio/Desktop/glgl/dynet/build/libdynet.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdynet.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdynet.dylib")
    execute_process(COMMAND "/usr/bin/install_name_tool"
      -id "libdynet.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdynet.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdynet.dylib")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/rio/Desktop/glgl/dynet/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
