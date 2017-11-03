#ifndef _FLVSTREAMTOH264_H_
#define _FLVSTREAMTOH264_H_

#include "BSFPDefined.hpp"
#include <list>

typedef void (*H264PacketCallback) (BSTPHeader* frame);

class FlvStreamToH264
{
public:
	FlvStreamToH264();
	~FlvStreamToH264();

public:
	int pushPacket(unsigned char* pData, int len, bool bFirst = false);
	int getPacket(BSTPHeader* frame);
	void setFrameCallback(H264PacketCallback func)
	{
		frameCallback_ = func;
	}
public:
	H264PacketCallback frameCallback_;
	bool bOneFrame_;
	unsigned char* frameCache_; ///<������һ֡����
	std::list<BSTPHeader*> frameQueue_; ///<ת������֡����
	unsigned char* leftBuff_;
	int leftLen_;

private:
	int parseFlvHeader(unsigned char** pData, int* len);
	int parseBody(unsigned char* pData, int* len);
	int parseTagData(unsigned char* pData, int* len);
};

#endif