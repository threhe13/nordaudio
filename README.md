# NordAudio

## API

[Reference](https://github.com/nodejs/node-addon-api/blob/main/doc/README.md)

### napi.h vs. node_api.h

`napi.h`는 `node-addon-api` 라이브러리를 사용하기 위한 헤더파일입니다. `node_api.h`는

### Napi::Addon vs. Napi::ObjectWrap

두 함수 모두 `InstanceWrap`을 상속받는 함수이다.

- `Napi::Addon<T>` : 자바스크립트 함수 제공
- `Napi::ObjectWrap<T>` : 자바스크립트 클래스 제공

## NODE_API

[Reference](https://github.com/nodejs/node-addon-api/issues/1190)

- NODE_API_MODULE
- NODE_API_ADDON
