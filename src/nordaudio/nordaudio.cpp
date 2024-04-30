/*
 * Copyright 2024 Hohae
 */

#include <napi.h>
#include "nordaudio.h"
#include "portaudio.h"

Nordaudio::Nordaudio(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Nordaudio>(info)
{
  // Napi::Env env = info.Env();
}

Napi::Object Nordaudio::Initialize(Napi::Env env, Napi::Object exports)
{
  Napi::Function func = DefineClass(env, "Nordaudio", {InstanceMethod("GetDevices", &Nordaudio::GetDevices), InstanceMethod("GetVersion", &Nordaudio::GetVersion)});

  Napi::FunctionReference *constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);
  exports.Set("Nordaudio", func);
  return exports;
}

Napi::Value Nordaudio::GetDevices(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  PaError error = Pa_Initialize();

  if (error != paNoError)
  {
    // Napi::String errorText = Napi::String::New(env, Pa_GetErrorText(error).c_str());
    Napi::Error::New(env, "[ERROR] Failed to initialize PortAudio").ThrowAsJavaScriptException();
  }

  int devices = Pa_GetDeviceCount();

  // TODO: 오디오 장치가 하나도 없는 경우
  if (devices == 0)
  {
  }

  Napi::Array deviceList = Napi::Array::New(env, devices);

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

Napi::Value Nordaudio::GetVersion(const Napi::CallbackInfo &info)
{
  return Napi::String::New(info.Env(), Pa_GetVersionText());
}