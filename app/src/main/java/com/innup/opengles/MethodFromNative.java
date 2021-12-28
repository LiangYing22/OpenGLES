package com.innup.opengles;

import android.content.res.AssetManager;

public class MethodFromNative {
    public native void onSurfaceCreated();
    public native void onSurfacechanged(int width, int height);
    public native void onDrawFrame();
    public native void loadAssetsText(AssetManager assetManager);

    private static MethodFromNative methodFromNative;

    private MethodFromNative(){
    }

    public static MethodFromNative getInstance(){
        if(methodFromNative == null){
            synchronized (MethodFromNative.class){
                if(methodFromNative == null){
                    methodFromNative = new MethodFromNative();
                }
            }
        }
        return methodFromNative;
    }
}
