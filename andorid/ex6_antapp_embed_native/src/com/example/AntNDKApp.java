package com.example;

import android.app.Activity;
import android.os.Bundle;

public class AntNDKApp extends Activity
{
    static
    {
        System.loadLibrary( "NativeLib" );
    }

    @Override protected void onCreate( Bundle icicle )
    {
        super.onCreate( icicle );

        onCreateNative();
    }

    public static native void onCreateNative();

};
