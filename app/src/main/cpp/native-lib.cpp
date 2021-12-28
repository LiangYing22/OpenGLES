#include "prefix.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_innup_opengles_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jint JNICALL
Java_com_innup_opengles_MainActivity_intFromJNI(
        JNIEnv* env,
        jobject mainActivity){
    return 101;
}