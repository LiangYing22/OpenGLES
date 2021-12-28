package com.innup.opengles;

import android.content.Context;
import android.opengl.GLSurfaceView;

public class LyGLSurfaceView extends GLSurfaceView {
    GLSurfaceView.Renderer renderer;
    public LyGLSurfaceView(Context context) {
        super(context);
        //设置版本
        setEGLContextClientVersion(2);
        //创建并设置渲染器
        renderer = new LyGLSurfaceViewRenderer();
        setRenderer(renderer);
    }
}
