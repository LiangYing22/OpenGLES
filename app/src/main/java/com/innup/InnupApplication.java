package com.innup;

import android.app.Application;

public class InnupApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        System.loadLibrary("testLy");//加载testLy.so
    }
}
