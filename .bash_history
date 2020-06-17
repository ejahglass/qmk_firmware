qmk setup ejahglass/qmk_firmware
qmk setup ejahglass/qmk_firmware
#!/bin/bash
function export_variables {     local util_dir=~/qmk_utils;     export PATH=$PATH:$util_dir;     export PATH=$PATH:$util_dir/dfu-programmer;     export PATH=$PATH:$util_dir/dfu-util-0.9-win64;     export PATH=$PATH:$util_dir/bootloadHID.2012-12-08/commandline;     export PATH=$PATH:$util_dir/avr8-gnu-toolchain/bin;     export PATH=$PATH:$util_dir/gcc-arm-none-eabi/bin; }
export_variables
qmk setup ejahglass/qmk_firmware
qmk setup ejahglass/qmk_firmware
qmk compile
qmk setup ejahglass/qmk_firmware
git add .
git commit -m "redo"
git config --global user.email elijahsing01@gmail.com
git sonfig --global user.name ejahglass
git config --global user.name ejahglass
git commit -m "redo"
git push
git push
qmk compile
