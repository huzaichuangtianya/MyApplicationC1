#include <jni.h>
#include <string>
#include "Hello.h"
#include <android/log.h>

const char *LOG_TGA = "LOG_TGA";

extern "C" JNIEXPORT jstring  JNICALL
Java_com_quliang_myapplicationc1_javanative_JniMethod_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT void  JNICALL
Java_com_quliang_myapplicationc1_javanative_JniMethod_returnValueVoid(
        JNIEnv *env,
        jobject thiz) {
    jclass clazz = (*env).GetObjectClass(thiz);//获取该对象的类
    jobject m_object = (*env).NewGlobalRef(thiz);//创建对象的本地变量
    jmethodID m_mid = (*env).GetMethodID(clazz, "javaNativeMdCall", "()V");//获取JAVA方法的ID
    (*env).CallVoidMethod(m_object, m_mid);
//    __android_log_print(ANDROID_LOG_DEBUG, LOG_TGA, "returnValueVoid");
}

extern "C" JNIEXPORT jint JNICALL
Java_com_quliang_myapplicationc1_javanative_JniMethod_sumFromJNI(JNIEnv *env, jobject instance,
                                                                 jint a,
                                                                 jint b) {
    Hello *hello = new Hello();
    return hello->sum(a, b);
}

extern "C" JNIEXPORT jint JNICALL
Java_com_quliang_myapplicationc1_javanative_JniMethod_getStringFromNative
        (JNIEnv *env, jobject) {
    return 10;
}

extern "C" JNIEXPORT jint JNICALL Java_com_quliang_myapplicationc1_javanative_JniMethod_getJavaField
        (JNIEnv *env, jobject thiz) {

    jclass clazz = (*env).GetObjectClass(thiz);//获取该对象的类
    jobject m_object = (*env).NewGlobalRef(thiz);//创建对象的本地变量
//    m_mid =(*env).GetMethodID(clazz, "notifyFiledChange", "()V");//获取JAVA方法的ID
    jfieldID m_fid = (*env).GetFieldID(clazz, "a", "I");//获取java变量的ID
    (*env).SetIntField(m_object, m_fid, 18);
    return 10;
}

extern "C" JNIEXPORT jint JNICALL
Java_com_quliang_myapplicationc1_javanative_JniMethod_getJavaNativeField
        (JNIEnv *env, jobject thiz) {

    jclass clazz = (*env).GetObjectClass(thiz);//获取该对象的类
    jobject m_object = (*env).NewGlobalRef(thiz);//创建对象的本地变量
//    m_mid =(*env).GetMethodID(clazz, "notifyFiledChange", "()V");//获取JAVA方法的ID
    jfieldID m_fid = (*env).GetFieldID(clazz, "a", "I");//获取java变量的ID
    (*env).SetIntField(m_object, m_fid, 18);
    return 10;
}

extern "C" JNIEXPORT jint JNICALL
Java_com_quliang_myapplicationc1_javanative_JniMethod_getJavaNativeMethod
        (JNIEnv *env, jobject thiz) {

    jclass clazz = (*env).GetObjectClass(thiz);//获取该对象的类
    jobject m_object = (*env).NewGlobalRef(thiz);//创建对象的本地变量
    jmethodID m_mid = (*env).GetMethodID(clazz, "javaNativeMdCall", "()V");//获取JAVA方法的ID
    (*env).CallVoidMethod(m_object, m_mid);
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TGA, "getJavaNativeMethod");
    return 0;
}


extern "C" JNIEXPORT jint JNICALL Java_com_quliang_myapplicationc1_javanative_JniMethod_setObj
        (JNIEnv *env, jobject thiz, jobject paramObj) {

    jclass jcInfo = env->FindClass("com/quliang/myapplicationc1/bean/ParamInfoBean");

    jfieldID jfi = env->GetFieldID(jcInfo, "intValue", "I");
//    paramInfo.intValue = env->GetIntField(paramObj, jfi);
    int a = env->GetIntField(paramObj, jfi);


//    jclass clazz = (*env).GetObjectClass(thiz);//获取该对象的类
//    jobject m_object = (*env).NewGlobalRef(thiz);//创建对象的本地变量
//    jmethodID  m_mid =(*env).GetMethodID(clazz, "javaNativeMdCall", "()V");//获取JAVA方法的ID
//    (*env).CallVoidMethod(m_object,m_mid);
//    __android_log_print(ANDROID_LOG_DEBUG, LOG_TGA, "getJavaNativeMethod");
    return a;
}





