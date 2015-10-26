#ifndef MOBILITY_H
#define MOBILITY_H


const int MOBILITY_ADDRESS = 4;

class Mobility
{
    public:
        Mobility();
    protected:
    private:
        struct MobilityMsg
        {
            int speedR;
            int timeR;
            int speedL;
            int timeL;
            MobilityMsg(){}
            MobilityMsg(rSpeed, rTime, lSpeed, lTime)
                :speedR(rSpeed), timeR(rTime), speedL(lSpeed), timeL(lTime) {}
        };
};

#endif // MOBILITY_H
