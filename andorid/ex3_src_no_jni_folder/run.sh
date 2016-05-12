#[Mastering Android NDK Build System - Part 1: Techniques with ndk-build](http://web.guohuiwang.com/technical-notes/androidndk1)

ndk-build NDK_APPLICATION_MK=./Application.mk
adb push libs/armeabi-v7a/hello /data/local/tmp
adb shell chmod 755 /data/local/tmp
adb shell /data/local/tmp/hello
