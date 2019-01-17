#include <jni.h>
#include <string>
#include "libyuv/include/libyuv.h"
#include <android/log.h>

#define LOG_TAG "libyuv"
#define LOGV(...)  __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
using namespace libyuv;

extern "C"
JNIEXPORT void JNICALL
Java_com_yuv_util_YUVUtil_ARGBToI420(JNIEnv *env, jclass type, jbyteArray src_argb_,
                                     jint src_stride_argb, jbyteArray dst_y_,
                                     jint dst_stride_y, jbyteArray dst_u_, jint dst_stride_u,
                                     jbyteArray dst_v_, jint dst_stride_v,
                                     jint width,
                                     jint height) {
    jbyte *src_argb = env->GetByteArrayElements(src_argb_, NULL);
    jbyte *dst_y = env->GetByteArrayElements(dst_y_, NULL);
    jbyte *dst_u = env->GetByteArrayElements(dst_u_, NULL);
    jbyte *dst_v = env->GetByteArrayElements(dst_v_, NULL);

    ARGBToI420((uint8_t *) src_argb, src_stride_argb,
               (uint8_t *) dst_y, dst_stride_y,
               (uint8_t *) dst_u, dst_stride_u,
               (uint8_t *) dst_v, dst_stride_v,
               width, height);


    env->ReleaseByteArrayElements(src_argb_, src_argb, 0);
    env->ReleaseByteArrayElements(dst_y_, dst_y, 0);
    env->ReleaseByteArrayElements(dst_u_, dst_u, 0);
    env->ReleaseByteArrayElements(dst_v_, dst_v, 0);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_yuv_util_YUVUtil_convertToARGB(JNIEnv *env, jclass type, jbyteArray src_frame_,
                                        jint src_size, jbyteArray dst_argb_,
                                        jint dst_stride_argb, jint crop_x, jint crop_y,
                                        jint src_width, jint src_height, jint crop_width,
                                        jint crop_height, jint rotation, jint format) {
    jbyte *src_frame = env->GetByteArrayElements(src_frame_, NULL);
    jbyte *dst_argb = env->GetByteArrayElements(dst_argb_, NULL);

    ConvertToARGB((uint8_t *) src_frame, src_size, (uint8_t *) dst_argb, dst_stride_argb,
                  crop_x,
                  crop_y, src_width, src_height, crop_width, crop_height, kRotate0,
                  FOURCC_IYUV);


    env->ReleaseByteArrayElements(src_frame_, src_frame, 0);
    env->ReleaseByteArrayElements(dst_argb_, dst_argb, 0);
}