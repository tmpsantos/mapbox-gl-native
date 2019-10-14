#include <jni.h>
#include <string>
#include <vector>
#include <mbgl/render_test_runner.hpp>

extern "C" JNIEXPORT jint JNICALL
Java_com_mapbox_testrunner_MainActivity_runTestRunner(
        JNIEnv *env,
        jobject /* this */,
        jobjectArray testCmdLineArgs) {

//    state->activity->vm->AttachCurrentThread(&env, 0);
//
//    jobject me = state->activity->clazz;
//
//    jclass acl = env->GetObjectClass(me); //class pointer of NativeActivity
//    jmethodID giid = env->GetMethodID(acl, "getIntent", "()Landroid/content/Intent;");
//    jobject intent = env->CallObjectMethod(me, giid); //Got our intent
//
//    jclass icl = env->GetObjectClass(intent); //class pointer of Intent
//    jmethodID gseid = env->GetMethodID(icl, "getStringExtra", "(Ljava/lang/String;)Ljava/lang/String;");
//
//    jstring jsParam1 = env->CallObjectMethod(intent, gseid, env->NewStringUTF("MY_PARAM_1"));
//    const char *Param1 = env->GetStringUTFChars(jsParam1, 0);
////When done with it, or when you've made a copy
//    env->ReleaseStringUTFChars(jsParam1, Param1);

    int argc = env->GetArrayLength(testCmdLineArgs);
    char **argv = new char *[argc + 1];
    for (int i = 0; i < argc; ++i) {
        jstring string = (jstring) (env->GetObjectArrayElement(testCmdLineArgs, i));
        const char *rawString = env->GetStringUTFChars(string, 0);
        argv[i] = new char[strlen(rawString) + 1];
        strcpy(argv[i], rawString);
        env->ReleaseStringUTFChars(string, rawString);
    }

    int result = mbgl::runRenderTests(argc, argv);

    // Cleanup
    for (int i = 0; i < argc; i++) delete[] argv[i];
    delete[] argv;

    return result;
}
