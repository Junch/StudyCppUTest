# The example is from %NDK_ROOT/sample/hello-jni and the book "Mastering Android NDK" - Creating an Ant-based application template manually
# https://github.com/corporateshark/Mastering-Android-NDK/tree/master/Chapter1/1_AntApp
ndk-build NDK_DEUBG=1
android update project --target android-17 --path .
ant debug
# adb install -r bin/AntNDKApp-debug.apk
ant debug install