LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := openxr_loader

# Generic Khronos OpenXR loader. The active device runtime is resolved by the
# system OpenXR broker, so Quake2Quest does not ship/load per-HMD proprietary loaders.
LOCAL_SRC_FILES := lib$(LOCAL_MODULE).so

ifneq (,$(wildcard $(LOCAL_PATH)/$(LOCAL_SRC_FILES)))
  include $(PREBUILT_SHARED_LIBRARY)
endif
