# Assignment YARP Sinusoid
The repository contains two YARP module:
* [producer](producer_module/): it opens a YARP port in streaming and sends a message containing a sinusoid with given frequency and amplitude (the desired values can be setted [here](producer_module/config/config.ini));
* [consumer](consumer_module/): it opens a YARP port to receive the signal and stores it into a file.

## Dependencies

* [yarp](http://www.yarp.it/)

## How to compile the modules

In order to **compile** and **install** the modules please run these commands
```sh
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=$ROBOT_INSTALL ../
make install
```

where `$ROBOT_INSTALL` is the folder where the modules will be installed.

**Note**: Please add into your `.bashrc` the following line:
```sh
export PATH=${PATH}:${ROBOT_INSTALL}/bin
```

## How to run the application

Launch yarpmanager
``` sh
cd assignment-yarp-sinusoid/
yarpmanager --from app/ymanager.ini
```
run all the modules and connect all the ports.

The `signal.txt` file will be saved into `assignment-yarp-sinusoid` folder.

## Status
[![Build Status](https://travis-ci.org/GiulioRomualdi/assignment-yarp-sinusoid.svg?branch=master)](https://travis-ci.org/GiulioRomualdi/assignment-yarp-sinusoid)
