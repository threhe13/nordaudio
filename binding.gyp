{
  "targets": [
    {
      "target_name": "nordaudio",
      "sources": [ 
        "src/main.cpp", 
        "src/nordaudio/nordaudio.cpp",
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "portaudio/include/",
        "src/nordaudio/",
      ],
      "dependencies": [
        # "<!@(node -p \"require('node-addon-api').gyp\")",
      ],
      "defines": [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      "conditions": [
        ["OS=='win' and target_arch=='x64'", {
          # "link_settings": {
          #   "libraries": [
          #     "-Wl,-rpath,build/Release/"
          #   ]
          # },
          "libraries" : [
            "<(module_root_dir)/portaudio/bin/Windows/x64/portaudio_x64.lib"
          ],
          "copies": [
            {
              "destination": "<(module_root_dir)/build/Release/",
              "files": [
                "portaudio/bin/Windows/x64/portaudio_x64.dll",
              ]
            }
          ]
        }],
        ["OS=='win' and target_arch=='x32'", {
          "link_settings": {
            "libraries": [
              "-Wl,-rpath,build/Release/"
            ]
          },
          "libraries" : [
            "<(module_root_dir)/portaudio/bin/Windows/Win32/portaudio_x86.lib"
          ],
          "copies": [
            {
              "destination": "<(module_root_dir)/build/Release/",
              "files": [
                "portaudio/bin/Windows/Win32/portaudio_x86.dll",
              ]
            }
          ]
        }],
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