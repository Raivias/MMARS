#ifndef PERCEPTION_H
#define PERCEPTION_H

const int PERCEP_ADDRESS = 5;

class Perception
{
    public:
        Perception();
        int getDistance(int pin);
    protected:
    private:
        struct percepMsg
        {
            int port;
            int value;
            percepMsg(){}
            MobilityMsg(portNum, val = 0)
                :port(portNum), value(val) {}

        };
};

#endif // PERCEPTION_H
