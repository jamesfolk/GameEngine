cd jni
ndk-build clean
ndk-build
cd ..
ant clean build
adb install -r bin/JLIGameEngine.apk
adb shell am start -n com.example.jligameengine/com.example.jligameengine.MainActivity

