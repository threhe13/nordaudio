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
        "portaudio/include",
        "./src/nordaudio/"
      ],
      "dependencies": [
        "<!@(node -p \"require('node-addon-api').gyp\")",
      ],
      "defines": [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      # "conditions": [
      #   ['OS=="win"', {}],
      #   ['OS=="mac"', {
      #     "xcode_settings": {
      #       'GCC_ENABLE_CPP_RTTI': 'YES',
      #       'MACOSX_DEPLOYMENT_TARGET': '10.7',
      #       'OTHER_CPLUSPLUSFLAGS': [
      #         '-std=c++11',
      #         '-stdlib=libc++',
      #         '-fexceptions'
      #       ]
      #     },
      #     "link_settings": {
      #       "libraries": [
      #         "-Wl,-rpath,@loader_path"
      #       ]
      #     },
      #     "libraries": [
      #       "libportaudio.dylib"
      #     ],
      #     "copies": [
      #       {
      #         "destination": "build/Release/",
      #         "files": [
      #           "<!@(ls -1 portaudio/bin/MacOS/libportaudio.dylib)"
      #         ]
      #       }
      #     ]
      #   }]
      # ],
    }
  ]
}