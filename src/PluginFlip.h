/*
 * PluginFlip.h
 *
 *  Created on: 13/02/2014
 *      Author: willytell
 */

#ifndef PLUGINFLIP_H_
#define PLUGINFLIP_H_
// OpenCV
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
// Local
#include "PluginVision.h"

class PluginFlip: public PluginVision {
public:
	PluginFlip();
	virtual ~PluginFlip();

	bool process(FrameData *data);
	std::string getName();	//Overload it to return the name of your plugin
};

#endif /* PLUGINFLIP_H_ */
