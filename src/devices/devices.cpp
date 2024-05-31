/*
 * Copyright 2024 Hohae
 */

#include <napi.h>

#include "devices.h"
#include "portaudio.h"

Napi::Value Devices::GetDevices(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  int devices = Pa_GetDeviceCount();
  Napi::Array deviceList = Napi::Array::New(env, devices);

  if (devices == 0)
  {
    printf("[Nordaudio] No device");
    return deviceList;
  }

  for (int i = 0; i < devices; i++)
  {
    const PaDeviceInfo *device = Pa_GetDeviceInfo(i);
    Napi::Object deviceInfo = Napi::Object::New(env);

    deviceInfo.Set("name", Napi::String::New(env, device->name));
    deviceInfo.Set("sampleRate", Napi::Number::New(env, device->defaultSampleRate));
    deviceInfo.Set("inputChannel", Napi::Number::New(env, device->maxInputChannels));
    deviceInfo.Set("outputChannel", Napi::Number::New(env, device->maxOutputChannels));
    deviceList[i] = deviceInfo;
  }

  return deviceList;
}
