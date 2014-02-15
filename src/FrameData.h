/*
 * FrameData.h
 *
 *  Created on: 09/12/2013
 *      Author: willytell
 */

#ifndef FRAMEDATA_H_
#define FRAMEDATA_H_

//C++
//#include <map>
//OpenCV
#include "opencv/highgui.h"
//Local
#include "RingBuffer.h"

using namespace std;

/*!
  \class   FrameDataMap
  \brief   A general storage map, for plugins to store and read their data
  \author  Stefan Zickler, (C) 2008

  This class acts as a storage map of string and data-pointer pairs.
  This allows any plugin to make its results publicly available to the
  entire image stack pipeline for the current frame.
*/
class FrameDataMap : protected map<string,void *>
{
public:
  void * get(const string & label) const {
    map<string,void *>::const_iterator iter = map<string,void *>::find(label);
    if (iter==map<string,void *>::end()) return 0;
    return iter->second;
  }
  void * insert(const string & label, void * item) {
    pair< map<string,void *>::iterator, bool > pair = map<string,void *>::insert ( make_pair(label,item) );
    if (pair.first==map<string,void *>::end()) return 0;
    return pair.first->second;
  }
};


/*!
  \class   FrameData
  \brief   A class to store any data related to the current frame.
  \author  Stefan Zickler, (C) 2008

  This class acts as the main storage class for any data related to the current frame.
  This includes the frame itself, stored in the \p Matrix frame
  Any additional data can be stored in the FrameDataMap \p map
*/
class FrameData {
public:
	long long frameNumber;
	double time;
	int deviceID;
	cv::Mat frame;
	FrameDataMap map;
public:
	FrameData();
	virtual ~FrameData();
};

typedef RingBuffer<FrameData> FrameBuffer;

#endif /* FRAMEDATA_H_ */
