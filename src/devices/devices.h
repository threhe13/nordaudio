/*
 * Copyright 2024 Hohae
 */

#ifndef DEVICES_H
#define DEVICES_H

#include <napi.h>

class Devices
{
public:
  Napi::Value GetDevices(const Napi::CallbackInfo &info);

private:
}

#endif