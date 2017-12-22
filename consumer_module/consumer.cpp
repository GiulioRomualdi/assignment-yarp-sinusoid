/* -*- mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include <yarp/os/Network.h>
#include <yarp/os/RFModule.h>

#include <yarp/os/BufferedPort.h>

#include <iostream>
#include <fstream>

class ConsumerModule:public yarp::os::RFModule
{
    yarp::os::BufferedPort<yarp::os::Bottle> SignalPort;
    std::ofstream file;
  
public:
    double getPeriod()
    {
        // period of the module (seconds)
        return 0.01;
    }

    bool updateModule()
    {
        // return immediately if no message is available 
        yarp::os::Bottle *msg = SignalPort.read(false);
        if (msg != NULL)
            {
                // get timestamp and signal from the msg
                double t = msg->get(0).asDouble();
                double signal = msg->get(1).asDouble();

                // save data into a file
                file << t << ", "<< signal <<std::endl;
            }
        return true;
    }

    bool configure(yarp::os::ResourceFinder &rf)
    {
        // open the stream
        file.open("signal.txt");

        // open the port
        SignalPort.open("/consumer/signal:i");

        return true;
    }

    bool interruptModule()
    {
        return true;
    }

    bool close()
    {
        // optional, close port explicitly
        SignalPort.close();

        // close the stream
        file.close();
    
        return true;
    }
};

int main(int argc, char * argv[])
{
    // initialize yarp network 
    yarp::os::Network yarp;

    // create the moduke your module
    ConsumerModule module;

    // prepare and configure the resource finder
    yarp::os::ResourceFinder rf;
    rf.setVerbose(true);
    rf.configure(argc, argv);

    // run the module
    module.runModule(rf);

    return 0;
}
