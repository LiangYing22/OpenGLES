package com.innup.opengles;

import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class LyGLSurfaceViewRenderer implements GLSurfaceView.Renderer {

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        MethodFromNative.getInstance().onSurfaceCreated();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        MethodFromNative.getInstance().onSurfacechanged(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        MethodFromNative.getInstance().onDrawFrame();
    }
}

