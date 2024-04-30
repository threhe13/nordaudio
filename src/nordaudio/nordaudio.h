/*
 * Copyright 2024 Hohae
 */

#ifndef NORDAUDIO_H
#define NORDAUDIO_H

#include <napi.h>

class Nordaudio : public Napi::ObjectWrap<Nordaudio>
{
public:
  Nordaudio(const Napi::CallbackInfo &info);
  // ~Nordaudio();

  static Napi::Object Initialize(Napi::Env env, Napi::Object exports);

private:
  Napi::Value GetDevices(const Napi::CallbackInfo &info);
  Napi::Value GetVersion(const Napi::CallbackInfo &info);
};

#endif // NORDAUDIO_H
