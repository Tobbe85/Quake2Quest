#if !defined(vrcommon_h)
#define vrcommon_h

#include <android/log.h>
#include <jni.h>
#include <stdbool.h>
#include <stdint.h>

#include <EGL/egl.h>
#include <GLES3/gl3.h>

#ifndef XR_USE_PLATFORM_ANDROID
#define XR_USE_PLATFORM_ANDROID
#endif
#ifndef XR_USE_GRAPHICS_API_OPENGL_ES
#define XR_USE_GRAPHICS_API_OPENGL_ES
#endif

#include <openxr/openxr.h>
#include <openxr/openxr_platform.h>

#include "mathlib.h"

#define LOG_TAG "Quake2VR"

#ifndef NDEBUG
#define DEBUG 1
#endif

#define ALOGE(...) __android_log_print( ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__ )

#if DEBUG
#define ALOGV(...) __android_log_print( ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__ )
#else
#define ALOGV(...)
#endif

#define NUM_EYES 2

typedef struct {
    XrVector3f Position;
    XrQuaternionf Orientation;
} q2xrPose;

typedef struct {
    q2xrPose Pose;
} q2xrHeadPose;

typedef struct {
    q2xrHeadPose HeadPose;
    XrSpaceVelocity Velocity;
    bool Active;
} ovrTracking;

typedef XrQuaternionf ovrQuatf;

typedef struct {
    float x;
    float y;
} ovrVector2f;

typedef struct {
    uint32_t Buttons;
    uint32_t Touches;
    float IndexTrigger;
    float GripTrigger;
    ovrVector2f Joystick;
} ovrInputStateTrackedRemote;

typedef uint64_t ovrDeviceID;

#define ovrButton_A             0x00000001u
#define ovrButton_B             0x00000002u
#define ovrButton_RThumb        0x00000004u
#define ovrButton_X             0x00000100u
#define ovrButton_Y             0x00000200u
#define ovrButton_LThumb        0x00000400u
#define ovrButton_Enter         0x00100000u
#define ovrButton_GripTrigger   0x04000000u
#define ovrButton_Trigger       0x20000000u
#define ovrButton_Joystick      0x80000000u
#define ovrTouch_ThumbRest      0x00000010u

#define XR_DEVICE_TYPE_GENERIC  0
#define XR_DEVICE_TYPE_META     1
#define XR_DEVICE_TYPE_PICO     2

extern bool quake2_initialised;

extern long long global_time;

extern float playerHeight;
extern float playerYaw;

extern bool showingScreenLayer;

extern vec3_t worldPosition;

extern vec3_t hmdPosition;
extern vec3_t hmdorientation;
extern vec3_t positionDeltaThisFrame;

extern vec3_t weaponangles;
extern vec3_t weaponoffset;

extern vec3_t flashlightangles;
extern vec3_t flashlightoffset;

#define DUCK_NOTDUCKED 0
#define DUCK_BUTTON 1
#define DUCK_CROUCHED 2
extern int ducked;

extern bool player_moving;


float radians(float deg);
float degrees(float rad);
qboolean isMultiplayer();
double GetTimeInMilliSeconds();
float length(float x, float y);
float nonLinearFilter(float in);
bool between(float min, float val, float max);
void rotateAboutOrigin(float v1, float v2, float rotation, vec2_t out);
void QuatToYawPitchRoll(ovrQuatf q, float pitchAdjust, vec3_t out);
bool useScreenLayer();
void handleTrackedControllerButton(u_int32_t buttonsNew, u_int32_t buttonsOld, uint32_t button, int key);

#endif //vrcommon_h
