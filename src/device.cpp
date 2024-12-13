/*
 * Copyright 2024 sunghyun
 */

#include <napi.h>

#include "portaudio.h"
#include "device.h"

namespace nordaudio
{

  NordaudioDevice::NordaudioDevice(const Napi::CallbackInfo &info) : Napi::ObjectWrap<NordaudioDevice>(info)
  {
    Napi::Env env = info.Env();

    num_of_devices = Pa_GetDeviceCount();
    if (num_of_devices == 0)
    {
      printf("[Nordaudio] No devices");
    }
    else
    {
      printf("[Nordaudio] Find %d devices", num_of_devices);
    }
  }

  NordaudioDevice::~NordaudioDevice()
  {
  }

  void NordaudioDevice::RefreshDevices(const Napi::CallbackInfo &info)
  {
    Napi::Env env = info.Env();
  }

  Napi::Value NordaudioDevice::GetAllDevices(const Napi::CallbackInfo &info)
  {
    Napi::Env env = info.Env();

    Napi::Array device_list = Napi::Array::New(env, num_of_devices);

    if (num_of_devices == 0)
    {
      printf("[Nordaudio] No device");
      return device_list;
    }

    for (int i = 0; i < num_of_devices; i++)
    {
      const PaDeviceInfo *device = Pa_GetDeviceInfo(i);
      Napi::Object device_info = Napi::Object::New(env);
      device_list.Set("name", Napi::String::New(env, device->name));
      device_list.Set("sampleRate", Napi::Number::New(env, device->defaultSampleRate));
      device_list.Set("inputChannel", Napi::Number::New(env, device->maxInputChannels));
      device_list.Set("outputChannel", Napi::Number::New(env, device->maxOutputChannels));
      device_list[i] = device_info;
    }

    return device_list;
  }

}