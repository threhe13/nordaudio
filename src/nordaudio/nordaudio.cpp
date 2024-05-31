/*
 * Copyright 2024 Hohae
 */

#include <napi.h>

#include "nordaudio.h"
#include "portaudio.h"

Napi::Object Nordaudio::Initialize(Napi::Env env, Napi::Object exports)
{
  Napi::Function func = DefineClass(env,
                                    "Nordaudio",
                                    {
                                        InstanceMethod("GetVersion", &Nordaudio::GetVersion),
                                        // InstanceMethod("GetDevices", &Nordaudio::GetDevices),
                                    });

  Napi::FunctionReference *constructor = new Napi::FunctionReference();
  // Create a persistent reference to the class constructor. This will allow
  // a function called on a class prototype and a function
  // called on instance of a class to be distinguished from each other.
  *constructor = Napi::Persistent(func);

  // Store the constructor as the add-on instance data. This will allow this
  // add-on to support multiple instances of itself running on multiple worker
  // threads, as well as multiple instances of itself running in different
  // contexts on the same thread.
  //
  // By default, the value set on the environment here will be destroyed when
  // the add-on is unloaded using the `delete` operator, but it is also
  // possible to supply a custom deleter.
  env.SetInstanceData(constructor);
  exports.Set("Nordaudio", func);
  return exports;
}

Nordaudio::Nordaudio(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Nordaudio>(info)
{
  Napi::Env env = info.Env();

  PaError error = Pa_Initialize();
  if (error != paNoError)
  {
    Napi::Error::New(env, "[Nordaudio] Failed to initialize PortAudio\n").ThrowAsJavaScriptException();
  }
  else
  {
    printf("[Nordaudio] Success to initialize PortAudio\n");
  }
}

Nordaudio::~Nordaudio()
{
  PaError error = Pa_Terminate();
  if (error != paNoError)
  {
    printf("[Nordaudio] Failed to terminate PortAudio\n");
  }
  else
  {
    printf("[Nordaudio] Success to terminate PortAudio\n");
  }
}

Napi::Value Nordaudio::GetVersion(const Napi::CallbackInfo &info)
{
  return Napi::String::New(info.Env(), Pa_GetVersionText());
}
