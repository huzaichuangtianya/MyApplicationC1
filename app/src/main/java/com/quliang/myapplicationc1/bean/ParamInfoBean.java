package com.quliang.myapplicationc1.bean;

/**
 * Created by quliang on 18-9-25.
 */

public class ParamInfoBean {
    public boolean boolValue;
    public char charValue;
    public double doubleValue;
    public int intValue;
    public byte bytew;
    public String str;

    public ParamInfoBean(boolean boolValue, char charValue, double doubleValue, int intValue, byte array, String str) {
        this.boolValue = boolValue;
        this.charValue = charValue;
        this.doubleValue = doubleValue;
        this.intValue = intValue;
        this.bytew = array;
        this.str = str;
    }

}
