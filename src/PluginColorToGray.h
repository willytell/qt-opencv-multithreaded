/*
 * PluginColorToGray.h
 *
 *  Created on: 13/02/2014
 *      Author: willytell
 */

#ifndef PLUGINCOLORTOGRAY_H_
#define PLUGINCOLORTOGRAY_H_

// OpenCV
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
// Local
#include "PluginVision.h"


using namespace cv;

class PluginColorToGray: public PluginVision {
public:
	PluginColorToGray();
	virtual ~PluginColorToGray();

	bool process(FrameData *data);
	std::string getName();	//Overload it to return the name of your plugin

};

#endif /* PLUGINCOLORTOGRAY_H_ */
