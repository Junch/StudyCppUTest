LOCAL_PATH:= $(call my-dir) # Get the local path of the project.
include $(CLEAR_VARS) # Clear all the variables with a prefix "LOCAL_"

LOCAL_SRC_FILES:= src/hello.cpp # Indicate the source code.
LOCAL_MODULE:= hello # The name of the binary.
include $(BUILD_EXECUTABLE) # Tell ndk-build that we want to build a native executable.
