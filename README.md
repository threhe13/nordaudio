# NordAudio

## Portaudio

[How to Build PortAudio](https://files.portaudio.com/docs/v19-doxydocs/compile_mac_coreaudio.html)

> [!IMPORTANT]
> PortAudio 프로젝트에서 몇가지 Flags를 설정해주어야 합니다. M2 Pro 기준으로 빌드 시, Makefile에서 CFlags에 `-Wno-unused-but-set-variable`를 추가해주어 사용하지 않는 변수에 대한 오류를 제거해주어야 합니다. 추가적으로 shared_library를 사용할 계획이므로 LDFLAGS에서 `-shared` 속성을 활성화 해주어야 합니다.

- MacOS

  > - M2 Pro

- Windows

  > -

## API

`napi.h`는 `node-addon-api` 라이브러리를 사용하기 위한 헤더파일입니다.

두 함수 모두 `InstanceWrap`을 상속받는 함수입니다.

- `Napi::Addon<T>` : 자바스크립트 함수 제공
- `Napi::ObjectWrap<T>` : 자바스크립트 클래스 제공

[Reference](https://github.com/nodejs/node-addon-api/blob/main/doc/README.md)를 참고해주세요.

## NODE_API

- NODE_API_MODULE
- NODE_API_ADDON

[Reference](https://github.com/nodejs/node-addon-api/issues/1190)를 참고해주세요.

## Usage

```bash
npm install
npm run build
npm run test
```

`npm run build`를 실행하게 되면 `build/Release`에 `nordaudio.node` 파일이 생성됩니다.
