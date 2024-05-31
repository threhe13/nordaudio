/*
 * Copyright 2024 Hohae
 */

#ifndef NORDAUDIO_H
#define NORDAUDIO_H

#include <napi.h>

class Nordaudio : public Napi::ObjectWrap<Nordaudio>
{
public:
  static Napi::Object Initialize(Napi::Env env, Napi::Object exports);
  Nordaudio(const Napi::CallbackInfo &info);
  ~Nordaudio();

private:
  Napi::Value GetVersion(const Napi::CallbackInfo &info);
};

#endif // NORDAUDIO_H
