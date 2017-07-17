#!/usr/bin/env bash

set -e
set -o pipefail

QT_VERSION='\\\"qt-v1.4.0\\\"'

rm -f mapbox-gl-native.pro

#
# Default project header.
#
cat << EOF >> mapbox-gl-native.pro
TARGET = qmapboxgl

load(qt_helper_lib)

CONFIG += qt c++14 exceptions warn_off staticlib object_parallel_to_source
CONFIG -= c++1z

QT += network-private \\
      gui-private \\
      sql-private

QMAKE_CXXFLAGS += \\
    -DNDEBUG \\
    -DQT_IMAGE_DECODERS \\
    -DQT_BUILD_MAPBOXGL_LIB \\
    -DRAPIDJSON_HAS_STDSTRING=1 \\
    -DMBGL_USE_GLES2 \\
    -D__QT__ \\
    -O3 \\
    -ftemplate-depth=1024 \\
    -fvisibility-inlines-hidden \\
    -fvisibility=hidden

android|win32|darwin|qnx {
    SOURCES += \\
        platform/qt/src/thread.cpp
} else {
    SOURCES += \\
        platform/default/thread.cpp
}

darwin {
    LIBS += \\
        -framework Foundation
}

win32 {
    QMAKE_CXXFLAGS += \\
        -D_WINDOWS \\
        -DNOGDI \\
        -DNOMINMAX \\
        -D_USE_MATH_DEFINES
}

qtConfig(system-zlib) {
    QMAKE_USE_PRIVATE += zlib
} else {
    QT_PRIVATE += zlib-private
}

# QTBUG-59035
TR_EXCLUDE += \$\$PWD/*

qtConfig(icu) {
    QMAKE_USE_PRIVATE += icu

    SOURCES += \\
        platform/default/bidi.cpp
} else {
    SOURCES += \\
        platform/qt/src/bidi.cpp
}

EOF

#
# Mapbox GL core files and Qt platform bindings.
#
echo "SOURCES += \\" >> mapbox-gl-native.pro
for FILE in $(git ls-files src/*.c src/*.cpp platform/qt/src/*.cpp |grep -v bidi.cpp |grep -v thread.cpp |grep -v headless_backend_qt.cpp) ; do
    echo "    ${FILE#*#} \\" >> mapbox-gl-native.pro
done

#
# Things we use from default implementation, hand picked.
#
cat << EOF >> mapbox-gl-native.pro
    platform/default/asset_file_source.cpp \\
    platform/default/default_file_source.cpp \\
    platform/default/file_source_request.cpp \\
    platform/default/local_file_source.cpp \\
    platform/default/local_glyph_rasterizer.cpp \\
    platform/default/mbgl/storage/offline.cpp \\
    platform/default/mbgl/storage/offline_database.cpp \\
    platform/default/mbgl/storage/offline_download.cpp \\
    platform/default/mbgl/util/default_thread_pool.cpp \\
    platform/default/mbgl/util/shared_thread_pool.cpp \\
    platform/default/online_file_source.cpp

EOF

#
# Header files to be processed by MOC.
#
echo "HEADERS += \\" >> mapbox-gl-native.pro
for FILE in $(git ls-files platform/qt/src/*.hpp platform/qt/include/*.hpp) ; do
    echo "    ${FILE#*#} \\" >> mapbox-gl-native.pro
done

#
# 3rd party libraries used by Mapbox GL
#
echo "" >> mapbox-gl-native.pro
echo "INCLUDEPATH += \\" >> mapbox-gl-native.pro
for FILE in $(ls mason_packages/headers |grep -v cheap_ruler) ; do
    VERSION=$(ls mason_packages/headers/$FILE)

    echo "    deps/${FILE#*#}/${VERSION#*#} \\" >> mapbox-gl-native.pro
    echo "    deps/${FILE#*#}/${VERSION#*#}/include \\" >> mapbox-gl-native.pro
done

cat << EOF >> mapbox-gl-native.pro
    include \\
    platform/default \\
    platform/qt \\
    platform/qt/include \\
    src

EOF

cat << EOF >> mapbox-gl-native.pro
QMAKE_CXXFLAGS += \\
    -DMBGL_VERSION_REV=$QT_VERSION
EOF
