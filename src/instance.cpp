/*
 * Copyright 2024 sunghyun
 */

#include <napi.h>
#include "portaudio.h"
#include "instance.h"
#include "device.h"

namespace nordaudio
{

  Napi::Object NordaudioInstance::Initialize(Napi::Env env, Napi::Object exports)
  {
    Napi::Function func = DefineClass(env,
                                      "Nordaudio",
                                      {
                                          InstanceMethod("GetVersion", &NordaudioInstance::GetVersion),
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

  NordaudioInstance::NordaudioInstance(const Napi::CallbackInfo &info) : Napi::ObjectWrap<NordaudioInstance>(info)
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
      // devices = std::make_shared<NordaudioDevice>(info);
    }
  }

  NordaudioInstance::~NordaudioInstance()
  {
    PaError error = Pa_Terminate();
    if (error != paNoError)
    {
      printf("[Nordaudio] Failed to terminate PortAudio\n");
    }
    else
    {
      printf("[Nordaudio] Success to terminate PortAudio\n");
      // delete devices;
    }
  }

  Napi::Value NordaudioInstance::GetVersion(const Napi::CallbackInfo &info)
  {
    return Napi::String::New(info.Env(), Pa_GetVersionText());
  }

}