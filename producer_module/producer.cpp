#include <yarp/os/Network.h>
#include <yarp/os/RFModule.h>
#include <yarp/os/Time.h>

#include <math.h>

// frequency and amplitude of the sinusoidal signal
#define FREQUENCY 1
#define AMPLITUDE 1

using namespace yarp::os;
class ProducerModule:public RFModule
{
  yarp::os::Port SignalPort;

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
    double signal = AMPLITUDE * sin(2 * M_PI * FREQUENCY * (t - t0));

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
  rf.configure(argc, argv);
  rf.setVerbose(true);

  module.runModule(rf);   

  return 0;
}
