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
  Napi::Function func = DefineClass(env, "Nordaudio", {InstanceMethod("GetDevices", &Nordaudio::GetDevices)});

  Napi::FunctionReference *constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);
  exports.Set("Nordaudio", func);
  return exports;
}

Napi::Value Nordaudio::GetDevices(const Napi::CallbackInfo &info)
{
  return Napi::Number::New(info.Env(), 3);
}

// Napi::Value Nordaudio::GetVersion(const Napi::CallbackInfo &info)
// {
//   return Napi::Number::New(info.Env(), Pa_GetVersion());
// }