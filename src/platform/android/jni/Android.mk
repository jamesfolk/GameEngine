LOCAL_PATH := $(call my-dir)

CORE_RELATIVE_PATH := /Users/jamesfolk/Dropbox/GameDevelopment/JLIGameEngine/src/core
COMMON_RELATIVE_PATH := /Users/jamesfolk/Dropbox/GameDevelopment/JLIGameEngine/src/platform/common
THIRDPARTY_RELATIVE_PATH := /Users/jamesfolk/Dropbox/GameDevelopment/JLIGameEngine/src/3rdParty

include $(CLEAR_VARS)
 
LOCAL_MODULE    := game
LOCAL_CFLAGS    := -Wall -Wextra
LOCAL_SRC_FILES := platform_asset_utils.c \
                   platform_log.c \
                   jni.c \
                   $(CORE_RELATIVE_PATH)/game.c \
                   $(CORE_RELATIVE_PATH)/texture.c \
                   $(CORE_RELATIVE_PATH)/shader.c \
                   $(CORE_RELATIVE_PATH)/buffer.c \
                   #$(CORE_RELATIVE_PATH)/image.c \
                   #$(CORE_RELATIVE_PATH)/asset_utils.c \
                   
                   
                   

LOCAL_C_INCLUDES := $(COMMON_RELATIVE_PATH)
LOCAL_C_INCLUDES += $(CORE_RELATIVE_PATH)

LOCAL_STATIC_LIBRARIES := libpng
LOCAL_LDLIBS := -lGLESv2 -llog -landroid
 
include $(BUILD_SHARED_LIBRARY)
 
$(call import-add-path, $(THIRDPARTY_RELATIVE_PATH))
$(call import-module,libpng)
