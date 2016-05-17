#include <stdlib.h>
#include <jni.h>
#include <android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "NDKApp", __VA_ARGS__))

extern "C"
{
	JNIEXPORT void JNICALL Java_com_example_AntNDKApp_onCreateNative( JNIEnv* env, jobject obj )
	{
		LOGI( "Hello Android NDK!" );
	}
}
