package com.quliang.myapplicationc1.javanative;

import com.quliang.myapplicationc1.bean.ParamInfoBean;
import com.quliang.myapplicationc1.util.AppLog;

/**
 * Created by quliang on 18-9-26.
 */

public class JniMethod {
    static {
        System.loadLibrary("native-lib");
    }

    public native String stringFromJNI();
    public native int getStringFromNative();
    public native int sumFromJNI(int a, int b);
    public native int getJavaNativeField();
    public native int getJavaNativeMethod();
    public native void returnValueVoid();
    public native int setObj(ParamInfoBean paramInfoBean);


    public int a=10;

public void javaNativeMdCall(){
    AppLog.D("niaho1");
}


}
