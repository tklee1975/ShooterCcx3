#!/bin/sh
cocos compile -p android -j 4
adb install -r ../bin/debug/android/Shooter-debug.apk
