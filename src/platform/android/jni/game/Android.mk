LOCAL_PATH := $(call my-dir)

#MY_SRC_PATH := $(LOCAL_PATH)/../../../../src/
#SRC_PATH := /Users/jamesfolk/Dropbox/GameDevelopment/JLIGameEngine/src/



include $(CLEAR_VARS)

MY_CORE_RELATIVE_PATH := /Users/jamesfolk/Dropbox/GameDevelopment/JLIGameEngine/src/core
MY_COMMON_RELATIVE_PATH := /Users/jamesfolk/Dropbox/GameDevelopment/JLIGameEngine/src/platform/common/
#MY_THIRTPARTY_RELATIVE_PATH := /Users/jamesfolk/Dropbox/GameDevelopment/JLIGameEngine/src/3rdParty
MY_THIRTPARTY_RELATIVE_PATH := $(LOCAL_PATH)/../

LOCAL_MODULE := game

LOCAL_C_INCLUDES := $(MY_THIRTPARTY_RELATIVE_PATH)/libzip/ $(MY_THIRTPARTY_RELATIVE_PATH)/libpng/
LOCAL_STATIC_LIBRARIES := libzip libpng

#-Wno-psabi to remove warning about GCC 4.4 va_list warning
LOCAL_CFLAGS := -DANDROID_NDK

LOCAL_DEFAULT_CPP_EXTENSION := cpp 

LOCAL_SRC_FILES := platform_asset_utils.c \
                   platform_log.c \
                   jni.c \
                   $(MY_CORE_RELATIVE_PATH)/game.c \
                   $(MY_CORE_RELATIVE_PATH)/texture.c \
                   $(MY_CORE_RELATIVE_PATH)/shader.c \
                   $(MY_CORE_RELATIVE_PATH)/buffer.c \
                   $(MY_CORE_RELATIVE_PATH)/image.c \
                   $(MY_CORE_RELATIVE_PATH)/asset_utils.c \

LOCAL_C_INCLUDES := $(MY_COMMON_RELATIVE_PATH) \
                    $(MY_CORE_RELATIVE_PATH) \
                    $(MY_THIRTPARTY_RELATIVE_PATH)/libpng/ \
                    $(MY_THIRTPARTY_RELATIVE_PATH)/libzip/

LOCAL_LDLIBS := -lGLESv2 -llog -landroid -ldl -lz

include $(BUILD_SHARED_LIBRARY)
