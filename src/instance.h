/*
 * Copyright 2024 sunghyun
 */

#ifndef NORDAUDIOINSTANCE_H
#define NORDAUDIOINSTANCE_H

#include <napi.h>
#include "device.h"

namespace nordaudio
{

  class NordaudioInstance : public Napi::ObjectWrap<NordaudioInstance>
  {
  public:
    static Napi::Object Initialize(Napi::Env env, Napi::Object exports);
    NordaudioInstance(const Napi::CallbackInfo &info);
    ~NordaudioInstance();

  private:
    std::shared_ptr<NordaudioDevice> devices;
    Napi::Value GetVersion(const Napi::CallbackInfo &info);
  };

}

#endif // NORDAUDIOINSTANCE_H
