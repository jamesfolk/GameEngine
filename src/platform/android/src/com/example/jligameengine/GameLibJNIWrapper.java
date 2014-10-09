package com.example.jligameengine;

import android.content.res.AssetManager;

public class GameLibJNIWrapper {
    static {
        System.loadLibrary("game");
        System.loadLibrary("stlport_shared");
    }
 
    public static native void on_surface_created();
 
    public static native void on_surface_changed(int width, int height);
 
    public static native void on_draw_frame();
    
    public static native void initAssetManager(AssetManager assetManager);
}
