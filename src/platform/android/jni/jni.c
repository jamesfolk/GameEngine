/* DO NOT EDIT THIS FILE - it is machine generated */
#include "../../../core/game.h"
#include "../../../core/macros.h"
#include <jni.h>
/* Header for class com_example_jligameengine_GameLibJNIWrapper */

#ifndef _Included_com_example_jligameengine_GameLibJNIWrapper
#define _Included_com_example_jligameengine_GameLibJNIWrapper
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_jligameengine_GameLibJNIWrapper
 * Method:    on_surface_created
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jligameengine_GameLibJNIWrapper_on_1surface_1created
(JNIEnv * env, jclass cls) {
	UNUSED(env);
	UNUSED(cls);
	on_surface_created();
}

/*
 * Class:     com_example_jligameengine_GameLibJNIWrapper
 * Method:    on_surface_changed
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_example_jligameengine_GameLibJNIWrapper_on_1surface_1changed
(JNIEnv * env, jclass cls, jint width, jint height) {
	UNUSED(env);
	UNUSED(cls);

	UNUSED(width);
	UNUSED(height);
	on_surface_changed();
}

/*
 * Class:     com_example_jligameengine_GameLibJNIWrapper
 * Method:    on_draw_frame
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jligameengine_GameLibJNIWrapper_on_1draw_1frame
(JNIEnv * env, jclass cls) {
	UNUSED(env);
	UNUSED(cls);
	on_draw_frame();
}


#ifdef __cplusplus
}
#endif
#endif
