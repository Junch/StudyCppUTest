# The example is from %NDK-ROOT/sources/third_party/googletest/README.NDK

ndk-build
adb push libs/armeabi/libfoo.so /data/local/tmp/
adb push libs/armeabi/libgnustl_shared.so /data/local/tmp/
adb push libs/armeabi/foo_unittest /data/local/tmp/
adb shell chmod 755 /data/local/tmp/foo_unittest
adb shell "LD_LIBRARY_PATH=/data/local/tmp /data/local/tmp/foo_unittest"
