/*
 * Copyright 2024 Hohae
 */

#include <napi.h>
#include "portaudio.h"
#include "devices.h"

Napi::Value GetDevices(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  PaError error = Pa_Initialize();

  if (error != paNoError)
  {
    // Napi::String errorText = Napi::String::New(env, Pa_GetErrorText(error).c_str());
    Napi::Error::New(env, "[ERROR] Failed to initialize PortAudio").ThrowAsJavaScriptException();
  }

  int devices = Pa_GetDeviceCount();
  Napi::Array deviceList = Napi::Array::New(env, devices);

  if (devices == 0)
  {
    Pa_Terminate();
    return deviceList;
  }

  for (int i = 0; i < devices; i++)
  {
    const PaDeviceInfo *device = Pa_GetDeviceInfo(i);
    Napi::Object deviceInfo = Napi::Object::New(env);
    deviceInfo.Set("name", Napi::String::New(env, device->name));
    deviceList[i] = (deviceInfo);
  }

  Pa_Terminate();
  return deviceList;
}
