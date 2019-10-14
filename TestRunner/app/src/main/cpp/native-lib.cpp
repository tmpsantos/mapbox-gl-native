#include <jni.h>
#include <string>
#include <vector>
#include <mbgl/render_test_runner.hpp>

extern "C" JNIEXPORT jint JNICALL
Java_com_mapbox_testrunner_MainActivity_runTestRunner(
        JNIEnv *env,
        jobject /* this */,
        jobjectArray testCmdLineArgs) {

    // Extract the test run params and prepare argc/argv pair
    int argc = env->GetArrayLength(testCmdLineArgs);

    std::vector<std::string> argv;
    for (int i = 0; i < argc; ++i) {
        jstring string = (jstring) (env->GetObjectArrayElement(gtestCmdLineArgs, i));
        const char *rawString = env->GetStringUTFChars(string, 0);
        argv.emplace_back(rawString);
        env->ReleaseStringUTFChars(string, rawString);
    }

    int result = mbgl::runRenderTests(argc, argv.data());

//    // Cleanup
//    for (int i = 0; i < argc; i++) delete[] argv[i];
//    delete[] argv;

    return result;
}
