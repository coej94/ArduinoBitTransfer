#ifndef ByteTransfer_h
#define ByteTransfer_h

class ByteTransfer{
public:
	ByteTransfer(int SIGNALOUT,int DATAOUT,int SIGNALIN, int DATAIN);
	void printBin();
	void checkSerialMonitor();
	void sendSignal(int value);	
private:
	int _SIGNALOUT;
	int _DATAOUT;
	int _SIGNALIN;
	int _DATAIN;
};

#endif