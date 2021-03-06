package com.quliang.myapplicationc1.ui;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

import com.quliang.myapplicationc1.R;
import com.quliang.myapplicationc1.bean.ParamInfoBean;
import com.quliang.myapplicationc1.javanative.JniMethod;
import com.quliang.myapplicationc1.util.AppLog;

/**
 * Created by quliang on 18-9-26.
 */

public class JavaCplusCallActivity extends AppCompatActivity {


    Handler handler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    int a = (int) msg.obj;
                    tv.setText("" + a);
                    AppLog.D("a:" + a);
                    break;

            }
        }
    };


    TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_javacpluscall);
        tv = (TextView) findViewById(R.id.sample_text);


        initData();
    }

    private void initData(){
        JniMethod jniMethod = new JniMethod();
//        tv.setText(""+jniMethod.getStringFromNative());
        tv.setText("" + jniMethod.sumFromJNI(1220, 22));

//        jniMethod.getJavaNativeField();
//        jniMethod.getJavaNativeMethod();
//        jniMethod.returnValueVoid();
//        AppLog.D("kan:"+jniMethod.a);
//        double a=18;

        byte[] b = new byte[10];
        for (int i = 0; i < 9; i++) {
            b[i] = (byte) (i + 97);
        }
        ParamInfoBean paramInfoBean = new ParamInfoBean(true, 'w', 18.8, 1112, new Byte("124"), "kankanni");
        paramInfoBean.setByteArray(b);

        ParamInfoBean c_paramInfoBean = (ParamInfoBean)jniMethod.setObj(paramInfoBean);

        AppLog.D("c_paramInfoBean.boolValue:" + c_paramInfoBean.boolValue);
        AppLog.D("c_paramInfoBean.charValue:" + c_paramInfoBean.charValue);
        AppLog.D("c_paramInfoBean.doubleValue:" + c_paramInfoBean.doubleValue);
        AppLog.D("c_paramInfoBean.intValue:" + c_paramInfoBean.intValue);
        AppLog.D("c_paramInfoBean.bytew:" + c_paramInfoBean.bytew);
        AppLog.D("c_paramInfoBean.str:" + c_paramInfoBean.str);

//        public byte byteArray[];
    }


}
