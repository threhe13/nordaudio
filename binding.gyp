{
  "targets": [
    {
      "target_name": "nordaudio",
      "sources": [ 
        "src/main.cpp", 
        "src/nordaudio/nordaudio.cpp" 
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "portaudio/include/",
        "src/nordaudio/"
      ],
      "dependencies": [
        # "<!@(node -p \"require('node-addon-api').gyp\")",
      ],
      "defines": [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      "conditions": [
        ['OS=="win"', {}],
        ['OS=="mac"', {
          "cflgs+": [ '-fvisibility=hideen' ],
          "xcode_settings": {
            'DYLIB_INSTALL_NAME_BASE': '@rpath'
            # "GCC_SYMBOLS_PRIVATE_EXTERN": "YES", # -fvisibility=hidden
            # 'GCC_ENABLE_CPP_RTTI': 'YES',
            # 'MACOSX_DEPLOYMENT_TARGET': '10.7',
            # 'OTHER_CPLUSPLUSFLAGS': [
            #   '-std=c++11',
            #   '-stdlib=libc++',
            #   '-fexceptions'
            # ]
          },
          "link_settings": {
            "libraries": [
              # "-L/portaudio/include/"
              "-Wl,-rpath,build/Release/"
              # "<(PRODUCT_DIR)/portaudio/bin/MacOS/libportaudio.dylib"
            ]
          },
          "libraries": [
            "libportaudio.dylib"
          ],
          "copies": [
            {
              "destination": "build/Release/",
              "files": [
                "portaudio/bin/MacOS/libportaudio.dylib"
              ]
            }
          ]
        }]
      ],
    }
  ]
}