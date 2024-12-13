/*
 * Copyright 2024 sunghyun
 */

#ifndef NORDAUDIODEVICE_H
#define NORDAUDIODEVICE_H

#include <napi.h>

namespace nordaudio
{

  class NordaudioDevice : public Napi::ObjectWrap<NordaudioDevice>
  {
  public:
    NordaudioDevice(const Napi::CallbackInfo &info);
    ~NordaudioDevice();

    void RefreshDevices(const Napi::CallbackInfo &info);
    Napi::Value GetAllDevices(const Napi::CallbackInfo &info);
    Napi::Value GetInputDevices(const Napi::CallbackInfo &info);
    Napi::Value GetOutputDevices(const Napi::CallbackInfo &info);
    Napi::Value SetInputDevices(const Napi::CallbackInfo &info);
    Napi::Value SetOutputDevices(const Napi::CallbackInfo &info);

  private:
    int num_of_devices = 0;
  };

}

#endif // NORDAUDIODEVICE_H
