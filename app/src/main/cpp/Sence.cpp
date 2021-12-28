//
// Created by Administrator on 2021/12/1.
//

#include "Sence.h"
#include "Utils.h"

extern "C" JNIEXPORT void JNICALL
Java_com_innup_opengles_MethodFromNative_onSurfaceCreated(
        JNIEnv *env,
        jobject methodFromNative) {
    __android_log_print(ANDROID_LOG_INFO, SENCE_LOG_TAG, "surfaceCreted");
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
}

extern "C" JNIEXPORT void JNICALL
Java_com_innup_opengles_MethodFromNative_onSurfacechanged(
        JNIEnv *env,
        jobject methodFromNative,
        jint width,
        jint height) {
    __android_log_print(ANDROID_LOG_INFO, SENCE_LOG_TAG, "surfaceChange %d %d", width, height);
    glViewport(0, 0, width, height);
}

extern "C" JNIEXPORT void JNICALL
Java_com_innup_opengles_MethodFromNative_onDrawFrame(
        JNIEnv *env,
        jobject methodFromNative) {
    __android_log_print(ANDROID_LOG_INFO, SENCE_LOG_TAG, "onDrawFrame");
    glClear(GL_COLOR_BUFFER_BIT);
}

extern "C" JNIEXPORT void JNICALL
Java_com_innup_opengles_MethodFromNative_loadAssetsText(
        JNIEnv *env,
        jobject methodFromNative,
        jobject assetManager) {
    //根据java层传入的AssetManager，获取native层的AssetManager
    AAssetManager *aAssetManager = AAssetManager_fromJava(env, assetManager);
    int fileSize = 0;
    //获取文件内容
    unsigned char *content = LoadFileContent(aAssetManager, "test.txt", fileSize);
    if (content != nullptr) {
        //如果 content 不为空，说明读取到内容了，打印出来
        __android_log_print(ANDROID_LOG_INFO, SENCE_LOG_TAG, "读取到的内容：%s", (char *) content);
        delete[] content;
    }
}