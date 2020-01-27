/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_android_framebufferizer_NativeRenderer */

#ifndef _Included_com_android_framebufferizer_NativeRenderer
#define _Included_com_android_framebufferizer_NativeRenderer
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_android_framebufferizer_NativeRenderer
 * Method:    setDeviceInfo
 * Signature: (Lcom/android/framebufferizer/utils/DeviceInfo;Z)I
 */
JNIEXPORT jint JNICALL Java_com_android_framebufferizer_NativeRenderer_setDeviceInfo(JNIEnv*,
                                                                                     jclass,
                                                                                     jobject,
                                                                                     jboolean);

/*
 * Class:     com_android_framebufferizer_NativeRenderer
 * Method:    renderBuffer
 * Signature: (IIIII[I)I
 */
JNIEXPORT jint JNICALL Java_com_android_framebufferizer_NativeRenderer_renderBuffer(
    JNIEnv*, jclass, jint, jint, jint, jint, jint, jintArray);

/*
 * Class:     com_android_framebufferizer_NativeRenderer_setLanguage
 * Method:    setLanguage
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT void JNICALL Java_com_android_framebufferizer_NativeRenderer_setLanguage(JNIEnv*, jclass,
                                                                                   jstring);
/*
 * Class:     com_android_framebufferizer_NativeRenderer_getLanguageIdList
 * Method:    getLanguageIdList
 */
JNIEXPORT jobjectArray JNICALL
Java_com_android_framebufferizer_NativeRenderer_getLanguageIdList(JNIEnv*, jclass);

#ifdef __cplusplus
}
#endif
#endif
