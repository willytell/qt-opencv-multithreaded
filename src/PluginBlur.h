/*
 * PluginBlur.h
 *
 *  Created on: 14/02/2014
 *      Author: willytell
 */

#ifndef PLUGINBLUR_H_
#define PLUGINBLUR_H_

// OpenCV
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
// Local
#include "PluginVision.h"

class PluginBlur: public PluginVision {
public:
	PluginBlur();
	virtual ~PluginBlur();

	bool process(FrameData *data);
	std::string getName();	//Overload it to return the name of your plugin
};

#endif /* PLUGINBLUR_H_ */
