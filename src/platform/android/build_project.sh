cd jni
ndk-build clean
ndk-build
cd ..
ant clean 
ant init
ant build
ant debug
adb uninstall com.example.jligameengine 
adb install bin/JLIGameEngine-debug.apk
adb shell am start -n com.example.jligameengine/com.example.jligameengine.MainActivity

