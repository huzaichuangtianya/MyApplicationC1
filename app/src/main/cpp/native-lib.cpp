#include <jni.h>
#include <string>
#include "Hello.h"
#include <android/log.h>
#include <string.h>

//const char *LOG_TGA = "LOG_TGA";
#define LOG_TAG  "C_TAG"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)


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
//    __android_log_print(ANDROID_LOG_DEBUG, LOG_TGA, "getJavaNativeMethod");
    return 0;
}


typedef struct {
    bool boolValue;
    char charValue;
    double doubleValue;
    int intValue;
    signed char intbyte;
    signed char array[255];
    char str[255];
} ParamInfo;

extern "C" JNIEXPORT jobject JNICALL Java_com_quliang_myapplicationc1_javanative_JniMethod_setObj
        (JNIEnv *env, jobject thiz, jobject paramObj) {

    jclass jcInfo = env->FindClass("com/quliang/myapplicationc1/bean/ParamInfoBean");

    jfieldID intValue = env->GetFieldID(jcInfo, "intValue", "I");
    jfieldID boolValue = env->GetFieldID(jcInfo, "boolValue", "Z");
    jfieldID charValue = env->GetFieldID(jcInfo, "charValue", "C");
    jfieldID doubleValue = env->GetFieldID(jcInfo, "doubleValue", "D");
    jfieldID bytew = env->GetFieldID(jcInfo, "bytew", "B");
    jfieldID str = env->GetFieldID(jcInfo, "str", "Ljava/lang/String;");
    jfieldID byteArray = env->GetFieldID(jcInfo, "byteArray", "[B");

    ParamInfo paramInfo;

    jint jin = env->GetIntField(paramObj, intValue);
    jboolean jb = env->GetBooleanField(paramObj, boolValue);
    jchar jc = env->GetCharField(paramObj, charValue);
    jdouble jd = env->GetDoubleField(paramObj, doubleValue);
    jbyte jby = env->GetByteField(paramObj, bytew);
    jstring jstr = (jstring) env->GetObjectField(paramObj, str);
    const char *pszStr = (char *) env->GetStringUTFChars(jstr, 0);
    LOGD("jin:%d,jb:%d,jc:%c,jd:%lf,jby:%u,jstr:%s", jin, jb, jc, jd, jby, pszStr);

    //获取实例的变量array的值
    jbyteArray ja = (jbyteArray) env->GetObjectField(paramObj, byteArray);
    int nArrLen = env->GetArrayLength(ja);


    char *chArr = (char *) env->GetByteArrayElements(ja, 0);

    memcpy(paramInfo.array, chArr, nArrLen);
    LOGD("paramInfo.strlen=%d", strlen(chArr));
    LOGD("paramInfo.arrayi=%d", chArr[9]);
    LOGD("paramInfo.nArrLen=%d", nArrLen);

    //获取实例的变量str的值
    strcpy(paramInfo.str, pszStr);

    paramInfo.intValue = jin;
    paramInfo.boolValue = jb;
    paramInfo.charValue = jc;
    paramInfo.doubleValue = jd;
    paramInfo.intbyte = jby;

    LOGD("paramInfo.array=%s, paramInfo.boolValue=%d, paramInfo.charValue=%c\n",
         paramInfo.array, paramInfo.boolValue, paramInfo.charValue);
    LOGD("paramInfo.doubleValue=%lf, paramInfo.intValue=%d,  paramInfo.str=%s,paramInfo.intbyte=%d\n",
         paramInfo.doubleValue, paramInfo.intValue, paramInfo.str, paramInfo.intbyte);

    jobject joInfo = env->AllocObject(jcInfo);
    env->SetBooleanField(joInfo, boolValue, paramInfo.boolValue);
    env->SetCharField(joInfo, charValue, (jchar) paramInfo.charValue);
    env->SetDoubleField(joInfo, doubleValue, paramInfo.doubleValue);
    env->SetIntField(joInfo, intValue, paramInfo.intValue);
    env->SetByteField(joInfo, bytew, paramInfo.intbyte);
    env->SetObjectField(joInfo, str, jstr);

    return joInfo;
}






