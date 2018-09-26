package com.quliang.myapplicationc1;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.quliang.myapplicationc1.javanative.JniMethod;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
//    static {
//        System.loadLibrary("native-lib");
//    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView) findViewById(R.id.sample_text);
        JniMethod jniMethod =new JniMethod();
        tv.setText(""+jniMethod.getStringFromNative());
    }


}
