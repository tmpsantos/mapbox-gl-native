//#include "jni_native.hpp"
#include "logger.hpp"

#include <mbgl/render_test.hpp>

#include <android_native_app_glue.h>

#include <jni/jni.hpp>
#include <android/log.h>

#ifndef NDEBUG
#  define LOGV(...)  ((void)__android_log_print(ANDROID_LOG_VERBOSE, "threaded_app", __VA_ARGS__))
#else
#  define LOGV(...)  ((void)0)
#endif

void android_main(struct android_app* app) {
    JNIEnv* env = nullptr;
    LOGV("%s:%d\n", __FUNCTION__, __LINE__);
    app->activity->vm->AttachCurrentThread(&env, NULL);
    LOGV("%s:%d\n", __FUNCTION__, __LINE__);


    jni::JNIEnv& v = jni::GetEnv(*app->activity->vm, jni::jni_version_1_6);
    mbgl::android::Logger::registerNative(v);
    //mbgl::android::registerNatives(app->activity->vm);
    LOGV("%s:%d\n", __FUNCTION__, __LINE__);

    char **argv = (char**) malloc(sizeof(char*) * 4);
    argv[0] = strdup("runner");
    argv[1] = strdup("-p");
    argv[2] = strdup(".");
    argv[3] = NULL;

    LOGV("argv[0] is %s\n", argv[0]);
    LOGV("argv[1] is %s\n", argv[1]);

    mbgl::runRenderTests(3, argv);
    LOGV("%s:%d\n", __FUNCTION__, __LINE__);

    app->activity->vm->DetachCurrentThread();
    LOGV("%s:%d\n", __FUNCTION__, __LINE__);

}
