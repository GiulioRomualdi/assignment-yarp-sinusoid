/* -*- mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*- */

#include <yarp/os/Network.h>
#include <yarp/os/RFModule.h>
#include <yarp/os/Time.h>

#include <math.h>

using namespace yarp::os;
class ProducerModule:public RFModule
{
    yarp::os::Port SignalPort;

    double frequency;
    double amplitude;
    double t0;
  
public:
    double getPeriod()
    {
        //  period of the module (seconds)
        return 0.01;
    }

    bool updateModule()
    {
        // get the current time
        double t = yarp::os::Time::now();

        // evaluate the signal
        double signal = amplitude * sin(2 * M_PI * frequency * (t - t0));

        // prepare the message
        Bottle msg;
        msg.addDouble((t - t0));
        msg.addDouble(signal);

        // send the message
        SignalPort.write(msg);
    }

    bool configure(yarp::os::ResourceFinder &rf)
    {
        // open the Signal port
        SignalPort.open("/producer/signal:o");

        amplitude = rf.find("amplitude").asDouble();
        frequency = rf.find("frequency").asDouble();

        // get init time
        t0 = yarp::os::Time::now();

        return true;
    }
  
  
    bool interruptModule()
    {
        return true;
    }
  
    bool close()
    {
        // close port explicitly
        SignalPort.close();

        return true;
    }
};

int main(int argc, char * argv[])
{
    // initialize yarp network
    Network yarp;
  
    // create the producer module 
    ProducerModule module;
  
    // prepare and configure the resource finder
    ResourceFinder rf;
    rf.setVerbose(true);
    rf.setDefaultConfigFile("config.ini");
    rf.configure(argc, argv);

    module.runModule(rf);   

    return 0;
}
